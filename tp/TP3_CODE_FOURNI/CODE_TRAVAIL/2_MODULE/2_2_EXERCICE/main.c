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
    imagePixel *img = NULL ;
	img = init_image(20,30,"vert") ;
	printf("%d - %d  - %s\n",recup_largeur(img),recup_hauteur(img),recup_color(img));
	free(img);
    return EXIT_SUCCESS;
}
