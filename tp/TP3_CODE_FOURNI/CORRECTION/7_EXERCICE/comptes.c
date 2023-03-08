#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "operation.h"

#include "comptes.h"

/*
 * définitions des constantes et variables, toutes locales au fichier
 */

// nombre de comptes effectifs
// note : on ne peut pas faire un "const int" avec gcc (mais avec g++ oui)
#define NB_COMPTES 10

// périodicité pour gagner 1 euro lors des crédits
static const int TIRAGE_BONUS = 7;

// montant de base du compte à la création
static const int INIT_COMPTE = 15;

// par défaut c'est initialisé à 0 et impossible ici d'initialiser
// à autre chose (avec la norme du C) (en fait je ne suis pas sûr)
static int comptes[NB_COMPTES];


/*
 * fonctions internes
 */

// gestion violente
// l'utilisation d'un assert serait plus élégante
static void verifNumCompte(int numCompte)
{
    if ((numCompte < 0) || (numCompte >= getNbComptes()))
    {
        fprintf(stderr, "numéro de compte incorrect.\n");
        exit(EXIT_FAILURE);
    }
}


/*
 * Cette fonction initialise les comptes bancaires, mais elle ne doit
 * être appelée qu'une seule fois avant tout autre appel du module.
 * solution 1 : elle est mise à disposition de l'extérieur en espérant
 *              que l'utilisateur du module n'oublie pas de l'appeler.
 * solution 2 (retenue) : elle appelée systématiquement par toutes les
 *              autres fonctions, et c'est elle-même qui invalide son
 *              action à partir de sa 2me exécution
 *              c'est le principe du singleton
 */
static void initComptes()
{
    static bool first = true;
    if (first)
    {
        for (int i = 0; i < NB_COMPTES; i++)
            comptes[i] = INIT_COMPTE;
        first = false;
    }
}

/*
 * fonctions externes
 */
int getNbComptes()
{
    initComptes();

    return NB_COMPTES;
}

int getSoldeCompte(int numCompte)
{
    initComptes();

    verifNumCompte(numCompte);

    return comptes[numCompte];
}

void creditCompte(int numCompte, int montant)
{
    initComptes();

    verifNumCompte(numCompte);

    static int cpt = 0;

    comptes[numCompte] = plus(comptes[numCompte], montant);

    cpt ++;
    if (cpt % TIRAGE_BONUS == 0)
        comptes[numCompte] = plus(comptes[numCompte], 1);
}

void debitCompte(int numCompte, int montant)
{
    initComptes();

    verifNumCompte(numCompte);

    comptes[numCompte] = moins(comptes[numCompte], montant);
}
