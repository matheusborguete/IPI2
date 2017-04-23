#ifndef GRILLE_H_INCLUDED
#define GRILLE_H_INCLUDED


/*typedef enum Color Color;
enum Color
{B,V,R,J,M,G
};

char** grille;
*/
char ** faire_alocation_matrice(int largeur,char **grille);
void faire_saisie_matrice(int largeur,char **grille);
void affiche(int largeur,char ** grille);
void faire_liberation_matrice(int largeur,char **grille);
int remplacer_matrice(char **grille,char c,int x, int y);
int verifie_victoire(char** grille, int largeur);
#endif
