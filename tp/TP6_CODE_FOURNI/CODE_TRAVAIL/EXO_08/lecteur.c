#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>

static void usage(const char *exeName, const char *message)
{
    fprintf(stderr, "usage : %s <fd>\n", exeName);
    if (message != NULL)
        fprintf(stderr, "message : %s\n", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
    if (argc != 2)
        usage(argv[0], NULL);

    printf("    [fils] Je suis le fils %d (après exec)\n", getpid());
    int fd = *argv[1],test;
    int a,b;
    // Lire, dans le file descriptor contenu dans argv[1] deux entiers en
    test = read(fd,&a,sizeof(int));
    assert(test != -1);
    test = read(fd,&b,sizeof(int));
    assert(test != -1);
    // mode binaire (toujours avec des assert)
    //todo
    printf("La somme est %d ", a+b);
    // ne pas oublier de fermer le file descriptor
    //todo

    // afficher la somme
    //todo

    return EXIT_SUCCESS;
}
