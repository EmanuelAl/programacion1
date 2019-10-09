#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "servicio.h"
/** \brief funcion para cargar el vector ingresado
 *
 * \param eColor vec[] vector a ser cargado
 * \param int tam es el tamaño del vector a ser cargado
 * \param int cantidad la cantidad que cargaremos al vector
 * \return 0 si no cargo el vector, sino devuelve la cantidad cargada
 *
 */
int hardcodearServicio( eServicio vec[], int tam, int cantidad)
{
    int cont = 0;

    eServicio aux[]={
    {20000,"Lavado",250},
    {20001,"Pulido",300},
    {20002,"Encerado",400},
   {20003,"Completo",600},
    };

    if( cantidad <= 4 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = aux[i];
            cont++;
        }
    }

    return cont;
}
void mostrarServicios(eServicio servicios[], int tam){
    printf(" Id   Descripcion    precio \n\n");
    for(int i=0; i < tam; i++){
        mostrarServicio( servicios[i]);
    }
    printf("\n");
}

void mostrarServicio(eServicio servicio){

    printf("  %d      %10s     %.2f \n", servicio.id, servicio.descServicio,servicio.precio);

}
int cargarDescServicio(int id, eServicio vec[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == vec[i].id){
            strcpy(desc, vec[i].descServicio);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}
