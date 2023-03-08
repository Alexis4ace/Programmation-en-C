/*
 * Exercice 1.07
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_07.c -o exo_1_07
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

// juste pour initialiser un tableau avec des lettres identiques
// on parle bien de tableau de caractères et non de chaîne
// Le code est fourni gratuitement
void exo_1_07_init(char tab[], int l, char lettre)
{
    for (int i = 0; i < l; i++)
        tab[i] = lettre;
}


int main()
{
    // ------------------------------------------------------------
    title_print("strncpy : utilisation");

    const char * source = "bonjour";
    const int LONGUEUR = strlen(source);

    // au fait quelle est la différence entre
    //     strlen(source) et strlen("source") ?
    // ====== TODO ==========

    // définitions demandées par l'énoncé
    char cible1[LONGUEUR - 1];
    char cible2[LONGUEUR];
    char cible3[LONGUEUR + 1];
    char cible4[LONGUEUR + 2];

    // juste pour voir explicitement les erreurs dans le code demandé ci-dessous
    exo_1_07_init(cible1, LONGUEUR - 1, 'a');
    exo_1_07_init(cible2, LONGUEUR,     'b');
    exo_1_07_init(cible3, LONGUEUR + 1, 'c');
    exo_1_07_init(cible4, LONGUEUR + 2, 'd');

    // appeler strncpy sur source et cible1 avec LONGUEUR-1 en paramètre
    // et afficher cible1 avec sa longueur
    // vérifier si tout est correct et expliquer (réponse : c'est incorrect)
    // ====== TODO ==========

    // avec avec cible2 et LONGUEUR (réponse : c'est incorrect)
    // ====== TODO ==========
    
    // avec avec cible3 et LONGUEUR+1 (réponse : c'est correct)
    // ====== TODO ==========
    
    // avec avec cible4 et LONGUEUR+2 (réponse : c'est correct)
    // ====== TODO ==========

    printf("\n");

    return EXIT_SUCCESS;
}
