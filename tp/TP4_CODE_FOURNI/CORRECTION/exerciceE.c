#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
// inclure les .h nécessaires

void ecritTabIntBin(const char *nomFichier, const int tab[], int n)
{
    FILE * fd = fopen(nomFichier, "w");
    fwrite(tab, sizeof(int), n, fd);
    fclose(fd);
}

int litIntPosBin(const char *nomFichier, int pos)
{
    int val = -1;
    FILE * fd;
    int taille;

    fd = fopen(nomFichier, "r");
    fseek(fd, 0, SEEK_END);
    taille = ftell(fd) / sizeof(int);
    
    if (pos < taille)
    {
        fseek(fd, pos * sizeof(int), SEEK_SET);
        fread(&val, sizeof(int), 1, fd);
    }

    fclose(fd);
    
    return val;
}

bool remplaceIntPosBin(const char *nomFichier, int pos, int newVal)
{
    bool ok = false;
    FILE * fd;
    int taille;

    fd = fopen(nomFichier, "r+");
    fseek(fd, 0, SEEK_END);
    taille = ftell(fd) / sizeof(int);
    
    if (pos < taille)
    {
        ok = true;
        fseek(fd, pos * sizeof(int), SEEK_SET);
        fwrite(&newVal, sizeof(int), 1, fd);
    }
    
    fclose(fd);
    
    return ok;
}

int main()
{
    int tab[] = {10, 5, 87, 0, 5, 212, 12, 14, 55};
    int n = sizeof(tab)/sizeof(*tab);                 // attention : l'utilisation de sizeof pour avoir la taille d'un tableau est fortement déconseillée

    // écrire le tableau dans le fichier FIC/exoE_test
    ecritTabIntBin("FIC/exoE_test", tab, n);

    // remplacer la case 2 (donc le 87) par 777
    remplaceIntPosBin("FIC/exoE_test", 2, 777);
    // remplacer la case 9 (indice trop grand) par 66 : il ne se passe rien
    remplaceIntPosBin("FIC/exoE_test", 9, 66);
    // remplacer la cse 0 (donc le 10) par 1111
    remplaceIntPosBin("FIC/exoE_test", 0, 1111);

    // afficher le contenu du fichier en utilisant la fonction litIntPosBin
    printf("  [");
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            printf(", ");
        printf("%d", litIntPosBin("FIC/exoE_test", i));
    }
    printf("]\n");
    
    return EXIT_SUCCESS;
}
