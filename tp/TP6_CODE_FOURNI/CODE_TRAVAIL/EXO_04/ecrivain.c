#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
// inclure les .h manquants
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
static void usage(const char *exeName, const char *message)
{
    fprintf(stderr, "usage : %s <nom tube>\n", exeName);
    if (message != NULL)
        fprintf(stderr, "message : %s\n", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
    if (argc != 2)
        usage(argv[0], NULL);
	
    // ouvrir avec "open" le tube en écriture (ne pas oublier le assert)
    // (note : le tube doit exister avant le lancement du programme)
    //todo
    //int res = mkfifo(argv[1],0644);
    //assert(res ==0);
    //printf("fifo reussis\n"); 
    int fdA = open(argv[1], O_WRONLY);
    int res;
    assert(fdA != -1);
    printf("fdA open \n");

    printf("Le tube est ouvert en écriture\n");

    printf("Saisissez des caractères. '!' pour terminer\n");

    while(true)
    {
        char c = getchar();
        if (c == '!')
            break;
        else{
            res = write(fdA,&c,1);
            assert(res == sizeof(char));
        }
        // écrire dans le tube (avec un assert)
        //todo
    }
    printf("je sort");
   
    close(fdA);
    
    // il ne faut pas oublier qqch ici
    // todo
    
    return EXIT_SUCCESS;
}
