// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include "exo7_comm.h"

const int MIN_SECONDES = 3;
const int MAX_SECONDES = 9;


//-----------------------------------------------------------------
// Il faut récupérer le sémaphore avec une clé générée par ftok et le
// le fichier fourni dans exo7_comm.h
// Il faut être rigoureux : le sémaphore doit déjà exister sinon
//      c'est une erreur
static int my_semget()
{
    key_t key;
    int semId;

    key = ftok(MON_FICHIER, PROJ_ID);
    assert(key != -1);
    // le flag (3me paramètre) doit absolument être à 0
    semId = semget(key, 1, 0);
    assert(semId != -1);
    // et donc pas d'initialisation

    return semId;
}

//-----------------------------------------------------------------
// Le code doit attendre tous les autres workers
static void my_barriere(int semId)
{
    int ret;
    // paramètres : num sépamhore, opération, flags
    struct sembuf operationMoins = {0, -1, 0};
    struct sembuf operationAttente = {0, 0, 0};
    ret = semop(semId, &operationMoins, 1);
    assert(ret != -1);
    ret = semop(semId, &operationAttente, 1);
    assert(ret != -1);
}


//-----------------------------------------------------------------
int main()
{
    int tempsAttente;
    int semId;

    // initialisation générateur aléatoire    
    srand(getpid());

    // récupération du sémaphore
    semId = my_semget();

    // simule la 1re partie du code
    tempsAttente = MIN_SECONDES + rand() % (MAX_SECONDES - MIN_SECONDES + 1);
    printf("1re partie : je bosse pendant %d seconde(s)\n", tempsAttente);
    printf("             Zzz...\n");
    sleep(tempsAttente);
    printf("             j'ai fini.\n");

    printf("\n");
    printf("J'attends les autres\n");
    
    // appel de la fonction implémentant la barrière
    my_barriere(semId);

    printf("\n");
    printf("Tout le monde a franchi la barrière\n");
    printf("\n");

    // simule la 2me partie du code
    tempsAttente = 1 + rand() % MIN_SECONDES;
    printf("2me partie : je bosse pendant %d seconde(s)\n", tempsAttente);
    printf("             Zzz...\n");
    sleep(tempsAttente);
    printf("             j'ai fini.\n");

    printf("\n");
    printf("Fin du worker\n");
    
    return EXIT_SUCCESS;
}
