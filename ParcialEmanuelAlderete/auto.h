
typedef struct
{
    int idAuto;
    char patente[20];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
} eAuto;
int buscarLibre(eAuto vec[], int tam);
altaAuto(int id,eAuto vec[],int tamAuto,eMarca marca[],int tamMarca,eColor color[],int tamColor);
eAuto newAuto( int idAuto,
    char patente[],
    int idMarca,
    int idColor,
    int modelo);
