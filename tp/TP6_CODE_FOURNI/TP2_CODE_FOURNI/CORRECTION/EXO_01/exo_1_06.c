/*
 * Exercice 1.06
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_06.c -o exo_1_06
 */
/*
 * ### les commentaires de correction sont précédés par ###
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

// Écrire ici la fonction mystrcpy
// ====== TODO ==========
// ### c'est la version la plus claire
char * mystrcpy(char *target, const char *source)
{
    int i = 0;
    while (source[i] != '\0')
    {
        target[i] = source[i];
        i ++;
    }
    target[i] = '\0';

    return target;
}

// ### et une version moins lisible
char * mystrcpy2(char *target, const char *source)
{
    int i = 0;
    while ((target[i] = source[i]) != '\0')
        i ++;
    return target;
}

// ### et encore moins lisible
char * mystrcpy3(char *target, const char *source)
{
    char *t = target;
    const char *s = source;
    while ((*t = *s) != '\0')
        t ++, s++;
    return target;
}

// ### et encore moins lisible, et conceptuellement incorrecte car :
// ### - on confond caractère et booléen
// ### - on fait un effet de bord dans une comparaison
// ### - bref n'est là que pour le fun ou plutôt pour se la
// ###   péter et croire qu'on est bon : à éviter voire à proscrire
char * mystrcpy4(char *target, const char *source)
{
    char *t = target;
    const char *s = source;
    while ((*(t++) = *(s++)))
        /* nothing */;
    return target;
}



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
    // ### pour la taille minimale, il ne faut pas oublier de compter le '\0'

    // Que se passe-t-il s'il y en moins ?
    // ====== TODO ==========
    // ### s'il y a moins de cases, on écrit au-delà du tableau : buffer
    // ### overflow

    // Et s'il y en a plus ?
    // ====== TODO ==========
    // ### s'il y en a plus, on gaspille de la place, mais le programme est
    // ### correct

    // En l'occurrence, les tableaux ciblés sont a priori sur-dimensionnés,
    // ce qui n'est pas une solution valide ; nous verrons des
    // solutions correctes avec l'allocation dynamique. Mais le but ici
    // est de se concentrer exclusivement sur la recopie de chaînes

    // recopiez la source dans cible1 avec strcpy
    // ====== TODO ==========
    strcpy(cible1, source);

    // recopiez la source dans cible2 avec mystrcpy
    // ====== TODO ==========
    mystrcpy(cible2, source);

    // afficher les deux résultats avec leurs longueurs
    // ====== TODO ==========
    printf("cible1 : %s (taille %ld)\n", cible1, strlen(cible1));
    printf("cible2 : %s (taille %ld)\n", cible2, strlen(cible2));

    printf("\n");

    return EXIT_SUCCESS;
}
