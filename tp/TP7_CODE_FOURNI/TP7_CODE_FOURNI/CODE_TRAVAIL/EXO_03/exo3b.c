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
    // ici il faut déclarer un sémaphore (en mode IPC_PRIVATE) de deux cases
    int sem = semget(IPC_PRIVATE, 2 ,IPC_CREAT | IPC_EXCL | 0641 );
    assert(sem != -1);
    // avec les droits 0641
    // et donc on ne le détruit pas

    return EXIT_SUCCESS;
}
