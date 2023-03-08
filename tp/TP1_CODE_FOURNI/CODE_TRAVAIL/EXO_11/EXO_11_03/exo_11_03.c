#include <stdio.h>
#include <stdlib.h>

/*
 * ATTENTION : programme faux et sans aucun sens
 */

int main()
{
    int i = 5;
    printf("l'adresse de l'adresse de i vaut : %p\n", (void *) &(&i));
    
    return EXIT_SUCCESS;
}
