#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
// inclure les .h nécessaires


void ecritTabIntAsc(const char *nomFichier, const int tab[], int n)
{
    // todo
    // rq : pas moyen de faire l'écriture d'un coup, il faut les écrire un par un
}

int litIntPosAsc(const char *nomFichier, int pos)
{
    // todo
    // rq : il faut les lire un par un jusqu'à la bonne position
    return -1;
}

bool remplaceIntPosAsc(const char *nomFichier, int pos, int newVal)
{
    // todo
    // rq : impossible de faire un remplacement simple car le nouveau nombre peut
    //      ne pas faire le même nombre de caractères que le précédent ce qui
    //      impose un décalage dans le fichier
    // rq : une solution simple (et coûteuse en mémoire) consiste à recopier
    //      tout le fichier dans un tableau, remplacer la bonne case, et réécrire
    //      complètement le fichier
    return false;
}

int main()
{
    int tab[] = {10, 5, 87, 0, 5, 212, 12, 14, 55};
    int n = sizeof(tab)/sizeof(*tab);

    // écrire le tableau dans le fichier FIC/exoF_test
    // todo

    // remplacer la case 2 (donc le 87) par 777
    // todo
    // remplacer la case 9 (indice trop grand) par 66 : il ne se passe rien
    // todo
    // remplacer la cse 0 (donc le 10) par 1111
    // todo

    // afficher le contenu du fichier en utilisant la fonction litIntPosAsc
    // todo
    
    return EXIT_SUCCESS;
}


/*
  SPOILER main

    // écrire le tableau dans le fichier exoF_test
    ecritTabIntAsc("exoF_test", tab, n);

    // remplacer la case 2 (donc le 87) par 9
    remplaceIntPosAsc("exoF_test", 2, 9);
    // remplacer la case 9 (indice trop grand) par 66 : il ne se passe rien
    remplaceIntPosAsc("exoF_test", 9, 66);
    // remplacer la cse 0 (donc le 10) par 1111
    remplaceIntPosAsc("exoF_test", 0, 1111);

    // afficher le contenu du fichier en utilisant la fonction litIntPosAsc
    printf("  [");
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            printf(", ");
        printf("%d", litIntPosAsc("exoF_test", i));
    }
    printf("]\n");
*/
