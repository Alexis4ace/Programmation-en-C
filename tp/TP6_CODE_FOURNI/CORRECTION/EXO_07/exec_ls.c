#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

int main()
{
    char *lsArgv[4];
    lsArgv[0] = "/bin/ls";
    lsArgv[1] = "-l";
    lsArgv[2] = "-h";
    lsArgv[3] = NULL;

    int ret = execv(lsArgv[0], lsArgv);

    // si on est là, ret vaut obligatoirement -1
    printf("retour de exec : %d (normalement -1)\n", ret);
    perror("Problème exec");
    
    return EXIT_SUCCESS;
}
