// compilation :
// $ gcc -g -Wall -Wextra -pedantic -std=c99 -o exo5_un exo5_un.c

// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include "myassert.h"

#include "exo5_comm.h"


int main()
{
    int ret;
    // il faut créer le sémaphore avec la clé fournie dans exo5_comm.h
    // il faut être rigoureux : si le sémphore existe déjà, c'est une erreur
    // et il ne faut pas oublier de l'initialiser
    int semId;

    //création
    semId = semget(MA_CLE, 1, IPC_CREAT | IPC_EXCL | 0641);
    myassert(semId != -1, "création sémaphore");
    // initialisation
    // - 2me paramètre (i.e. 0) : numéro sémaphore
    // - 4me paramètre (i.e. 0) : valeur du sémaphore
    ret = semctl(semId, 0, SETVAL, 0);
    myassert(ret != -1, "initialisation sémaphore");

    // une longue attente pour qu'on ait le temps de lancer exo5_deux
    // et pour être sûr que ce dernier attend
    sleep(5);
    printf("Processus un %d ! (normalement je m'affiche en premier)\n",
           getpid());
    sleep(1);
    
    // ici il faut débloquer le processus "deux"
    // paramètres : num sépamhore, opération, flags
    struct sembuf operation = {0, 1, 0};
    ret = semop(semId, &operation, 1);
    myassert(ret != -1, "erreur 'vendre' sémaphore");

    // Qui doit détruire le sémaphore ? un ou deux ?
    // Rappelez-vous que lorsqu'on détruit un sémaphore, il faut
    // être certain qu'aucun autre processus ne l'utilise.

    // ce n'est pas un (cf. deux.c)

    printf("Fin de un\n");
    
    return EXIT_SUCCESS;
}
