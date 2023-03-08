/*
 * Exercice 1.07
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_07.c -o exo_1_07
 */
/*
 * ### les commentaires de correction sont précédés par ###
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
    // ### strlen(source) : longueur de la chaine contenue dans
    // ###       la variable source, à savoir 7
    // ### strlen("source") : longueur du mot "source" à savoir 6

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
    strncpy(cible1, source, LONGUEUR - 1);
    //printf("cible1 : %s (taille %ld)\n", cible1, strlen(cible1)); // BOUM !
    // ### on ne recopie que les 6 premiers caractères dans cible1 : bonjou
    // ### mais pas le '\0', donc c'est une faute de faire printf("%s")
    // ### et strlen
    // ### chez moi ça donne le bon résultat mais c'est de la chance, ceci
    // ### dit (toujours chez moi) valgrind profère un message d'insulte

    // avec avec cible2 et LONGUEUR (réponse : c'est incorrect)
    // ====== TODO ==========
    strncpy(cible2, source, LONGUEUR);
    //printf("cible2 : %s (taille %ld)\n", cible2, strlen(cible2)); // BOUM !
    // ### exactement le même problème avec les mêmes conséquences si
    // ### ce n'est qu'on manipule 7 caractères : bonjour, mais toujours
    // ### pas le '\0'
    
    // avec avec cible3 et LONGUEUR+1 (réponse : c'est correct)
    // ====== TODO ==========
    strncpy(cible3, source, LONGUEUR+1);
    printf("cible3 : %s (taille %ld)\n", cible3, strlen(cible3));
    // ### là c'est ok, mais tout juste. Le strcpy s'arrête à la fois
    // ### parce qu'il rencontre un '\0' et qu'il atteint la limite fixée
    
    // avec avec cible4 et LONGUEUR+2 (réponse : c'est correct)
    // ====== TODO ==========
    strncpy(cible4, source, LONGUEUR+2);
    printf("cible4 : %s (taille %ld)\n", cible4, strlen(cible4));
    // ### là on est large, strcpy s'arrête sur le '\0', et donc la 9me
    // ### case de cible4 n'est pas modifée (et reste avec la valeur 'd')

    printf("\n");

    return EXIT_SUCCESS;
}
