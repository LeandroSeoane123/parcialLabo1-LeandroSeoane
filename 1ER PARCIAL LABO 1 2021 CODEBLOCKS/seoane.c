#include "Seoane.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void getInt (char* mensaje, int* entero)
{
    printf(mensaje);
    scanf("%d", entero);
}

void getFloat (char* mensaje, float* flotante)
{
    printf(mensaje);
    scanf("%f", flotante);
}

void getString(char* mensaje, char* cadena)
{
    printf(mensaje);
    fflush(stdin);
    gets(cadena);
}

void getChar (char* mensaje, char* caracter)
{
    printf(mensaje);
    fflush(stdin);
    scanf("%c", caracter);
}

void validarMenu (int opcion, int opcionMenor, int opcionMayor)
{
    if(opcion <opcionMenor || opcion >opcionMayor)
    {
        puts("\nLa opcion ingresada es incorrecta.");
    }
}

void validarDia (int* dia)
{
    while(*dia > 31 || *dia < 1)
    {
        getInt("\nERROR: El dia ingresado es incorrecto, por favor intente nuevamente: ", dia);
    }
}

void validarMes (int* mes)
{
    while(*mes > 12 || *mes < 1)
    {
        getInt("\nERROR: El mes ingresado es incorrecto, por favor intente nuevamente: ", mes);
    }
}

void validarAnio (int* anio)
{
    while(*anio > 2021 || *anio < 2021)
    {
        getInt("\nERROR: El anio ingresado es incorrecto, por favor intente nuevamente: ", anio);
    }
}
