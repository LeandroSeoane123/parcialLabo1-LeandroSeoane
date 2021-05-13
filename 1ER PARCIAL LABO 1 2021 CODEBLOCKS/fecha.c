#include "fecha.h"
#include "seoane.h"
#define VACIO 1
#define OCUPADO 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hardcodearFechas (eFecha arrayFecha[], int tam)
{
    int i;
    int retorno;

    retorno = 0;

    for(i=0; i<tam; i++)
    {
        arrayFecha[i].idFecha = i+1;
        arrayFecha[i].isEmpty = VACIO;
        retorno = 1;
    }

    return retorno;
}

int buscarLibreFecha (eFecha arrayFecha[], int tam)
{
    int i;
    int pos;

    pos = -1;

    for(i=0; i<tam; i++)
    {
        if(arrayFecha[i].isEmpty == VACIO)
        {
            pos = i;
            break;
        }
    }

    return pos;
}

void agregarFecha (eFecha arrayFecha[], int posF, int dia, int mes, int anio)
{
    arrayFecha[posF].dia = dia;
    arrayFecha[posF].mes = mes;
    arrayFecha[posF].anio = anio;
}


