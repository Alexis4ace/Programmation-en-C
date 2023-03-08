#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

int main(int argc, char * argv[])
{
    char **lsArgv = malloc((argc+1) * sizeof(char *));
    lsArgv[0] = "/bin/ls";
    for (int i = 1; i < argc; i++)
        lsArgv[i] = argv[i];
    lsArgv[argc] = NULL;

    int ret = execv(lsArgv[0], lsArgv);

    // si on est là, ret vaut obligatoirement -1
    printf("retour de exec : %d (normalement -1)\n", ret);
    perror("Problème exec");
    
    // note : le code ci-après n'est jamais exécuté si le exec est ok
    // notamment le free
    free(lsArgv);

    return EXIT_SUCCESS;
}
