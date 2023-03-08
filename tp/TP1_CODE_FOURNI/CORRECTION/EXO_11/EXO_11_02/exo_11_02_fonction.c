#include <stdio.h>
#include <stdlib.h>

/*
 * ATTENTION : programme faux
 */

void f()
{
    int *p;
    // oubli d'initialisation, donc warning à la compilation

    printf("Le pointeur non initialisé vaut %p\n", (void *) p);
    printf("Dans la zone pointée il y a %d\n", *p);
    printf("Passe-t-on par là ?\n");
}

int main()
{
    f();
    
    return EXIT_SUCCESS;
}
