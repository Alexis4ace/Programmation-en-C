#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int tab[5] = {1, 2, 3, 4, 5};
    int * autreTab = malloc(5 * sizeof(int));
    autreTab = tab;
    // ...
    //free(autreTab);    // BOUM !
    return EXIT_SUCCESS;
}

/*
 * Essayez la commande :
 * $ valgrind --leak-check=full ./exo_11_06
 *
 * todo : expliquer les erreurs
 * toto : écrivez un code correct pour faire une recopie de tableau
 */
