#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
// inclure les .h nécessaires

void ecritTabIntAsc(const char *nomFichier, const int tab[], int n)
{
    FILE * fd = fopen(nomFichier, "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(fd, "%d", tab[i]);
        if (i != n-1)
            fprintf(fd, " ");
    }
    fclose(fd);
}

int litIntPosAsc(const char *nomFichier, int pos)
{
    int val = -1;
    FILE * fd;

    fd = fopen(nomFichier, "r");
    for (int i = 0; i <= pos; i++)
    {
        int tmp;
        int ret;
        
        ret = fscanf(fd, "%d", &tmp);
        if (ret == EOF)
            break;
        if (i == pos)
            val = tmp;
    }

    fclose(fd);
    
    return val;
}

bool remplaceIntPosAsc(const char *nomFichier, int pos, int newVal)
{
    // ce n'est possible de décaler des caractères dans un fichier, il faut
    // sauvegarder les valeurs dans un tableau et les réécrire.
    // On fait une solution violente
    // - on recrée un tableau complet avec les valeurs
    // - on réécrit tout le tableau dans le même fichier
    
    bool ok = false;
    int *tab = NULL;
    FILE * fd;
    int taille = 0;

    // lecture complète du fichier
    fd = fopen(nomFichier, "r");
    while (true)
    {
        int tmp;
        int ret;
        
        ret = fscanf(fd, "%d", &tmp);
        if (ret == EOF)
            break;

        taille ++;
        tab = realloc(tab, taille*sizeof(int));
        tab[taille-1] = tmp;
    }
    fclose(fd);
    
    if (pos < taille)
    {
        ok = true;
        tab[pos] = newVal;
        ecritTabIntAsc(nomFichier, tab, taille);
    }

    free(tab);
    
    return ok;
}

int main()
{
    int tab[] = {10, 5, 87, 0, 5, 212, 12, 14, 55};
    int n = sizeof(tab)/sizeof(*tab);

    // écrire le tableau dans le fichier FIC/exoE_test
    ecritTabIntAsc("FIC/exoE_test", tab, n);

    // remplacer la case 2 (donc le 87) par 9
    remplaceIntPosAsc("FIC/exoE_test", 2, 9);
    // remplacer la case 9 (indice trop grand) par 66 : il ne se passe rien
    remplaceIntPosAsc("FIC/exoE_test", 9, 66);
    // remplacer la cse 0 (donc le 10) par 1111
    remplaceIntPosAsc("FIC/exoE_test", 0, 1111);

    // afficher le contenu du fichier en utilisant la fonction litIntPosAsc
    printf("  [");
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            printf(", ");
        printf("%d", litIntPosAsc("FIC/exoE_test", i));
    }
    printf("]\n");
    
    return EXIT_SUCCESS;
}
