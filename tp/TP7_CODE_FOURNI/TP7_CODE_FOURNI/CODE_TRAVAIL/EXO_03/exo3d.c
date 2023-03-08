// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <assert.h>
// mettre les bons includes

int main()
{
    int sem = semget(IPC_PRIVATE, 2 ,IPC_CREAT | IPC_EXCL | 0641 );
    assert(sem != -1);
    sem = semctl(sem,-1,IPC_RMID);
    assert(sem != -1);
    // ici il faut déclarer un sémaphore (en mode IPC_PRIVATE) de deux cases
    // avec les droits 0641
    // et on le détruit cette fois-ci

    return EXIT_SUCCESS;
}
