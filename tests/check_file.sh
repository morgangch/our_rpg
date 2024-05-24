#!/bin/bash

# Vérifier si un argument a été fourni
if [ -z "$1" ]; then
    echo "Usage: $0 /chemin/vers/Makefile_ou_binaire"
    exit 1
fi

# Chemin vers le fichier
INPUT_PATH=$1
OUTPUT_FILE="appels_fonctions.txt"

# Fonctions à vérifier
declare -a FONCTIONS=(
    "sfRenderWindow_setFramerateLimit"
    "sfRenderWindow_create"
    "sfRenderWindow_destroy"
    "sfRenderWindow_isOpen"
    "sfRenderWindow_pollEvent"
    "sfRenderWindow_clear"
    "sfRenderWindow_drawSprite"
    "sfRenderWindow_display"
    "sfRenderWindow_close"
    "sfSprite_create"
    "sfSprite_destroy"
    "sfSprite_setTexture"
    "sfTexture_createFromFile"
    "sfImage_createFromFile"
    "sfTexture_destroy"
    "sfImage_destroy"
    "sfClock_create"
    "sfClock_destroy"
    "sfClock_getElapsedTime"
    "sfClock_restart"
)

# Fonction pour extraire la variable NAME du Makefile
extract_name_from_makefile() {
    local makefile=$1
    local name=$(grep -E '^NAME = ' "$makefile" | cut -d '=' -f2 | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')
    echo "$name"
}

# Vérifier si le fichier fourni est un Makefile
if grep -q 'Makefile' <<< "$INPUT_PATH"; then
    # Aller dans le répertoire du Makefile
    echo "Makefile found in $INPUT_PATH"
    MAKEFILE_DIR=$(dirname "$INPUT_PATH")
    cd "$MAKEFILE_DIR" || exit

    echo "Entering directory $MAKEFILE_DIR"
    # Extraire le nom du binaire de la variable NAME
    BINARY_NAME=$(extract_name_from_makefile "Makefile")

    echo "Binary name: $BINARY_NAME"

    # Vérifier si la variable NAME a été trouvée
    if [ -z "$BINARY_NAME" ]; then
        echo "Erreur: La variable NAME n'a pas été trouvée dans le Makefile."
        exit 1
    fi

    # Compilation du code avec l'option debug du Makefile
    make debug

    # Vérifier si la compilation a réussi
    if [ $? -ne 0 ]; then
        echo "Erreur: La compilation a échoué."
        exit 1
    fi

    # Définir le chemin vers le binaire
    EXECUTABLE="$BINARY_NAME"

else
    echo "Makefile not found in $INPUT_PATH"
    # Si ce n'est pas un Makefile, considérer l'argument comme un fichier binaire
    EXECUTABLE="$INPUT_PATH"
fi

# Vérifier si l'exécutable existe
if [ ! -f "$EXECUTABLE" ]; then
    echo "Erreur: Le fichier exécutable '$EXECUTABLE' n'existe pas."
    exit 1
fi

# Vérification des appels de fonctions avec nm et objdump
{
    echo "=== Appels de fonctions dans le fichier objet ==="
    nm -C "$EXECUTABLE" | grep -E "$(IFS='|'; echo "${FONCTIONS[*]}")"

    echo ""
    echo "=== Désassemblage et vérification des appels de fonctions ==="
    objdump -d -M intel "$EXECUTABLE" | grep -E "$(IFS='|'; echo "call.*(${FONCTIONS[*]})")"
} > "$OUTPUT_FILE"

echo "Analyse terminée. Les résultats sont dans le fichier $OUTPUT_FILE."
