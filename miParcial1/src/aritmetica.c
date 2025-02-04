/*
 * aritmetica.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Luca
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aritmetica.h"
#include "validaciones.h"
#include "output.h"
#include "hardcodear.h"

/////////////////////////////////////////////////////////INCIALIZAR//////////////////////////////////////////////////////////////////////////////////////////////////////

int inicializarMascotas(eMascota vec[], int tam)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0)
	{
		for(int i = 0 ; i < tam ; i++)
		{
			vec[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}
int inicializarTrabajos(eTrabajo vec[], int tam)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0)
	{
		for(int i = 0 ; i < tam ; i++)
		{
			vec[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

///////////////////////////////////////////////////////BUSCAR LIBRE///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int buscarLibreMascotas(int* pIndice, eMascota vec[], int tam)
{
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if( vec[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreTrabajos(int* pIndice, eTrabajo vec[], int tam)
{
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if( vec[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
        todoOk = 1;
    }
    return todoOk;
}


///////////////////////////////////////////////////////ALTA///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int altaMascotas(int* pLegajo, eMascota vecMascotas[], eTipo vecTipos[], eColor vecColores[], int tamMascotas, int tamTipos, int tamColores)
{
	systemCls();
	char seguir;
    int todoOk = 0;
    int indice;
    eMascota auxMascota;

    if(pLegajo != NULL && vecMascotas != NULL && vecTipos != NULL && vecColores != NULL && tamMascotas > 0 && tamTipos > 0 && tamColores > 0)
    {
    	do
    	{
    		printf("**** Alta Mascotas ****\n\n");
    		buscarLibreMascotas(&indice, vecMascotas, tamMascotas);
			if(indice == -1)
			{
				printf("No hay lugar en el sistema.\n");
			}
			else
			{
				cargarMascota(&auxMascota, vecTipos,vecColores,tamMascotas,tamTipos,tamColores);
				auxMascota.id = *pLegajo;
				*pLegajo = *pLegajo + 1;
				vecMascotas[indice] = auxMascota;
				todoOk = 1;
			}
			printf("Le gustaria ingresar otra mascota:");
			fflush(stdin);
			scanf("%c", &seguir);
			validarCaracterSeguir(&seguir);

    	}while(seguir != 'n');
    }

    return todoOk;

}

int altaTrabajos(int* pLegajo, eMascota vecMascotas[], eTipo vecTipos[], eColor vecColores[], int tamMascotas, int tamTipos, int tamColores, eTrabajo vecTrabajos[], int tamTrabajos, eServicio vecServicios[], int tamServicios)
{
	systemCls();
	char seguir;
    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;

    if(pLegajo != NULL && vecMascotas != NULL && vecTipos != NULL && vecColores != NULL && vecTrabajos != NULL &&tamMascotas > 0 && tamTipos > 0 && tamColores > 0 && tamTrabajos > 0)
    {
    	do
    	{
    		printf("**** Alta Trabajos ****\n\n");
    		buscarLibreTrabajos(&indice, vecTrabajos, tamTrabajos);
			if(indice == -1)
			{
				printf("No hay lugar en el sistema.\n");
			}
			else
			{
				cargarTrabajo(vecMascotas, vecTipos,vecColores,tamMascotas,tamTipos,tamColores, &auxTrabajo, tamTrabajos, vecServicios, tamServicios);
				auxTrabajo.id = *pLegajo;
				*pLegajo = *pLegajo + 1;
				vecTrabajos[indice] = auxTrabajo;
				todoOk = 1;
			}
			printf("Le gustaria ingresar otro trabajo:");
			fflush(stdin);
			scanf("%c", &seguir);
			validarCaracterSeguir(&seguir);

    	}while(seguir != 'n');


    }
    return todoOk;
}

///////////////////////////////////////////////////CARGAR////////////////////////////////////////////////////////////////////////////
int cargarMascota(eMascota * pMascota,  eTipo vecTipos[], eColor vecColor[], int tamMascotas, int tamTipos, int tamColores )
{
	systemCls();
    int todoOk = 0;
    eMascota auxMascota;

    if(pMascota != NULL)
	{
    	printf("Ingrese nombre de su mascota: ");
		fflush(stdin);
		scanf("%s", auxMascota.nombre);
		validarNombreMascota(&auxMascota, 10);
		strcpy(pMascota->nombre, auxMascota.nombre);

		systemCls();

		printf("\n\nIngrese ID tipo: \n");
		mostrarTipos(vecTipos, tamTipos);
		printf("Que opcion elige: \n");
		fflush(stdin);
		scanf("%d", &auxMascota.idTipo);
		validarIDs(&auxMascota, 1);
		pMascota->idTipo=auxMascota.idTipo;

		systemCls();

		printf("\n\nIngrese ID Color: \n");
		mostrarColores(vecColor, tamColores);
		printf("Que opcion elige: \n");
		fflush(stdin);
		scanf("%d", &auxMascota.idColor);
		validarIDs(&auxMascota, 2);
		pMascota->idColor=auxMascota.idColor;

		systemCls();

		printf("\n\nIngrese edad: ");
		scanf("%d", &auxMascota.edad);
		validarEdades(&auxMascota);
		pMascota->edad=auxMascota.edad;

		systemCls();

		printf("\n\nSu mascota esta vacunada?: ");
		fflush(stdin);
		scanf("%c", &auxMascota.vacunado);
		validarCaracterVacunado(&auxMascota);
		pMascota->vacunado=auxMascota.vacunado;

		pMascota->isEmpty = 0;

		todoOk = 1;
	}

    return todoOk;
}

int cargarTrabajo(eMascota vecMascotas[],  eTipo vecTipos[], eColor vecColores[], int tamMascotas, int tamTipos, int tamColores, eTrabajo * pTrabajo, int tamTrabajos, eServicio vecServicios[], int tamServicios)
{
	systemCls();
    int todoOk = 0;
    int indice;

    eTrabajo auxTrabajo;

    if(pTrabajo != NULL)
	{

		mostrarMascotas(vecMascotas,vecTipos,vecColores, tamMascotas,tamTipos,tamColores);
		printf("INGRESE ID DE MASCOTA: \n");
		scanf("%d", &auxTrabajo.idMascota);
		buscarMascota(&indice, auxTrabajo.idMascota, vecMascotas, tamMascotas);
		while(indice==-1)
		{
			printf("No existe una mascota con ese ID: %d\n", auxTrabajo.idMascota);
			printf("\nINGRESE ID DE MASCOTA VALIDO: \n");
			scanf("%d", &auxTrabajo.idMascota);
			buscarMascota(&indice, auxTrabajo.idMascota, vecMascotas, tamMascotas);
		}
		pTrabajo->idMascota=auxTrabajo.idMascota;

		systemCls();
		mostrarServicios(vecServicios, tamServicios);
		printf("INGRESE ID servicio: \n");
		printf("Que opcion elige: \n");
		fflush(stdin);
		scanf("%d", &auxTrabajo.idServicio);
		while(!validarIdServicios(vecServicios, auxTrabajo.idServicio,  4))
		{
			printf("INGRESE UN ID VALIDO: \n");
			printf("Que opcion elige: \n");
			fflush(stdin);
			scanf("%d", &auxTrabajo.idServicio);
			validarIdServicios(vecServicios, auxTrabajo.idServicio, 4);
		}
		pTrabajo->idServicio=auxTrabajo.idServicio;

		systemCls();


		printf("Ingrese Fecha de Nacimiento: \n");


		printf("Ingrese año: ");
		scanf("%d", &auxTrabajo.fecha.anio);
		validarFecha(&auxTrabajo, 3);
		pTrabajo->fecha.anio=auxTrabajo.fecha.anio;

		printf("Ingrese mes: ");
		scanf("%d", &auxTrabajo.fecha.mes);
		validarFecha(&auxTrabajo, 2);
		pTrabajo->fecha.mes=auxTrabajo.fecha.mes;


		printf("Ingrese dia: ");
		scanf("%d", &auxTrabajo.fecha.dia);
		validarFecha(&auxTrabajo, 1);
		pTrabajo->fecha.dia=auxTrabajo.fecha.dia;


		pTrabajo->isEmpty = 0;

		systemCls();
		todoOk = 1;
	}

    return todoOk;
}

int cargarDescripcionTipos(int idTipos, char descripcion[], eTipo vec[], int tam)
{
	int todoOk=0;
	if(descripcion!=NULL && vec !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(vec[i].id==idTipos)
			{
				strcpy(descripcion, vec[i].descripcion);
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int cargarDescripcionColores(int idColor, char descripcion[], eColor vec[], int tam)
{
	int todoOk=0;
	if(descripcion!=NULL && vec !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(vec[i].id==idColor)
			{
				strcpy(descripcion, vec[i].descripcion);
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int cargarDescripcionMascota(int idMascotas, char descripcion[], eMascota vec[], int tam)
{
	int todoOk=0;
	if(descripcion!=NULL && vec !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(vec[i].id==idMascotas)
			{
				strcpy(descripcion, vec[i].nombre);
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int cargarDescripcionServicio(int idServicios, char descripcion[], eServicio vec[], int tam)
{
	int todoOk=0;
	if(descripcion!=NULL && vec !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(vec[i].id==idServicios)
			{
				strcpy(descripcion, vec[i].descripcion);
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}


///////////////////////////////////////////////////////MODIFICAR/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int modificarMascotas(eMascota vecMascotas[], eTipo vecTipos[],eColor vecColores[] ,int tamMascotas, int tamTipos, int tamColores)
{
	systemCls();
    int todoOk = 0;
	int legajo;
	int indice;
	char confirma;
	char seguir;
	int modificar;
	int flag;
	eMascota auxMascota;

	if(vecMascotas != NULL && vecTipos != NULL && vecColores != NULL && tamMascotas > 0 && tamTipos > 0 && tamColores >0)
	{
		systemCls();
		printf("**** Modificar Mascota ****\n\n");

		flag=mostrarMascotas(vecMascotas,vecTipos,vecColores ,tamMascotas,tamTipos , tamColores);
		if(flag==-1)
		{
			printf("Primero debe haber dado de alta para realizar una modificacion\n\n");
		}
		else
		{
			do
			{
				printf("\nIngrese ID de la mascota a modificar: ");
				scanf("%d", &legajo);
				buscarMascota(&indice, legajo, vecMascotas, tamMascotas);
				if(indice == -1)
				{
					printf("No existe una mascota con ese ID: %d\n", legajo);
				}
				else
				{
					systemCls();
					mostrarMascota(vecMascotas[indice], vecTipos,vecColores ,tamTipos,tamColores);
					modificar=subMenuModificar();

					switch(modificar)
					{
						case 1:
						//TIPOS
							systemCls();
							mostrarTipos(vecTipos, tamTipos);
							printf("Ingrese id nuevo tipo: ");
							scanf("%d", &auxMascota.idTipo);
							validarIDs(&auxMascota, 1);
							printf("Confirma modificacion?: ");
							fflush(stdin);
							confirma = getchar();
							if(confirma == 's')
							{
								vecMascotas[indice].idTipo=auxMascota.idTipo;
								mostrarMascota(vecMascotas[indice], vecTipos,vecColores ,tamTipos,tamColores);
								printf("\n\nModificacion exitosa.\n\n");
							}
							else
							{
								printf("\n\nSe ha cancelado la modificacion.\n\n");
							}
							break;
						case 2:
							systemCls();
							printf("\nEsta vacunada su mascota? s/n: ");
							fflush(stdin);
							scanf("%c",&auxMascota.vacunado);
							validarCaracterVacunado(&auxMascota);
							printf("Confirma modificacion?: ");
							fflush(stdin);
							confirma = getchar();
							if(confirma == 's')
							{
								vecMascotas[indice].vacunado=auxMascota.vacunado;
								mostrarMascota(vecMascotas[indice], vecTipos,vecColores ,tamTipos,tamColores);
								printf("\n\nModificacion exitosa.\n\n");
							}
							else
							{
								printf("Se ha cancelado la modificacion.\n\n");
							}
							break;

						default:
							break;
						}
						systemCls();
						mostrarMascota(vecMascotas[indice], vecTipos,vecColores ,tamTipos,tamColores);
						printf("Desea cambiar otra area?:");
						fflush(stdin);
						scanf("%c", &seguir);
						validarCaracterSeguir(&seguir);

					}

			}while(seguir!='n');
		}
		todoOk = 1;
	}
	return todoOk;
}

////////////////////////////////////////////////////////////////BUSCAR//////////////////////////////////////////////////////////////////////////////////
int buscarMascota(int* pIndice, int legajo, eMascota vec[], int tam)
{
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if( !vec[i].isEmpty && vec[i].id == legajo )
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
        todoOk = 1;
    }
    return todoOk;
}
////////////////////////////////////////////////////////////////BAJA//////////////////////////////////////////////////////////////////////////////////


int bajaMascotas(eMascota vecMascotas[], eTipo vecTipos[],eColor vecColores[] ,int tamMascotas, int tamTipos, int tamColores)
{
	systemCls();
    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    int flag;//para ver si hay o no gente para dar de baja
    if(vecMascotas != NULL && vecTipos != NULL && vecColores != NULL && tamMascotas > 0 && tamTipos > 0 && tamColores >0)
    {
        printf("**** Baja Mascota ****\n\n");

        flag=mostrarMascotas(vecMascotas,vecTipos,vecColores, tamMascotas,tamTipos,tamColores);
		if(flag==-1)
		{
			printf("Primero debe haber un algún alumno dado de alta para realizar una baja\n\n");
		}
		else
		{
			printf("Ingrese legajo a dar de baja: ");
			scanf("%d", &legajo);
			buscarMascota(&indice, legajo, vecMascotas, tamMascotas);

			while(indice == -1)
			{
				printf("No existe un mascota con legajo: %d\n", legajo);
				printf("Ingrese legajo a dar de baja valido: ");
				scanf("%d", &legajo);
				buscarMascota(&indice, legajo, vecMascotas, tamMascotas);
			}
				systemCls();
				mostrarMascota(vecMascotas[indice], vecTipos,vecColores, tamTipos, tamColores);
				printf("Confirma baja?: ");
				fflush(stdin);
				confirma = getchar();

				if(confirma == 's')
				{
					vecMascotas[indice].isEmpty = 1;
					printf("Baja exitosa.\n");
				}
				else
				{
					printf("Se ha cancelado la baja.\n");
				}

			todoOk = 1;
		}
    }
    return todoOk;
}

//////////////////////////////////////////////////////////////ORDENAR//////////////////////////////////////////////////////////////////////////////////////////////////////////
int ordenarMascotas(eMascota vecMascotas[], eTipo vecTipos[],eColor vecColores[] ,int tamMascotas, int tamTipos, int tamColores)
{
	int todoOk = 0;
	eMascota aux;

		    if(vecMascotas != NULL && vecTipos != NULL && vecColores != NULL && tamMascotas > 0 && tamTipos > 0 && tamColores >0)
		    {
		        for(int i = 0 ; i < tamMascotas  - 1 ; i++)
		        {
		            for(int j = i + 1 ; j < tamMascotas ; j++)
		            {
						if((vecMascotas[i].idTipo > vecMascotas[j].idTipo)
							||(vecMascotas[i].idTipo == vecMascotas[j].idTipo
							&& strcmp(vecMascotas[i].nombre, vecMascotas[j].nombre) > 0))
							{
								aux = vecMascotas[i];
								vecMascotas[i] = vecMascotas[j];
								vecMascotas[j] = aux;
							}
		            }
		        }
		        todoOk = 1;
		    }
		    return todoOk;
}


