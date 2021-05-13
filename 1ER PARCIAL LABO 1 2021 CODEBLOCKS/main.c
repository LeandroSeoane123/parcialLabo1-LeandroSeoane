#define CT 10
#define CF 10
#define CS 4
#include <stdio.h>
#include <stdlib.h>
#include "trabajoServicio.h"
#include "seoane.h"


int main()
{
    int opcion;
    eTrabajo arrayDeTrabajos[CT];
    eServicio arrayDeServicios[CS];
    eFecha arrayDeFechas[CF];

    hardcodearTrabajos(arrayDeTrabajos, CT);
    hardcodearServicios(arrayDeServicios, CS);
    hardcodearFechas(arrayDeFechas, CF);

   do
    {
        getInt("***** ABM TRABAJOS Y SERVICIOS: MENU DE OPCIONES *****"
               "\n1. Alta trabajo."
               "\n2. Modificar trabajo."
               "\n3. Baja trabajo."
               "\n4. Listar trabajos."
               "\n5. Listar servicios."
               "\n6. Total de pesos por los servicios prestados."
               "\n7. Salir."
               "\nIngrese la opcion que desea realizar: ", &opcion);

        switch(opcion)
        {
        case 1:
            cargarTrabajo(arrayDeTrabajos, CT, arrayDeServicios, CS, arrayDeFechas, CF);
            break;
        case 2:
            modificarTrabajo(arrayDeTrabajos, CT, arrayDeServicios, CS, arrayDeFechas, CF);
            break;
        case 3:
            bajaLogicaTrabajo(arrayDeTrabajos, CT, arrayDeServicios, CS, arrayDeFechas, CF);
            break;
        case 4:
            mostrarTrabajos(arrayDeTrabajos, CT, arrayDeServicios, CS, arrayDeFechas, CF);
            break;
        case 5:
            mostrarServicios(arrayDeServicios, CS);
            break;
        case 6:
            puts("\nPROXIMAMENTE");
            break;
        case 7:
            puts("\nGracias por utilizar el programa!");
            break;
        }

        validarMenu(opcion, 1, 7);
        fflush(stdin);
        getchar();
        system("cls");

    }while(opcion !=7);


    return 0;
}
