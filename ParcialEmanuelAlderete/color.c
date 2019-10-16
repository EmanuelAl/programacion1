#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "color.h"
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
void listarColores(eColor color[], int tam){
    printf(" Id   Descripcion\n\n");
    for(int i=0; i < tam; i++){
        mostrarColor( color[i]);
    }
    printf("\n");
}

void mostrarColores(eColor color[], int tam){
    printf(" Id   Descripcion\n\n");
    for(int i=0; i < tam; i++){
        mostrarColor( color[i]);
    }
    printf("\n");
}

void mostrarColor(eColor color){

    printf("  %d      %s\n", color.idColor, color.nombreColor);

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
    return todoOk;
}
