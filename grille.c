#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include <time.h>

/**
 * \file      grille.c
 * \author    Fatma Bali, Ines Belkacem, Matheus Souza, Selma Labidi
 * \version   1.0
 * \date      24/04/2017
 */

/**
 * \brief fait une allocation dynamique d'une matrice
 *\details  reserve dynamiquement un nombre appelé largeur ou chaque case est de taille d'un caractère
 *\param grille c'est une matrice de caractères et chaque caractère designe une couleur
 * \param largeur designe la taille de la matrice carré
 * \return une matrice de caractères*/
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


/**
*\brief fait le remplissage de matrice
*\details realise l'initialisation de la grille à partir de valeurs aléatoires
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param largeur designe la taille de la matrice carré
*\return une matrice de caractères
*/
/*
  FONCTION faire_saisie_matrice
  @ensure rien
  @requires int : largeur de la grille, char** : la grille
  @return rien
*/
void faire_saisie_matrice(int largeur,char **grille)
{
  int randomValue;
  int i =0, j=0;

  srand( (unsigned)time(NULL) );


  for(i=0; i<largeur; i++)
      for(j=0; j<largeur; j++)
      {
          /*randomValue =  (int)(rand() / (double)RAND_MAX * (N - 1)+1);*/
          randomValue = (rand() % 6) + 1; /*0 - 6*/
          if(randomValue==1) grille[i][j] ='B';
          if(randomValue==2) grille[i][j] ='V';
          if(randomValue==3) grille[i][j] ='R';
          if(randomValue==4) grille[i][j] ='J';
          if(randomValue==5) grille[i][j] ='M';
          if(randomValue==6) grille[i][j] ='G';
      }
}


/**
*\brief realise le remplissage de la matrice à partir d'un fichier
*\details cette fontion realise le remplissage de la matrice
à partir d'un fichier existant qu'on rempli avec des valeurs definies
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param largeur designe la taille de la matrice carré
*\return n'a pas de retour
*/
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

/**
*\brief fait la libération de l'espace alloué
*\details fait une liberation de l'espace memoire resérvé puisqu'on aura pas besoin dans la suite
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param largeur designe la taille de la matrice carré
*\return pas de retour une simple libération
*/
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


/**
*\brief fait l'affichage de toute la matrice
*\details on réalise le parcours de toute la grille et on fait
deux boucle afin qu'on puisse afficher tous les caractères entrées dans la grille
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param largeur designe la taille de la matrice carré
*\return pas de retour seulement un affichage
*/
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


/**
*\brief remplacement d'une couleur par une autre couleur
*\details on donne en entrée les coordonnés de la case à modifier et en sortie
elle donne une novelle matrice contenant la modification
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param le deuxième paramètre à entrer designe la nouvelle couleur
*\param le troisième paramètre designe les coordonnées du point à modifier
*\param le troisième paramètre designe les coordonnées du point à modifier
*\return n'a pas de retour
*/
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


/**
*\brief verifie si le joueur a gagne
*\details verifie la victoire en faisant une comparation pour verifier si toutes les cases ont le meme couleur
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param largeur designe la taille de la matrice carré
*\return 1 (true) si le joueur a gagne ou 0 (false) si il n'ai pas gagne
*/
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



/**
*\brief identifie les compsantes connexes d'une case passé en argument
*\details prend une matrice de couleur et sa largeur ainsi qu'une
cordonnée d'une case et retourne le nombre de composantes connexes
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param le deuxième paramètre designe la taille de la matrice carré
*\param le troisième paramètre designe les coordonnées du point à modifier
*\param le troisième paramètre designe les coordonnées du point à modifier
*\param nb designe le nombre de composants connexes
*\param largeur designe la largeur de la matrice
*\return un tableau contenant les coordonnées des composantes connexes
*/
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
    tab[i]=malloc(4* sizeof(int ));
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


/**
*\brief fait le changement de couleur de toutes les cases de la matrice
*\details realise la modification de la case entrée en paramètre (case d'origine)
et ses composants connexes par la nouvelle couleur c
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param la nouvelle couleur à modifier
*\param coordoné x de la case
*\param coordonnée y de la case
*\param largeur designe la taille de la matrice carré
*\return la grille avec les nouvelles valeurs
*/
/*
  FONCTION changement_couleur
  @ensure change la couleur de la composant 4-fonnexe
  @requires int : largeur de la grille, x et y, char** : grille,et la char la couleur c
  @return rien
*/
char** changement_couleur(char **grille,char c,int x, int y,int largeur)
{
  int i;

  if(grille[x][y]!=c)
  {
    int ** tab;
    int * nb=malloc(sizeof(int ));

    tab=connexite_matrice(largeur,x,y,nb);

    for(i=0; i<*nb; i++)
    {
      if((grille[tab[0][i]][tab[1][i]]!=c)&&(grille[x][y]==grille[tab[0][i]][tab[1][i]]))
      {
        remplacer_matrice(grille,c,tab[0][i],tab[1][i], largeur);
      }
    }

    remplacer_matrice(grille,c,x,y, largeur);
  }

  return grille;
}


