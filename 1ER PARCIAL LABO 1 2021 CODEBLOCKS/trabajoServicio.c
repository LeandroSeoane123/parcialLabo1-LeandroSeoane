#include "trabajoServicio.h"
#include "seoane.h"
#define VACIO 1
#define OCUPADO 0
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
        getInt("\nIngrese que tipo de servicio desea que le realicemos a su bicicleta: ", &idServicio);
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

int modificarTrabajo (eTrabajo arrayTrabajo[], int tamT, eServicio arrayServicio[], int tamS, eFecha arrayFecha[], int tamF)
{
    int retorno;
    int idTrabajo;
    char idTraStr;
    char marcaBicicleta[25];
    int rodadoBicicleta;
    int idServicio;
    int idFecha;
    int posT;
    int posS;
    int posF;
    int len;

    retorno = 0;

    len = tra_len(arrayTrabajo, tamT);

    if(len > 0)
    {
        getInt("\nIngrese el id del trabajo que desea modificar: ", &idTrabajo);
        posT = buscarTrabajoPorId(arrayTrabajo, tamT, idTrabajo);

        if(posT != -1)
        {
            puts("\nTRABAJO ENCONTRADO.");
            posS = buscarServicioPorTrabajo(arrayTrabajo, posT, arrayServicio, tamS);
            posF = buscarFechaPorTrabajo(arrayTrabajo, posT, arrayFecha, tamF);
            puts("\n--- ID -------- MARCA -------- RODADO -------- SERVICIO -------- PRECIO -------- FECHA");
            mostrarUnTrabajo(arrayTrabajo, posT, arrayServicio, posS, arrayFecha, posF);
            tra_cargarUltimoID("config.csv", &idTraStr);
            idTrabajo = atoi(&idTraStr);
            idTrabajo++;
            tra_guardarUltimoID("config.csv", idTrabajo);
            getString("\nRe-ingrese la marca de la bicicleta que esta modificando: ", marcaBicicleta);
            strlwr(marcaBicicleta);
            marcaBicicleta[0] = toupper(marcaBicicleta[0]);
            mostrarServicios(arrayServicio, tamS);
            getInt("\nRe-ingrese el tipo de servicio que desea que le realicemos a su bicicleta: ", &idServicio);
            posS = buscarServicioPorId(arrayServicio, tamS, idServicio);
            while(posS == -1)
            {
                getInt("\nERROR: El numero ingresado no corresponde con ningun servicio existente."
                       "\nPor favor, re-ingrese que tipo de servicio desea que le realicemos a su bicicleta: ", &idServicio);
                posS = buscarServicioPorId(arrayServicio, tamS, idServicio);
            }
            rodadoBicicleta = arrayTrabajo[posT].rodadoBicicleta;
            idFecha = arrayTrabajo[posT].idFecha;
            agregarTrabajo(arrayTrabajo, posT, idTrabajo, marcaBicicleta, rodadoBicicleta, idServicio, idFecha);

            puts("\nEL TRABAJO HA SIDO MODIFICADO CON EXITO, NOS COMUNICAREMOS UNA VEZ ESTE REALIZADO.");

            retorno = 1;
        }
        else
        {
            puts("\nERROR: El ID ingresado no corresponde con ningun trabajo cargado anteriormente.");
            retorno = 0;
        }
    }
    else
    {
        puts("\nERROR: No hay trabajos cargados para modificar.");
        retorno = 0;
    }

    return retorno;
}

