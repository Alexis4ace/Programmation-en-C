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

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("%d + %d = %d\n", a, b, a+b);

    return EXIT_SUCCESS;
}
