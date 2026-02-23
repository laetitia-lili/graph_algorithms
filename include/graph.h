#ifndef GRAPH_H
#define GRAPH_H

/* =======Définition d'un booléen======= */
typedef enum {
    faux,   // faux = 0
    vrai    // vrai = 1
} Booleen;

/* =======Définition d'un Noeud (sommet)======= */
typedef struct NoeudListeElement {

    int valeur;                         
    struct NoeudListeElement *suivant; 

} NoeudListeElement, *NoeudListe;

/* =======Définition d'une liste d'adjacence======= */
typedef struct ListeAdjacenceElement {

    NoeudListeElement *debut;      

} ListeAdjacenceElement, *ListeAdjacence;

/* =======Définition d'un Graphe======= */
typedef struct GrapheElement {

    Booleen est_oriente;                
    int nb_sommets;                     
    ListeAdjacence tab_voisins;  // Tableau de listes d'adjacence (un par sommet)          
    FILE *graph_file;

} GrapheElement, *Graphe;

/* =======Création d'un nouveau graphe (prototypes)======= */
Graphe nouveau_graphe(int nb_sommets, Booleen est_oriente);
Graphe construire_graphe_exemple(void);
Booleen graphe_est_vide(Graphe g);
NoeudListe ajouter_noeud(int x);
void ajouter_arete(Graphe g , int src , int dest);
void afficher_graphe(Graphe g);
void dessiner_graphe(Graphe g);
void effacer_graphe(Graphe g);

#endif