int bajaLogicaTrabajo (eTrabajo arrayTrabajo[], int tamT, eServicio arrayServicio[], int tamS, eFecha arrayFecha[], int tamF)
{
    int retorno;
    int len;
    int posT;
    int posS;
    int posF;
    int idTrabajo;
    int confirmacion;

    retorno = 0;

    len = tra_len(arrayTrabajo, tamT);

    if(len > 0)
    {
        getInt("\nIngrese el id del trabajo que desea borrar: ", &idTrabajo);
        posT = buscarTrabajoPorId(arrayTrabajo, tamT, idTrabajo);

        if(posT != -1)
        {
            puts("\nTRABAJO ENCONTRADO.");
            posS = buscarServicioPorTrabajo(arrayTrabajo, posT, arrayServicio, tamS);
            posF = buscarFechaPorTrabajo(arrayTrabajo, posT, arrayFecha, tamF);
            puts("\n--- ID -------- MARCA -------- RODADO -------- SERVICIO -------- PRECIO -------- FECHA");
            mostrarUnTrabajo(arrayTrabajo, posT, arrayServicio, posS, arrayFecha, posF);

            getInt("\nEsta seguro que desea eliminar este trabajo?"
                   "\nIngrese '1' para si o cualquier otro numero para no: ", &confirmacion);

            if(confirmacion == 1)
            {
                arrayTrabajo[posT].isEmpty = VACIO;
                retorno = 1;
                puts("\nTRABAJO BORRADO CON EXITO.");
            }
            else
            {
                puts("\nOPERACION CANCELADA.");
                retorno = 0;
            }
        }
        else
        {
            puts("\nERROR: El ID ingresado no corresponde con ningun trabajo cargado anteriormente.");
        }

    }
    else
    {
        puts("\nERROR: No hay trabajos cargados para borrar.");
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
    arrayTrabajo[posT].isEmpty = OCUPADO;
}

int buscarServicioPorTrabajo(eTrabajo arrayTrabajo[], int posT, eServicio arrayServicio[], int tamS)
{
    int i;
    int pos;

    pos = -1;

    for(i=0; i<tamS; i++)
    {
        if(arrayServicio[i].isEmpty == OCUPADO)
        {
            if(arrayServicio[i].id == arrayTrabajo[posT].idServicio)
            {
                pos = i;
                break;
            }
        }
    }

    return pos;
}

int buscarFechaPorTrabajo (eTrabajo arrayTrabajo[], int posT, eFecha arrayFecha[], int tamF)
{
    int i;
    int pos;

    pos = -1;

    for(i=0; i<tamF; i++)
    {
        if(arrayFecha[i].isEmpty == OCUPADO)
        {

            if(arrayFecha[i].idFecha == arrayTrabajo[posT].idFecha)
            {
                pos = i;
                break;
            }
        }
    }

    return pos;
}

void mostrarTrabajos (eTrabajo arrayTrabajo[], int tamT, eServicio arrayServicio[], int tamS, eFecha arrayFecha[], int tamF)
{
    int i;
    int len;
    int posS;
    int posF;

    len = tra_len(arrayTrabajo, tamT);

    if(len > 0)
    {
        puts("\n--- ID -------- MARCA -------- RODADO -------- SERVICIO -------- PRECIO -------- FECHA");

        for(i=0; i<tamT; i++)
        {
            if(arrayTrabajo[i].isEmpty == OCUPADO)
            {
                posS = buscarServicioPorTrabajo(arrayTrabajo, i, arrayServicio, tamS);
                if(posS != -1)
                {
                    posF = buscarFechaPorTrabajo(arrayTrabajo, i, arrayFecha, tamF);
                    if(posF != -1)
                    {
                        mostrarUnTrabajo(arrayTrabajo, i, arrayServicio, posS, arrayFecha, posF);
                    }
                    else
                    {
                        puts("\nERROR: Fallo al buscar la fecha del ingreso.");
                    }
                }
                else
                {
                    puts("\nERROR: Fallo al buscar el servicio contratado.");
                }
            }
        }
    }
    else
    {
        puts("\nERROR: No hay trabajos cargados para mostrar.");

    }
}

void mostrarUnTrabajo (eTrabajo arrayTrabajo[], int posT, eServicio arrayServicio[], int posS, eFecha arrayFecha[], int posF)
{
    printf("%6d %14s %15d %17s %15.2f %7d/%d/%d", arrayTrabajo[posT].id,
                                                  arrayTrabajo[posT].marcaBicicleta,
                                                  arrayTrabajo[posT].rodadoBicicleta,
                                                  arrayServicio[posS].descripcion,
                                                  arrayServicio[posS].precio,
                                                  arrayFecha[posF].dia,
                                                  arrayFecha[posF].mes,
                                                  arrayFecha[posF].anio);
}
