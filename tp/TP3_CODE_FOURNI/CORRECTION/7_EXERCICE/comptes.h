#ifndef COMPTES_H
#define COMPTES_H

// note : si un numéro de compte est incorrect, le programme s'arrête
//        c'est de votre responsabilité de vérifier les numéros de comptes

int getNbComptes();
int getSoldeCompte(int numCompte);
void creditCompte(int numCompte, int montant);
void debitCompte(int numCompte, int montant);

#endif
