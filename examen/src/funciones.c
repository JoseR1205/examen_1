
#include "funciones.h"
#include "biblioteca.h"
#include "salon.h"
#include "arcade.h"
#include "informes.h"
#include "juego.h"
void menu(Salon *sala,Arcade *arcade, int len, int lenA,Juego *juego){
	int opcion;
	int idSeleccionado;
	int idaux;
	int flagOpcion=0;
	int flagOpcion2=0;
	if(sala != NULL && len > 0){
		while(opcion != 10){
			if(utn_getInt(&opcion, "\n1)Alta de salon\n2)Eliminar salon\n3)imprimir salones\n4)Incorporar arcade\n5)Modificar arcade\n6)Eliminar arcade\n7)Imprimir Arcade\n8)Imprimir juegos\n9)Informes\n10)Salir\n", "Error", 1, 10, 5)==0){
				switch(opcion){
					case 1:
						ingresarSalon(sala, len);
						flagOpcion=1;
						break;
					case 2:
						if(flagOpcion==1){
							printSalas(sala, len, -1);
							if(utn_getInt(&idSeleccionado, "\n ingresar id del salon para eliminar\n", "\nerror.", 1, 10000, 5)==0){
								idaux = buscarId(sala, len, idSeleccionado);
								if(eliminarSalon(sala, len, idaux)==0){
									printf("\nSe elimino correctamente\n");
									eliminarArcadeSala(arcade, lenA, idSeleccionado,juego);
								}else{
									printf("\nerror volviendo al menu...\n");
								}
							}
						}
						break;
					case 3:
						if(flagOpcion==1){
							printSalas(sala, len, 0);
						}
						break;
					case 4:
						if(flagOpcion==1){
							ingresarArcade(arcade, lenA, sala, len,juego);
							flagOpcion2=1;
						}
						break;
					case 5:
						if(flagOpcion2==1 && flagOpcion==1){
							printArcade(arcade, lenA,juego);
							modificarArcade(arcade, lenA,juego);
						}
						break;
					case 6:
						if(flagOpcion2==1 && flagOpcion==1){
							if(printArcadeSalon(arcade, lenA, sala, len, juego)==0){
								eliminarArcade(arcade, lenA,juego);
							}
						}
						break;
					case 7:
						if(flagOpcion2==1 && flagOpcion==1){
							printArcade(arcade, lenA,juego);
						}
						break;
					case 8:
						if(flagOpcion2==1 && flagOpcion==1){
							mostrarjuegosSinrepetir(juego, lenA);
						}
						break;
					case 9:
						if(flagOpcion2==1 && flagOpcion==1){
							informes(sala, arcade, len, lenA,juego);
						}
						break;
				}
			}
		}
	}
}



void eliminarArcadeSala(Arcade *arcade,int lenA,int idEliminado,Juego *juego){
	for(int i = 0;i<lenA;i++){
		if(arcade[i].idSalon==idEliminado){
			arcade[i].isEmpty=0;
			for(int x = 0;x<lenA ; x++){
				if(arcade[i].id==juego[x].idArcade){
					juego[x].isEmpty=0;
				}
			}
		}
	}
}
/*
void altaForzada(Salon *sala, int len, Arcade *arcade, int lenA){
	sala[0].isEmpty=1;
	sala[0].id=autoIdSalon();
	strcpy(sala[0].nombre,"sala1");
	sala[0].tipo=1;

	arcade[0].cantJugadores=5;
	arcade[0].fichasMax=5;
	arcade[0].id=autoIdArcade();
	arcade[0].idSalon=1;
	arcade[0].isEmpty=1;
	//strcpy(arcade[0].juego,"juego1");
	strcpy(arcade[0].nacionalidad,"argentina");
	arcade[0].tipoS=1;

	arcade[1].cantJugadores=5;
	arcade[1].fichasMax=5;
	arcade[1].id=autoIdArcade();
	arcade[1].idSalon=1;
	arcade[1].isEmpty=1;
	//strcpy(arcade[1].juego,"juego1");
	strcpy(arcade[1].nacionalidad,"chile");
	arcade[1].tipoS=2;

	arcade[2].cantJugadores=5;
	arcade[2].fichasMax=5;
	arcade[2].id=autoIdArcade();
	arcade[2].idSalon=1;
	arcade[2].isEmpty=1;
	//strcpy(arcade[2].juego,"juego3");
	strcpy(arcade[2].nacionalidad,"chile");
	arcade[2].tipoS=2;

	arcade[3].cantJugadores=5;
	arcade[3].fichasMax=5;
	arcade[3].id=autoIdArcade();
	arcade[3].idSalon=1;
	arcade[3].isEmpty=1;
	//strcpy(arcade[3].juego,"juego4");
	strcpy(arcade[3].nacionalidad,"chile");
	arcade[3].tipoS=2;

}
*/
