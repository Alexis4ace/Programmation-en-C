/*
 * Exercice 1.03
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_03.c -o exo_1_03
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

// Écrire ici la fonction isPalin
// ====== TODO ==========
bool isPalin(char *s1 ){
	int taille1=strlen(s1);
	for(int i=0;i<taille1/2;i++){
		if (s1[i] != s1[taille1-i-1])
			return false ;
	}
	return true;
}	
	

// Écrire ici la fonction isPalinTab
// ====== TODO ==========
bool isPalinTab(char *tab,int n){
	for(int i=0;i<n/2;i++){
		if (tab[i] != tab[n-i-1])
			return false ;
	}
	return true;
}	

int main()
{
    // ------------------------------------------------------------
    title_print("iPalin");
    // appeler isPalin avec les deux chaînes :
    // - "esope reste ici et se repose" : ce n'est pas un palindrome
    // - "esoperesteicietserepose" : c'est un palindrome
    // Pour info voici d'autres palindromes :
    // - "etlamarinevaveniramalte"
    // - "eluparcettecrapule",
    // - "02022020" i.e. le 2 février 2020
    // - "engagelejeuquejelegagne"
    // ====== TODO ==========
    char *s1 = "esope reste ici et se repose";
    char *s2 = "esoperesteicietserepose";
    if(!isPalin(s2))
    	printf("NOT PALIN\n");
    // ------------------------------------------------------------
    title_print("iPalinTab");
    // appeler isPalinTab avec un tableau qui n'est pas un palindrome (par
    // exemple 'b','a','t','e','a','u') puis avec un palindrome (par
    // exemple 'k','a','y','a','k')
    // ====== TODO ==========
	char t[]={'b','a','t','e','a','u'};
	
	if(isPalinTab(t,5))
		printf("palindrome");
    printf("\n");

    return EXIT_SUCCESS;
}
