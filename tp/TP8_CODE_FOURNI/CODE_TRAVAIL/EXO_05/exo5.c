#include <stdio.h>
#include <stdlib.h>
// inclure ici les .h nécessaires
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>


// nombre de threads à lancer
#define NB_THREADS  4

// structure pour passer les paramètres aux pthread :
//   . un pointeur sur l'entier devant recevoir le résultat
//   . le début de l'intervalle
//   . la fin de l'intervalle
typedef struct
{
	int *entier;
	int debut;
	int fin;
    // TODO
} ThreadData;

// Fonction support d'un thread
// Tous les threads lanceront cette fonction
// Code
//    le paramètre de la fonction est un void *
//    il faut le caster en ThreadData *
//    on calcule la somme des entiers (par exemple si l'intervalle
//        est [5, 9], il faut calculer 5+6+7+8+9)
//    on stocke le résultat dans la zone mémoire fournie
void * codeThreads(void * arg ){
	int nombreFinal = 0;
	ThreadData * pdata = (ThreadData *) arg;
	for(int k=pdata->debut;k<=pdata->fin;k++){
		nombreFinal += k ;
	}
	*(pdata->entier) = nombreFinal;

	return NULL;
}
// TODO

int main()
{
    // Débuts et fins des intervalles (attention si on change NB_THREADS)
    int debuts[NB_THREADS] = {3,  9, -3,  5};
    int fins[NB_THREADS]   = {7, 12,  2, 10};
    // tableau rempli par les threads
    int results[NB_THREADS];
	int res ;
	pthread_t id[NB_THREADS];
    // On déclare ici un tableau de pthread_t pour stocker tous les
    // identifiants des threads
    // TODO
    // et un tableau de struct pour que chaque thread ait sa propre structure
    ThreadData datas[NB_THREADS];

    // pré-initialisation des données
    for (int i = 0; i < NB_THREADS; i++)
    {
    	
        // il faut initialiser datas[i] avec :
        //   . un pointeur sur la ième case de results
        datas[i].entier = &(results[i]);
        //   . le début de l'intervalle : debuts[i];
        datas[i].debut = debuts[i];
        //   . la fin de l'intervalle : fins[i]
        datas[i].fin = fins[i];
    }

    // lancement des threads
    for (int i = 0; i < NB_THREADS; i++)
    {
    	res = pthread_create(&id[i],NULL,codeThreads,&(datas[i]));
    	assert(res == 0 );
        // et donc on passe un pointeur sur une struct différente chaque fois
        // TODO
    }

    // attente de la fin des threads
    // (testez le programme sans attente, éventuellement avec une
    //  temporisation dans le code du thread)
    for (int i = 0; i < NB_THREADS; i++)
    {
    	res = pthread_join(id[i],NULL);
    	assert(res == 0 );
        // TODO
    }

    // Affichages résultats
    printf("Fin thread principal : résultats\n");
    printf("Attendus : [");
    for (int i = 0; i < NB_THREADS; i++)
    {
        int res = 0;
        for (int v = debuts[i]; v <= fins[i]; v++)
            res += v;
        // ou sans boucle : res = b*(b+1)/2-(a-1)*a/2;
        if (i != 0)
            printf(", ");
        printf("%3d", res);
    }
    printf("]\n");
    printf("Obtenus  : [");
    for (int i = 0; i < NB_THREADS; i++)
    {
        if (i != 0)
            printf(", ");
        printf("%3d", results[i]);
    }
    printf("]\n");

    return EXIT_SUCCESS;
}
