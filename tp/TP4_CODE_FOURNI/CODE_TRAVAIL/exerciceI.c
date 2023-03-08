#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
// inclure les .h nécessaires
#include <unistd.h>

int main()
{
    // code gracieusement offert
    FILE *fd = fopen("FIC/exoI_test", "w");
    fprintf(fd, "aa\n");
    fprintf(fd, "bb\n");
    fprintf(fd, "cc\n");
    printf("Appuyez sur Ctrl-C\n");
    sleep(10);
    fprintf(fd, "dd\n");
    fclose(fd);

    return EXIT_SUCCESS;
}
