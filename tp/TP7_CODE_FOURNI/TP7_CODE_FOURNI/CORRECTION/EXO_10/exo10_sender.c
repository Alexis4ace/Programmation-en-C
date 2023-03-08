// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "exo10_comm.h"

// création d'une file IPC
static int my_msgget()
{
    key_t key;
    int msgId;

    key = ftok(MON_FICHIER, PROJ_ID);
    assert(key != -1);
    msgId = msgget(key, IPC_CREAT | IPC_EXCL | 0641);
    assert(msgId != -1);

    return msgId;
}

// envoi d'un entier
void my_msgsndInt(int msgId, int v)
{
    MsgInt msg;
    msg.mtype = MSG_INT_TYPE;
    msg.val = v;
    
    int ret = msgsnd(msgId, &msg, MSG_INT_TAILLE, 0);
    assert(ret == 0);
}

// envoi d'un caractère
void my_msgsndChar(int msgId, char v)
{
    MsgChar msg;
    msg.mtype = MSG_CHAR_TYPE;
    msg.val = v;
    
    int ret = msgsnd(msgId, &msg, MSG_CHAR_TAILLE, 0);
    assert(ret == 0);
}

// suppression de la file
static void my_msgDestroy(int msgId)
{
    int ret;
    ret = msgctl(msgId, IPC_RMID, NULL);
    assert(ret != -1);
}


int main()
{
    int msgId;

    // création file
    msgId = my_msgget();
    sleep(1);

    // on envoie différentes valeurs
    my_msgsndInt(msgId, 1);
    my_msgsndInt(msgId, 2);
    my_msgsndChar(msgId, 'A');
    sleep(1);
    my_msgsndInt(msgId, 3);
    my_msgsndInt(msgId, 4);
    my_msgsndChar(msgId, 'B');
    my_msgsndChar(msgId, 'C');
    sleep(2);
    my_msgsndChar(msgId, 'D');
    my_msgsndInt(msgId, 5);
    my_msgsndChar(msgId, '.');    // fin suite char
    my_msgsndInt(msgId, 6);
    my_msgsndInt(msgId, 7);
    sleep(1);
    my_msgsndInt(msgId, -1);      // fin suite int

    // on détruit la file
    // Attention, il faudrait être sûr que les deux autres
    // processus n'utilise plus la file, et pour cela
    // il faudrait un sémaphore
    // On fait plus simple : c'est l'utilisateur qui donne l'ordre
    // de destruction
    printf("Appuyez sur \"Entrée\" pour détruire la file.\n");
    printf("--> ");
    getchar();

    my_msgDestroy(msgId);

    printf("Fin de l'émetteur\n");
    
    return EXIT_SUCCESS;
}
