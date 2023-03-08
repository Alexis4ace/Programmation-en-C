/*
 * Exercice 1.12
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_12.c -o exo_1_12
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

int main()
{
    // ------------------------------------------------------------
    title_print("sprintf : utilisation");

    const int MAX = 10000;   // toujours pour éviter la gestion mémoire (mais beurk)
    char s[MAX];

    int n = 3;
    // mettre dans s la phrase : "Il y a <n> pingouins" où <n> doit être
    // remplacé par la valeur de n
    // ====== TODO ==========

    // mettre dans s la table de multiplication jusqu'à n
    // par exemple si n contient 4, s contiendra (retour chariot compris) :
    //       n   1  2  3  4
    //       1   1  2  3  4
    //       2   2  4  6  8
    //       3   3  6  9 12
    //       4   4  8 12 16
    // utiliser conjointement sprintf et strcat peut être une solution
    n = 4;
    // ====== TODO ==========

    printf("\n");

    return EXIT_SUCCESS;
}
