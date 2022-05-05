//TRABAJO PROGRAMACIÓN 2022 AIR-HOCKEY

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define N 30

typedef struct {
	char nombre[N];
	char apellido[N];
	int edad;
}Jugador;

void CargarJugador(Jugador* jugadores, int n_jugador);
void RellenarEstructura(Jugador* j);

int main(void) {

	setlocale(LC_ALL, "es-ES");

	//variables
	int opcion;
	int menu2;
	int n_jugadores;
	Jugador* v_jugador;

	//Registrarse
	printf("Introduzca el número de jugadores: \n");
	scanf_s("%d", &n_jugadores);
	printf("Rellene sus datos: \n");
	v_jugador = (Jugador*)calloc(n_jugadores, sizeof(Jugador));
	if (v_jugador == NULL) {
		printf("\n Error en la asignacion de memoria: ");
		free(v_jugador);
	}
	else {
		CargarJugador(v_jugador, n_jugadores);
		//menu ppal
		do {
			printf("----------MENU PRINCIPAL----------\n");
			printf("--> Introduzca una opción: \n");
			printf("1. NUEVA PARTIDA\n");
			printf("2. VER MEJORES PUNTUACIONES\n");
			printf("3. SALIR");

			printf("\nIntroduzca la opción deseada: \n");
			scanf_s("%d", &opcion);

			switch (opcion) {

			case 1:
				do {
					//menu de partidas
					printf("-----MENU DE PARTIDAS-----\n");
					printf("Seleccione el modo de juego: \n");
					printf("1. Al mejor de 3\n");
					printf("2. Al mejor de 5\n");
					printf("3. Muerte subita\n");
					printf("4. Terminar partida\n");

					printf("\nIntroduzca una opcion: \n");
					scanf_s("%d", &menu2);

					switch (menu2) {

					case 1:
						//Funcion al mejor de 3
						break;
					case 2:
						//Funcion al mejor de 5
						break;
					case 3:
						//Muerte súbita
						break;
					case 4:
						printf("Su partida ha finalizado");
						//Mostrar puntuación
						break;
					default:
						printf("\nIntroduzca una opción válida\n");
					}
				} while (menu2 == 1 || menu2 == 2 || menu2 == 3 || menu2 == 4);
				break;
			case 2:
			{
				// funcion que llame a mostrar puntuaciones
			}
			break;
			case 3:
				break;
			default:
				printf("Esa opción no esta en el menu\n");
			}
		} while (opcion != 3);
	}

	return 0;
}
void CargarJugador(Jugador* jugadores, int n_jugador) {
	int i;
	printf("Se va a proceder a la carga de la estructura de jugador: \n");
	for (i = 0; i < n_jugador; i++) {
		RellenarEstructura(&jugadores[i]);
	}
	return;
}
void RellenarEstructura(Jugador* j) {
	printf("\nIntroduzca el nombre del jugador: ");
	getchar();
	fgets(j->nombre, N, stdin);
	//gets_s(j->nombre);
	printf("\nIntroduzca el apellido del jugador: ");
	getchar();
	fgets(j->apellido, N, stdin);
	//gets_s(j->apellido);
	printf("\nIntroduzca la edad del jugador: ");
	scanf_s("%d", &(j->edad));
	return;
}