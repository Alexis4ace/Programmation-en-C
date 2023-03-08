// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
    // ici il faut déclarer un sémaphore (en mode IPC_PRIVATE) de deux cases
    // avec les droits 0641
    // et on le détruit cette fois-ci

    int semId;

    // le IPC_CREAT|IPC_EXCL n'est pas utile avec IPC_PRIVATE mais c'est plus clair
    semId = semget(IPC_PRIVATE, 2, IPC_CREAT | IPC_EXCL | 0641);
    assert(semId != -1);

    // le second paramètre est ignoré avec IPC_RMID, normalemet c'est le numéro
    //      du sémaphore (semId désigne un tableau de sémaphores). On met -1 pour
    //      montrer clairement qu'on ne l'utilise pas
    // le 4e paramètre est aussi ignoré : on ne le met pas
    int ret = semctl(semId, -1, IPC_RMID);
    assert(ret != -1);

    return EXIT_SUCCESS;
}
