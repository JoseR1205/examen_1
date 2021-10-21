#include "arcade.h"
#include "salon.h"
#include "biblioteca.h"
#include "juego.h"

void eliminarArcade(Arcade *arcade, int lenA,Juego *juego){
	int opcion;
	int idaux;
	if(utn_getInt(&opcion, "\nIngresar id a eliminar", "\nError\n", 1, 9999, 5)==0){
		idaux = buscarIdArcade(arcade, lenA, opcion);
		if(arcade[idaux].isEmpty==1){
			printf("\nId:|%d|nacionalidad:|%s|jugadores:|%d|fichas|%d|", arcade[idaux].id, arcade[idaux].nacionalidad,arcade[idaux].cantJugadores,arcade[idaux].fichasMax);
			if(arcade[idaux].tipoS==1){
				printf("Sonido:|mono|");
			}else{
				printf("Sonido:|estereo|");
			}
			for(int a = 0; a<lenA ; a++){
				if(juego[a].isEmpty==1 && juego[a].idArcade==arcade[idaux].id){
					printf(" Juego:|%s|",juego[a].juego);
				}
			}
			if(utn_getInt(&opcion, "\nEsta seguro se eliminar ?\n1_Si\n2_no", "\nError", 1, 2, 5)==0){
				if(opcion == 1){
					arcade[idaux].isEmpty=0;
					for(int i=0;i<lenA;i++){
						if(juego[i].idArcade== arcade[idaux].id){
							juego[i].isEmpty=0;
						}
					}
				}else{
					printf("\nVolviendo al menu...");
				}
			}
		}else{
			printf("\nId no existe volviendo al menu...");
		}
	}
}

int printArcadeSalon(Arcade *arcade, int lenA, Salon *sala, int len,Juego *juego){
	int retorno = -1;
	if(arcade!=NULL && sala!=NULL && lenA>0 && len >0){
		for(int i=0;i<len;i++){
			if(sala[i].isEmpty==1){
				printf("\nId:|%d| nombre:|%s| direccion:|%s|",sala[i].id,sala[i].nombre,sala[i].direccion);
				if(sala[i].tipo==1){
					printf("Tipo|SHOPPING|");
				}else{
					printf("Tipo|LOCAL|");
				}
				for(int x = 0; x<lenA ;x++){
					if(arcade[x].isEmpty==1 && arcade[x].idSalon==sala[i].id){
						printf("\n  -Id:|%d|nacionalidad:|%s|jugadores:|%d|fichas|%d|", arcade[x].id, arcade[x].nacionalidad,arcade[x].cantJugadores,arcade[x].fichasMax);
						if(arcade[x].tipoS==1){
							printf("Sonido:|mono|");
						}else{
							printf("Sonido:|estereo|");
						}
						for(int a = 0; a<lenA ; a++){
							if(juego[a].isEmpty==1 && juego[a].idArcade==arcade[x].id){
								printf(" Juego:|%s|",juego[a].juego);
							}
						}
					}
				}

			}
		}
		retorno = 0;
	}

	return retorno;
}

void modificarArcade(Arcade* arcade, int lenA,Juego *juego){
	int opcion;
	int subopcion;
	if(utn_getInt(&opcion, "\nIngresar id a modificar\n", "\nerror", 1, 10000, 5)==0){
		if(arcade[buscarIdArcade(arcade, lenA, opcion)].isEmpty==1){
			if(utn_getInt(&subopcion, "\n1_Modificar cantidad de jugadores\n2_Modificar juego", "\nerror\n", 1, 2, 4)==0){
				if(subopcion==1){
					utn_getInt(&arcade[buscarIdArcade(arcade, lenA, opcion)].cantJugadores, "\nIngresar cantidad de juegadores", "\nerror\n", 1, 50000, 5);
				}else{
					mostrarjuegosSinrepetir(juego, lenA);
					for(int i=0;i<lenA;i++){
						if(juego[i].idArcade==opcion){
							utn_getChar(juego[i].juego, "\nIngresar el nuevo nombre del juego\n", "\nError\n", 63, 5);
						}
					}
				}
			}
		}else{
			printf("\nid incorrecta volviendo al menu");
		}
	}
}


