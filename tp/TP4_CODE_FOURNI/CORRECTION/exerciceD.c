#define _XOPEN_SOURCE 500

#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
#include <assert.h>
// inclure les .h nécessaires

// note : la gestion mémoire est particulièrement brutale

// fonction qui sauvegarde un tableau de chaînes de caractères dans un fichier
void ecritTabChaines(const char *nomFichier, char * s[], int size)
{
    FILE * fd = fopen(nomFichier, "w");
    fwrite(&size, sizeof(int), 1, fd);
    for (int i = 0; i < size; i++)
    {
        int len = strlen(s[i]) + 1;
        fwrite(&len, sizeof(int), 1, fd);
        fwrite(s[i], sizeof(char), len, fd);
    }
    fclose(fd);
}

// fonction qui lit un tableau de chaînes de caractères
void litTabChaines(const char *nomFichier, char * tab[], int *size)
{
    FILE * fd = fopen(nomFichier, "r");
    fread(size, sizeof(int), 1, fd);
    for (int i = 0; i < *size; i++)
    {
        int len;
        fread(&len, sizeof(int), 1, fd);
        fread(tab[i], sizeof(char), len, fd);
    }
    fclose(fd);
}


/*----------------------------------------------------------------------*
 * entête pour la gestion des tableaux
 *----------------------------------------------------------------------*/
// taille des tableaux manipulés
static int getNbChaine();
// alloue et initialise un tableau de chaînes (pour l'écriture)
static char ** alloueInit();
// alloue (en surdimensionnant) un tableau de chaînes (pour la lecture)
static char ** alloue();
// libération mémoire
static void libere(char **tab);


int main()
{
    int n = getNbChaine();
    char **originaux = alloueInit();
    char **copies = alloue();

    // todo
    int nbCopies;
    ecritTabChaines("FIC/exoD_test", originaux, n);
    litTabChaines("FIC/exoD_test", copies, &nbCopies);
    
    if (nbCopies != n)
        printf("PB ! mauvais nombre de chaînes lues\n");
    else
    {
        for (int i = 0; i < nbCopies; i++)
        {
            if (strcmp(originaux[i], copies[i]) == 0)
                printf("ok, les deux chaînes numéro %2d sont identiques\n", i);
            else
                printf("PB ! Les deux chaînes numéro %2d diffèrent\n", i);
        }
    }
    
    libere(originaux);
    libere(copies);
    
    return EXIT_SUCCESS;
}



/*----------------------------------------------------------------------*
 * code pour la gestion des tableaux
 *----------------------------------------------------------------------*/
// inutile de regarder (ce n'est pas le but de l'exercice

// surdimensionnement pour simplifier la gestion mémoire
#define EXO_D_LEN (1000 + 1)
#define EXO_D_NB 3

static int getNbChaine()
{
    return EXO_D_NB;
}

static char ** alloueInit()
{
    char *contenu[] = {"Bonjour monde !", "Atchoum", "Grincheux"};
    assert(sizeof(contenu)/sizeof(char *) == EXO_D_NB);
    
    char **tab = malloc(EXO_D_NB * sizeof(char *));
    for (int i = 0; i < EXO_D_NB; i++)
    {
        assert(strlen(contenu[i]) + 1 <= EXO_D_LEN);
        tab[i] = strdup(contenu[i]);
    }
        
    return tab;
}

static char ** alloue()
{
    char **tab = malloc(EXO_D_NB * sizeof(char *));
    for (int i = 0; i < EXO_D_NB; i++)
    {
        tab[i] = malloc(EXO_D_LEN * sizeof(char));
    }
        
    return tab;
}

static void libere(char **tab)
{
     for (int i = 0; i < EXO_D_NB; i++)
         free(tab[i]);
     free(tab);
}
