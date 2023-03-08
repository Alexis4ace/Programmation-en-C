#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
    // construire le tableau d'arguments à passer dans le execv
    char *s[4];
    s[0]="/bin/ls";
    s[1]="-l";
    s[2]="-h";
    s[3]=NULL;
    // donc les arguments sont "-l" et "-h"
    //todo
    int ret = execv(s[0],s);
    // appeler execv avec "/bin/ls"
    
    //todo
    
    // si on est là, execv obligatoirement renvoyé -1
    printf("retour de exec : %d (normalement -1)\n", ret);
    perror("Problème exec");
    
    return EXIT_SUCCESS;
}
