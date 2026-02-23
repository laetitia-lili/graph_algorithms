#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


/* =======Crée et retourne un nouveau graphe avec nb_sommets sommets======= */
Graphe nouveau_graphe(int nb_sommets, Booleen est_oriente){

    GrapheElement *element;

    /* =======Allocation dynamique de la structure principale du graphe======= */
    element = malloc(sizeof(*element));
     if (element == NULL){
        fprintf(stderr,"Erreur lors de l'allocation dynamique .\n");
        exit(EXIT_FAILURE); 
     };

     /* =======Initialisation des champs du graphe======= */
     element->est_oriente = est_oriente;
     element->nb_sommets = nb_sommets;

     /* =======Allocation du tableau de listes d'adjacence (une liste par sommet)======= */
     element->tab_voisins = malloc(nb_sommets *sizeof(ListeAdjacenceElement));

     if (element->tab_voisins == NULL){
        fprintf(stderr ,"Erreur lors de l'allocation dynamique ()" );
        exit(EXIT_FAILURE);
     }

     /* =======Initialisation de chaque liste d'adjacence à NULL (aucun voisin au départ)======= */
     for (int i = 1; i <= nb_sommets; i++){
        element->tab_voisins [i-1].debut = NULL ; 
     }

     if (element->est_oriente){ element->graph_file = fopen ("digraph.dot","w"); // GO
     }else{ element->graph_file = fopen("graph.dot","w"); } // GNO 
     
     if (element->graph_file == NULL){
        fprintf(stderr,"Problème de création du fichier.\n");
        exit (EXIT_FAILURE);
     }

     if (element->est_oriente){
        fprintf (element->graph_file , "digraph mon_graphe\n{\n");
     }else {
        fprintf (element->graph_file , "graph mon_graphe\n{\n");
     }

     /* =======Retourne le pointeur vers le graphe nouvellement créé======= */
     return element;
}    

/*---------------------------------------------------------------------------*/

Booleen graphe_est_vide(Graphe g) {
    if (g == NULL) return vrai;
    return faux;
}

/*---------------------------------------------------------------------------*/
NoeudListe ajouter_noeud(int x) {
    NoeudListe n = malloc (sizeof(NoeudListeElement));
     if (n == NULL){
        fprintf(stderr,"Erreur lors de l'allocation dynamique .\n");
        exit(EXIT_FAILURE); 
     };

     n->valeur = x;
     n->suivant = NULL ;

     return n ;

}

/*---------------------------------------------------------------------------*/
void effacer_graphe(Graphe g) {
    if (graphe_est_vide (g) ){
        printf("Rien à effacer , le graphe n'existe pas ");
        return ;
    }  

    // Si sommets adjacents 
    if (g -> tab_voisins){ 
        for (int i = 1; i <= g->nb_sommets; i++) {
            NoeudListe n = g ->tab_voisins [i - 1].debut ;

            while (n != NULL){
                NoeudListe tmp = n ;
                n = n->suivant;
                free(tmp);
            }
        }

        // Libération de la liste d'adjacence 
        free(g->tab_voisins);
    }

    // // fin et fermeture du fichier Graphviz
    fprintf(g->graph_file, "}\n");
    fclose(g->graph_file);
    //libération du graphe 
    free(g);
}

/*---------------------------------------------------------------------------*/

void ajouter_arete(Graphe g , int src , int dest){

    // il faut le faire dans le cas d'un GO et GNO
    NoeudListe n = ajouter_noeud (dest);
    n->suivant = g->tab_voisins [src - 1].debut;
    g->tab_voisins [src - 1].debut = n;

    // cas GNO
    if (!g -> est_oriente){
        n = ajouter_noeud (src);
        n->suivant = g->tab_voisins[dest - 1].debut;
        g->tab_voisins[dest - 1].debut = n ;
    }

    // ajout d'un lien dans le fichier graphiz
    if (g->est_oriente){ fprintf(g->graph_file, "\t%d -> %d;\n" , src, dest);
    }else{ fprintf(g->graph_file, "\t%d -- %d;\n ", src, dest); }
}

/*---------------------------------------------------------------------------*/
void afficher_graphe (Graphe g){

     if (graphe_est_vide(g)){ printf("Le graphe n'existe pas "); return; }

     for (int i = 1 ; i < g ->nb_sommets + 1; i++){
        NoeudListe n = g -> tab_voisins [i - 1].debut;
        printf("(%d) : ",i);

        while (n != NULL) {
            printf("%d, ",n ->valeur);
            n = n->suivant;
        }
        printf("NULL\n");
     }
}

/*---------------------------------------------------------------------------*/
Graphe construire_graphe_exemple(void)
{
    Graphe g1 = nouveau_graphe ( 5 , faux ); // GNO
    ajouter_arete(g1, 1, 2);
    ajouter_arete(g1, 1, 5);
    ajouter_arete(g1, 2, 4);
    ajouter_arete(g1, 2, 3);
    ajouter_arete(g1, 3, 4); 
    ajouter_arete(g1, 4, 5);
    return g1;
}

/*---------------------------------------------------------------------------*/

void dessiner_graphe (Graphe g){
     
    // géré par le script de compilation 
    
}