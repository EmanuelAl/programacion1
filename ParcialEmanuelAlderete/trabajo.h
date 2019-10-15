
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int idTrabajo;
    char patente[20];
    int idServicio;
    eFecha fecha;
    int isEmpty;

} eTrabajo;

void listarTrabajos(eTrabajo trabajo[], int tam,eServicio servicio[],int tamS);
void mostrarTrabajos(eTrabajo trabajo[], int tam,eServicio servicio[],int tamS);
void mostrarTrabajo(eTrabajo trabajo,eServicio servicio[],int tamS);
int altaTrabajo(eTrabajo vec[], int tam,int idTrabajo,eServicio servicios[], int tamS,eAuto autos[],int tamAuto);
int bajaTrabajo(eTrabajo vec[], int tam,eServicio servicio[],int tamS);
int modificarTrabajo(eTrabajo vec[], int tam,eServicio servicios[], int tamS);
int buscarLibreTrabajo(eTrabajo vec[], int tam);
int estaCargadoTrabajo(eTrabajo vec[], int tam);
int buscarTrabajo(int idTrabajo, eTrabajo vec[], int tam);
eTrabajo newTrabajo( int idTrabajo,
               char patente[],
               int idServicio,
               eFecha fecha);

int buscarTrabajoPatente(char patente[], eTrabajo vec[], int tam);
void inicializarTrabajo(eTrabajo vec[], int tam);
