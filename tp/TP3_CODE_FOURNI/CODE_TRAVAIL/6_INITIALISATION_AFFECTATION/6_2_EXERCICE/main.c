#include <stdio.h>
#include <stdlib.h>

// définir ici une variable non static
int aa; //non concerné
// définir ici une variable static
static int bb; // non concerné

void f()
{
    // définir ici une variable static
    static int IA; //non concerné
    // définir ici une variable non static
    int IB;//concerné
    // afficher les deux variables
    printf("%d \n",IA);
    printf("%d \n",IB);
}

int main()
{
    // définir ici une variable non static
    int MA;//concerné
    static int mB; // non concerné
    // afficher les 3 variables visibles du main
    f();
    printf(" %d ", aa);
    printf(" %d ", bb);
    printf(" %d ", MA);
    printf(" %d ",mB);
    
    return EXIT_SUCCESS;
}
