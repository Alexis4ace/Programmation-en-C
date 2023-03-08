#include <stdio.h>
#include <stdlib.h>
// inclure ici les .h nécessaires
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
// TODO


// nombre de threads à lancer
#define NB_THREADS  3

// Fonction support d'un thread
// Tous les threads lanceront cette fonction
// Code
//    le paramètre de la fonction est un void *
//    il faut le caster en int *, avec un code qui ressemble à
//            int *p = (int *) arg;
//    on fait une temporisation d'une seconde avant l'affichage
//    on affiche la valeur du pointeur (p) et de l'entier pointé (*p)

// TODO
void * codeThread(void * arg ){
	sleep(1);
	int  * parg = (int *) arg;
	printf(" valeur compteur : %d \n",*parg);
	return NULL;
}
int main()
{
    // On déclare ici un tableau de pthread_t pour stocker tous les
    pthread_t id[NB_THREADS];
    // identifiants des threads
    
    // TODO
    
    // le compteur pour passer un numéro aux threads
    int compteur = 0;
	int ret ;
    // lancement des threads
    for (int i = 0; i < NB_THREADS; i++)
    {
    	ret = pthread_create(&id[i], NULL, codeThread, &compteur);
    	assert(ret == 0);
        compteur ++;
        // et donc on passe un pointeur sur compteur au thread
        // TODO
    }

    // attente de la fin des threads
    // (testez le programme sans attente, éventuellement avec une
    //  temporisation dans le code du thread)
    for (int i = 0; i < NB_THREADS; i++)
    {
    	ret = pthread_join(id[i], NULL);
    	assert(ret == 0);
        // TODO
    }

    printf("Fin thread principal\n");
    return EXIT_SUCCESS;
}
