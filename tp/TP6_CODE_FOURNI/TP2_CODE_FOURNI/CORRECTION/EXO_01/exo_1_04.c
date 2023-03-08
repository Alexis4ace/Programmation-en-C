/*
 * Exercice 1.04
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_04.c -o exo_1_04
 */
/*
 * ### les commentaires de correction sont précédés par ###
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

// Écrire ici la fonction mirror
// ====== TODO ==========
void mirror(char *s)
{
    int l = strlen(s);
    for (int i = 0; i < l/2; i++)
    {
        char c = s[i];
        s[i] = s[l-i-1];
        s[l-i-1] = c;
    }
}

// ### pour le fun, une version avec arithmétique de pointeur (à vérifier si c'est plus efficace)
void mirror2(char *s)
{
    char *d = s;
    char *f = s + strlen(s) - 1;
    while (d < f)
    {
        char c = *d;
        *d = *f;
        *f = c;
        d ++;
        f --;
    }
}

// ### et si vous aimez la programmation illisible (que je ne veux pas voir dans vos devoirs)
void mirror3(char *s)
{
    char *f = s + strlen(s) - 1;
    while (s < f)
    {
        *s = *s ^ *f;
        *f = *s ^ *f;
        *s = *s ^ *f;
        s ++;
        f --;
    }
}


int main()
{
    title_print("mirror");

    char s[] = "il fait beau !";  // "char *" est incorrect ! Pourquoi ?
                                  // Parce qu'on va modifier la chaine

    printf("Voici la chaîne avant retournement : \"%s\" (%ld)\n", s, strlen(s));
    // appeler ici la fonction mirror
    // ====== TODO ==========
    mirror(s);
    printf("Voici la chaîne après retournement : \"%s\" (%ld)\n", s, strlen(s));
    
    printf("\n");

    return EXIT_SUCCESS;
}
