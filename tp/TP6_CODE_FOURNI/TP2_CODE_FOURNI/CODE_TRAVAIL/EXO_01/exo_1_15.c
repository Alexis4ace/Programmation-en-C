/*
 * Exercice 1.15
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_15.c -o exo_1_15
 */

#define _XOPEN_SOURCE 500  // pour strdup
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

int main()
{
    // ------------------------------------------------------------
    title_print("==");
    
    // ------------------------------------------------------------
    // illustration 1
    char t1a[] = "chaton";
    const char *t1b = "chaton";
    if (t1a == t1b)
        printf("vrai");
    else
        printf("faux");
    printf(" : un [] et un char *\n");
    // Expliquez
    // ====== TODO ==========

    // ------------------------------------------------------------
    // illustration 2
    char t2a[] = "chaton";
    char t2b[] = "chaton";
    if (t2a == t2b)
        printf("vrai");
    else
        printf("faux");
    printf(" : deux []\n");
    // Expliquez
    // ====== TODO ==========

    // ------------------------------------------------------------
    // illustration 3
    const char *t3a = "chaton";
    const char *t3b = "chaton";
    if (t3a == t3b)
        printf("vrai");
    else
        printf("faux");
    printf(" : deux char *\n");
    // Expliquez
    // ====== TODO ==========

    // ------------------------------------------------------------
    // illustration 4
    const char *t4a = "chaton";
    const char *t4b = t4a;
    if (t4a == t4b)
        printf("vrai");
    else
        printf("faux");
    printf(" : deux char *\n");
    // Expliquez
    // ====== TODO ==========

    // ------------------------------------------------------------
    // illustration 5
    char t5a[] = "chaton";
    char *t5b = t5a;
    if (t5a == t5b)
        printf("vrai");
    else
        printf("faux");
    printf(" : un [] et un char *\n");
    // Expliquez
    // ====== TODO ==========

    // ------------------------------------------------------------
    // illustration 6
    char *t6a = strdup("chaton");
    char *t6b = strdup("chaton");
    if (t6a == t6b)
        printf("vrai");
    else
        printf("faux");
    printf(" : deux char * avec malloc/strdup\n");
    free(t6a);
    free(t6b);
    // Expliquez
    // ====== TODO ==========

    printf("\n");

    return EXIT_SUCCESS;
}
