#include "servicio.h"
#include "seoane.h"
#define VACIO 1
#define OCUPADO 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hardcodearServicios(eServicio arrayServicio[], int tam)
{
    int i;
    int retorno;

    retorno = 0;

    eServicio arrayServicioLocal[4] = {{20000, "Limpieza", 250, OCUPADO},
                                       {20001, "Parche", 300, OCUPADO},
                                       {20002, "Centrado", 400, OCUPADO},
                                       {20003, "Cadena", 350, OCUPADO}};

    for(i=0; i<tam; i++)
    {
        arrayServicio[i] = arrayServicioLocal[i];
        retorno = 1;
    }

    return retorno;
}

int buscarServicioPorId (eServicio arrayServicio[], int tam, int idServicio)
{
    int i;
    int posS;

    posS = -1;

    for(i=0; i<tam; i++)
    {
        if(arrayServicio[i].isEmpty == OCUPADO)
        {
            if(arrayServicio[i].id == idServicio)
            {
                posS = i;
                break;
            }
        }
    }

    return posS;
}

void mostrarServicios (eServicio arrayServicio[], int tam)
{
    int i;

    puts("ID -------- SERVICIO -------- PRECIO");
    for(i=0; i<tam; i++)
    {
        if(arrayServicio[i].isEmpty == OCUPADO)
        {
            mostrarUnServicio(arrayServicio, i);
        }
    }
}

void mostrarUnServicio(eServicio arrayServicio[], int posS)
{
    printf("\n%d %14s %15.2f", arrayServicio[posS].id,
                             arrayServicio[posS].descripcion,
                             arrayServicio[posS].precio);

}
