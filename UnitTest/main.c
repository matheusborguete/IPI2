
/*
 cc     essaicunit.c   -o essaicunit -I /usr/local/Cellar/cunit/2.1-3/include/ -lCUnit -L /usr/local/Cellar/cunit/2.1-3/lib/
 */

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <stdio.h>


 /*								*/
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

void test_faire_alocation_matrice(void)
{
	char** grille = NULL;
	char** grille2 = NULL;
	char** grille3 = NULL;
	char** grille4 = NULL;
	char** grille5 = NULL;

	grille = faire_alocation_matrice(12, grille);
	grille2 = faire_alocation_matrice(18, grille);
	grille3 = faire_alocation_matrice(24, grille);
	grille4 = faire_alocation_matrice(-5, grille);
	grille5 = faire_alocation_matrice(0, grille);

	CU_ASSERT_PTR_NOT_NULL(grille);
	CU_ASSERT_PTR_NOT_NULL(grille2);
	CU_ASSERT_PTR_NOT_NULL(grille3);
	CU_ASSERT_PTR_NOT_NULL(grille4);
	CU_ASSERT_PTR_NOT_NULL(grille5);
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
            if(randomValue==1) grille[i][j] ='B';
            if(randomValue==2) grille[i][j] ='V';
            if(randomValue==3) grille[i][j] ='R';
            if(randomValue==4) grille[i][j] ='J';
            if(randomValue==5) grille[i][j] ='M';
            if(randomValue==6) grille[i][j] ='G';
        }
}

void test_faire_saisie_matrice(void)
{
	char** grille = NULL;
	int i, j, taille =12;
	grille = faire_alocation_matrice(taille, grille);
	
	faire_saisie_matrice(taille, grille);

	for(i=0; i<taille; i++)
		for(j=0; j<taille; j++)
			{
				if(grille[i][j] == 'B')	
				{
					CU_ASSERT_PTR_EQUAL(grille[i][j], 'B');
				}
				else if (grille[i][j] == 'V')	
				{
					CU_ASSERT_PTR_EQUAL(grille[i][j], 'V');
				}
				else if (grille[i][j] == 'R')	
					{
						CU_ASSERT_PTR_EQUAL(grille[i][j], 'R');
					}
				else if (grille[i][j] == 'J')	
					{
						CU_ASSERT_PTR_EQUAL(grille[i][j], 'J');
					}
				else if (grille[i][j] == 'M')	
					{
						CU_ASSERT_PTR_EQUAL(grille[i][j], 'M');
					}
				else 
					CU_ASSERT_PTR_EQUAL(grille[i][j], 'G');
			}
}


