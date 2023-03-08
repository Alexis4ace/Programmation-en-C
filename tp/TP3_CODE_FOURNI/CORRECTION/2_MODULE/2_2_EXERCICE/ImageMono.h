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
// ### (cF. aussi "pragma once")

#ifndef IMAGE_MONO
#define IMAGE_MONO

// ### Donc on ne gère pas ici la taille de la chaîne
// ### Note : les commentaires dans un .h ne concernent que l'utilisateur
// ###        du module et donc ne doivent pas être des commentaires décrivant
// ###        l'implémentation (ce type de commentaires sont dans le fichier .c).
// ###        Par exemple on explicitera le domaine de validité d'un paramètre.
// ### Note : il est primordial de mettre le mot-clé "const" quand un paramètre
// ###        n'est pas modifié par une fonction.

// ### première remarque a priori surprenante :
// ### - la définition de la structure de doit pas être ici
// ### En effet c'est un choix d'implémentation qui ne regarde pas
// ### l'utilisateur. D'ailleurs dans les langages objets, ces définitions
// ### sont en private.
// ### Exemple : c'est le problème du concepteur de savoir s'il stocke
// ###      la largeur et la hauteur dans deux variables séparées ou
// ###      dans un tableau à 2 cases ; et surtout il doit pouvoir le
// ###      changer dans impacter l'utilisateur ou même sans que
// ###      celui-ci soit au courant
// ###
// ### Ceci dit, supprimer la définition de la structure dans le .h n'est
// ### pas chose simple. Nous verrons ultérieurement comment faire
// ### avec l'abstraction pointeur.

// définition des données (une structure)
// ====== TODO ==========
#define N 100
typedef struct
{
    int largeur, hauteur;
    char couleur[N];
} ImageMono;

// ### Rq : on note le préfixe "im_" pour les méthodes afin de ne pas entrer
// ###      en conflit avec d'autres fonctions de l'application

// "constructeur"
// - largeur et hauteur doivent être positifs
// - la couleur ne doit pas être vide
// ====== TODO ==========
// Ne pas respecter ces directives peut conduire à des erreurs d'exécution
// ### Tous ces commentaires apportent une information utile à l'utilisateur,
// ### notamment les conséquences s'il ne respecte pas les restrictions.
// ### Le fait que les valeurs erronées ne soit pas gérées par le module
// ### n'est pas une faute de programmation, c'est un choix ; c'est ce qu'on
// ### appelle la programmation par contrat.
// ### Note : on a fait le choix de passer en paramètre (par pointeur) la
// ###        structure à initialiser ; cela aurait pu être le retour de la
// ###        fonction (avec un petite perte d'efficacité)
void im_init(ImageMono *self, int largeur, int hauteur, const char *couleur);

// accesseurs : dimensions
// ====== TODO ==========
int im_getLargeur(const ImageMono *self);
int im_getHauteur(const ImageMono *self);
// la largeur et la hauteur ne peuvent pas être modifiées après
// l'initialisation, d'où l'absence des setters

// accesseurs : couleur
// getter
// ====== TODO ==========
const char * im_getCouleur(const ImageMono *self);
// setter
// la couleur ne doit pas être vide
// ====== TODO ==========
void im_setCouleur(ImageMono *self, const char *couleur);

// cf. premier TODO
// ====== TODO ==========
#endif
