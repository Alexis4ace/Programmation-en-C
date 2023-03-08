/*
 * Exercice 1.09
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_09.c -o exo_1_09
 */
/*
 * ### les commentaires de correction sont précédés par ###
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

// écrire ici la fonction mystrcmp
// ====== TODO ==========
int mystrcmp(const char *s1, const char *s2)
{
    int i = 0;
    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
        i++;
    return (s1[i] - s2[i]);
    // ### la boucle classique : on avance tant que les caractères sont égaux
    // ### return : on joue sur le fait que les char sont des nombres
    // ###          et que '\0' vaut 0. Ce n'est pas lisible (ce que
    // ###          généralement je n'accepte pas), mais je me suis placé
    // ###          ici dans une optique "système" et efficacité à tout prix
}

// ### une version moins lisible et plus efficace (a priori)
// ### On joue sur le fait que s1 et s2 sont passés par copie et que donc
// ### on peut les modifier sans conséquence
int mystrcmp2(const char *s1, const char *s2)
{
    while ((*s1 == *s2) && (*s1 != '\0') && (*s2 != '\0'))
        s1 ++, s2 ++;
    return (*s1 - *s2);
}

int main()
{
    // ------------------------------------------------------------
    title_print("strcmp : version personnelle");

    // voici un ensemble de chaînes à comparer
    char *essais[][2] =
        {
            {"chat", "chat"},
            {"chat", "chien"},
            {"chien", "chat"},
            {"chat", "chaton"},
            {"souris", "elephant"},
            {"souris", "élephant"},
            {"anticonstitutionnellement", "zoo"},
            {"145", "237"},
            {"1453", "22"},
            {"+23", "-23"}
        };
    int nbCouples = sizeof(essais) / sizeof(*essais);

    for (int i = 0; i < nbCouples; i++)
    {
        // appeler mystrcmp sur essais[i][0] et essais[i][1]
        // et afficher le résultat (en indiquant également "plus petit" "égal"
        // ou "plus grand")
        // Vérifiez si vous avez les mêmes résultats que l'exercice précédent
        // ====== TODO ==========
        int retour = mystrcmp(essais[i][0], essais[i][1]);
        char signe;
        if (retour == 0)
            signe = '=';
        else if (retour < 0)
            signe = '<';
        else
            signe = '>';

        printf("%30s %c %s\n", essais[i][0], signe, essais[i][1]);
        // ### Attention : chez moi tout est ok SAUF "élephant"
        // ### C'est le problème de l'encodage UTF8 ou le 'é' est
        // ### codé sur 2 octets.
        // ### si mon fichier avait été en iso-latin, il n'y aurait pas
        // ### de problème (et donc il semble que strcmp gère l'UTF8)
    }

    // note : à étudier, lorsqu'il y a des accents, l'influence de
    //        l'encodage (UTF8 ou iso-latin)

    printf("\n");

    return EXIT_SUCCESS;
}
