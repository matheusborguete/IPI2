
#ifndef GRILLE_H_INCLUDED
#define GRILLE_H_INCLUDED

/**
 * \brief structure pile
 */
typedef struct pile
{
	char couleur[1000];
	int sommet;
} pile;



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

int remplacer_matrice(char **grille,char c,int x, int y, int largeur);


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

int ** connexite_matrice(int largeur, int x, int y, int  * nb);


/**
*\brief realise le remplissage de la matrice à partir d'un fichier
*\details cette fontion realise le remplissage de la matrice
à partir d'un fichier existant qu'on rempli avec des valeurs definies
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param largeur designe la taille de la matrice carré
*\return n'a pas de retour
*/

char** lecture(char ** grille, int largeur, char* fichier);


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

char** changement_couleur(char **grille,char c,int x, int y,int largeur);


/**
*\brief verifie si le joueur a gagne
*\details verifie la victoire en faisant une comparation pour verifier si toutes les cases ont le meme couleur
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param largeur designe la taille de la matrice carré
*\return 1 (true) si le joueur a gagne ou 0 (false) si il n'ai pas gagne
*/

int verifie_victoire(char** grille, int largeur);

/**
*\changement de couleur des cases
*\param x : entier qui designe la position x
*\param y : entier qui designe la position y
*\param c : char qui est la couleur
*\param grille c'est une matrice de caractères et chaque caractère designe une couleur
*\param largeur designe la taille de la matrice carré
*\param oldcolor : char qui est la couleur avant du changement
*\return 1 (true) si le joueur a gagne ou 0 (false) si il n'ai pas gagne
*/
void floodFill(int x, int y, char c, char** grille, int largeur, char oldcolor);



/**
*\brief initialise la pile
*\param pile qui sera initialise
*\return la pile initialise
*/
pile initialise_pile(pile solution);


/**
*\brief fait une inserction dans la pile
*\param pile qui sera initialise
*\param newcolor qui sera ajoute dans la pile
*\return la pile
*/
pile push(pile solution, char newcolor);


/**
*\brief retirer le element au sommet de la pile
*\param pile qui sera initialise
*\return la pile 
*/
pile pop(pile solution);


/**
*\brief verifie si la solution trouve c'est mieux qui la qu'on a trouv´e avant
*\param solution avec la nouvelesolution
*\param bestsolution avec la mieux solution
*\return rien 
*/
pile uneSolutionTrouvee(pile solution, pile bestsolution);

/**
*\brief trouve la mieux solution pour la resolution de la grille
\*param grille la grille du jeu
\*param largeur de la grille
*\param solution avec la nouvelesolution
*\param bestsolution avec la mieux solution
*\return rien 
*/
pile solveur(char** grille, int largeur, pile solution, pile bestsolution, int profundeur);


/**
*\brief copie une matrice `a autre
\*param grille la premiere matrice
\*param g2 la deuxieme matrice
\*param largeur de la grille
*\return rien 
*/
void copier_matrice(char** grille, char**g2, int largeur);


#endif
