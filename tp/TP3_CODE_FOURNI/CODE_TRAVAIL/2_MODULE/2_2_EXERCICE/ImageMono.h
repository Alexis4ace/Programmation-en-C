/*
 * Exercice 2.02
 * compilation :
 *   un .h NE se compile PAS (enfin pas ce cours)
 */
/*
 * ### les commentaires de correction sont précédés par ###
 */

// on n'oublie pas la protection contre les doubles inclusions
// ====== TODO ==========
#ifndef IMAGE_MONO
#define IMAGE_MONO


// définition des données (une structure)
// ====== TODO ==========
#define taille 100
typedef struct image{
	int largeur,hauteur;
	char couleur[taille];
}imagePixel;
// "constructeur"
// - largeur et hauteur doivent être positifs
// - la couleur ne doit pas être vide
// Ne pas respecter ces directives peut conduire à des erreurs d'exécution
// ====== TODO ==========
imagePixel* init_image(int largeur,int hauteur,char couleur[]);
// accesseurs : dimensions
// ====== TODO ==========
int recup_largeur(imagePixel *img);
int recup_hauteur(imagePixel *img);
char* recup_color(imagePixel *img);
// la largeur et la hauteur ne peuvent pas être modifiées après
// l'initialisation, d'où l'absence des setters
void change_color(imagePixel *img,char couleur[]);
// accesseurs : couleur
// getter
// ====== TODO ==========
// setter
// la couleur ne doit pas être vide
// ====== TODO ==========

// cf. premier TODO
// ====== TODO ==========




#endif
