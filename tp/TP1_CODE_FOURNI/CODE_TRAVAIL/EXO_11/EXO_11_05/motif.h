/******************
 * fichier header *
 ******************/

#ifndef MOTIF_H
#define MOTIF_H

#include <stdbool.h>

// dimensions du dessin
#define NX  70
#define NY  20

// param x : abscisse du point (0 <= x < NX)
// param y : ordonnée du point (0 <= y < NY)
// return : true si le point est allumé, false sinon
bool isOn(int x, int y);

#endif
