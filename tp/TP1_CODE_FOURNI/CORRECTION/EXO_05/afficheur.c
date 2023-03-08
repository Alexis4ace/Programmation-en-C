#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("affichage avec printf\n");
    fprintf(stdout, "affichage avec fprintf stdout\n");
    fprintf(stderr, "affichage avec fprintf stderr\n");

    printf("Entrez un entier : ");
    scanf("%d", &n);
    printf("L'entier est : %d\n", n);
    
    return EXIT_SUCCESS;
}
