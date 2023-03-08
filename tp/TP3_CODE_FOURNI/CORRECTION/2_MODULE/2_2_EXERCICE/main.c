/*
 * Exercice 2.02
 * compilation :
 *   $ make main.o     # ne génère que le .o
 * ou :
 *   $ make main       # génère l'exécutable (et les .o)
 */
/*
 * ### les commentaires de correction sont précédés par ###
 */

#include <stdio.h>
#include <stdlib.h>

// sûrement quelque chose à faire ici
// ====== TODO ==========
#include "ImageMono.h"

int main()
{
    // déclaration et initialisation de l'image
    // changement de la couleur
    // affichage des caractéristiques
    // ====== TODO ==========

    ImageMono im;

    im_init(&im, 20, 30, "bleu");
    im_setCouleur(&im, "vert");
    printf("(%d, %d) : %s\n", im_getLargeur(&im), im_getHauteur(&im), im_getCouleur(&im));
    //## Le problème (cf. .h) est qu'on a ici accès directement au contenu
    //## de la structure (i.e. sans passer par les méthodes) et qu'on peut
    //## modifier la hauteur ou la largeur alors que c'est interdit.
    //## Dans un langage objet ces attributs seraient "private" et il
    //## n'y aurait plus de problème.
    //## En C on peut utiliser l'abstraction pointeur pour pallier ce problème.

    return EXIT_SUCCESS;
}
