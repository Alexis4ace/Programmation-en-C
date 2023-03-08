
#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
// inclure les .h nécessaires

void ecritChaine(const char *nomFichier, const char *s)
{
    // todo
    // À vous de voir si vous écrivez le '\0' dans le fichier.
    //      Ce n'est pas une obligation, mais cela peut facilier le code
    //      de la fonction litChaine
    // rq : cf. fonction litChaine pour des explications supplémentaires
}

void litChaine(const char *nomFichier, char *s)
{
    // todo
    // rq : la chaîne doit être lue en une seule fois (un seul fread, enfin deux)
    //      ce qui implique qu'on doit connaître sa taille avant la lecture.
    //      Il pourrait donc être intéressant d'avoir une information avant la chaîne
    //      proprement dite (ce qui fait que l'on a deux fread !), cette
    //      information étant écrite par ecritChaine.
}

int main()
{
    // note : on ne gère pas ici la mémoire, ce n'est pas le but de l'exercice
    char original[1000] = "Bonjour monde !";
    char copie[1000];
    
    // todo (cf. spoiler ci-dessous)
    
    return EXIT_SUCCESS;
}



/*
  SPOITLER du main
      
    ecritChaine("exoC_test", original);
    litChaine("exoC_test", copie);
    
    if (strcmp(original, copie) == 0)
        printf("Tout est ok, les deux chaînes sont identiques\n");
    else
        printf("PB ! Les deux chaînes diffèrent\n");
*/
