#include <stdio.h>
#include <stdlib.h>

//## on retrouve ce qui a été dit dans le chapitre "extern" en note
//## de bas de page (de bas de cours plutôt)

int globale;                  //## initialisée à 0
static int static_fichier;    //## initialisée à 0

void f()
{
    static int static_fonction;    //## initialisée à 0
    int locale_fonction;           //## non initialisée => warning

    printf("static_fonction : %d\n", static_fonction);
    printf("locale_fonction : %d\n", locale_fonction);
}

int main()
{
    int locale_main;  //## non initialisée (mais dans les faits à 0) => warning
    
    printf("globale         : %d\n", globale);
    printf("static_fichier  : %d\n", static_fichier);
    printf("locale_main     : %d\n", locale_main);
    f();
    
    return EXIT_SUCCESS;
}
