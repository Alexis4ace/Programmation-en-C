#include <stdio.h>
#include <stdlib.h>

#define TAILLE1 10

struct Exo
{
    float f;
    float tab1[TAILLE1];
    int taille2;
    float *tab2;
};

/*
 * initialisation arbitraire
 */
void init(struct Exo *exo, float f, int taille2)
{
    exo->f = f;
    for (int i = 0; i < TAILLE1; i++)
        exo->tab1[i] = (i+1) * f;
    exo->taille2 = taille2;
    exo->tab2 = malloc(taille2 * sizeof(float));
    for (int i = 0; i < taille2; i++)
        exo->tab2[i] = f + i;
}

struct Exo * creer(int n)
{
    struct Exo *exos;
    exos = malloc(n * sizeof(struct Exo));

    for (int i = 0; i < n; i++)
        init(&(exos[i]), 3.14*i, n+3+i);

    return exos;
}

void libere(struct Exo exos[], int n)
{
    for (int i = 0; i < n; i ++)
        free(exos[i].tab2);
    free(exos);
}

int main()
{
    struct Exo *exos = creer(15);
    libere(exos, 15);
    exos = NULL;
    
    return EXIT_SUCCESS;
}
