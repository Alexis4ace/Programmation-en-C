/*
 * Exercice 1.14
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_14.c -o exo_1_14
 */
/*
 * ### les commentaires de correction sont précédés par ###
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

// remplace tous les caractères d'une chaîne par des '.'
void pointe(char *s)
{
    for (size_t i = 0; i < strlen(s); i++)
        s[i] = '.';
}

// Bien que calculant le bon résultat, le code précédent pose
// un problème.
// Proposez une meilleure solution
// ====== début TODO ==========
// ### Le problème est l'efficacité : à chaque tour de boucle
// ### on rappelle strlen qui coûte un parcours de chaîne complet.
// ### Il suffit de stocker la longueur de la chaîne dans une variable
// ### intermédiaire et on passe d'une complexité quadratique (O(n^2))
// ### en une complexité linéaire (O(n))
void pointe2(char *s)
{
    size_t l = strlen(s);
    for (size_t i = 0; i < l; i++)
        s[i] = '-';
}


int main()
{
    // ------------------------------------------------------------
    title_print("strlen : coûts cachés");

    char s[] = "point virgule";
    printf("avant : \"%s\"\n", s);
    pointe(s);
    printf("après : \"%s\"\n", s);

    // ### test
    pointe2(s);
    printf("après : \"%s\"\n", s);

    printf("\n");

    return EXIT_SUCCESS;
}
