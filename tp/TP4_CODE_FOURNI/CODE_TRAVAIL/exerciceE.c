#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
// inclure les .h nécessaires

void ecritTabIntBin(const char *nomFichier, const int tab[], int n)
{
}

int litIntPosBin(const char *nomFichier, int pos)
{
    return -1;
}

bool remplaceIntPosBin(const char *nomFichier, int pos, int newVal)
{
    return false;
}

int main()
{
    int tab[] = {10, 5, 87, 0, 5, 212, 12, 14, 55};
    int n = sizeof(tab)/sizeof(*tab);                 // attention : l'utilisation de sizeof pour avoir la taille d'un tableau est fortement déconseillée

    // écrire le tableau dans le fichier FIC/exoE_test
    // todo

    // remplacer la case 2 (donc le 87) par 777
    // todo
    // remplacer la case 9 (indice trop grand) par 66 : il ne se passe rien
    // todo
    // remplacer la cse 0 (donc le 10) par 1111
    // todo

    // afficher le contenu du fichier en utilisant la fonction litIntPosBin
    // todo
    
    return EXIT_SUCCESS;
}


/*
  SPOILER main

    // écrire le tableau dans le fichier exoE_test
    ecritTabIntBin("exoE_test", tab, n);

    // remplacer la case 2 (donc le 87) par 777
    remplaceIntPosBin("exoE_test", 2, 777);
    // remplacer la case 9 (indice trop grand) par 66 : il ne se passe rien
    remplaceIntPosBin("exoE_test", 9, 66);
    // remplacer la cse 0 (donc le 10) par 1111
    remplaceIntPosBin("exoE_test", 0, 1111);

    // afficher le contenu du fichier en utilisant la fonction litIntPosBin
    printf("  [");
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            printf(", ");
        printf("%d", litIntPosBin("exoE_test", i));
    }
    printf("]\n");
*/
