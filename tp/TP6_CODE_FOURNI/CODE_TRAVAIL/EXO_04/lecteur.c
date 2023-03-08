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

    // ouvrir avec "open" le tube en lecture (ne pas oublier le assert)
    int fdB = open(argv[1],O_RDONLY);
    int res;
    assert(fdB!=-1);
    // (note : le tube doit exister avant le lancement du programme)
    //todo

    while(true)
    {
    	char c ;
    	res = read(fdB,&c,1);
    	assert((res == sizeof(char)) || (res == 0));
    	if(res == 0)
    	     break;
    	putchar(c);
        // lire un caractère en testant si l'écrivain s'est terminé (et sortir
        // de la boucle dans ce cas ; cf. "man read") et afficher le caractère
        // todo
    }
    close(fdB);
    // il ne faut pas oublier qqch ici
    // todo
    
    return EXIT_SUCCESS;
}
