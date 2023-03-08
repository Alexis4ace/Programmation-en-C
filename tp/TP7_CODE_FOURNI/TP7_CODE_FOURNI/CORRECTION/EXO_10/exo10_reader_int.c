// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "exo10_comm.h"

// récupérer la file IPC
static int my_msgget()
{
    key_t key;
    int msgId;

    key = ftok(MON_FICHIER, PROJ_ID);
    assert(key != -1);
    msgId = msgget(key, 0);
    assert(msgId != -1);

    return msgId;
}

// lecture d'un message
int my_msgrvcInt(int msgId)
{
    MsgInt msg;
    msg.mtype = -1;
    int ret;
    
    ret = msgrcv(msgId, &msg, MSG_INT_TAILLE, MSG_INT_TYPE, 0);
    assert(ret == MSG_INT_TAILLE);
    assert(msg.mtype == MSG_INT_TYPE);
    
    return msg.val;
}


int main()
{
    int msgId;

    // récupération de la file
    msgId = my_msgget();

    // réception des valeurs
    while (true)
    {
        int v = my_msgrvcInt(msgId);
        if (v == -1)
            break;
        printf("J'ai reçu %d\n", v);
    }

    // pas de destruction de la file

    printf("Fin du récepteur d'entiers\n");
    
    return EXIT_SUCCESS;
}
