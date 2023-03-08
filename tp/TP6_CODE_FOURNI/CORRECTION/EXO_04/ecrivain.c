#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
// inclure les .h manquants
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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

    int fd;
    int ret;
    
    // ouvrir avec "open" le tube en écriture (ne pas oublier le assert)
    // (note : le tube doit exister avant le lancement du programme)
    //todo
    fd = open(argv[1], O_WRONLY);
    assert(fd != -1);

    printf("Le tube est ouvert en écriture\n");

    printf("Saisissez des caractères. '!' pour terminer\n");

    while(true)
    {
        char c = getchar();
        if (c == '!')
            break;
        // écrire dans le tube (avec un assert)
        //todo
        ret = write(fd, &c, sizeof(char));
        assert(ret == sizeof(char));
    }

    // il ne faut pas oublier qqch ici
    //todo
    close(fd);
    
    return EXIT_SUCCESS;
}
