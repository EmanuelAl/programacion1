#include <stdio.h>
#include <stdlib.h>
#include "marca.h"
/** \brief funcion para cargar el vector ingresado
 *
 * \param eColor vec[] vector a ser cargado
 * \param int tam es el tamaño del vector a ser cargado
 * \param int cantidad la cantidad que cargaremos al vector
 * \return 0 si no cargo el vector, sino devuelve la cantidad cargada
 *
 */
int hardcodearMarcas( eMarca vec[], int tam, int cantidad)
{
    int cont = 0;

    eMarca marcas[]={
    {1000,"Renault"},
    {1001,"Fiat"},
    {1002,"Ford"},
    {1003,"Chevrolet"},
    {1004,"Peugeot"}
    };

    if( cantidad <= 5 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = marcas[i];
            cont++;
        }
    }

    return cont;
}
void mostrarMarcas(eMarca marcas[], int tam){
    printf(" Id   Descripcion\n\n");
    for(int i=0; i < tam; i++){
        mostrarMarca( marcas[i]);
    }
    printf("\n");
}

void mostrarMarca(eMarca marca){

    printf("  %d      %10s\n", marca.idMarca, marca.descMarca);

}

int cargarDescMarca(int id, eMarca vec[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == vec[i].idMarca){
            strcpy(desc, vec[i].descMarca);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}
