/*
 * Exercice 2.01
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_2_01.c -o exo_2_01
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"


// Écrire ici la fonction strClone
// ====== TODO ==========
char *strClone(const char *src,int n){
	char *temp;
	temp = malloc(sizeof(char) * (n +1) );
	for(int i=0;i<n;i++){
		temp[i]=src[i];
	}
	temp[n]='\0';
	return temp;
}
int main()
{
    title_print("clone");

    // ne décommenter qu'une seule définition
    const char *source = "Tu vois, le monde se divise en deux catégories, "
        "ceux qui ont un pistolet chargé et ceux qui creusent."
        " Toi, tu creuses.";
    //const char *source = "aa\nbb";
    //const char *source = "";
    //const char *source = "aa\0bb";    // exemple curieux
    
    printf("source : \"%s\"\n", source);
	char *cpy;
	cpy = strClone(source,strlen(source));
	printf("LA copie : %s \n", cpy);
    // déclarer la chaîne qui va recevoir la copie, faire la copie
    // et l'afficher.
    // ====== TODO ==========

    // il y a sûrement quelque chose à faire ici ?
    // ====== TODO ==========

    printf("\n");

    return EXIT_SUCCESS;
}
