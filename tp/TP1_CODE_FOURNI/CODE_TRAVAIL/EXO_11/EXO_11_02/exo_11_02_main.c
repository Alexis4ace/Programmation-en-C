#include <stdio.h>
#include <stdlib.h>

/*
 * ATTENTION : programme faux
 */

int main()
{
    int *p,nb;
    // oubli d'initialisation, donc warning à la compilation
    p = &nb;
    printf("Le pointeur non initialisé vaut %p\n", (void *) p);
    printf("Dans la zone pointée il y a %d\n", *p);
    printf("Passe-t-on par ici ?\n");
    
    return EXIT_SUCCESS;
}