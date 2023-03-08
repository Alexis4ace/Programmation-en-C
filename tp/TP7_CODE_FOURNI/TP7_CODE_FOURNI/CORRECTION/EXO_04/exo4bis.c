// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

void un(int semId)
{
    sleep(3);
    printf("Processus un   %d ! (normalement je m'affiche en premier)\n", getpid());
    
    // ici il faut débloquer le processus "deux"
    int ret;
    // champs : num sémaphore, opération, flags
    struct sembuf operation = {0, 1, 0};
    // c'est normalement un tableau d'opérations qu'on passe, le dernier
    // paramètre indique que le tableau ne fait qu'une case (ça marche car
    // il n'y a pas de différence entre un pointeur sur une variable et un
    // pointeur sur un tableau à une case).
    ret = semop(semId, &operation, 1);
    assert(ret != -1);
}

void deux(int semId)
{
    // ici il faut attendre le déblocage venant de "un"
    int ret;
    // champs : num sépamhore, opération, flags
    struct sembuf operation = {0, -1, 0};
    // cf. ci-dessus
    ret = semop(semId, &operation, 1);
    assert(ret != -1);
    
    printf("Processus deux %d ! (normalement je m'affiche en dernier)\n", getpid());

    printf("Fin de deux (%d)\n", getpid());
    exit(EXIT_SUCCESS);  // pour éviter de revenir dans le main
}

int main()
{
    // ici il faut déclarer un sémaphore (en mode IPC_PRIVATE) et l'initialiser
    // voyez-vous pourquoi il faut créer le sémaphore ici et non pas
    // dans les fonctions un et deux ?
    // réponse : si on fait la création après le fork, chaque processus aura son
    //           son propre sémaphore : les deux sémaphores seront indépendants

    int semId;
    pid_t retFork;
    int ret;

    // le IPC_CREAT|IPC_EXCL n'est pas utile avec IPC_PRIVATE
    semId = semget(IPC_PRIVATE, 1, IPC_CREAT | IPC_EXCL | 0641);
    assert(semId != -1);
    // puis initialisation
    // - 2me paramètre (i.e. 0) : numéro du sémaphore
    // - 4me paramètre (i.e. 0) : valeur du sémaphore
    ret = semctl(semId, 0, SETVAL, 0);
    assert(ret != -1);

    retFork = fork();
    assert(retFork != -1);
    if (retFork != 0)
        un(semId);
    else
        deux(semId);

    // seul le père passe par ici

    // attente de la fin du fils
    wait(NULL);

    // ici il faut détruire le sémaphore
    // chaque processus doit-il le détruire ?
    // sinon qui doit s'en charger ?
    // réponse : il faut le détruire une seule fois (c'est assez logique)
    //           c'est le dernier se terminant (le père donc) qui doit
    //           le faire, comme cela on est sûr que personne ne l'utilise :
    //           en effet le père attend la fin du fils (wait) est reste
    //           le seul à utiliser le sémaphore.
    //           Si on détruit un sémaphore alors qu'un autre processus
    //           l'utilise, ce dernier plante (contrairement aux tubes nommés).
    ret = semctl(semId, -1, IPC_RMID);
    assert(ret != -1);

    printf("Fin de un   (%d)\n", getpid());
    
    return EXIT_SUCCESS;
}
