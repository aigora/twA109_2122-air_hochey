#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#define N 50

typedef struct {
	char nombre[N];
	char apellido[N];
	int edad;
	int puntuacion;
}Jugador;


int menu_principal(void);
void leer_fichero_jugador(Jugador*, int*, int);
int alta_jugador(Jugador[], int*, int);
int nueva_partida (Jugador[], int*, int);
Jugador leer_datos_jugador(char);
int escribir_fichero_jugador(Jugador*, int);
void listado_puntuaciones(Jugador*, int);
void mostar_puntuaciones(void);


int main()
{
	Jugador jugador[N];
	int n = 0;
	int resultado;
	int opcion;
	int opcion2;
	int longitud = N;

	leer_fichero_jugador(jugador, &n, longitud);

	do
	{
		opcion = menu_principal();
		resultado = -1;

		switch (opcion)
		{
		case 1: 
			resultado = alta_jugador(jugador, &n, N);
			break;
		case 2:
			resultado = opcion2 = nueva_partida(jugador, &n, N);
			
			switch (opcion2)
			{
			case 1:
				//funcion al mejor de 3
				break;
			case 2:
				//funcion al mejor de 5
				break;
			case 3:
				//muerte súbita
				break;
			case 4:
				printf("Su partida ha finalizado");
				//Funcion que muestre la puntuacion
				listado_puntuaciones(jugador,n);
				break;
			}
			break;
		case 3: 
			//funcion que muestre las mejores puntuaciones
			break;
		case 4:
			break;
		}
		if (resultado == 0)
			escribir_fichero_jugador(jugador, n);

		printf("\n\n");
	} while (opcion != 4);

	return 0;
}


int menu_principal(void)
{
	int opcion;
	char intro;
	do
	{
		printf("----------MENU PRINCIPAL----------\n");
		printf("--> Introduzca una opción: \n");
		printf("1. ALTA DEL JUGADOR\n");
		printf("2. NUEVA PARTIDA\n");
		printf("3. VER MEJORES PUNTUACIONES\n");
		printf("4. SALIR");
		printf("\nIntroduzca la opción deseada: \n");
		scanf_s("%d", &opcion);
		intro = getchar();

		if(opcion<1||opcion>4)
			printf("\nOpción incorrecta.\n\n");
	} while (opcion < 1 || opcion>4);
	printf("\n");
	return opcion;
}

Jugador leer_datos_jugador(char operacion)
{
	Jugador jugador;
	char intro, edad[N];

	printf("Nombre:");
	gets_s(jugador.nombre, N);
	printf("Apellidos:");
	gets_s(jugador.apellido, N);
	printf("Edad:");
	scanf_s("%d", &jugador.edad);
	intro = getchar(); // Evitamos que se quede un '\n' en el buffer del teclado.
	
	return jugador;
}

int alta_jugador(Jugador u[], int* pn, int longitud)
{
	int e;
	int n = *pn;

	if (n == longitud)
	{
		printf("La lista está completa\n");
		e = -1;
	}
	else
	{
		u[n] = leer_datos_jugador(n);
		n++;
		*pn = n;
		e = 0;
	}
	return e;
}

int nueva_partida(Jugador u[], int* pn, int longitud)
{
	int opcion2;
	char intro;

	do
	{
		printf("-----MENU DE PARTIDAS-----\n");
		printf("Seleccione el modo de juego: \n");
		printf("1. Al mejor de 3\n");
		printf("2. Al mejor de 5\n");
		printf("3. Muerte subita\n");
		printf("4. Terminar partida\n");
		printf("\nIntroduzca una opcion: \n");
		scanf_s("%d", &opcion2);
		intro = getchar();

		if (opcion2 < 1 || opcion2>6)
			printf("\nOpción inexistente.\n\n");
	} while (opcion2 < 1 || opcion2>6);
	printf("\n");

	return opcion2;
}


void leer_fichero_jugador(Jugador p[], int* pnumero, int longitud)
{

	FILE* fichero; 
	int num = 0; 
	int i, pos; 
	errno_t e;
	char intro[2];

	e = fopen_s(&fichero, "Jugadores.txt", "rt");

	if (e != 0)
		*pnumero = 0;
	else
	{
		fscanf_s(fichero, "%d", &num); 
		if (num == 0) 
			*pnumero = 0;
		else
		{
			if (num > longitud) // Si no hay memoria suficiente
			{
				printf("Memoria insuficiente para el almacenamiento de los datos del fichero\n");
				*pnumero = 0;
			}
			else
			{
				fgets(intro, 2, fichero); 
				for (i = 0; i < num; i++)
				{
					fgets((p + i)->nombre, N, fichero);
					pos = strlen((p + i)->nombre);
					(p + i)->nombre[pos - 1] = '\0';
					fgets((p + i)->apellido, N, fichero);
					pos = strlen((p + i)->apellido);
					(p + i)->apellido[pos - 1] = '\0';
					fscanf_s(fichero, "%d", &(p + i)->edad);
					fgets(intro, 2, fichero);
				}
				*pnumero = num;
			}
		}
		fclose(fichero);
	}
}

int escribir_fichero_jugador(Jugador* lista, int numero)
{
	int i;
	FILE* fichero;
	errno_t err;

	err=fopen_s(&fichero, "Jugadores.txt", "w");
	if (err == 0) 
	{
		fprintf(fichero, "%d\n", numero); // Se graba en el fichero el n�mero de usuarios
		for (i = 0; i < numero; i++)
		{

			fprintf(fichero, "%s\n", (lista + i)->nombre);
			fprintf(fichero, "%s\n", (lista + i)->apellido);
			fprintf(fichero, "%d\n", (lista + i)->edad);
		}
		fclose(fichero);
	}
	else
		printf("Se ha producido un problema a la hora de grabar el fichero de jugadores\n");
	return err;
}

void listado_puntuaciones(Jugador* jugador, int n)
{
	int i;
	if (n == 0)
		printf("En este momento no hay puntuaciones guardadas");
	else
	{
		mostrar_puntuaciones();
	}
}

void mostar_puntuaciones(void)
{
	//funcion que muestre las mejores puntuaciones
}
