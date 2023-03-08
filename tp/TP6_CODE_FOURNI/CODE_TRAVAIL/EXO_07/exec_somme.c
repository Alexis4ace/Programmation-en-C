#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

int main()
{
    int a, b;
    
    printf("entrez a et b : ");
    scanf("%d %d", &a, &b);
    char ca[100],cb[100];
   
    sprintf(ca,"%c",a);

    sprintf(cb,"%c",b);
    char *s[4];
    s[0]="somme";
    s[1]=ca;
    s[2]=cb;
    s[3]=NULL;
    // faites un execv sur le programme "somme" en lui passant les deux valeurs en paramètres
    // note : vous avez besoin de transformer les deux entiers en chaînes, vous pouvez,
    //        pour simplifier le code, déclarer end dur des chaînes surdimensionnées.
    //todo
     printf("je lance execv\n");
    execv(s[0],s);
     // si on est là, execv obligatoirement renvoyé -1
    perror("Problème exec");

    return EXIT_SUCCESS;
}
