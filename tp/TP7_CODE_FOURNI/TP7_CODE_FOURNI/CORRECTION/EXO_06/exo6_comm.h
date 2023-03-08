#ifndef EXO6_COMM
#define EXO6_COMM

// fichier (qui doit être accessible) choisi pour l'identification du sémaphore
#define MON_FICHIER "exo6_comm.h"

// identifiant pour le deuxième paramètre de ftok
#define PROJ_ID 5

#endif

/*
 * Question : pourquoi "/tmp" n'est pas une bonne valeur pour MON_FICHIER ?
 * rq : le fait que ce soit un répertoire n'est pas un problème
 * réponse : parce que un autre utilisateur pourrait aussi le choisir et
 *           donc générerait la même clé et référencerait le même sémaphore.
 *           On aurait des programme qui plantent sans savoir pourquoi.
 *           Il est préférable de prendre un fichier un fichier de sa propre
 *           arborescence (et encore mieux dans un répertoire avec accès
 *           restreint pour être sûr qu'un autre utilisateur ne le choisisse pas).
 */
