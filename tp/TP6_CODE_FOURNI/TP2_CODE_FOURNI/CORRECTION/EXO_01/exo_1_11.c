/*
 * Exercice 1.11
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_11.c -o exo_1_11
 */
/*
 * ### les commentaires de correction sont précédés par ###
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

int main()
{
    // ------------------------------------------------------------
    title_print("strstr : utilisation");

    // décommenter une seule ligne
    const char * s[2] = { "Il fait beau et chaud", "beau" };
    //const char * s[2] = { "Il fait beau et chaud", " " };
    //const char * s[2] = { "Il fait beau et chaud", "i" };
    //const char * s[2] = { "Il fait beau et chaud", "au" };
    //const char * s[2] = { "Il fait beau et chaud", "au " };
    //const char * s[2] = { "Il fait beau et chaud", "aud" };
    //const char * s[2] = { "Il fait beau et chaud", "froid" };
    //const char * s[2] = { "Il fait beau et chaud", "x" };

    // Indiquer si s[1] est une sous-chaîne de s[0]
    // ====== TODO ==========
    printf("\"%s\" sous-chaîne de \"%s\" ?\n", s[1], s[0]);
    if (strstr(s[0], s[1]) != NULL)
        printf("   oui\n");
    else
        printf("   non\n");

    // Plus compliqué : si s[1] est une sous-chaîne de s[0], indiquer
    // à quelle position se trouve cette sous-chaîne
    // ====== TODO ==========
    char *pt = strstr(s[0], s[1]);
    if (pt != NULL)
        printf("   à la position %ld\n", pt-s[0]);
    // ### la complexité (relative) vient qu'on fait de l'arithmétique
    // ### de pointeurs

    // à étudier le problème de l'encodage

    printf("\n");

    return EXIT_SUCCESS;
}
