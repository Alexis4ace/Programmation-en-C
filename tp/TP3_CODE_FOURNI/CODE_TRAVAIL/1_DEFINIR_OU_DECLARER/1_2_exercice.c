/*
 * Exercice 1.02
 * compilation :
 *   $ make 1_2_exercice
 */

#include <stdio.h>
#include <stdlib.h>

// Donc à part montrer la différence entre déclaration
// et définition, ce code est n'importe quoi

// déclarer afficheN
extern void afficheN(char txt[],int N);
// ====== TODO ==========

// déclarer afficheN
// ====== TODO ==========
extern void afficheN(char txt[],int N);
// définir afficheN
// ====== TODO ==========
void afficheN(char txt[],int N){
	for(int i=0; i<N ; i++)
		printf(" %s \n",txt);
}
// déclarer afficheN
extern void afficheN(char txt[],int N);
// ====== TODO ==========

int main()
{
    // déclarer afficheN
    // ====== TODO ==========
    extern void afficheN(char txt[],int N);
    // todo

    // appeler afficheN pour afficher 3 fois "Bonjour"
    // ====== TODO ==========
    afficheN("Bonjour",3);
    return EXIT_SUCCESS;
}
