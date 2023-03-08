/*
 * Exercice 1.02
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_02.c -o exo_1_02
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
    const char *s1 = "chien";
    char s2[] = "chiot";

    // ------------------------------------------------------------
    title_print("Modification de s1");
    printf("s1 avant : %s\n", s1);
    s1 = "cheval";
    printf("s1 après : %s\n", s1);
    // Explication
    // ====== TODO ==========

    // ------------------------------------------------------------
    title_print("Modification de s1 ou *s1");
     s2[0]= 'r';
     s2[1]= 'a';
     s2[2]= 't';
     s2[3]= '\0';
     printf("s2 après : %s\n", s2);
    // Explication
    // ====== TODO ==========
    // code pour réaffecter la chaîne
    // ====== TODO ==========
  
    // ------------------------------------------------------------
    title_print("Modification de s1 ou *s1 (suite)");
    // s2 = "cheval";
    // Explication
    // la taille réservé n'est pas assez grande pour accueillir ce cheval peut etre essayer avec un poney
    // ====== TODO ==========
    // strcpy(s2, "cheval");
    // Expliquez pourquoi c'est incorrect
    // ====== TODO ==========

    printf("\n");

    return EXIT_SUCCESS;
}
