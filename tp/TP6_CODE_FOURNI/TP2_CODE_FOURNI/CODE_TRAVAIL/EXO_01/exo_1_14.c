/*
 * Exercice 1.14
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_14.c -o exo_1_14
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

// remplace tous les caractères d'une chaîne par des '.'
void pointe(char *s)
{
    for (size_t i = 0; i < strlen(s); i++)
        s[i] = '.';
}

// Bien que calculant le bon résultat, le code précédent pose
// un problème.
// Proposez une meilleure solution
// ====== début TODO ==========


int main()
{
    // ------------------------------------------------------------
    title_print("strlen : coûts cachés");

    char s[] = "point virgule";
    printf("avant : \"%s\"\n", s);
    pointe(s);
    printf("après : \"%s\"\n", s);

    // test
    pointe(s);
    printf("après : \"%s\"\n", s);

    printf("\n");

    return EXIT_SUCCESS;
}
