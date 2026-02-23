#include <stdio.h>
#include <stdlib.h>
#include "graph.h"



int main (void){

    Graphe g1 = construire_graphe_exemple();

    afficher_graphe(g1);
    dessiner_graphe(g1);
    effacer_graphe (g1);  
     
    
    return 0;
}