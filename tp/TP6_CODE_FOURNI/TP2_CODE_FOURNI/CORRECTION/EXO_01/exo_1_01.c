/*
 * Exercice 1.01
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_01.c -o exo_1_01
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
    // les déclarations de l'énoncé
    char c = 'A';
    char *s1 = "chien";
    char s2[] = "chiot";
    char t[] = {'c', 'h', 'o', 'u', 'x'};

    // ------------------------------------------------------------
    // Affichage des 4 variables
    title_print("Affichage des 4 variables");
    // ====== TODO ==========
    printf("c  : %c\n", c);
    printf("s1 : %s\n", s1);
    printf("s2 : %s\n", s2);
    printf("t  : ");
    for (int i = 0; i < 5; i++)   // on peut obtenir 5 par sizeof(t)/sizeof(*t)
        printf("%c ", t[i]);
    printf("\n");
    // ### printf("%s") n'est pas possible sur t car il n'y a pas de '\0'
    // ### en fin de tableau
    // ### Le résultat peut être curieux

    // ------------------------------------------------------------
    // Utilisation de strlen
    title_print("strlen or not strlen, this is the question");
    // ====== TODO ==========
    // ### pas de sens sur c : c'est un caractère et non une chaîne
    printf("s1 : %ld\n", strlen(s1));
    printf("s2 : %ld\n", strlen(s2));
    // ### pas de sens sur t : pas de '\0' en fin (t n'est pas une chaîne)
    // ### encore une fois le résultat peut être curieux

    // ------------------------------------------------------------
    // Quelle est la différence en s1 et s2 ?
    title_print("différence entre s1 et s2");
    // explications
    // ====== TODO ==========
    // ### s1 pointe sur chaîne qui est dans une zone mémoire read-only
    // ### s2 est tableau local (i.e. dans la pile du processus) avec
    // ###    une copie de la chaîne initiale ; le tableau pourra être modifié

    // Modifier la 4me lettre de s1
    // ====== TODO ==========
    // ### s1[3] = 'E';    // boum
    // ### on tente de modifier une zone read-only

    // Modifier la 4me lettre de s2
    // ====== TODO ==========
    s2[3] = 'O';
    printf("s2 : %s (%ld)\n", s2, strlen(s2));
    // ### là pas de problème, on travaille sur un tableau dans la
    // ### pile d'appels : on peut le modifier et heureusement

    // ------------------------------------------------------------
    // Combien de cases
    // ====== TODO ==========
    // ### c  : pas de sens, ce n'est pas un tableau
    // ### s1 : 6 cases : il y a le '\0' en plus
    // ### s2 : 6 cases : il y a le '\0' en plus
    // ### st : 5 cases : pas de '\0'
    // ### Dans une chaîne, au mieux le tableau a une case de plus que
    // ### la longueur de la chaîne ; mais le nombre de cases peut être
    // ### bien plus important (cf. ci-dessous)

    // ------------------------------------------------------------
    // Remplacer la 3me lettre (le i) de s2 '\0'
    title_print("longueur vs. nombre de cases");
    // ====== TODO ==========
    s2[2] = '\0';
    printf("s2 : %s (%ld)\n", s2, strlen(s2));
    // ### comme strlen s'arrête sur le '\0', on a une longueur de 2
    // ### en revanche le tableau fait toujours 6 cases

    // ------------------------------------------------------------
    // peut-on appeler strlen sur une chaîne littérale ?
    title_print("strlen sur une chaîne littérale");
    // ====== TODO ==========
    int l = strlen("colibri");
    printf("cte : %d\n", l);
    // ### pas de soucis, c'est une chaîne normale si ce n'est qu'elle est
    // ### constante. Et comme strlen ne modifie pas la chaîne, tout est ok.

    printf("\n");

    return EXIT_SUCCESS;
}
