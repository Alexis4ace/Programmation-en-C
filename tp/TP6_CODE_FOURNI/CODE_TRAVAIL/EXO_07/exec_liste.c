#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	
    // construire le tableau d'arguments à passer dans le execv
    // donc les arguements sont "-l" et "-h"
    //todo
    char *s[4];
    s[0]="liste_arguments";
    s[1]="-l";
    s[2]="-h";
    s[3]=NULL;
 
    int ret = execv(s[0],s);
    

    printf("retour de exec : %d (normalement -1)\n", ret);
    perror("Problème exec");

    // appeler execv avec "liste_arguments"
    //todo
    
    // si on est là, execv obligatoirement renvoyé -1
    perror("Problème exec");
    
    return EXIT_SUCCESS;
}
