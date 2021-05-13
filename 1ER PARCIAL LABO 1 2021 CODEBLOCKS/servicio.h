typedef struct{

    int id;
    char descripcion[25];
    float precio;
    int isEmpty;

}eServicio;

int hardcodearServicios(eServicio arrayServicio[], int tam);
int buscarServicioPorId (eServicio arrayServicio[], int tam, int idServicio);
void mostrarServicios (eServicio arrayServicio[], int tam);
void mostrarUnServicio(eServicio arrayServicio[], int posS);
