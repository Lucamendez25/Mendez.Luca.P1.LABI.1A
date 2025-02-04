/*
 ============================================================================
 Name        : miParcial1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM_M 8
#define TAM_T 5
#define TAM_C 5
#define TAM_S 3
#define TAM_V 5
#define TAM_TRA 5
#include "aritmetica.h"
#include "validaciones.h"
#include "output.h"
#include "hardcodear.h"
int main(void)
{
	setbuf(stdout,NULL);

	char seguir;

	eMascota listaMascotas[TAM_M];
	/*
	  	Tipos (Ave, Perro, Roedor, Gato, Pez)
		Colores (Negro, Blanco, Rojo, Gris, Azul)
		Servicios (Corte: $450, Desparasitado: $800, Castrado: $600)
 */
	eTipo listaTipos[TAM_T]=
		{
			{100, "ave"},
			{101, "Perro"},
			{102, "Roedor"},
			{103, "Gato"},
			{104, "Pez"},
		};

	eColor listaColores[TAM_C]=
	{
		{100, "Negro"},
		{101, "Blanco"},
		{102, "Rojo"},
		{103, "Gris"},
		{104, "Azul"}
	};


	eServicio listaServicios[TAM_S]=
	{
		{20000, "Corte", 450},
		{20001, "Desparasitado", 800},
		{20002, "Castrado", 600},

	};


	eTrabajo listaTrabajos[TAM_TRA];

	int todoOkInciadosMascotas=0;
	int todoOkInciadosTrabajos=0;
	int nextMascotas = 1000;
	int nextTrabajos = 10000;

	todoOkInciadosMascotas=inicializarMascotas(listaMascotas, TAM_M);
	todoOkInciadosTrabajos=inicializarTrabajos(listaTrabajos, TAM_TRA);
	if(todoOkInciadosMascotas==1 && todoOkInciadosTrabajos == 1 )
	{
		hardcodearMascotas(&nextMascotas, listaMascotas, TAM_M, 8);
		hardcodearTrabajos(&nextTrabajos, listaTrabajos, TAM_TRA, 4);
		do
			{
				systemCls();
			    seguir=menu();
				switch(seguir)
				{
					case 'a':
						altaMascotas(&nextMascotas, listaMascotas, listaTipos, listaColores ,TAM_M, TAM_T,TAM_C);
						printf("\n\n");
						systemPause();
						break;
					case 'b':
						modificarMascotas(listaMascotas, listaTipos, listaColores, TAM_M, TAM_T, TAM_C);
						printf("\n\n");
						systemPause();
						break;
					case 'c':
						bajaMascotas(listaMascotas, listaTipos, listaColores, TAM_M, TAM_T, TAM_C);
						printf("\n\n");
						systemPause();
						break;
					case 'd':
						ordenarMascotas(listaMascotas,listaTipos,listaColores,TAM_M, TAM_T,TAM_C);
						mostrarMascotas(listaMascotas,listaTipos,listaColores,TAM_M, TAM_T,TAM_C);
						systemPause();
						break;
					case 'e':
						mostrarTipos(listaTipos, TAM_T);
						printf("\n\n");
						systemPause();
						break;
					case 'f':
						mostrarColores(listaColores, TAM_C);
						printf("\n\n");
						systemPause();
						break;
					case 'g':
						mostrarServicios(listaServicios, TAM_S);
						printf("\n\n");
						systemPause();
						break;
					case 'h':
						altaTrabajos(&nextTrabajos, listaMascotas,listaTipos,listaColores,TAM_M, TAM_T,TAM_C, listaTrabajos, TAM_TRA, listaServicios, TAM_S);
						printf("\n\n");
						systemPause();
						break;
					case 'i':
						mostrarTrabajos(listaMascotas,listaTipos,listaColores,TAM_M, TAM_T,TAM_C, listaTrabajos, TAM_TRA, listaServicios, TAM_S);
						printf("\n\n");
						systemPause();
						break;
					case 'j':
						subMenuListarMascotasPorColor(listaMascotas,listaTipos,listaColores,TAM_M, TAM_T,TAM_C);
						printf("\n\n");
						systemPause();
						break;
					case 'k':
						promedioMascotasVacunadas(listaMascotas,listaTipos,listaColores,TAM_M, TAM_T,TAM_C);
						printf("\n\n");
						systemPause();
						break;
					case 'l':
						mostrarMascotasConMenorEdad(listaMascotas,listaTipos,listaColores,TAM_M, TAM_T,TAM_C);
						printf("\n\n");
						systemPause();
						break;
					case 'm':
						mostrarMascotasPorTipoSeparados(listaMascotas,listaTipos,listaColores,TAM_M, TAM_T,TAM_C);
						printf("\n\n");
						systemPause();
						break;
					case 'n':
						mostrarMascotaColorYTipo(listaMascotas,listaTipos,listaColores,TAM_M, TAM_T,TAM_C);
						printf("\n\n");
						systemPause();
						break;
					case 'o':
						mostrarColoresMasAnimales(listaMascotas,listaTipos,listaColores,TAM_M, TAM_T,TAM_C);
						printf("\n\n");
						systemPause();
						break;

					default:
						printf("Esta opcion no es válida");
						printf("\n\n");
						systemPause();
						break;
				}
			}while(seguir !='s');
	}
	else
	{
		printf("Hubo un problema al inicializar");
	}

	return EXIT_SUCCESS;
}
