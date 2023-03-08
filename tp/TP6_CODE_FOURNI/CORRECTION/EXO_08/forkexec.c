#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

void pere(int fdWrite)
{
    printf("[père] Je suis le père %d (avant exec)\n", getpid());

    char s[1000];
    char *argv[3];

    sprintf(s, "%d", fdWrite);
    argv[0] = "ecrivain";
    argv[1] = s;
    argv[2] = NULL;

    execv(argv[0], argv);
    perror("pb exec pere");
}

void fils(int fdRead)
{
    printf("    [fils] Je suis le fils %d (avant exec)\n", getpid());

    char s[1000];
    char *argv[3];

    sprintf(s, "%d", fdRead);
    argv[0] = "lecteur";
    argv[1] = s;
    argv[2] = NULL;

    execv(argv[0], argv);
    perror("pb exec fils");
}


int main()
{
    int pereToFils[2];
    int ret;
    pid_t retFork;

    ret = pipe(pereToFils);
    assert(ret == 0);

    retFork = fork();
    assert(retFork != -1);

    if (retFork == 0)
    {
        close(pereToFils[1]);
        fils(pereToFils[0]);

        // on n'arrive jamais ici normalement
        close(pereToFils[0]);
        assert(false);
    }
    else
    {
        close(pereToFils[0]);
        pere(pereToFils[1]);
        
        // on n'arrive jamais ici normalement
        close(pereToFils[1]);
        assert(false);
    }

    // on n'arrive jamais ici normalement
    printf("PB ! Fin processus %d\n", getpid());
    
    return EXIT_SUCCESS;
}
