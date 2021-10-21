
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "salon.h"
#include "juego.h"
#ifndef ARCADE_H_
#define ARCADE_H_

typedef struct
{
int id;
char nacionalidad[51];
//char juego[63];
int cantJugadores;
int fichasMax;
int tipoS;
int idSalon;
int isEmpty;
}Arcade;



/** \brief Se ingresa un id para eliminar
* \param arcade Arcade*
* \param len intA
*/
void eliminarArcade(Arcade *arcade, int lenA,Juego *juego);
/** \brief muestra el salon con su arcade
* \param sala Salon*
* \param arcade Arcade*
* \param len int
* \param len intA
* return int
*/
int printArcadeSalon(Arcade *arcade, int lenA, Salon *sala, int len,Juego *juego);
/** \brief Muestra los juegos sin repetir
* \param arcade Arcade*
* \param len intA
*/
void mostrarjuegosSinrepetir(Juego *juego,int lenA);
/** \brief modifica el id ingresado en un sub menu
* \param arcade Arcade*
* \param len intA
*/
void modificarArcade(Arcade* arcade, int lenA,Juego *juego);
/** \brief busca el la ubicacion del array con el id
* \param arcade Arcade*
* \param len int
* return int
* */
int buscarIdArcade(Arcade* arcade, int len,int id);

int printArcade(Arcade* arcade, int len,Juego *juego);
int ingresarArcade(Arcade *arcade,int len,Salon *sala,int lenSalon,Juego *juego);
void cargarArcade(Arcade *arcade,int ubi,Salon *sala,int lenSalon, Juego *juego,int lenA);
int validarSalonArcade(Arcade *arcade,Salon *sala,int idingresado,int ubi,int len);
int autoIdArcade();
int initArcade(Arcade * arcade, int len);
#endif
