/*
 * Exercice 1.12
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_12.c -o exo_1_12
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
    title_print("sprintf : utilisation");

    const int MAX = 10000;   // toujours pour éviter la gestion mémoire (mais beurk)
    char s[MAX];

    int n = 3;
    // mettre dans s la phrase : "Il y a <n> pingouins" où <n> doit être
    // remplacé par la valeur de n
    // ====== TODO ==========
    sprintf(s, "Il y a %d pingouins", n);
    printf("vérif : %s\n", s);

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
    char tmp[1000];  // on ne gère toujours pas la taille des tableaux
    // ### ligne 1
    sprintf(s, "    n ");
    for (int i = 1; i <= n; i++)
    {
        sprintf(tmp, "%3d", i);
        strcat(s, tmp);
    }
    strcat(s, "\n");
    // ### la table
    for (int l = 1; l <= n; l++)
    {
        sprintf(tmp, "%5d ", l);
        strcat(s, tmp);
        for (int i = 1; i <= n; i++)
        {
            sprintf(tmp, "%3d", l*i);
            strcat(s, tmp);
        }
        strcat(s, "\n");
    }
    printf("vérif :\n%s\n", s);

    printf("\n");

    return EXIT_SUCCESS;
}
