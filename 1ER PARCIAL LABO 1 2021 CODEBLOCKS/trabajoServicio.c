#include "trabajoServicio.h"
#include "seoane.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cargarTrabajo (eTrabajo arrayTrabajo[], int tamT, eServicio arrayServicio[], int tamS, eFecha arrayFecha[], int tamF)
{
    int posT;
    int posF;
    int posS;
    int retorno;
    int idTrabajo;
    char idTraStr;
    char marcaBicicleta[25];
    int rodadoBicicleta;
    int idServicio;
    int dia;
    int mes;
    int anio;
    int idFecha;

    posT = buscarLibreTrabajo(arrayTrabajo, tamT);
    posF = buscarLibreFecha(arrayFecha, tamF);

    if(posT != -1 && posF != -1)
    {
        puts("\nDISPONIBILIDAD ENCONTRADA.");
        tra_cargarUltimoID("config.csv", &idTraStr);
        idTrabajo = atoi(&idTraStr);
        idTrabajo++;
        tra_guardarUltimoID("config.csv", idTrabajo);
        idFecha = arrayFecha[posF].idFecha;
        getString("\nIngrese la marca de la bicicleta: ", marcaBicicleta);
        strlwr(marcaBicicleta);
        marcaBicicleta[0] = toupper(marcaBicicleta[0]);
        getInt("\nIngrese el rodado de la bicicleta: ", &rodadoBicicleta);
        getInt("\nIngrese el dia en el que entrega la bicicleta: ", &dia);
        validarDia(&dia);
        getInt("\nIngrese el mes en el que entrega la bicicleta: ", &mes);
        validarMes(&mes);
        getInt("\nIngrese el anio en el que entrega la bicicleta: ", &anio);
        validarAnio(&anio);
        mostrarServicios(arrayServicio, tamS);
        getInt("\nIngrese que tipo de servicio desea que le realizemos a su bicicleta: ", &idServicio);
        posS = buscarServicioPorId(arrayServicio, tamS, idServicio);
        while(posS == -1)
        {
            getInt("\nERROR: El numero ingresado no corresponde con ningun servicio existente."
                   "\nPor favor, re-ingrese que tipo de servicio desea que le realicemos a su bicicleta: ", &idServicio);
            posS = buscarServicioPorId(arrayServicio, tamS, idServicio);
        }

        agregarTrabajo (arrayTrabajo, posT, idTrabajo, marcaBicicleta, rodadoBicicleta, idServicio, idFecha);
        agregarFecha(arrayFecha, posF, dia, mes, anio);
        puts("\nTRABAJO CARGADO CON EXITO, NOS COMUNICAREMOS UNA VEZ ESTE REALIZADO.");

    }
    else
    {
        puts("\nLo sentimos, de momento no contamos con disponibilidad para atender su pedido.");
        retorno = 0;
    }

    return retorno;
}

void agregarTrabajo (eTrabajo arrayTrabajo[], int posT, int idTrabajo, char* marcaBicicleta, int rodadoBicicleta, int idServicio, int idFecha)
{
    arrayTrabajo[posT].id = idTrabajo;
    strcpy(arrayTrabajo[posT].marcaBicicleta, marcaBicicleta);
    arrayTrabajo[posT].rodadoBicicleta = rodadoBicicleta;
    arrayTrabajo[posT].idServicio = idServicio;
    arrayTrabajo[posT].idFecha = idFecha;
}
