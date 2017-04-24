#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

/*
  FONCTION faire_alocation_matrice
  @ensure allocation de memoire
  @requires int : largeur de la grille, char** la grille
  @return la grille aprés faire l'allocation de memoire
*/
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


/*
  FONCTION faire_saisie_matrice
  @ensure rien
  @requires int : largeur de la grille, char** : la grille
  @return rien
*/
void faire_saisie_matrice(int largeur,char **grille)
{
  int N=7;
  int randomValue;
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


/*
  FONCTION lecture
  @ensure prend les couleurs d'un fichier et met sur la grille
  @requires int : largeur de la grille, char** : la grille
  @return NULL si il y a eu des problemes ou la grille si tout a bien passe
*/
char** lecture (char ** grille, int largeur, char* fichier)
{
  FILE * fd;
  int i,j;

  fd= fopen (fichier,"r+");

  if((largeur != 12) && (largeur != 18) && (largeur != 24))
    return NULL;

  if(fd == NULL)
  {
    printf("Probleme: Erreur au ouvrir le fichier \n");
    return NULL;
  }

  else 
    { 
      grille = faire_alocation_matrice(largeur,grille);
      for (i =0; i<largeur;i++)
        {
          grille[i] = (char *) calloc (largeur, sizeof(char *));
        }
      char ch [128];
      for (i =0; i<largeur;i++)
      {
        fgets(ch,sizeof(ch),fd);
        for( j =0; j<largeur;j++)
        {
          if((ch[j] != 'B') && (ch[j] != 'R') && (ch[j] != 'V') && (ch[j] != 'J') && (ch[j] != 'M') && (ch[j] != 'G'))
            return NULL;

          grille[i][j]=ch[j];
        }
      }
      
      fclose(fd);
      return grille;
    }
}

/*
  FONCTION faire_liberation_matrice
  @ensure libére la memoire destiné a la matrice
  @requires int : largeur de la grille, char** : la grille
  @return rien
*/
void faire_liberation_matrice(int largeur,char ** grille)
{
  int i;
  for(i=0 ; i < largeur; i++)
  {
    free(grille[i]);
  }

  free(grille);
}


/*
  FONCTION affiche
  @ensure affiche la matrice (grille)
  @requires int : largeur de la grille, char** : la grille
  @return rien
*/
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


/*
  FONCTION remplacer_matrice
  @ensure prend la position x et y de la matrice et la remplace avec la couleur c
  @requires int : largeur de la grille, char** : la grille, char : c, x et y
  @return 0(false) si il y a eu des problémes ou 1(true) si tout a bien passé
*/
int remplacer_matrice(char **grille,char c,int x, int y, int largeur)
{
  if ((c != 'B') && (c != 'V') && (c != 'R') && (c != 'J') && (c != 'M') && (c != 'G'))
  {
      return 0;
  }

  if ((x > largeur) || (y > largeur) || (y < 0) || (x < 0))
  {
    return 0;
  }

  grille[x][y]=c;
  return 1;
}


/*
  FONCTION verifie_victoire
  @ensure verifie si le joueur a gagné
  @requires int: largeur de la grille, char** : la grille
  @return 0 si le joueur ne pas gagné ou 1 si il a gagné
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


/*
  FONCTION connexite_matrice
  @ensure trouve la composant 4-connexe de la grille
  @requires int : la largeur de la grille, les couleurs x et y, char** la grille, int * nb 
  @return la composant 4-connexe
*/
int **  connexite_matrice(int largeur,int x, int y,  int * nb)
{
  int ** tab;
  int i;
  
  tab=malloc(2 * sizeof(int *));
  
  for(i=0;i<2;i++)
  {
    tab[i]=malloc(4* sizeof(int *));
  }

  int j=0;
  if(y-1>=0)
  {
    tab[0][j]=x;
    tab[1][j]=y-1;
    j++;
  }

  if(y+1<largeur)
  {
    tab[0][j]=x;
    tab[1][j]=y+1;
    j++;
  }

  if(x-1>=0)
  {
    tab[0][j]=x-1;
    tab[1][j]=y;
    j++;
  }

  if(x+1<largeur)
  {
    tab[0][j]=x+1;
    tab[1][j]=y;
    j++;
  }

  *nb=j;

  return tab;
}


/*
  FONCTION changement_couleur
  @ensure change la couleur de la composant 4-fonnexe
  @requires int : largeur de la grille, x et y, char** : grille,et la char la couleur c
  @return rien
*/
void changement_couleur(char **grille,char c,int x, int y,int largeur)
{
  int i;

  if(grille[x][y]!=c)
  {
    int ** tab;
    int * nb=malloc(sizeof(int ));

    tab=connexite_matrice(largeur,x,y,nb);
    for(i=0; i<nb; i++)
    {
      if((grille[tab[0][i]][tab[1][i]]!=c)&&(grille[x][y]==grille[tab[0][i]][tab[1][i]]))
      {
        remplacer_matrice(grille,c,tab[0][i],tab[1][i], largeur);
      }
    }

  remplacer_matrice(grille,c,x,y, largeur);
  }
}
