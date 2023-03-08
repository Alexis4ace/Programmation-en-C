#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    i = 99;
    printf("i = %d\n", i);
    i += 2;
    printf("i = %d\n", i);

    int *pi;
    pi = &i;
    printf("pi = %p, *pi = %d\n", (void *)pi, *pi);
    *pi += 2;
    printf("pi = %p, *pi = %d\n", (void *)pi, *pi);
    printf("i = %d\n", i);
    
    return EXIT_SUCCESS;
}
