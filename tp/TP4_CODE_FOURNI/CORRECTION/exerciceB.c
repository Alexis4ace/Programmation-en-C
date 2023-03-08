#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
// inclure les .h nécessaires

// on utilise les fonctions fopen, fwrite et fclose

int main()
{
    int n1 = 1952540739;
    int n2 = 1130914164;

    printf("valeur hexa de n1 (%d) : %x\n", n1, n1);
    printf("valeur hexa de n2 (%d) : %X\n", n2, n2);
    printf ("\n");

    // créer le fichier "exoB_1_test" et écrire dedans en binaire (avec fwrite) le nombre n1
    FILE * fd1 = fopen("FIC/exoB_1_test", "w");
    fwrite(&n1, sizeof(int), 1, fd1);
    fclose(fd1);

    // créer le fichier "exoB_2_test" et écrire dedans en binaire (avec fwrite) le nombre n2
    FILE * fd2 = fopen("FIC/exoB_2_test", "w");
    fwrite(&n2, sizeof(int), 1, fd2);
    fclose(fd2);

    // pour vérifier sur le premier fichier
    int c;
    printf("valeur hexa de %d : %x\n", n1, n1);
    printf("Et en code ascii on a : \n");
    c = (n1 & 0xFF000000) >> 24;
    printf("   0x%2x : %c\n", c, c);
    c = (n1 & 0x00FF0000) >> 16;
    printf("   0x%2x : %c\n", c, c);
    c = (n1 & 0x0000FF00) >> 8;
    printf("   0x%2x : %c\n", c, c);
    c = (n1 & 0x000000FF) >> 0;
    printf("   0x%2x : %c\n", c, c);
    printf("Et on est en little endian\n");
    
    return EXIT_SUCCESS;
}
