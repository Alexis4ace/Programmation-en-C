#ifndef EXO10_COMM
#define EXO10_COMM

/**************************************************************************
 * données pour ftok
 **************************************************************************/
// fichier (qui doit être accessible) choisi pour l'identification de la file
#define MON_FICHIER "exo10_comm.h"

// identifiants pour le deuxième paramètre de ftok
#define PROJ_ID 5


/**************************************************************************
 * données pour les messages d'entiers
 **************************************************************************/
// type struct
typedef struct
{
    long mtype;
    int val;
} MsgInt;

// taille (pour shmsnd)
#define MSG_INT_TAILLE  (sizeof(MsgInt) - sizeof(long))

// valeur du type de messages
#define MSG_INT_TYPE   5

/**************************************************************************
 * données pour les messages de char
 **************************************************************************/
// type struct 
typedef struct
{
    long mtype;
    char val;
} MsgChar;

#define MSG_CHAR_TAILLE  (sizeof(MsgChar) - sizeof(long))

// valeur du type de messages
#define MSG_CHAR_TYPE   9

#endif
