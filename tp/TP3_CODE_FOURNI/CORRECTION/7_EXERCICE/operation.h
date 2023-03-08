#ifndef OPERATION_H
#define OPERATION_H

// variable globale qui ne sert à rien
extern int dummy;

int plus(int a, int b);
int moins(int a, int b);

// nombre d'appels à "plus" et "moins"
int getNbOperations();

#endif
