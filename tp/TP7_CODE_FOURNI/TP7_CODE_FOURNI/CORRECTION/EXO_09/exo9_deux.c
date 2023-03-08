// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "exo9_comm.h"


// récupération d'un sémaphore IPC
static int my_semget(int projectId)
{
    key_t key;
    int semId;

    key = ftok(MON_FICHIER, projectId);
    assert(key != -1);
    semId = semget(key, 1, 0);
    assert(semId != -1);

    return semId;
}

// -1 sur un sémaphore
static void prendre(int semId)
{
    int ret;
    struct sembuf op = {0, -1, 0};
    ret = semop(semId, &op, 1);
    assert(ret != -1);
}

// +1 sur un sémaphore
static void vendre(int semId)
{
    int ret;
    struct sembuf op = {0, +1, 0};
    ret = semop(semId, &op, 1);
    assert(ret != -1);
}

// récupération d'un segment
static int my_shmget()
{
    key_t key;
    int shmId;

    key = ftok(MON_FICHIER, PROJ_ID_SHM);
    assert(key != -1);
    shmId = shmget(key, SHM_TAILLE, 0);
    assert(shmId != -1);

    return shmId;
}

// attachement sur un segment
static char * my_shmat(int shmId)
{
    char *ptShm = shmat(shmId, NULL, SHM_RDONLY);
    assert(ptShm != ((void *) -1));
    return ptShm;
}

// détachement d'un segment
void my_shmdt(void *pt)
{
    int ret = shmdt(pt);
    assert(ret != -1);
}


int main()
{
    int semIdEcriture;
    int semIdFin;
    int shmId;
    char * ptShm = NULL;
    
    // récupération sémaphores
    semIdEcriture = my_semget( PROJ_ID_SEM_ECRITURE);
    semIdFin = my_semget(PROJ_ID_SEM_FIN);

    // création segment (rappel : on suppose le segment assez grand)
    shmId = my_shmget();
    // et un pointeur sur le segment (autant le mettre en read only)
    ptShm = my_shmat(shmId);

    // on attend l'autorisation de un
    prendre(semIdEcriture);

    // On affiche la chaine
    printf("chaine : %s\n", ptShm);

    // on détache le pointeur
    my_shmdt(ptShm);

    // on dit à un qu'il peut tout détruire
    vendre(semIdFin);

    // et donc rien à détruire
    
    printf("Fin de deux\n");
    
    return EXIT_SUCCESS;
}
