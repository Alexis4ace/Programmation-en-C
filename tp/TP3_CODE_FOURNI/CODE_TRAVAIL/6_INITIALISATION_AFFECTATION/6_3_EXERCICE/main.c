#include <stdio.h>
#include <stdlib.h>

// définir ici une constante non static (sans l'initialiser)
const int aa;
// définir ici une constante static (sans l'initialiser)
const static int bb; //warning
void f()
{
    // définir ici une constante static (sans l'initialiser)
    const static int fa; //warning
    // définir ici une constante non static (sans l'initialiser)
    const int fb; //warning
    // essayez de changer ces deux constantes
    //fa = 1;  //interdit
    //fb = 2;   //interdit
    // afficher les deux constantes
    printf("%d ",fa);
    printf("%d \n",fb);
}

int main()
{
    // définir ici une constante non static (sans l'initialiser)
    const int mb; //warning
    //const static int ba;
    // afficher les 3 constantes visibles du main
    // essayez de changer ces trois constantes
    printf("%d ",aa);
    printf("%d \n",bb);
    
    printf("%d ",mb);
    //printf("%d \n",ba);
    f();
    
    return EXIT_SUCCESS;
}
