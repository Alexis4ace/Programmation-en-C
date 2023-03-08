/*
 * Exercice 2.03
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_2_03.c -o exo_2_03
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

char * strFormat()
{
    float r1 = 3.14159f;
    double r2 = 19.0 / 6.0;
    const char *format = "est-ce que %g est plus grand que %lf ?";
    char *res;

    // voici le code que l'on NE veut PAS
    // ----------------------------------
    res = malloc(10000*sizeof(char));    // on est tranquille (!!! vraiment ?)
    sprintf(res, format, r1, r2);
    res = realloc(res, (strlen(res) + 1) * sizeof(char));

    // Mettez le code ci-dessus en commentaire
    // Et écrivez votre propre code pour que le malloc, avant le sprintf,
    // soit directement de la bonne taille.
    // ====== TODO ==========

    return res;
}

int main()
{
    title_print("sprintf et malloc");

    char *resultat = strFormat();
    printf("%s\n", resultat);

    // il y a sûrement quelque chose à faire ici ?
    // ====== TODO ==========

    printf("\n");

    return EXIT_SUCCESS;
}
