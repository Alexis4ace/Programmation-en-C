#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/wait.h>

void pere(int fdWrite, int fdRead)
{
    printf("Je suis le père %d\n", getpid());

    int a, b, somme;
    int ret;

    printf("entrez deux entiers : ");
    scanf("%d %d", &a, &b);
    ret = write(fdWrite, &a, sizeof(int));
    assert(ret == sizeof(int));
    ret = write(fdWrite, &b, sizeof(int));
    assert(ret == sizeof(int));
    ret = read(fdRead, &somme, sizeof(int));
    assert(ret == sizeof(int));

    printf("La somme est : %d\n", somme);
}

void fils(int fdWrite, int fdRead)
{
    printf("    Je suis le fils %d\n", getpid());

    int a, b, somme;
    int ret;
    
    ret = read(fdRead, &a, sizeof(int));
    assert(ret == sizeof(int));
    ret = read(fdRead, &b, sizeof(int));
    assert(ret == sizeof(int));
    somme = a + b;
    ret = write(fdWrite, &somme, sizeof(int));
    assert(ret == sizeof(int));
}


int main()
{
    int pereToFils[2];
    int filsToPere[2];
    int ret;
    pid_t retFork;

    ret = pipe(pereToFils);
    assert(ret == 0);
    ret = pipe(filsToPere);
    assert(ret == 0);

    retFork = fork();
    assert(retFork != -1);

    if (retFork == 0)
    {
        close(pereToFils[1]);
        close(filsToPere[0]);
        fils(filsToPere[1], pereToFils[0]);
        close(pereToFils[0]);
        close(filsToPere[1]);
    }
    else
    {
        close(pereToFils[0]);
        close(filsToPere[1]);
        pere(pereToFils[1], filsToPere[0]);
        close(pereToFils[1]);
        close(filsToPere[0]);
        
        ret = wait(NULL);
        assert(ret != -1);
    }

    printf("fin processus %d\n", getpid());
    
    return EXIT_SUCCESS;
}
