#include "trabajo.h"
#include "seoane.h"
#define VACIO 1
#define OCUPADO 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hardcodearTrabajos (eTrabajo arrayTrabajo[], int tam)
{
    int i;
    int retorno;

    retorno = 0;

    for(i=0; i<tam; i++)
    {
        arrayTrabajo[i].isEmpty = VACIO;
        retorno = 1;
    }

    return retorno;
}

int buscarLibreTrabajo (eTrabajo arrayTrabajo[], int tam)
{
    int i;
    int pos;

    pos = -1;

    for(i=0; i<tam; i++)
    {
        if(arrayTrabajo[i].isEmpty == VACIO)
        {
            pos = i;
            break;
        }
    }

    return pos;
}

int tra_guardarUltimoID(char* path, int id)
{
    FILE* pFile;
    int retorno=0;

    pFile = fopen(path, "w");

    if(pFile != NULL)
    {
        fprintf(pFile,"%d", id);
        retorno=1;
    }

    fclose(pFile);

    return retorno;
}

int tra_cargarUltimoID (char* path, char* id)
{
    int retorno=0;
    FILE* pFile;

    pFile = fopen(path, "r");

    if(pFile != NULL)
    {
        fscanf(pFile, "%s", id);
        retorno=1;
    }

    fclose(pFile);

    return retorno;
}
