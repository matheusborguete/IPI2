#include <stdio.h>
#include <stdlib.h>
/*#include "grille.h"*/

char** faire_alocation_matrice(int largeur,char ** grille)
{
    int i =0;

    if((largeur != 12) && (largeur != 18) && (largeur != 24))
        largeur = 18;

    grille= (char **) malloc( sizeof(char *) * largeur);

    for(i=0; i<largeur; i++)
    {
        grille[i] = (char *) malloc(sizeof(char) * largeur);
    }

    return grille;
}

void faire_saisie_matrice(int largeur,char **grille)
{
    int N=7;
    int randomValue;
    /*printf("%d",randomValue);*/
    int i =0, j=0;
    for(i=0; i<largeur; i++)
        for(j=0; j<largeur; j++)
        {
            randomValue =  (int)(rand() / (double)RAND_MAX * (N - 1)+1);
            printf("%d     ",randomValue);
            if(randomValue==1) grille[i][j] ='B';
            if(randomValue==2) grille[i][j] ='V';
            if(randomValue==3) grille[i][j] ='R';
            if(randomValue==4) grille[i][j] ='J';
            if(randomValue==5) grille[i][j] ='M';
            if(randomValue==6) grille[i][j] ='G';
        }
}

void faire_liberation_matrice(int largeur,char ** grille)
{
    int i;

    for(i=0 ; i < largeur; i++)
        free(grille[i]);
    
    free(grille);
}

void affiche(int largeur,char ** grille)
{
    int i,j;

    for( i=0; i<largeur; i++)
    {
        for( j=0; j<largeur; j++)
            printf("%c  ",grille[i][j]);
        printf("\n");
    }
}

int remplacer_matrice(char **grille,char c,int x, int y)
{
    if ((c != 'B') && (c != 'V') && (c != 'R') && (c != 'J') && (c != 'M') && (c != 'G'))
    {
        return 0;
    }

    grille[x][y]=c;
    return 1;
}

/*

*/
int verifie_victoire(char** grille, int largeur)
{
    int i, j;
    char c = grille[0][0];

    for(i=0; i<largeur; i++)
    {
        for(j=0; j<largeur; j++)
        {
            if(grille[i][j] != c)
                return 0;
        }
    }

    return 1;
}