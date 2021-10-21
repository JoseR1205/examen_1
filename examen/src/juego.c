#include "juego.h"


int ingresarJuego(Juego *juego, int lenA, int ubiArcade){
	int retorno = -1;
	for(int i = 0; i<lenA;i++){
		if(juego[i].isEmpty==0){
			utn_getChar(juego[i].juego, "\nIngresar juego\n", "\nerror\n", 63, 5);
			juego[i].isEmpty=1;
			juego[i].idArcade = ubiArcade;
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int initJuego(Juego * juego, int lenA)
{
	int retorno = -1;
	if(juego != NULL && lenA > 0){
		retorno = 0;
		for(int i = 0; i<lenA ; i++){
			juego[i].isEmpty = 0;
		}
	}
	return retorno;
}

int autoIdJuego(){
	static int id =1;
	return id++;
}
