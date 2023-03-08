#include <stdio.h>
#include <stdlib.h>

//## On a exactement le même comportement que pour les variables non-const.
//## Ce qui est cohérent
//## Mais impossible de changer la valeur après coup et heureusement ; et
//## c'est une erreur de compilation.

const int globale;                    //## initialisée à 0
static const int static_fichier;      //## initialisée à 0

void f()
{
    static const int static_fonction;  //## initialisée à 0
    const int locale_fonction;         //## non initialisée => warning

    //static_fonction = 1;        // boum
    //locale_fonction = 1;        // boum

    printf("static_fonction : %d\n", static_fonction);
    printf("locale_fonction : %d\n", locale_fonction);
}

int main()
{
    const int locale_main;   //## non initialisée (mais dans les faits à 0)
                             //## => warning
    
    printf("globale         : %d\n", globale);
    printf("static_fichier  : %d\n", static_fichier);
    printf("locale_main     : %d\n", locale_main);

    //globale = 1;            // boum
    //static_fichier = 1;     // boum
    //locale_main = 1;        // boum
    
    f();
    
    return EXIT_SUCCESS;
}
