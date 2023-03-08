// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
// ajouter ici les include nécessaires

#include <sys/ipc.h>
#include <sys/sem.h>

#include "exo6_comm.h"


int main()
{
    // Il faut créer le sémaphore avec une clé générée par ftok et le
    key_t cle = ftok("/home/info/Bureau/TP7_CODE_FOURNI/CODE_TRAVAIL",PROJ_ID);
    assert(cle != -1);	
    // le fichier fourni dans exo6_comm.h
    int semId = semget(cle,1,IPC_CREAT | IPC_EXCL | 0641 );
    assert(semId != -1 );
    // Il faut être rigoureux : si le sémphore existe déjà, c'est une erreur
    // et il ne faut pas oublier de l'initialiser
	ret = semctl(semId, 0, SETVAL, 0);
    assert(ret != -1);
    // une longue attente pour qu'on ait le temps de lancer exo5_deux
    // et pour être sûr que ce dernier attend
    sleep(5);
    printf("Processus un %d ! (normalement je m'affiche en premier)\n",
           getpid());
    sleep(1);
    
    // ici il faut débloquer le processus "deux"
	struct sembuf operation = { 0 , 1 , 0 };
	int test = semop(semId,&operation,1);
	assert(test != -1);


    // Qui doit détruire le sémaphore ? un ou deux ?
    // Rappelez-vous que lorsqu'on détruit un sémaphore, il faut
    // être certain qu'aucun autre processus ne l'utilise.


    printf("Fin de un\n");
    
    return EXIT_SUCCESS;
}
