#include <stdio.h>
#include <stdlib.h>
// inclure ici les .h nécessaires
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>


// nombre de threads à lancer
#define NB_THREADS  3

// Fonction support d'un thread
// Tous les threads lanceront cette fonction
// Code
//    le paramètre de la fonction est un void *
//    il faudrait le caster en int *, mais on va le caster en float *
//    avec un code qui ressemble à
//            float *p = (float *) arg;
//    on fait une temporisation d'une seconde avant l'affichage
//    on affiche la valeur du pointeur (p) et du "float" pointé (*p)
void * codeThread(void * arg)
{
    float *p = (float *) arg;
    
    sleep(1);
    printf("Thread %g (%p)\n", *p, (void *)p);
    return NULL;
}

int main()
{
    // On déclare ici un tableau de pthread_t pour stocker tous les
    // identifiants des threads
    pthread_t tabId[NB_THREADS];
    // un tableau de compteurs pour que chaque thread ait son propre compteur
    int compteurs[NB_THREADS];

    // pré-initialisation des compteurs
    for (int i = 0; i < NB_THREADS; i++)
        compteurs[i] = i+1;

    // lancement des threads
    for (int i = 0; i < NB_THREADS; i++)
    {
        // et donc on passe un pointeur sur une case différente chaque fois
        int ret = pthread_create(&(tabId[i]), NULL, codeThread, &(compteurs[i]));
        assert(ret == 0);
    }

    // attente de la fin des threads
    // (testez le programme sans attente, éventuellement avec une
    //  temporisation dans le code du thread)
    for (int i = 0; i < NB_THREADS; i++)
    {
        int ret = pthread_join(tabId[i], NULL);
        assert(ret == 0);
    }

    printf("Fin thread principal\n");
    return EXIT_SUCCESS;
}
