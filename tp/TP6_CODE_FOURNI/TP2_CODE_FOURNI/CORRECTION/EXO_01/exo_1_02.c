/*
 * Exercice 1.02
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_02.c -o exo_1_02
 */
/*
 * ### les commentaires de correction sont précédés par ###
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"


int main()
{
    // ------------------------------------------------------------
    // les déclarations de l'énoncé
    const char *s1 = "chien";
    char s2[] = "chiot";

    // ------------------------------------------------------------
    title_print("Modification de s1");
    printf("s1 avant : %s\n", s1);
    s1 = "cheval";
    printf("s1 après : %s\n", s1);
    // Explication
    // ====== TODO ==========
    // ### il n'y a pas de modification de chaîne, c'est s1 qui pointe
    // ### sur une autre chaîne (littérale et constante elle aussi)
    // ### Donc l'affection concerne le pointeur et non la chaîne, ce qui est
    // ### tout à fait correct.
    // ### Il faut noter que, dans le cas ci-dessus, s1 pointe sur une chaîne
    // ### non mutable que l'on ne peut donc pas modifier.

    // ------------------------------------------------------------
    title_print("Modification de s1 ou *s1");
    // s2 = "rat";
    // Explication
    // ====== TODO ==========
    // ### Techniquement c'est incorrect car s2 est considéré comme un pointeur constant
    // code pour réaffecter la chaîne
    // ====== TODO ==========
    // ### il faut utiliser les fonctions standard (ou les récrire)
    printf("s2 avant : %s\n", s2);
    strcpy(s2, "rat");
    printf("s2 après : %s\n", s2);
    // ### cf. cas ci-dessous sur les précautions à prendre
  
    // ------------------------------------------------------------
    title_print("Modification de s1 ou *s1 (suite)");
    // s2 = "cheval";
    // Explication
    // ====== TODO ==========
    // ### cf. ci-dessus pour expliquer le fait que le code est incorrect
    // strcpy(s2, "cheval");
    // Expliquez pourquoi c'est incorrect
    // ====== TODO ==========
    // ### peut pas faire de strcpy car s2 contient 6 cases et qu'on essaie
    // ### d'en modifier 7 (les 6 de "cheval" et le '\0'). Cela ferait
    // ### un buffer overflow qui est généralement source de catastrophe.
    // ### Essayez de compiler l'instruction : j'ai un joli warning
    // ### En revanche l'exécution ne pose pas de problème mais c'est de la
    // ### chance : on a mis un 0 (un '\0') dans l'octet après le tableau s2 et
    // ### il pourrait y avoir à cet endroit, par exemple, une autre variable
    // ### du programme.

    printf("\n");

    return EXIT_SUCCESS;
}
