typedef struct
{
    int idMarca;
    char descMarca[20];
} eMarca;

int hardcodearMarcas( eMarca vec[], int tam, int cantidad);
void mostrarMarcas(eMarca marcas[], int tam);
void mostrarMarca(eMarca marca);
int cargarDescMarca(int id, eMarca vec[], int tam, char desc[]);
