#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

int main()
{
    char** grille;

    grille = faire_alocation_matrice(12, grille);
    affiche(12, grille);
}

