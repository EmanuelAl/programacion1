#include <stdio.h>
#include <stdlib.h>

#include "color.h"
/** \brief funcion para cargar el vector ingresado
 *
 * \param eColor vec[] vector a ser cargado
 * \param int tam es el tamaño del vector a ser cargado
 * \param int cantidad la cantidad que cargaremos al vector
 * \return 0 si no cargo el vector, sino devuelve la cantidad cargada
 *
 */

int hardcodearColores( eColor vec[], int tam, int cantidad)
{
    int cont = 0;

    eColor aux[]={
    {5000,"Negro"},
    {5001,"Blanco"},
    {5002,"Gris"},
    {5003,"Rojo"},
    {5004,"Azul"}
    };

    if( cantidad <= 5 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = aux[i];
            cont++;
        }
    }

    return cont;
}
void mostrarColores(eColor color[], int tam){
    printf(" Id   Descripcion\n\n");
    for(int i=0; i < tam; i++){
        mostrarColor( color[i]);
    }
    printf("\n");
}

void mostrarColor(eColor color){

    printf("  %d      %10s\n", color.idColor, color.nombreColor);

}
int cargarDescColor(int id, eColor vec[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == vec[i].idColor){
            strcpy(desc, vec[i].nombreColor);
            todoOk = 1;
            break;
        }
    }
}
