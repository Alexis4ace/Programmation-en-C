/*
 * Exercice 1.01
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_01.c -o exo_1_01
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

void affichage_C(char C){
    printf("%c",C);
}
void affichage_chaine(char *s1){
    int i=0;
    while(i != 5){
    	affichage_C(*(s1+i)); 
    	i++;
    }
    printf("\n");
}
void affichage_chainev2(char s2[]){
    int i=0;
    while(s2[i]!='\0'){
    	affichage_C(s2[i]);
    	i++;
    }
    printf("\n");
}
int main()
{
    // ------------------------------------------------------------
    // les déclarations de l'énoncé
    char c = 'A';
    char *s1 = "chien";
    char s2[] = "chiot";
    char t[] = {'c', 'h', 'o', 'u', 'x'};

    // ------------------------------------------------------------
    // Affichage des 4 variables
    title_print("Affichage des 4 variables");
    // ====== TODO ==========
    affichage_C(c);	
    printf("\n");
    affichage_chainev2(s1);
    affichage_chainev2(s2);
    affichage_chainev2(t);
    // ------------------------------------------------------------
    // Utilisation de strlen
    title_print("strlen or not strlen, this is the question");
    // ====== TODO ==========
    printf("VALUER : \n");
    printf(" %ld \n",strlen(&c) );
    printf(" %ld \n",strlen(s1));
    printf(" %ld \n",strlen(s2));
    printf(" %ld \n",strlen(t));
    // ------------------------------------------------------------
    // Quelle est la différence en s1 et s2 ?
    title_print("différence entre s1 et s2");
    //*(s1+3)='P';
    s2[3]='p';
    affichage_chainev2(s1);
    affichage_chainev2(s2);
    // explications
    // ====== TODO ==========
	//s1 pointe sur une chaine en memoire uniquement en lecture alors que s2 va la copier pour pouvoir la modifier 
	
    // Modifier la 4me lettre de s1
    // ====== TODO ==========
    
    // Modifier la 4me lettre de s2
    // ====== TODO ==========

    // ------------------------------------------------------------
    // Combien de cases
    // ====== TODO ==========

    // ------------------------------------------------------------
    // Remplacer la 3me lettre (le i) de s2 '\0'
    title_print("longueur vs. nombre de cases");
    // ====== TODO ==========
	s2[2]= '\0' ;
	affichage_chainev2(s2);
	printf(" %ld \n",strlen(s2));
    // ------------------------------------------------------------
    // peut-on appeler strlen sur une chaîne littérale ?
    title_print("strlen sur une chaîne littérale");
    // ====== TODO ==========
	printf(" %ld \n",strlen("yolo"));
    printf("\n");

    return EXIT_SUCCESS;
}
