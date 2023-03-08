#include <stdio.h>
#include <stdlib.h>
// inclure ici les .h nécessaires
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>


// nombre de threads à lancer
#define NB_THREADS  3

// fonction support d'un thread
// éventuellement faites une temporisation d'une seconde avant l'affichage
// tous les threads lanceront cette fonction
void * codeThread(void * arg)
{
    assert(arg == NULL);
    
    sleep(1);
    printf("Thread %d\n", getpid());
    return NULL;
}

int main()
{
    // On déclare ici un tableau de pthread_t pour stocker tous les
    // identifiants des threads
    pthread_t tabId[NB_THREADS];

    // lancement des threads
    for (int i = 0; i < NB_THREADS; i++)
    {
        int ret = pthread_create(&(tabId[i]), NULL, codeThread, NULL);
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
    
    // Rq : il y a bien deux boucles : une pour lancer tous les threads
    //      (quasi) en même temps, et une autre après pour attendre
    //      leurs fins.
    //      Si on ne fait qu'une seule boucle :
    //          for (...) {
    //              lancer thread
    //              attendre fin thread
    //          }
    //      alors les threads s'exécutent les uns après les autres au lieu
    //      d'être en concurrence (auquel cas les threads sont inutiles et
    //      autant appeler la fonction normalement).
    //      À tester pour être convaincu.

    // Rq : tous les threads affichent la même chose. "getpid" renvoie
    //      le pid du processus lourd (qui est le même pour tous) et
    //      non pas l'identifiant du thread.

    printf("Fin thread principal\n");
    return EXIT_SUCCESS;
}
