#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include <ctype.h>

/*Declaration de la fonction fpurge qui faire la liberation du buffer*/
void __fpurge();

int main()
{
	/*Creation des variables*/
	int largeur;
	/*FILE * fd;
	int x, y*/
	int coups, victoire = 0; /*victoire = 1, il a gagne*/
	char** grille = NULL;
	/*char** g2; LOT D*/
	char c, tmp;


	
	/*Boucle du jeu*/
	do
	{
		/*Effacement du ecran*/
		system("clear");
		
		/*Message de bienvenue*/
		printf("BIENVENUE AU COLOR FLOOD!\n\n");

		/*Demande de la largeur au utilisateur*/ 
		do
		{
			__fpurge(stdin);
			printf("Donnez la largeur entre 12, 18 ou 24 ou 99 pour sortir du jeu : \n");
			scanf("%d", &largeur);
		}while((largeur != 12) && (largeur != 18) && (largeur != 24) && (largeur != 99));
		
		/*Pour sortir du jeu*/
		if(largeur == 99)
		{
			exit(0);
		}

		/*Choisir le nombre de coups*/
		switch(largeur)
		{
			case 12:
			coups = 21;
			break;

			case 18:
			coups = 25;
			break;

			case 24:
			coups = 43;
			break;
		}

		/*Creation de la grille*/
		grille = faire_alocation_matrice(largeur, grille);
		/*g2 = faire_alocation_matrice(largeur, g2); LOT D*/

		/*Creation des coleurs aleactoires*/
		faire_saisie_matrice(largeur,grille);
	 	
	 	/*LOT D
		
		pile solution = initialise_pile(solution);
		pile bestsolution = initialise_pile(solution);
		copier_matrice(grille, g2, largeur);
		bestsolution = solveur(g2, largeur,  solution, bestsolution, 0);

	 	*/
	 	
	 	/*Boucle du jeu*/
	 	while((coups > 0) && (victoire != 1))
	 	{
	 		/*Effacer l'ecran*/
			system("clear");

			/*Afficher la grille et nb coups restants */
			affiche(largeur, grille);
			printf("\nNombres de coups restants: %d\n", coups);
			/*
			printf("couleur[0]%c\n", bestsolution.couleur[0]);
			printf("sommet %d\n", bestsolution.sommet); LOT D */
			/*Selectioner la couleur*/
			do
			{	
				__fpurge(stdin);
				printf("\n Selectioner les couleurs entre J, M, V, B, R et G : ");
				scanf("%c", &tmp);
				c = toupper(tmp);

			}
			while((c != 'B') && (c != 'V') && (c != 'R') && (c != 'J') && (c != 'M') && (c != 'G'));
			
			/*Changement de couleur */
			floodFill(0, 0, c, grille, largeur, grille[0][0]);

			/*Reduction du nombre de coups*/
			coups -= 1;

			/*Faire le derniere actualisation du ecran*/
			if(coups == 0)
			{
				/*Effacer l'ecran*/
				system("clear");

				/*Afficher la grille et nb coups restants */
				affiche(largeur, grille);
				printf("\nNombres de coups restants: %d\n", coups);
			}
			/*Verifier condition de victoire*/
			victoire = verifie_victoire(grille, largeur);
		}

		/*Message finale*/
		if(coups == 0)
		{
			printf("\n Vouz n'avez plus de coups, vous avez perdu. =( \n");
		}
		else
		{
			printf("\n Vous avez gagne! =) \n");
		}
		faire_liberation_matrice(largeur, grille);

		/*Attendre quelque case pour recommencer le jeu*/
		__fpurge(stdin);
		scanf("%c", &c);

	}while(1);

	return 0;
}


