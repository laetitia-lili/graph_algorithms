#!/bin/bash 
mkdir -p obj

gcc -Wall -I include/ -c src/main.c     -o obj/main.o
gcc -Wall -I include/ -c src/graph.c    -o obj/graph.o


gcc -o mon_programme obj/main.o obj/graph.o 

echo "Compilation terminée ✅"
./mon_programme

/opt/homebrew/bin/dot -Tpng graph.dot -o graph.png
[ -f graph.dot ]   && /opt/homebrew/bin/dot -Tpng graph.dot   -o graph.png   && open graph.png
[ -f digraph.dot ] && /opt/homebrew/bin/dot -Tpng digraph.dot -o digraph.png && open digraph.png
