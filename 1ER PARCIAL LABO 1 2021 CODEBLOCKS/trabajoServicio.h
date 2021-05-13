#include "trabajo.h"
#include "servicio.h"
#include "fecha.h"

int cargarTrabajo (eTrabajo arrayTrabajo[], int tamT, eServicio arrayServicio[], int tamS, eFecha arrayFecha[], int tamF);
void agregarTrabajo (eTrabajo arrayTrabajo[], int posT, int idTrabajo, char* marcaBicicleta, int rodadoBicicleta, int idServicio, int idFecha);
int modificarTrabajo (eTrabajo arrayTrabajo[], int tamT, eServicio arrayServicio[], int tamS);
int buscarServicioPorTrabajo (eTrabajo arrayTrabajo[], int posT, eServicio arrayServicio[], int tamS);
int buscarFechaPorTrabajo (eTrabajo arrayTrabajo[], int posT, eFecha arrayFecha[], int tamF);
void mostrarTrabajos (eTrabajo arrayTrabajo[], int tamT, eServicio arrayServicio[], int tamS, eFecha arrayFecha[], int tamF);
void mostrarUnTrabajo (eTrabajo arrayTrabajo[], int posT, eServicio arrayServicio[], int posS, eFecha arrayFecha[], int posF);
