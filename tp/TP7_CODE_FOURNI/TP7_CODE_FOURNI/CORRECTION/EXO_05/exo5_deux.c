// compilation :
// $ gcc -g -Wall -Wextra -pedantic -std=c99 -o exo5_deux exo5_deux.c myassert.c

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
    // il faut récupérer le sémaphore avec la clé fournie dans exo5_comm.h
    // il faut être rigoureux : le sémaphore doit déjà exister sinon
    //      c'est une erreur
    // faut-il initialiser le sémaphore ?
    int semId;

    // création
    // - le flag (3me paramètre) doit absolument être à 0
    semId = semget(MA_CLE, 1, 0);
    myassert(semId != -1, "'ouverture' sémaphore");
    // et donc pas d'initialisation

    // ici il faut attendre le déblocage venant de "un"
    int ret;
    // paramètres : num sépamhore, opération, flags
    struct sembuf operation = {0, -1, 0};
    ret = semop(semId, &operation, 1);
    myassert(ret != -1, "erreur 'prendre' sémaphore");
    
    // affichage venant après celui de un
    printf("Processus deux %d ! (normalement je m'affiche en dernier)\n",
           getpid());

    // Qui doit détruire le sémaphore ? un ou deux ?
    // Rappelez-vous que lorsqu'on détruit un sémaphore, il faut
    // être certain qu'aucun autre processus ne l'utilise.
    
    // En l'occurrence c'est "deux" car c'est le dernier à l'utiliser
    ret = semctl(semId, -1, IPC_RMID);
    myassert(ret != -1, "destruction sémaphore");

    printf("Fin de deux\n");
    
    return EXIT_SUCCESS;
}
