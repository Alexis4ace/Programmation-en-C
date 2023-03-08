/*
 * Exercice 2.03
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_2_03.c -o exo_2_03
 */
/*
 * ### les commentaires de correction sont précédés par ###
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
    /*
    res = malloc(10000*sizeof(char));    // on est tranquille (!!! vraiment ?)
    sprintf(res, format, r1, r2);
    res = realloc(res, (strlen(res) + 1) * sizeof(char));
    */

    // Mettez le code ci-dessus en commentaire
    // Et écrivez votre propre code pour que le malloc, avant le sprintf,
    // soit directement de la bonne taille.
    // ====== TODO ==========
    // ### snprintf retourne un nombre de caractères (sans compter le \0) :
    // ### - s'il y avait la place, alors c'est le nombre de caractères
    // ###   mis dans la chaîne
    // ### - si le résultat est tronqué, alors c'est le nombre de caractères
    // ###   qu'elle voudrait écrire dans la chaîne cible.
    // ###   Et c'est là qu'on récupère l'information voulue
    // ### Attention, si la chaîne est tronquée, alors le résultat ne
    // ### contient pas le '\0'
    // ### L'idée est d'appeler snprintf avec une taille maximale de 0 ;
    // ### ainsi rien n'est physiquement recopié, mais la fonction retourne
    // ### la longueur de la chaîne recherchée.
    // ### On pense à faire +1 pour compter le '\0', et on a la taille
    // ### pour le malloc
    // ### On note aussi le NULL pour la destination car on sait que
    // ### rien ne sera écrit
    int nbChar = snprintf(NULL, 0, format, r1, r2);
    res = malloc((nbChar+1) * sizeof(char));    // on est tranquille !
    sprintf(res, format, r1, r2);

    return res;
}

int main()
{
    title_print("sprintf et malloc");

    char *resultat = strFormat();
    printf("%s\n", resultat);

    // il y a sûrement quelque chose à faire ici ?
    // ====== TODO ==========
    free(resultat);

    printf("\n");

    return EXIT_SUCCESS;
}
