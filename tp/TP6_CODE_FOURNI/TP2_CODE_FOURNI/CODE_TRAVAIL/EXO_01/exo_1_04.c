/*
 * Exercice 1.04
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_04.c -o exo_1_04
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

// Écrire ici la fonction mirror
// ====== TODO ==========
void miroir(char s[],int n){
	char temp[]=" ";
	for(int i=0;i<n/2;i++){
		temp[0]=s[i];
		s[i]=s[n-1-i];
		s[n-1-i]=temp[0];
	}
}	

int main()
{
    title_print("mirror");

    char s[] = "il fait beau !";  // "char *" est incorrect ! Pourquoi ?
                                  // Parce qu'on va modifier la chaine

    printf("Voici la chaîne avant retournement : \"%s\" (%ld)\n", s, strlen(s));
    // appeler ici la fonction mirror
    // ====== TODO ==========
    miroir( s , strlen(s) );
    printf("Voici la chaîne après retournement : \"%s\" (%ld)\n", s, strlen(s));
    
    printf("\n");

    return EXIT_SUCCESS;
}
