
#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
// inclure les .h nécessaires

void ecritChaine(const char *nomFichier, const char *s)
{
    // On écrit d'abord la taille de la chaîne pour faciliter la lecture
    // on note qu'on fait le choix d'écrire le '\0' dans le fichier.
    int taille = strlen(s) + 1;   // +1 pour le '\0'
    FILE * fd = fopen(nomFichier, "w");
    fwrite(&taille, sizeof(int), 1, fd);
    fwrite(s, sizeof(char), taille, fd);
    fclose(fd);
}

void litChaine(const char *nomFichier, char *s)
{
    int taille;
    FILE * fd = fopen(nomFichier, "r");
    fread(&taille, sizeof(int), 1, fd);
    fread(s, sizeof(char), taille, fd);
    fclose(fd);
}

int main()
{
    // note : on ne gère pas ici la mémoire, ce n'est pas le but de l'exercice
    char original[1000] = "Bonjour monde !";
    char copie[1000];
    
    ecritChaine("FIC/exoC_test", original);
    litChaine("FIC/exoC_test", copie);
    
    if (strcmp(original, copie) == 0)
        printf("Tout est ok, les deux chaînes sont identiques\n");
    else
        printf("PB ! Les deux chaînes diffèrent\n");
    
    return EXIT_SUCCESS;
}
