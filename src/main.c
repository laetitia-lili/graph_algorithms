#include <stdio.h>
#include <stdlib.h>
#include "graph.h"



int main (void){

   

    Graphe g1 = nouveau_graphe ( 5 , faux );// GNO
    ajouter_arete(g1, 1, 2);
    ajouter_arete(g1, 1, 5);
    ajouter_arete(g1, 2, 4);
    ajouter_arete(g1, 2, 3);
    ajouter_arete(g1, 3, 4); 
    ajouter_arete(g1, 4, 5);
    
    
    afficher_graphe(g1);
    dessiner_graphe(g1);
    effacer_graphe (g1);  
     
    
    return 0;
}