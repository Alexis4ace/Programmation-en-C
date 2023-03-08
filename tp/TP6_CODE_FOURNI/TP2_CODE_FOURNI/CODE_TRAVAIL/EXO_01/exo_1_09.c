/*
 * Exercice 1.09
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_09.c -o exo_1_09
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

// écrire ici la fonction mystrcmp
// ====== TODO ==========

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
    }

    // note : à étudier, lorsqu'il y a des accents, l'influence de
    //        l'encodage (UTF8 ou iso-latin)

    printf("\n");

    return EXIT_SUCCESS;
}