char** lecture (char ** grille, int largeur, char* fichier)
{
  FILE * fd;
  int i,j;

  fd= fopen (fichier,"r+");

  if((largeur != 12) && (largeur != 18) && (largeur != 24))
  	return NULL;

  if(fd == NULL)
  {
    /*printf("Probleme: Erreur au ouvrir le fichier \n");*/
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

void test_lecture(void)
{
	char** grille = NULL;
	int taille = 12, i, j;
	grille = faire_alocation_matrice(taille, grille);

	grille = lecture(grille, taille, "txtbon.txt");
	
	for(i=0; i<taille; i++)
		for(j=0; j<taille; j++)
			{
				if(grille[i][j] == 'B')	
				{
					CU_ASSERT_PTR_EQUAL(grille[i][j], 'B');
				}
				else if (grille[i][j] == 'V')	
				{
					CU_ASSERT_PTR_EQUAL(grille[i][j], 'V');
				}
				else if (grille[i][j] == 'R')	
					{
						CU_ASSERT_PTR_EQUAL(grille[i][j], 'R');
					}
				else if (grille[i][j] == 'J')	
					{
						CU_ASSERT_PTR_EQUAL(grille[i][j], 'J');
					}
				else if (grille[i][j] == 'M')	
					{
						CU_ASSERT_PTR_EQUAL(grille[i][j], 'M');
					}
				else 
					CU_ASSERT_PTR_EQUAL(grille[i][j], 'G');
			}

			grille = lecture(grille, 33, "txtbon.txt");
			CU_ASSERT_PTR_NULL(grille);
			grille = lecture(grille, -33, "txtbon.txt");
			CU_ASSERT_PTR_NULL(grille);
			grille = lecture(grille, 0, "txtbon.txt");
			CU_ASSERT_PTR_NULL(grille);
			grille = lecture(grille, 'v', "txtbon.txt");
			CU_ASSERT_PTR_NULL(grille);

			grille = lecture(grille, taille, "txtmauvais.txt");
			CU_ASSERT_PTR_NULL(grille);

			CU_ASSERT_PTR_NULL(lecture(grille, taille, "quelquechose.txt"));
}


void faire_liberation_matrice(int largeur,char ** grille)
{
    int i;

    for(i=0 ; i < largeur; i++)
    {
        free(grille[i]);
    }
    
    free(grille);
}

void test_faire_liberation_matrice(void)
{
	char** grille = NULL;
	grille = faire_alocation_matrice(12, grille);

	faire_saisie_matrice(12, grille);
	faire_liberation_matrice(12, grille);
	
	/*CU_ASSERT_PTR_NOT_NULL(grille);*/
	CU_PASS("Il n'y a pas comment tester la fonction free");

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

void test_affiche(void)
{
	char** grille = NULL;
	grille = faire_alocation_matrice(12, grille);
	faire_saisie_matrice(12, grille);

	CU_PASS("Fonction d'affichage. Pas de test logique");

}

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


void test_remplacer_matrice(void)
{
	char** grille = NULL;
	grille = faire_alocation_matrice(12, grille);
	faire_saisie_matrice(12, grille);

	int tmp;

	remplacer_matrice(grille, 'B', 1, 1, 12);
	tmp = remplacer_matrice(grille, 'A', 1, 1, 12);

	CU_ASSERT_PTR_NOT_EQUAL(grille[1][1], 'A');
	CU_ASSERT_EQUAL(tmp, 0)
	CU_ASSERT_PTR_EQUAL(grille[1][1], 'B');

	remplacer_matrice(grille, 'V', 1, 1, 12);
	CU_ASSERT_PTR_EQUAL(grille[1][1], 'V');

	remplacer_matrice(grille, 'R', 1, 1, 12);
	CU_ASSERT_PTR_EQUAL(grille[1][1], 'R');
	
	remplacer_matrice(grille, 'J', 1, 1, 12);
	CU_ASSERT_PTR_EQUAL(grille[1][1], 'J');
	
	remplacer_matrice(grille, 'M', 1, 1, 12);
	CU_ASSERT_PTR_EQUAL(grille[1][1], 'M');
	
	remplacer_matrice(grille, 'G', 1, 1, 12);
	CU_ASSERT_PTR_EQUAL(grille[1][1], 'G');

	tmp =7;
	tmp = remplacer_matrice(grille, 3, 1, 1, 12);
	CU_ASSERT_EQUAL(tmp, 0);

	tmp = 7;
	tmp = remplacer_matrice(grille, -3, 1, 1, 12);
	CU_ASSERT_EQUAL(tmp, 0);
}

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

void test_verifie_victoire(void)
{
	int i, j;
	char** grille = NULL;
	grille = faire_alocation_matrice(12, grille);

	for(i=0; i<12; i++)
		for(j=0; j<!2; j++)
		{
			remplacer_matrice(grille, 'B', i, j, 12);
		}

	int tmp = verifie_victoire(grille, 12);
	CU_ASSERT_EQUAL(tmp, 1);
	remplacer_matrice(grille, 'J', 1, 1, 12);
	tmp = verifie_victoire(grille, 12);
	CU_ASSERT_EQUAL(tmp, 0);
}

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



void changement_couleur(char **grille,char c,int x, int y,int largeur)
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
}


void floodFill(int x, int y, char c, char** grille, int largeur, char oldcolor)
{
  if((x < largeur) && (y < largeur) && (x >= 0) && (y >= 0) && (grille[x][y] != c) && (oldcolor == grille[x][y]))
  {
      remplacer_matrice(grille, c, x, y, largeur);
      floodFill(x+1, y, c, grille, largeur, oldcolor);
      floodFill(x, y+1, c, grille, largeur, oldcolor);
  }
}

void test_floodfill(void)
{
	char** grille = NULL;
	int largeur = 12;
	grille = faire_alocation_matrice(largeur, grille);

	grille = lecture(grille, largeur, "txtfloodfill.txt");

	CU_ASSERT_PTR_EQUAL(grille[0][0], 'B');
	CU_ASSERT_PTR_EQUAL(grille[0][1], 'G');
	CU_ASSERT_PTR_EQUAL(grille[1][0], 'V');

	floodFill(0, 0, 'G', grille, largeur, grille[0][0]);

	CU_ASSERT_PTR_EQUAL(grille[0][0], 'G');
	CU_ASSERT_PTR_EQUAL(grille[0][1], 'G');
	CU_ASSERT_PTR_NOT_EQUAL(grille[1][0], 'G');


	floodFill(0, 0, 'V', grille, largeur, grille[0][0]);

	CU_ASSERT_PTR_EQUAL(grille[0][0], 'V');
	CU_ASSERT_PTR_EQUAL(grille[0][1], 'V');
	CU_ASSERT_PTR_EQUAL(grille[1][0], 'V');


	floodFill(0, 0, 'B', grille, largeur, grille[0][0]);

	CU_ASSERT_PTR_EQUAL(grille[0][0], 'B');
	CU_ASSERT_PTR_EQUAL(grille[0][1], 'B');
	CU_ASSERT_PTR_EQUAL(grille[1][0], 'B');
	CU_ASSERT_PTR_EQUAL(grille[1][1], 'B');
	CU_ASSERT_PTR_EQUAL(grille[0][2], 'R');
	CU_ASSERT_PTR_EQUAL(grille[1][2], 'M');
	CU_ASSERT_PTR_EQUAL(grille[2][0], 'M');
	CU_ASSERT_PTR_EQUAL(grille[2][1], 'V');
	
}


int main() {
	CU_pSuite pSuite = NULL;
	
	if (CU_initialize_registry() != CUE_SUCCESS) {
		return CU_get_error();
	}

	pSuite = CU_add_suite("Suite",NULL,NULL);

	if (pSuite==NULL) {
		CU_cleanup_registry();
		return CU_get_error();
	}
    
	if (CU_add_test (pSuite, "test of faire_alocation_matrice()",test_faire_alocation_matrice)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test (pSuite, "test of faire_saisie_matrice()",test_faire_saisie_matrice)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test (pSuite, "test of faire_liberation_matrice()",test_faire_liberation_matrice)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

	if (CU_add_test (pSuite, "test of affiche()",test_affiche)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test (pSuite, "test of remplacer_matrice()",test_remplacer_matrice)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test (pSuite, "test of verifie_victoire()",test_verifie_victoire)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

	if (CU_add_test (pSuite, "test of lecture()",test_lecture)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test (pSuite, "test of floodfill()",test_floodfill)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    /*CU_cleanup_registry();*/

	return 0;
}
