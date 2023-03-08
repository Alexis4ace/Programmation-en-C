#include <stdio.h>
#include <stdlib.h>

int main()
{
    // première partie du code gracieusement offert
    int i;
    int *p = &i;

    i = 99;
    printf("i = %d  et adresse %p\n", *p,p);
    *p += 2;
    printf("i = %d\n", i);
    printf("i = %d et %p\n", *p,p);

    // todo : manipulation du contenu de i via un pointeur
    
    return EXIT_SUCCESS;
}
