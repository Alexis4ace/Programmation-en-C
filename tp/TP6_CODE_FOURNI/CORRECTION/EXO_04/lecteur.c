#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
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

    // ouvrir avec "open" le tube en lecture (ne pas oublier le assert)
    // (note : le tube doit exister avant le lancement du programme)
    //todo
    fd = open(argv[1], O_RDONLY);
    assert(fd != -1);
    printf("Le tube est ouvert en lecture\n");

    while(true)
    {
        // lire un caractère en testant si l'écrivain s'est terminé (et sortir
        // de la boucle dans ce cas ; cf. "man read") et afficher le caractère
        // todo
        char c;
        ret = read(fd, &c, sizeof(char));
        assert((ret == sizeof(char)) || (ret == 0));

        // si ret == 0, c'est que tous les écrivains ont fermé leur tube
        // et on décide de s'arrêter (on pourrait aussi réouvrir
        // le tube pour un futur écrivain)
        if (ret == 0)
        {
            printf("Fin lecture\n");
            break;
        }
        putchar(c);
    }

    // il ne faut pas oublier qqch ici
    // todo
    close(fd);
    
    return EXIT_SUCCESS;
}
