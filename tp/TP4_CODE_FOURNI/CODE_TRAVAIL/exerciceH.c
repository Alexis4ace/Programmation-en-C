#define _XOPEN_SOURCE 700   // pour dprintf

#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
// inclure les .h nécessaires
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    // code gracieusement offert
    int fd = open("FIC/exoH_test", O_CREAT|O_WRONLY, 0644);
    dprintf(fd, "AA\n");
    dprintf(fd, "BB\n");
    dprintf(fd, "CC\n");
    printf("Appuyez sur Ctrl-C\n");
    sleep(10);
    dprintf(fd, "DD\n");
    close(fd);

    return EXIT_SUCCESS;
}
