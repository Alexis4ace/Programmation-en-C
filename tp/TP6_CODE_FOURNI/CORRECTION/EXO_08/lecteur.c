#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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

    int a, b;
    int fd = atoi(argv[1]);
    int ret;

    ret = read(fd, &a, sizeof(int));
    assert(ret == sizeof(int));
    ret = read(fd, &b, sizeof(int));
    assert(ret == sizeof(int));

    close(fd);

    printf("    [fils] %d + %d = %d\n", a, b, a+b);

    return EXIT_SUCCESS;
}
