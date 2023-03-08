/*
 * Exercice 2.02
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_2_02.c -o exo_2_02
 */
/*
 * ### les commentaires de correction sont précédés par ###
 */

#define _XOPEN_SOURCE 500  // pour strdup
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"


// Écrire ici la fonction strDynCat
// ====== TODO ==========
// ### Avec la réallocation, le valeur du pointeur peut changer,
// ### il faut donc passer un pointeur sur le pointeur
// ### Et donc la syntaxe est pénible
// ### Hormis cela, le code est classique
void strDynCat(char **dest, const char *src)
{
    int lenDest = strlen(*dest);
    int lenSrc = strlen(src);

    (*dest) = realloc(*dest, (lenDest + lenSrc + 1) * sizeof(char));
    strcat(*dest, src);
}


int main()
{
    title_print("strcat dynamique");

    // Chaine qui doit être allongée : obligatoirement allouée dynamiquement
    char *dest;
    dest = strdup("Tu vois, le monde se divise en deux catégories, ");
    const char *add1 = "ceux qui ont un pistolet chargé et ceux qui creusent.";
    const char *add2 = " Toi, tu creuses.";
    
    printf("avant : %s\n", dest);

    // En utilisant votre fonction, concaténez add1 et add2 à dest;
    // ====== TODO ==========
    strDynCat(&dest, add1);
    strDynCat(&dest, add2);

    // vérification
    printf("après : %s\n", dest);

    // il y a sûrement quelque chose à faire ici ?
    // ====== TODO ==========
    free(dest);

    printf("\n");

    return EXIT_SUCCESS;
}
