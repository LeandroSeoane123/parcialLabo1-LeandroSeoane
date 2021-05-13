typedef struct{

    int id;
    char marcaBicicleta[25];
    int rodadoBicicleta;
    int idServicio;
    int idFecha;
    int isEmpty;

}eTrabajo;

int hardcodearTrabajos (eTrabajo arrayTrabajo[], int tam);
int buscarLibreTrabajo (eTrabajo arrayTrabajo[], int tam);
int tra_guardarUltimoID(char* path, int id);
int tra_cargarUltimoID (char* path, char* id);
