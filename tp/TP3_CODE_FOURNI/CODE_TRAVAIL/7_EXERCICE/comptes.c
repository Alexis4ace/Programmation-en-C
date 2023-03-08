// todo : des include

// todo : définitions des constantes, types, variables, ...



/*
 * fonctions internes
 */

// gestion violente
// l'utilisation d'un assert serait plus élégante
// todo : la fonction est locale au fichier, y a-t-il quelque chose à faire ?
void verifNumCompte(int numCompte)
{
    if ((numCompte < 0) || (numCompte >= getNbComptes()))
    {
        fprintf(stderr, "numéro de compte incorrect.\n");
        exit(EXIT_FAILURE);
    }
}

// todo : le reste du code
