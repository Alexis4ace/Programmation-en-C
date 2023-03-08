/*
 * Exercice 1.02
 * compilation :
 *   $ make 1_2_exercice
 */
/*
 * ### les commentaires de correction sont précédés par ###
 */

#include <stdio.h>
#include <stdlib.h>

// Donc à part montrer la différence entre déclaration
// et définition, ce code est n'importe quoi

void afficheN(int n, const char *msg);  // déclaration
void afficheN(int n, const char *msg);  // déclaration

void afficheN(int n, const char *msg)   // définition
{
    for (int i = 0; i < n; i ++)
        printf("%s\n", msg);
}

void afficheN(int n, const char *msg);  // déclaration

int main()
{
    void afficheN(int n, const char *msg);  // déclaration
    afficheN(3, "Bonjour");                 // appel
    
    return EXIT_SUCCESS;
}
