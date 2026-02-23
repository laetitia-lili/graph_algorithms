#!/bin/bash

# Crée le répertoire obj
mkdir -p obj

# Compilation des fichiers source
gcc -Wall -I include/ -c src/main.c     -o obj/main.o
gcc -Wall -I include/ -c src/graph.c    -o obj/graph.o

# Création de l'exécutable
gcc -o mon_programme obj/main.o obj/graph.o 

# Message de fin de compilation
echo "Compilation terminée ✅"

# Exécution du programme
./mon_programme

# Génération des images à partir des fichiers .dot
if [ -f graph.dot ]; then
    # Vérifie si la commande dot est disponible
    if command -v dot &> /dev/null; then
        dot -Tpng graph.dot -o graph.png
        # Ouvrir l'image selon le système
        if [[ "$OSTYPE" == "darwin"* ]]; then
            # macOS: utiliser la commande `open`
            open graph.png
        elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
            # Linux: utiliser la commande `xdg-open`
            xdg-open graph.png
        fi
    else
        echo "Erreur: La commande 'dot' n'est pas disponible. Installez Graphviz."
    fi
fi

if [ -f digraph.dot ]; then
    if command -v dot &> /dev/null; then
        dot -Tpng digraph.dot -o digraph.png
        # Ouvrir l'image selon le système
        if [[ "$OSTYPE" == "darwin"* ]]; then
            # macOS: utiliser la commande `open`
            open digraph.png
        elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
            # Linux: utiliser la commande `xdg-open`
            xdg-open digraph.png
        fi
    else
        echo "Erreur: La commande 'dot' n'est pas disponible. Installez Graphviz."
    fi
fi