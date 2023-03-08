#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// le break n'est pas top (encore que), mais introduire un booléen
// serait vraiment lourd et selon moi moins lisible
void version1()
{
    while (true)
    {
        int c = fgetc(stdin);
        if (c == EOF)
            break;
        fputc(c, stdout);
    }
}

// en règle générale je n'aime pas faire des affectations dans
// un test
// Mais dans ce cas c'est tellement classique (limite idiomatique
// au langage) qu'il m'arrive de faire une exception
void version2()
{
    int c;
    
    while ((c = fgetc(stdin)) != EOF)
        fputc(c, stdout);
}

int main()
{
    //version1();
    version2();

    return EXIT_SUCCESS;
}
