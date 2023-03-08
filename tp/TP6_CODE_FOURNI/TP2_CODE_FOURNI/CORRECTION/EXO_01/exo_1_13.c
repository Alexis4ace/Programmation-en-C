/*
 * Exercice 1.13
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_13.c -o exo_1_13
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
    title_print("du bon usage de strlen");

    const int MAX = 10;   // toujours pour éviter la gestion mémoire (mais beurk)
    char s[MAX];
    strcpy(s, "AAA");

    // Corriger le code
    // ====== début TODO ==========
    // ### for (unsigned int i = 0; i < strlen(s); i++)
    // ###     strcat(s, "a");
    // ### le code est faux car à chaque tour de boucle strlen
    // ### est appelé, mais la chaîne s'est aussi agrandie.
    // ### on a un joli buffer overflow et potentiellement une
    // ### boucle infinie.
    // ### Note : chez moi la boucle tourne 20 fois avant de s'arrêter
    // ###        si c'est la même chose chez vous, cherchez pourquoi,
    // ###        c'est intéressant
    // ### il suffit d'appeler strlen avant et de stocker la
    // ### longueur dans une variable
    unsigned int lg = strlen(s);
    for (unsigned int i = 0; i < lg; i++)
        strcat(s, "a");
    // ### en outre ce n'est pas efficace car strcat reparcourt systématiquement
    // ### toute la chaîne s
    // ====== fin TODO ==========
    printf("vérif : %s\n", s);
    
    printf("\n");

    return EXIT_SUCCESS;
}
