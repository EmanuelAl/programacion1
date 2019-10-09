typedef struct
{
    int idColor;
    char nombreColor[20];

} eColor;

int hardcodearColores( eColor vec[], int tam, int cantidad);
void mostrarColores(eColor color[], int tam);
void mostrarColor(eColor color);
int cargarDescColor(int id, eColor vec[], int tam, char desc[]);