/**
*\brief fait le changement de couleur de la composant connexe
*\details realise la modification de de couleur de la composant connexe
*\param coordoné x de la case
*\param coordonnée y de la case
*\param la nouvelle couleur à modifier
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param largeur designe la taille de la matrice carré
*\param oldcolor qui dit la couleur a ete la composant avant
*\return rien
*/
void floodFill(int x, int y, char c, char** grille, int largeur, char oldcolor)
{
  if((x < largeur) && (y < largeur) && (x >= 0) && (y >= 0) && (grille[x][y] != c) && (oldcolor == grille[x][y]))
  {
      remplacer_matrice(grille, c, x, y, largeur);
      floodFill(x+1, y, c, grille, largeur, oldcolor);
      floodFill(x, y+1, c, grille, largeur, oldcolor);
      floodFill(x-1, y, c, grille, largeur, oldcolor);
      floodFill(x, y-1, c, grille, largeur, oldcolor);
  }
}


/**
*\brief initialise la pile
*\param pile qui sera initialise
*\return la pile initialise
*/
pile initialise_pile(pile solution)
{
  /*Declaration des variables*/
  int i=0;

  /*Si la case est vide ça valeur est égalle a 'z'*/
  for(i=0; i<1000; i++)
    solution.couleur[i]='z';

  /*Initialization de la sommet = -1*/
  solution.sommet=-1;

  return solution;
}

/**
*\brief fait une inserction dans la pile
*\param pile qui sera initialise
*\param newcolor qui sera ajoute dans la pile
*\return la pile
*/
pile push(pile solution, char newcolor)
{
    /*Taille de la pile = 100*/
  if(solution.sommet < 999)
  {
        solution.sommet+= 1;
        solution.couleur[solution.sommet] = newcolor;
  }

  return solution;
}

/**
*\brief retirer le element au sommet de la pile
*\param pile qui sera initialise
*\return la pile
*/
pile pop(pile solution)
{
    if(solution.sommet>=0)
    {
        if(solution.sommet==0)
            solution.couleur[0]='z';
        else
        {
            solution.couleur[solution.sommet]='z';
            solution.sommet-= 1;
        }

    }
    else
        solution.sommet=-1;

    return solution;
}


char dernier_Couleur(pile solution)
{
    return solution.couleur[solution.sommet];

}

/**
*\brief verifie si la solution trouve c'est mieux qui la qu'on a trouv´e avant
*\param solution avec la nouvelesolution
*\param bestsolution avec la mieux solution
*\return rien
*/
pile uneSolutionTrouvee(pile solution, pile bestsolution)
{
  if(bestsolution.sommet == -1)
    bestsolution = solution;
  else
  {
    if(solution.sommet < bestsolution.sommet)
      bestsolution = solution;
  }

  return bestsolution;
}


/**
*\brief trouve la mieux solution pour la resolution de la grille
\*param grille la grille du jeu
\*param largeur de la grille
*\param solution avec la nouvelesolution
*\param bestsolution avec la mieux solution
*\return rien
*/
pile solveur(char** grille, int largeur, pile solution, pile bestsolution, int profundeur)
{

    int i=0;
    char** g2 = grille;
    for (i=0; i<6; i=i+1)
    {
  /*  printf("%d", i); */
        switch(i)
        {
            case 0:
             if ((dernier_Couleur(solution)!='J')||(solution.sommet==-1))
                {solution = push(solution,'J');
                floodFill(0, 0, 'J', g2, largeur, g2[0][0]);}
                break;
            case 1: if ((dernier_Couleur(solution)!='B')||(solution.sommet!=-1))
                {solution = push(solution,'B');
                floodFill(0, 0, 'B', g2, largeur, g2[0][0]);}
                break;
            case 2:
             if ((dernier_Couleur(solution)!='V')||(solution.sommet!=-1))
               { solution = push(solution,'V');
                floodFill(0, 0, 'V', g2, largeur, g2[0][0]);}
                break;
            case 3:
             if ((dernier_Couleur(solution)!='M')||(solution.sommet!=-1))
              { solution = push(solution,'M');
                floodFill(0, 0, 'M', g2, largeur, g2[0][0]);}
                break;
            case 4:
             if ((dernier_Couleur(solution)!='R')||(solution.sommet!=-1))
              {  solution = push(solution,'R');
                floodFill(0, 0, 'R', g2, largeur, g2[0][0]);
                }break;
            case 5:
             if ((dernier_Couleur(solution)!='G')||(solution.sommet!=-1))
               { solution = push(solution,'G');
                floodFill(0, 0, 'G', g2, largeur, g2[0][0]);}
                break;
        }

        if (verifie_victoire(g2, largeur) == 1)
        {
          bestsolution = uneSolutionTrouvee(solution, bestsolution);
          solution = pop(solution);
          largeur = profundeur;
        }
         if(largeur>profundeur )
           solution = solveur(g2, largeur, solution,  bestsolution, profundeur+1);
        else
        {

             /*solution = solveur(g2, largeur, solution,  bestsolution, profundeur+1); */
              solution = pop(solution);

        }
    }
    	/*printf("sommet %d\n", bestsolution.sommet); */
  return bestsolution;
}


