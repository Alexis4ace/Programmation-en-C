/*
 * Exercice 1.13
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_13.c -o exo_1_13
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

int main()
{
    // ------------------------------------------------------------
    title_print("du bon usage de strlen");

    const int MAX = 10;   // toujours pour éviter la gestion mémoire (mais beurk)
    char s[MAX];
    strcpy(s, "AAA");

    // Corriger le code
    // ====== début TODO ==========
    for (unsigned int i = 0; i < strlen(s); i++)
        strcat(s, "a");
    // ====== fin TODO ==========
    printf("vérif : %s\n", s);
    
    printf("\n");

    return EXIT_SUCCESS;
}
