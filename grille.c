#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

char** faire_alocation_matrice(int largeur,char ** grille)
{
int i =0, j=0;



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

int i =0, j=0;
  for(i=0; i<largeur; i++)
    for(j=0; j<largeur; j++)
{randomValue =  (int)(rand() / (double)RAND_MAX * (N - 1)+1);

if(randomValue==1) grille[i][j] ='B';
if(randomValue==2) grille[i][j] ='V';
if(randomValue==3) grille[i][j] ='R';
if(randomValue==4) grille[i][j] ='J';
if(randomValue==5) grille[i][j] ='M';
if(randomValue==6) grille[i][j] ='G';

     }
}
void lecture (char ** grille, int largeur)
    {
   FILE * fd;
int i,j;
    fd= fopen ("txt.txt","r+");

if(fd == NULL)
   {
      printf("Error opening file\n");

   }

 else { grille = faire_alocation_matrice(largeur,grille);
    for (i =0; i<largeur;i++)
      {
    grille[i] = (char *) calloc (largeur, sizeof(char *));
    }
    char ch [128];
    for (i =0; i<largeur;i++)
      {
    fgets(ch,sizeof(ch),fd);
    for( j =0; j<largeur;j++)
      {grille[i][j]=ch[j];}

}
    for (i=0; i<largeur;i++){
      for (j=0; j<largeur;j++)
    {
      printf("%c",grille[i][j]);}

      printf("\n");}
    fclose(fd);}
    }
void faire_liberation_matrice(int largeur,char ** grille)
{
int i;
for(i=0 ; i < largeur; i++){

     free(grille[i]);
}
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
void remplacer_matrice(char **grille,char c,int x, int y)
{
grille[x][y]=c;
}
int **  connexite_matrice(char **grille,int largeur,int x, int y,  int * nb)
{

int ** tab;
int i;
tab=malloc(2 * sizeof(int *));
for(i=0;i<2;i++)
{tab[i]=malloc(4* sizeof(int *));
}
int j=0;
if(y-1>=0)
{tab[0][j]=x;
tab[1][j]=y-1;
j++;
}
if(y+1<largeur)
{tab[0][j]=x;
tab[1][j]=y+1;
j++;
}
if(x-1>=0)
{tab[0][j]=x-1;
tab[1][j]=y;
j++;
}
if(x+1<largeur)
{tab[0][j]=x+1;
tab[1][j]=y;
j++;
}

*nb=j;


return tab;
}
void changement_couleur(char **grille,char c,int x, int y,int largeur)
{
int i;

if(grille[x][y]!=c)
 {
 int ** tab;
    int * nb=malloc(sizeof(int ));

tab=connexite_matrice(grille,largeur,x,y,&nb);
for(i=0; i<nb; i++)
{
if((grille[tab[0][i]][tab[1][i]]!=c)&&(grille[x][y]==grille[tab[0][i]][tab[1][i]]))
{remplacer_matrice(grille,c,tab[0][i],tab[1][i]);

}
}
remplacer_matrice(grille,c,x,y);

}
}