void mostrarjuegosSinrepetir(Juego *juego,int lenA){
	int auxCon = 0;
	Juego aux[lenA];
	for(int i = 0;i<lenA;i++){
		if(juego[i].isEmpty==1){
			for(int x = 0;x<lenA;x++){
				if(strcmp(juego[i].juego,aux[x].juego)!=0 && juego[i].isEmpty==1){
					strcpy(aux[auxCon].juego,juego[i].juego);
					auxCon++;
					break;
				}
			}
		}
	}
	for(int f=0;f<auxCon;f++){
		printf("\n%s",aux[f].juego);
	}
}

int buscarIdArcade(Arcade* arcade, int len,int id)
{
	int idP = -1;
	if(arcade != NULL && len > 0){
		for(int i=0;i<len;i++){
			if(arcade[i].id==id){
				idP = i;
				break;
			}
		}
	}
	return idP;
}
int printArcade(Arcade* arcade, int len,Juego *juego)
{
	int retorno = -1;
	for(int i=0;i<len;i++){
		if(arcade[i].isEmpty==1){
			printf("\nId:|%d|nacionalidad:|%s|jugadores:|%d|fichas|%d|", arcade[i].id, arcade[i].nacionalidad,arcade[i].cantJugadores,arcade[i].fichasMax);
			if(arcade[i].tipoS==1){
				printf("Sonido:|mono|");
			}else{
				printf("Sonido:|estereo|");
			}
			for(int x=0;x<len;x++){
				if(juego[x].idArcade==arcade[i].id){
					printf("Juego:|%s|", juego[x].juego);
					break;
				}
			}
		}
	}
	return retorno;
}

int ingresarArcade(Arcade *arcade,int len,Salon *sala,int lenSalon,Juego *juego){
	int retorno =-1;
	if(arcade != NULL && len>0){
		for(int i=0;i<len;i++){
			if(arcade[i].isEmpty==0){
				cargarArcade(arcade, i, sala, lenSalon,juego,len);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
void cargarArcade(Arcade *arcade,int ubi,Salon *sala,int lenSalon, Juego *juego,int lenA){
	int idaux;
	if(utn_getChar(arcade[ubi].nacionalidad, "\nIngresar nacionalidad del arcade\n", "\nError\n", 51, 5)==0){
		if(utn_getInt(&arcade[ubi].tipoS, "\nIngresar tipo de sonido:\n1_Mono\n2_Estereo", "\nerror opcion invalida\n", 1, 2, 5)==0){
			if(utn_getInt(&arcade[ubi].cantJugadores, "\nIngresar cantidad de jugadores\n", "\nError\n", 1, 20, 5)==0){
				if(utn_getInt(&arcade[ubi].fichasMax, "\nIngresar la cantidad maxima de fichas\n", "\nerror\n", 1, 5000, 5)==0){
					if(utn_getInt(&idaux, "\nIngesar id salon del arcade\n", "\nerror\n", 1, 10000, 5)==0 && validarSalonArcade(arcade, sala, idaux, ubi, lenSalon)==0){
						arcade[ubi].id=autoIdArcade();
						arcade[ubi].isEmpty=1;
						if(ingresarJuego(juego, lenA, arcade[ubi].id)==0){
							printf("\nSe cargo el arcade correctamente");
						}
					}else{
						printf("\nError el salon no existe.\nVovlviendo al menu\n");
					}
				}
			}
		}
	}
}
int validarSalonArcade(Arcade *arcade,Salon *sala,int idingresado,int ubi,int len){
	int retorno = -1;
	if(sala[buscarId(sala, len, idingresado)].isEmpty==1){
		arcade[ubi].idSalon=idingresado;
		retorno = 0;
	}
	return retorno;
}
int initArcade(Arcade * arcade, int len)
{
	int retorno = -1;
	if(arcade != NULL && len > 0){
		retorno = 0;
		for(int i = 0; i<len ; i++){
			arcade[i].isEmpty = 0;
		}
	}
	return retorno;
}
int autoIdArcade(){
	static int id =1;
	return id++;
}
