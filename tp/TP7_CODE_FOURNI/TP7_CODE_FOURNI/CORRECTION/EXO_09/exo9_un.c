// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "exo9_comm.h"

// création d'un sémaphore IPC
static int my_semget(int projectId, int initVal)
{
    key_t key;
    int semId;
    int ret;

    key = ftok(MON_FICHIER, projectId);
    assert(key != -1);
    semId = semget(key, 1, IPC_CREAT | IPC_EXCL | 0641);
    assert(semId != -1);
    // 2e param : numéro sémaphore ; 4e param : valeur du sémaphore
    ret = semctl(semId, 0, SETVAL, initVal);
    assert(ret != -1);

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

// création d'un segment
static int my_shmget()
{
    key_t key;
    int shmId;

    key = ftok(MON_FICHIER, PROJ_ID_SHM);
    assert(key != -1);
    shmId = shmget(key, SHM_TAILLE, IPC_CREAT | IPC_EXCL | 0641);
    assert(shmId != -1);

    return shmId;
}

// attachement sur un segment
static char * my_shmat(int shmId)
{
    char *ptShm = shmat(shmId, NULL, 0);
    assert(ptShm != ((void *) -1));
    return ptShm;
}

// détachement d'un segment
void my_shmdt(void *pt)
{
    int ret = shmdt(pt);
    assert(ret != -1);
}

// suppression des sémaphores et du segment
static void my_destroyAll(int sem1, int sem2, int shm)
{
    int ret;

    ret = semctl(sem1, -1, IPC_RMID);
    assert(ret != -1);
    
    ret = semctl(sem2, -1, IPC_RMID);
    assert(ret != -1);

    ret = shmctl(shm, IPC_RMID, NULL);
    assert(ret != -1);
}


int main()
{
    const char * const chaine = "Bonjour monde !";
    int semIdEcriture;
    int semIdFin;
    int shmId;
    char * ptShm = NULL;

    // création sémaphores
    semIdEcriture = my_semget( PROJ_ID_SEM_ECRITURE, 0);
    semIdFin = my_semget( PROJ_ID_SEM_FIN, 0);

    // création segment (rappel : on suppose le segment assez grand)
    shmId = my_shmget();
    // et un pointeur sur le segment
    ptShm = my_shmat(shmId);

    // on écrit avec une tempo
    sleep(3);
    printf("Je vais écrire la chaine\n");
    strcpy(ptShm, chaine);
    sleep(1);
    printf("Chaine écrite\n");

    // on débloque deux
    vendre(semIdEcriture);

    // on attend que deux n'ait plus besoin du segment (et des sémaphore)
    prendre(semIdFin);

    // on détache le pointeur
    my_shmdt(ptShm);

    // on détruit tout le monde
    my_destroyAll(semIdEcriture, semIdFin, shmId);
    

    printf("Fin de un\n");
    
    return EXIT_SUCCESS;
}
