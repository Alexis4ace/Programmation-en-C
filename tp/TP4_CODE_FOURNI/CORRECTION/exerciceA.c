// pour des problèmes de compilation
#define _XOPEN_SOURCE 700

#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
// inclure les .h nécessaires (cf. manuel)
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int i = 13;
    
    // avec open, dprintf et close, créer le fichier "FIC/exoA_1_test" et écrire l'entier 12 dedans
    int fd1 = open("FIC/exoA_1_test", O_CREAT|O_WRONLY, 0644);
    dprintf(fd1, "%d", i);
    close(fd1);
  
    // avec open, write et close, créer le fichier "FIC/exoA_2_test" et écrire l'entier 12 dedans
    int fd2 = open("FIC/exoA_2_test", O_CREAT|O_WRONLY, 0644);
    write(fd2, &i, sizeof(int));
    close(fd2);

    // avec fopen, fprintf et fclose, créer le fichier "FIC/exoA_3_test" et écrire l'entier 12 dedans
    FILE * fd3 = fopen("FIC/exoA_3_test", "w");
    fprintf(fd3, "%d", i);
    fclose(fd3);
    
    // avec fopen, fwrite et fclose, créer le fichier "FIC/exoA_4_test" et écrire l'entier 12 dedans
    FILE * fd4 = fopen("FIC/exoA_4_test", "w");
    fwrite(&i, sizeof(int), 1, fd4);
    fclose(fd4);
    
    return EXIT_SUCCESS;
}
