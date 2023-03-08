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
    // Il faut récupérer le sémaphore avec une clé générée par ftok et le
    key_t cle = ftok("/home/info/Bureau/TP7_CODE_FOURNI/CODE_TRAVAIL",PROJ_ID);
    assert(cle != -1);	
    // le fichier fourni dans exo6_comm.h
    // Il faut être rigoureux : le sémaphore doit déjà exister sinon
    //      c'est une erreur
    int semId = semget(cle,1,0);
    assert(semId != -1 );
    // faut-il initialiser le sémaphore ?


    // ici il faut attendre le déblocage venant de "un"
	struct sembuf operation = { 0 , -1 , 0};
	int test = semop(semId,&operation,1);
	assert(test != -1 );
    // affichage venant après celui de un
    printf("Processus deux %d ! (normalement je m'affiche en dernier)\n",
           getpid());

    // Qui doit détruire le sémaphore ? un ou deux ?
    // Rappelez-vous que lorsqu'on détruit un sémaphore, il faut
    // être certain qu'aucun autre processus ne l'utilise.
	test = semctl(semId,-1,IPC_RMID);
	assert(ret != -1);
    printf("Fin de deux\n");
    
    return EXIT_SUCCESS;
}
