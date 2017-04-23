#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
int main()
{
 int largeur ;
 FILE * fd;
 int i,j;
printf("donner largeur \n");
 scanf("%d",&largeur);
char **grille;
 grille = faire_alocation_matrice(largeur,grille);
 faire_saisie_matrice(largeur,grille);
 affiche(largeur,grille);
             lecture(grille,largeur);
int x,y ;char c;
printf("donner postion à modifier \n");
 scanf("%d",&x);
 scanf("%d",&y);
 printf("donner un caractere\n");

c='P';

affiche(largeur,grille);
    printf("Hello world!\n");
    int ** tab;
    int * nb=malloc(sizeof(int ));

tab=connexite_matrice(grille,largeur,x,y,&nb);

changement_couleur(grille,c,x,y,largeur);
affiche(largeur,grille);

    return 0;
}
