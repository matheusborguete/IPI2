
#ifndef GRILLE_H_INCLUDED
#define GRILLE_H_INCLUDED
/*typedef enum Color Color;
enum Color
{B,V,R,J,M,G
};
*/
//char** grille;
//
/**
 * \file          module_modeleVoiture.c
 * \author    Miroslav
 * \version   1.0
 * \date       12 Novembre 2009
 * \brief       Définit les modèles de voiture et leur particularités.
 *
 * \details    Cette classe surcharge les accesseurs standards du module_voiture pour
 *                  convenir aux spécificités des différents modèles possibles.
 */



 /**
 * \brief fait une allocation dynamique d'une matrice
 *\details  reserve dynamiquement un nombre appelé largeur ou chaque case est de taille d'un caractère
 *\param grille c'est une matrice de caractères et chaque caractère designe une couleur
 * \param largeur designe la taille de la matrice carré
 * \return une matrice de caractères*/

char ** faire_alocation_matrice(int largeur,char **grille);
/**
*\brief fait le remplissage de matrice
*\details realise l'initialisation de la grille à partir de valeurs aléatoires
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param largeur designe la taille de la matrice carré
*\return une matrice de caractères
*/
void faire_saisie_matrice(int largeur,char **grille);
/**
*\brief fait l'affichage de toute la matrice
*\details on réalise le parcours de toute la grille et on fait
deux boucle afin qu'on puisse afficher tous les caractères entrées dans la grille
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param largeur designe la taille de la matrice carré
*\return pas de retour seulement un affichage
*/


void affiche(int largeur,char ** grille);

/**
*\brief fait la libération de l'espace alloué
*\details fait une liberation de l'espace memoire resérvé puisqu'on aura pas besoin dans la suite
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param largeur designe la taille de la matrice carré
*\return pas de retour une simple libération
*/

void faire_liberation_matrice(int largeur,char **grille);

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
void remplacer_matrice(char **grille,char c,int x, int y);
/**
*\brief identifie les compsantes connexes d'une case passé en argument
*\details prend une matrice de couleur et sa largeur ainsi qu'une
cordonnée d'une case et retourne le nombre de composantes connexes
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param le deuxième paramètre designe la taille de la matrice carré
*\param le troisième paramètre designe les coordonnées du point à modifier
*\param le troisième paramètre designe les coordonnées du point à modifier
*\param nb designe le nombre de composants connexes
*\return un tableau contenant les coordonnées des composantes connexes
*/



int ** connexite_matrice(char **grille,int largeur,int x, int y, int  * nb);

/**
*\brief realise le remplissage de la matrice à partir d'un fichier
*\details cette fontion realise le remplissage de la matrice
à partir d'un fichier existant qu'on rempli avec des valeurs definies
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param largeur designe la taille de la matrice carré
*\return n'a pas de retour
*/





void lecture(char ** grille, int largeur);

/**
*\brief fait le changement de couleur de toutes les cases de la matrice
*\details realise la modification de la case entrée en paramètre (case d'origine)
et ses composants connexes par la nouvelle couleur c
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param la nouvelle couleur à modifier
*\param coordoné x de la case
*\param coordonnée y de la case
*\param largeur designe la taille de la matrice carré
*\return n'a pas de retour
*/

void changement_couleur(char **grille,char c,int x, int y,int largeur);
#endif
