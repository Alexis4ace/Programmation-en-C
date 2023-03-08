#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[], char * env[])
{
    int i;

    printf("Il y a %d paramètre(s)\n", argc-1);
    for (int i = 1; i < argc; i++)
        printf("   - %s\n", argv[i]);
    printf("\n");

    printf("Voici les variables d'environnement :\n");
    i = 0;
    while (env[i] != NULL)
    {
        printf("   - %s\n", env[i]);
        i++;
    }
    
    return EXIT_SUCCESS;
}
