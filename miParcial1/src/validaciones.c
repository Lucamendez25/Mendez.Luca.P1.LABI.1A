/*
 * validaciones.c
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



int validarCaracterSeguir(char *pSeguir)
{
	int retorno = 0;
	if(pSeguir!=NULL)
	{
		while(*pSeguir!='s' && *pSeguir!='n' && *pSeguir!='S' && *pSeguir!='N')
		{
			printf("Esta opcion es incorrecta, intentelo nuevamente (s/n): ");
			fflush(stdin);
			scanf("%c", pSeguir);
			*pSeguir=tolower(*pSeguir);
		}
	retorno = 1;
	}

	return retorno;
}


int validarNombreMascota(eMascota *pMascota, int tam)
{
	int retorno = 0;
	if(pMascota !=NULL && tam > 0)
	{
		while(strlen(pMascota->nombre) > tam)
		{
			printf("Nombre invalido, intentelo nuevamente: ");
			fflush(stdin);
			scanf("%s", pMascota->nombre);
		}
		retorno = 1;
	}

	return retorno;
}


int validarIDs(eMascota *pMascota, int condicion)
{
	int retorno = 0;
	if(pMascota!=NULL)
	{
		if(condicion == 1)
		{
			while(pMascota->idTipo<100 || pMascota->idTipo>104)
			{
				printf("Ningun tipo tiene este id, intentelo nuevamente: ");
				scanf("%d", &pMascota->idTipo);
				retorno = 1;
			}
		}
		else
		{
			while(pMascota->idColor<100 || pMascota->idColor>104)
			{
				printf("Id color invalido, intentelo nuevamente: ");
				scanf("%d", &pMascota->idColor);
			}
			retorno = 1;
		}

	}
	return retorno;
}

int validarIdServicios(eServicio vecServicios[],int id,  int tam)
{
	int todoOk=0;

	if(vecServicios!=NULL && id>0 && tam>0)
	{
		for(int i = 0; i<tam;i++)
		{
			if(vecServicios[i].id == id )
			{
				todoOk=1;
				break;
			}
		}
	}
	return todoOk;
}


int validarEdades(eMascota *pMascota)
{
	int retorno = 0;

	if(pMascota!=NULL)
	{
		while(pMascota->edad<0 || pMascota->edad>50)
		{
			printf("edad invalida, intentelo nuevamente: ");
			scanf("%d",&pMascota->edad);

		}
	retorno = 1;
	}

	return retorno;
}


int validarCaracterVacunado(eMascota *pMascota)
{
	int retorno = 0;
		if(pMascota!=NULL)
		{
			while(pMascota->vacunado!='s' && pMascota->vacunado!='n')
			{
				printf("Lo ingresado es incorrecto, intentelo nuevamente: s/n ");
				fflush(stdin);
				scanf("%c", &pMascota->vacunado);
				pMascota->vacunado=tolower(pMascota->vacunado);
			}
			retorno = 1;
		}

	return retorno;
}


int validarFecha(eTrabajo *pTrabajo, int crit)
{
	int retorno = 0;
	if(pTrabajo !=NULL && crit > 0)
	{
		switch(crit)
		{
			case 1:

				if(pTrabajo->fecha.mes == 1 || pTrabajo->fecha.mes == 3 || pTrabajo->fecha.mes == 5 ||
				   pTrabajo->fecha.mes == 7 || pTrabajo->fecha.mes == 8 || pTrabajo->fecha.mes == 10 ||
				   pTrabajo->fecha.mes == 12)
				{
					while(pTrabajo->fecha.dia < 1 || pTrabajo->fecha.dia >31 )
					{
						printf("Dia invalido, intentelo nuevamente: ");
						scanf("%d",&pTrabajo->fecha.dia);
					}
				}
				else
				{
					if(pTrabajo->fecha.mes == 4 || pTrabajo->fecha.mes == 6 || pTrabajo->fecha.mes == 9 ||
					   pTrabajo->fecha.mes == 11)
					{
						while(pTrabajo->fecha.dia < 1 || pTrabajo->fecha.dia >30 )
						{
							printf("Dia invalido, intentelo nuevamente: ");
							scanf("%d",&pTrabajo->fecha.dia);
						}
					}
					else
					{
						while(pTrabajo->fecha.dia < 1 || pTrabajo->fecha.dia >28 )
						{
							printf("Dia invalido, intentelo nuevamente: ");
							scanf("%d",&pTrabajo->fecha.dia);
						}
					}
				}

				break;
			case 2:
				while(pTrabajo->fecha.mes < 1 || pTrabajo->fecha.mes >12 )
				{
					printf("Mes invalido, intentelo nuevamente: ");
					scanf("%d",&pTrabajo->fecha.mes);
				}
				break;
			case 3:
				while(pTrabajo->fecha.anio < 1800 || pTrabajo->fecha.anio >2023 )
				{
					printf("Año invalido, intentelo nuevamente: ");
					scanf("%d",&pTrabajo->fecha.anio);
				}
				break;
		}
	}

	return retorno;
}


