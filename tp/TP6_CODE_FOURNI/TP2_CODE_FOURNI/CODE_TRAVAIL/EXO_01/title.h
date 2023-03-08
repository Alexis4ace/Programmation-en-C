#ifndef TITLE_H
#define TITLE_H

// l'UTF8 n'est pas géré

#include <stdio.h>
#include <stdbool.h>

// affiche à l'écran la répétition d'une chaîne
// param s : la chaîne à répéter
// param n : le nombre de répétitions
// param withReturn : indique si l'affiche se termine par un retour chariot
void title_repeat(const char *s, int n, bool withReturn);
// même chose, mais dans un flux
void title_repeatStream(FILE *fd, const char *s, int n, bool withReturn);

// affiche à l'écran un titre encadré
// param title : le titre
void title_print(const char *title);
// même chose, mais dans un flux
void title_printStream(FILE *fd, const char *title);

#endif
