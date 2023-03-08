#include "operation.h"

int dummy = 14;

static int nbOperations = 0;

int plus(int a, int b)
{
    nbOperations ++;
    return a + b;
}

int moins(int a, int b)
{
    nbOperations ++;
    return a - b;
}

int getNbOperations()
{
    return nbOperations;
}
