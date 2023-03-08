/*
 * Exercice 1.05
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_05.c -o exo_1_05
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

// Écrire ici la fonction mystrlen
// ====== TODO ==========

int main()
{
    title_print("mystrlen");

    // décommenter une seule ligne
    const char *s = "il fait beau !";
    //const char *s = "aa";
    //const char *s = "aa\n";

    printf("Voici la chaîne : \"%s\"\n", s);

    // appeler ici mystrlen et strlen, et afficher le résultat
    // ====== TODO ==========

    printf("\n");

    return EXIT_SUCCESS;
}
