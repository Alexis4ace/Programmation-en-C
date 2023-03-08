#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
// inclure les .h nécessaires

struct S
{
    int i;
    char c;
    float f;
    int tab[10];
};

void ecritStructBin(const char *nomFichier, const struct S *s)
{
    FILE * fd = fopen(nomFichier, "w");
    fwrite(s, sizeof(struct S), 1, fd);
    fclose(fd);
}

void litStructBin(const char *nomFichier, struct S *s)
{
    FILE * fd = fopen(nomFichier, "r");
    fread(s, sizeof(struct S), 1, fd);
    fclose(fd);
}

void tailleStruct()
{
    printf("Taille totale     : %ld\n", sizeof(struct S));
    printf("Somme des tailles : %ld\n", sizeof(int) + sizeof(char) + sizeof(float) + 10 * sizeof(int));
}


int main()
{
    struct S original = {42, 'a', 3.14159, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}};
    struct S copie;

    // écrire la structure "original" dans le fichier FIC/exoG_test
    ecritStructBin("FIC/exoG_test", &original);

    // lire le fichier et remplir la structure "copie"
    litStructBin("FIC/exoG_test", &copie);

    // comparer les deux structures
    if (memcmp(&original, &copie, sizeof(struct S)) == 0)
        printf("Ok les structures sont identiques\n");
    else
        printf("PB ! Les structures sont différentes\n");

    // appeler la fonction tailleStruct
    tailleStruct();

    return EXIT_SUCCESS;
}

/*
  La taille de la structure est plus grande que la somme des tailles
  des champs.
  Il y a des trous, vraisemblablement pour des alignements mémoire
  et des optimisations d'accès.

  Le fichier contient les "trous".

  La question est est-ce que les "trous" ont des valeurs aléatoires ?
  La réponse est généralement : osef
*/
