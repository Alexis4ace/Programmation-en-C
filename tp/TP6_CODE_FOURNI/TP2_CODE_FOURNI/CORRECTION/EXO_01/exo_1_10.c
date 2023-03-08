/*
 * Exercice 1.10
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_10.c -o exo_1_10
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
    title_print("strcat : utilisation");

    // on surdimensionne la cible pour éviter la gestion mémoire
    char target[1000] = "il fait beau";
    const char * source = " et chaud";

    // afficher target et source et leurs longueurs
    // ====== TODO ==========
    printf("avant :\n");
    printf("   target : %s (%ld)\n", target, strlen(target));
    printf("   source : %s (%ld)\n", source, strlen(source));
    
    // contaténer source à la fin de target
    // ====== TODO ==========
    strcat(target, source);
    
    // afficher target et sa longueur
    // ====== TODO ==========
    printf("après :\n");
    printf("   target : %s (%ld)\n", target, strlen(target));

    printf("\n");

    return EXIT_SUCCESS;
}
