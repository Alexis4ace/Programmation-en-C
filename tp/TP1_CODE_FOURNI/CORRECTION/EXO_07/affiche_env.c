#include <stdio.h>
#include <stdlib.h>

// rq : il n'est pas nécessaire de passer le 3me argument bien que l'on
//      manipule les variables d'environnement
int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        printf("usage : %s <nom variable>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *nom = argv[1];
    const char *val = getenv(argv[1]);
    
    if (val == NULL)
        printf("la variable %s n'existe pas.\n", nom);
    else
        printf("la variable %s vaut >>%s<<.\n", nom, val);
    
    return EXIT_SUCCESS;
}


/*
 * Quelques remarques :
 * - de même qu'on utilise EXIT_SUCCESS, on utilise EXIT_FAILURE
 * - en règle générale je déclare les variables juste après une '{',
 *   mais je trouve plus lisible ici de traiter d'abord le cas d'erreur
 * - je ne veux pas voir de
 *        if (val)
 *   ou de
 *        if (! val)
 *   un pointeur n'est pas un booléen, donc ça n'a pas de sens.
 */
