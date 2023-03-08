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
 * Ce n'est pas une recopie : autreTab n'est qu'un pointeur
 * qui vient pointer au même endroit que tab.
 * On n'a qu'un seul tableau, et deux manières d'y accéder.
 *
 * Et au passage on a une jolie fuite mémoire.
 * Un free(autreTab) revient à faire free(tab) qui n'a pas été allouée
 * dynamiquement
 * Essayez la commande :
 * $ valgrind --leak-check=full ./exo_11_06
 *
 * Conclusion :
 *   - un tel code signifie très vraisemblablement que le programmeur
 *     pense faire une recopie de tableau.
 *   - ce n'est pas le cas, et donc il y a une fuite mémoire
 */

/*
 * Voici un code correct
 */
int main2()
{
    int tab[5] = {1, 2, 3, 4, 5};
    int * autreTab = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
        autreTab[i] = tab[i];
    // ...
    free(autreTab);
    return EXIT_SUCCESS;
}

/*
 * Voici un autre code correct, plus subtil et peut-être moins lisible
 */
int main3()
{
    int tab[5] = {1, 2, 3, 4, 5};
    int * autreTab = malloc(5 * sizeof(int));
    memcpy(autreTab, tab, 5*sizeof(int));
    // ...
    free(autreTab);
    return EXIT_SUCCESS;
}
