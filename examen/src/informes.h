#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arcade.h"
#include "salon.h"
#ifndef INFORMES_H_
#define INFORMES_H_


int printPromedioArcadesSalon(Salon *sala, int len, Arcade *arcade, int lenA);
void printSalonCompleto(Salon *sala, int len, Arcade *arcade,int lenA);



void compararJuego(Arcade *arcade, int lenA,Juego *juego);
void pesosFicha(Salon *sala, int len, Arcade *arcade, int lenA);
void printCantArcadeSalon(Salon *sala,Arcade *arcade,int len, int lenA);
void idSalonPrintArcade(Salon *sala, Arcade *arcade, int len, int lenA,Juego *juego);
void informes(Salon *sala, Arcade *arcade, int len, int lenA,Juego *juego);
void listarSalonArcades(Salon *sala, int len, Arcade *arcade, int lenA);
void listarArcadeJugadores(Salon *sala,int len,Arcade *arcade,int lenA,Juego *juego);
void salonArcadeNumero(Salon *sala, Arcade *arcade, int len, int lenA);
#endif
