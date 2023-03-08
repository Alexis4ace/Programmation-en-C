/*
 * Exercice 2.02
 * compilation :
 *   $ make ImageMono.o     # ne génère que le .o
 */
/*
 * ### les commentaires de correction sont précédés par ###
 */

#include <string.h>

// une inclusion à faire ici
#include <ImageMono.h>
// ====== TODO ==========

// constructeur
// ====== TODO ==========
imagePixel* init_image(int l,int h,char *c){
	imagePixel *newImg;
	newImg = malloc(sizeof(struct image) );
	newImg->largeur = l;
	newImg->hauteur = h;
	strcpy(newImg->couleur,c);
	return newImg;
}



// getters largeur et hauteur
// ====== TODO ==========
int recup_largeur(imagePixel *img){
	return img->largeur;
}
int recup_hauteur(imagePixel *img){
	return img->hauteur;
}



// getter et setter couleur
// ====== TODO ==========

void change_color(imagePixel *img,char c[]){
	strcpy(img->couleur ,c);
}

char* recup_color(imagePixel *img){
	return img->couleur;
}
