/*
 * Exercice 2.01
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_2_01.c -o exo_2_01
 */
/*
 * ### les commentaires de correction sont précédés par ###
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"


// Écrire ici la fonction strClone
// ====== TODO ==========
// ### rien de particulier, il faut penser au '\0'
char * strClone(const char *source)
{
    int l = strlen(source);
    char *res = malloc((l+1) * sizeof(char));
    for (int i = 0; i <= l; i++)
        res[i] = source[i];
    return res;
}

int main()
{
    title_print("clone");

    // ne décommenter qu'une seule définition
    const char *source = "Tu vois, le monde se divise en deux catégories, "
        "ceux qui ont un pistolet chargé et ceux qui creusent."
        " Toi, tu creuses.";
    //const char *source = "aa\nbb";
    //const char *source = "";
    //const char *source = "aa\0bb";    // exemple curieux
    
    printf("source : \"%s\"\n", source);

    // déclarer la chaîne qui va recevoir la copie, faire la copie
    // et l'afficher.
    // ====== TODO ==========
    char * res = strClone(source);
    printf("target : \"%s\"\n", res);

    // il y a sûrement quelque chose à faire ici ?
    // ====== TODO ==========
    // ### pas de fuite mémoire surtout
    free(res);

    printf("\n");

    return EXIT_SUCCESS;
}
