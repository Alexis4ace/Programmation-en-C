/*
 * Exercice 1.06
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_06.c -o exo_1_06
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

// Écrire ici la fonction mystrcpy
// ====== TODO ==========


int main()
{
    title_print("mystrcpy");

    const int MAX = 1000;   // pour ne pas gérer la mémoire (ce n'est pas le but ici)
    char source[] = "il fait chaud !";
    char cible1[MAX];
    char cible2[MAX];

    printf("Chaîne source : %s (taille %ld)\n", source, strlen(source));

    // Remarque : lorsqu'on copie une chaîne dans un autre tableau,
    // il faut donc s'assurer que le tableau cible contient suffisament de cases.
    // D'ailleurs combien en faut-il au minimum ?
    // ====== TODO ==========

    // Que se passe-t-il s'il y en moins ?
    // ====== TODO ==========

    // Et s'il y en a plus ?
    // ====== TODO ==========

    // En l'occurrence, les tableaux ciblés sont a priori sur-dimensionnés,
    // ce qui n'est pas une solution valide ; nous verrons des
    // solutions correctes avec l'allocation dynamique. Mais le but ici
    // est de se concentrer exclusivement sur la recopie de chaînes

    // recopiez la source dans cible1 avec strcpy
    // ====== TODO ==========

    // recopiez la source dans cible2 avec mystrcpy
    // ====== TODO ==========

    // afficher les deux résultats avec leurs longueurs
    // ====== TODO ==========

    printf("\n");

    return EXIT_SUCCESS;
}
