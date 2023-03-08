/*
 * Exercice 1.03
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_03.c -o exo_1_03
 */
/*
 * ### les commentaires de correction sont précédés par ###
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

// Écrire ici la fonction isPalin
// ====== TODO ==========
// ### je m'autorise des return en plein milieu, même si je ne suis pas fan en général
bool isPalin2(const char *s)
{
    int l = strlen(s);
    for (int i = 0; i < l/2; i++)
    {
        if (s[i] != s[l-i-1])
            return false;
    }
    return true;
}

// voici la version politiquement correcte, mais moins claire je trouve
bool isPalin(const char *s)
{
    int l = strlen(s);
    bool ok = true;
    int i = 0;
    
    while (ok && (i < l/2))
    {
        if (s[i] != s[l-i-1])
            ok = false;
        i ++;
    }
    return ok;
}


// Écrire ici la fonction isPalinTab
// ====== TODO ==========
// ### je m'autorise des return en plein milieu, même si je ne suis pas fan en général
bool isPalinTab2(const char s[], int taille)
{
    for (int i = 0; i < taille/2; i++)
    {
        if (s[i] != s[taille-i-1])
            return false;
    }
    return true;
}

// voici la version politiquement correcte (et moins claire)
bool isPalinTab(const char s[], int taille)
{
    bool ok = true;
    int i = 0;
    
    while (ok && (i < taille/2))
    {
        if (s[i] != s[taille-i-1])
            ok = false;
        i ++;
    }
    return ok;
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
    const char *s1 = "esope reste ici et se repose";
    const char *s2 = "esoperesteicietserepose";
    printf("%s\n", s1);
    if (isPalin(s1))
        printf("    ok\n");
    else
        printf("    pas ok\n");
    printf("%s\n", s2);
    if (isPalin(s2))
        printf("    ok\n");
    else
        printf("    pas ok\n");
    
    // ------------------------------------------------------------
    title_print("iPalinTab");
    // appeler isPalinTab avec un tableau qui n'est pas un palindrome (par
    // exemple 'b','a','t','e','a','u') puis avec un palindrome (par
    // exemple 'k','a','y','a','k')
    // ====== TODO ==========
    // ### pas de '\0' donc il faut passer la taille en paramètre
    // ### je fais avec des mots courts parce que j'ai la flemme
    const char t1[] = {'b', 'a', 't', 'e', 'a', 'u'};
    const char t2[] = {'k', 'a', 'y', 'a', 'k'};
    if (isPalinTab(t1, 6))
        printf("    ok\n");
    else
        printf("    pas ok\n");
    if (isPalinTab(t2, 5))
        printf("    ok\n");
    else
        printf("    pas ok\n");

    printf("\n");

    return EXIT_SUCCESS;
}