void  Puch_Color(char ** g2,int largeur,int x, int y , pile solution){
    char c = g2[0][0] ;
    if((x >= 0) && (x < largeur) && (y >= 0) && (y < largeur)
       && (g2[x][y] == c ))
    {

        Puch_Color(g2,largeur, x + 1, y,solution);
        Puch_Color(g2,largeur, x , y + 1,solution);

    }
    else if (x >= 0 && x < largeur && y >= 0 && y < largeur
             && g2[x][y] != c){
        if(solution.sommet==1){
            solution = push(solution,c);
        }

    }

}



/**SOLVEUR_OPTIMISER
*\brief trouve la mieux solution pour la resolution de la grille
\*param grille la grille du jeu
\*param largeur de la grille
*\param solution avec la nouvelesolution
*\param bestsolution avec la mieux solution
*\return rien
*/
pile solveur_Optimal(char** grille, int largeur, pile solution, pile bestsolution, int profundeur)
{

    int i=0;
    char** g2 = grille;
    /*Puch_Color(g2,largeur,0,0,solution); */
    for (i=0; i<6; i=i+1)
    {
  
    /*printf("i : %d, prof : %d. \t", i, profundeur); */
        switch(i)
        {
            case 0:
             if ((dernier_Couleur(solution)!='J')||(solution.sommet==-1))
                {solution = push(solution,'J');
                floodFill(0, 0, 'J', g2, largeur, g2[0][0]);}
                break;
            case 1: if ((dernier_Couleur(solution)!='B')||(solution.sommet!=-1))
                {solution = push(solution,'B');
                floodFill(0, 0, 'B', g2, largeur, g2[0][0]);}
                break;
            case 2:
             if ((dernier_Couleur(solution)!='V')||(solution.sommet!=-1))
               { solution = push(solution,'V');
                floodFill(0, 0, 'V', g2, largeur, g2[0][0]);}
                break;
            case 3:
             if ((dernier_Couleur(solution)!='M')||(solution.sommet!=-1))
              { solution = push(solution,'M');
                floodFill(0, 0, 'M', g2, largeur, g2[0][0]);}
                break;
            case 4:
             if ((dernier_Couleur(solution)!='R')||(solution.sommet!=-1))
              {  solution = push(solution,'R');
                floodFill(0, 0, 'R', g2, largeur, g2[0][0]);
                }break;
            case 5:
             if ((dernier_Couleur(solution)!='G')||(solution.sommet!=-1))
               { solution = push(solution,'G');
                floodFill(0, 0, 'G', g2, largeur, g2[0][0]);}
                break;
        }

        if (verifie_victoire(g2, largeur) == 1)
        {
            bestsolution = uneSolutionTrouvee(solution, bestsolution);
        solution = pop(solution);
            largeur = profundeur;
            continue;
        }
         if(largeur>profundeur )
           solution =solveur_Optimal(g2, largeur, solution,  bestsolution, profundeur+1);
        else
        {

             /* solution = solveur(g2, largeur, solution,  bestsolution, profundeur+1);*/
              solution = pop(solution);

        }
    }
    	/*printf("sommet %d\n", bestsolution.sommet); */
  return bestsolution;
}
/**
*\brief copie une matrice `a autre
\*param grille la premiere matrice
\*param g2 la deuxieme matrice
\*param largeur de la grille
*\return rien
*/
void copier_matrice(char** grille, char** g2, int largeur)
{
  int i=0, j=0;

  for(i=0; i<largeur; i++)
    for(j=0; j<largeur; j++)
      g2[i][j]=grille[i][j];
}
