// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include "exo6_comm.h"


int main()
{
    // Il faut récupérer le sémaphore avec une clé générée par ftok et le
    // le fichier fourni dans exo6_comm.h
    // Il faut être rigoureux : le sémaphore doit déjà exister sinon
    //      c'est une erreur
    // faut-il initialiser le sémaphore ?
    key_t key;
    int semId;

    key = ftok(MON_FICHIER, PROJ_ID);
    assert(key != -1);
    // le flag (3me paramètre) doit absolument être à 0
    semId = semget(key, 1, 0);
    assert(semId != -1);
    // et donc pas d'initialisation

    // ici il faut attendre le déblocage venant de "un"
    int ret;
    // paramètres : num sépamhore, opération, flags
    struct sembuf operation = {0, -1, 0};
    ret = semop(semId, &operation, 1);
    assert(ret != -1);
    
    // affichage venant après celui de un
    printf("Processus deux %d ! (normalement je m'affiche en dernier)\n",
           getpid());

    // Qui doit détruire le sémaphore ? un ou deux ?
    // Rappelez-vous que lorsqu'on détruit un sémaphore, il faut
    // être certain qu'aucun autre processus ne l'utilise.
    
    // En l'occurrence c'est "deux" car c'est le dernier à l'utiliser
    ret = semctl(semId, -1, IPC_RMID);
    assert(ret != -1);

    printf("Fin de deux\n");
    
    return EXIT_SUCCESS;
}
