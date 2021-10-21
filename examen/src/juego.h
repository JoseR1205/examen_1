
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef JUEGO_H_
#define JUEGO_H_

typedef struct
{
int id;
char juego[63];
int idArcade;
int isEmpty;
}Juego;



int ingresarJuego(Juego *juego, int lenA, int ubiArcade);
int initJuego(Juego * juego, int lenA);
int autoIdJuego();


#endif
