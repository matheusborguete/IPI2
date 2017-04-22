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

int x,y ;char c;
printf("donner postion à modifier \n");
 scanf("%d",&x);
 scanf("%d",&y);
 printf("donner un caractere\n");
// scanf("%c",&c);
c='P';
 printf("%c \n",c);
 remplacer_matrice(grille,c,x,y);
affiche(largeur,grille);
    printf("Hello world!\n");


    //////////////////////////////////////////

faire_liberation_matrice(largeur,grille);
system("pause");
    return 0;
}
