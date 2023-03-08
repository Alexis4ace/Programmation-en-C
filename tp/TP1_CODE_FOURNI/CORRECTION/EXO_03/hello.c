/*
 * Normalement votre programme est quasi-identique à celui-ci
 *
 * Voici les points de discussion :
 * - include
 *    . on ne met que les include strictement nécessaires
 *    . si on n'est pas capable d'expliquer la présence d'un include,
 *      c'est qu'il est inutile et on l'enlève.
 *    . autrement dit on ne met pas d'include par habitude
 *    . "stdio.h" pour le printf
 *    . "stdlib.h" pour le EXIT_SUCCESS
 * - paramètres du main
 *    . pas de paramètre (i.e. pas de argc, argc et envp) car
 *      on ne les utilisent pas
 *    . le prototype "int main(void)" me semble incorrect car il signifie
 *      que la fonction "main" n'a pas de paramètre, or c'est faux puisqu'elle
 *      en a trois
 *    . le prototype "int main()" signifie qu'il y a des paramètres mais
 *      qu'on ne les utilise pas
 *    . (c'est discutable comme analyse)
 *    . le fait de ne pas déclarer tous les paramètres n'a de sens
 *      que pour la fonction "main"
 * - indentation
 *    . elle est obligatoire (c'est une faute professionnelle de ne pas
 *      indenter)
 *    . elle doit être la même partout (3 ou 4 espaces par exemple)
 *    . tabulation ou espaces ? j'ai une préférence pour les espaces
 *      car si un autre programmeur utilise un éditeur qui n'a pas
 *      la même taille de tabulation, la présentation du code peut être
 *      pénible
 * - sauts de lignes
 *    . permet d'aérer le code
 *    . séparer les blocs de code (par exemple, déclarations, initialisations,
 *      vérifications, ...)
 * - EXIT_SUCCESS
 *    . on utilise les constantes nommées lorsqu'elles existent car cela
 *      apporte du sens et facilite la lecture du programme.
 *    . donc pas de "return 0" en fin de main
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello World!\n");

    return EXIT_SUCCESS;
}
