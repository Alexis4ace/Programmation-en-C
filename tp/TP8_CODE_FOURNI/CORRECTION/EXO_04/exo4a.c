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
//    il faut le caster en int *, avec un code qui ressemble à
//            int *p = (int *) arg;
//    on fait une temporisation d'une seconde avant l'affichage
//    on affiche la valeur du pointeur (p) et de l'entier pointé (*p)
void * codeThread(void * arg)
{
    int *p = (int *) arg;
    
    sleep(1);
    printf("Thread %d (%p)\n", *p, (void *)p);
    return NULL;
}

int main()
{
    // On déclare ici un tableau de pthread_t pour stocker tous les
    // identifiants des threads
    pthread_t tabId[NB_THREADS];
    // le compteur pour passer un numéro aux threads
    int compteur = 0;

    // lancement des threads
    for (int i = 0; i < NB_THREADS; i++)
    {
        compteur ++;
        // et donc on passe un pointeur sur compteur au thread
        int ret = pthread_create(&(tabId[i]), NULL, codeThread, &compteur);
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

    // Rq : tous les threads affichent la même chose.
    //      Les threads recoivent un pointeur sur compteur, donc ils
    //      pointent tous sur le même espace mémoire qui est changé
    //      en permanence par le main.
    //      Avec la temporisation, au moment de l'affichage, la zone
    //      pointée contient le numéro le plus grand.

    printf("Fin thread principal\n");
    return EXIT_SUCCESS;
}
