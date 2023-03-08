#include <stdio.h>
#include <stdlib.h>

static void usage(const char *exeName, const char *message)
{
    fprintf(stderr, "usage : %s <n1> <n2>\n", exeName);
    if (message != NULL)
        fprintf(stderr, "message : %s\n", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
    if (argc != 3)
        usage(argv[0], NULL);
    printf("argv 1 %d \n",*argv[1]);
    printf("argv 2 %d \n",*argv[2]);
    printf( "La somme est egal a =%d  \n",*argv[1]+*argv[2] );
    // il faut affichier la somme de argv[1] et de argv[2]
    //todo

    return EXIT_SUCCESS;
}
