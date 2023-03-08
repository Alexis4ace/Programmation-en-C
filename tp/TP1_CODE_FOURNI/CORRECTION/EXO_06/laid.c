#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[], char * env[])
{
    char **p;

    printf("Il y a %d paramètre(s)\n", argc-1);
    for (int i = 1; i < argc; i++)
        printf("   - %s\n", argv[i]);
    printf("\n");

    printf("Voici les variables d'environnement :\n");
    p = env;
    while (*p != NULL)
    {
        printf("   - %s\n", *p);
        p++;
    }
    
    return EXIT_SUCCESS;
}
