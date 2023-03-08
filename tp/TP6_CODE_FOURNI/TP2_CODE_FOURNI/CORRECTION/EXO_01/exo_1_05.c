/*
 * Exercice 1.05
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_05.c -o exo_1_05
 */
/*
 * ### les commentaires de correction sont précédés par ###
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

// Écrire ici la fonction mystrlen
// ====== TODO ==========
long mystrlen(const char *s)
{
    long i = 0;
    while (s[i] != '\0')
        i ++;
    return i;
}

// ### une version peut-être plus efficace (à vérifier sur le code compilé cependant)
long mystrlen2(const char *s)
{
    const char *p = s;
    while (*p != '\0')
        p ++;
    return p-s;
}


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
    printf("  mystrlen : %ld\n", mystrlen(s));
    printf("  strlen   : %ld\n", strlen(s));

    printf("\n");

    return EXIT_SUCCESS;
}
