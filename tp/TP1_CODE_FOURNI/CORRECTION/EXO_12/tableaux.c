#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(int tab[], int n, int min, int max)
{
    for (int i = 0; i < n; i++)
        tab[i] = min + rand()%(max-min+1);
}

void affiche(const int tab[], int n, const char *titre)
{
    printf("== %s ==\n", titre);
    printf("   taille : %d\n", n);
    printf("   [ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", tab[i]);
        if (i != n-1)
            printf(", ");
    }
    printf(" ]\n");
    printf("\n");
}

float moyenne(const int tab[], int n)
{
    int somme = 0;
    for (int i = 0; i < n; i++)
        somme += tab[i];
    return ((float)somme)/n;
    //return 1.0*somme/n;
}

void somme(const int lhs[], const int rhs[], int res[], int n)
{
    for (int i = 0; i < n; i++)
        res[i] = lhs[i] + rhs[i];
}

// on suppose qu'il y a au moins deux cases
int max2(const int tab[], int n)
{
    int posM;
    int posm;
    
    if (tab[0] < tab[1])
    {
        posM = 1;
        posm = 0;
    }
    else
    {
        posM = 0;
        posm = 1;
    }

    for (int i = 2; i < n; i++)
    {
        if (tab[i] > tab[posM])
        {
            posm = posM;
            posM = i;
        }
        else if (tab[i] > tab[posm])
            posm = i;
    }

    return posm;
}

// j'ai la flemme d'optimiser
void bulle(int tab[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (tab[j] > tab[j+1])
            {
                int tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;
            }
        }
    }
}


#define N 15

int main()
{
    int t[N];
    int u[N];
    int r[N];

    srand(time(NULL));

    init(t, N, 10, 99);
    affiche(t, N, "t");
    printf("moyenne : %g\n", moyenne(t, N));
    printf("case 2me maximum : %d\n", max2(t, N));

    init(u, N, 12, 18);
    affiche(u, N, "u");
    somme(t, u, r, N);
    affiche(r, N, "t+u");

    affiche(t, N, "t");
    bulle(t, N);
    affiche(t, N, "t tri");
    
    return EXIT_SUCCESS;
}
