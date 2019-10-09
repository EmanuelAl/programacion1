#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "auto.h"
void mostrarAutos(eAuto autos[], int tam){
    printf(" Id   patente  idMarca   idColor  modelo  \n\n");
    for(int i=0; i < tam; i++){
        mostrarAuto( autos[i]);
    }
    printf("\n");
}

void mostrarAuto(eAuto aut){

    printf("  %d      %10s   %d    %d   %d \n", aut.idAuto, aut.patente,aut.idMarca,aut.idColor,aut.modelo);

}
altaAuto(int id,eAuto vec[],int tamAuto,eMarca marca[],int tamMarca,eColor color[],int tamColor){
int todoOk = 0;
char patente[20];
    int indice;
    int idMarca;
    int idColor;
    int modelo;

    system("cls");

    printf("*****Alta Auto*****\n\n");

    indice = buscarLibre(vec, tamAuto);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese patente: ");
        fflush(stdin);
        gets(patente);

        mostrarColores(color,tamColor);
        printf("Ingrese id color: ");
        scanf("%d",&idColor);
        mostrarMarcas(marca,tamMarca);
        printf("Ingrese id Marca: ");
        scanf("%d", &idMarca);
        printf("Ingrese año de modelo : ");
        scanf("%d", &modelo);

        vec[indice] = newAuto(id, patente , idMarca , idColor , modelo);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;

}

int buscarLibre(eAuto vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty==1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int buscarAuto(int idAuto, eAuto vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].idAuto == idAuto && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
eAuto newAuto( int idAuto,
    char patente[],
    int idMarca,
    int idColor,
    int modelo)
    {
    eAuto aux;
    aux.idAuto=idAuto;
    aux.idColor=idColor;
    aux.idMarca=idMarca;
    aux.modelo=modelo;
    strcpy(aux.patente,patente);
    aux.isEmpty=0;

    return aux;

    }
int bajaAuto(eAuto vec[], int tam)
{
    int todoOk = 0;
  char patente[20];
    int indice;
    int idMarca;
    int idColor;
    int modelo;
    char confirma;
    system("cls");
    printf("***** Baja Auto *****\n\n");
    printf("Ingrese patente: ");
    gets(patente);

    indice = buscarAuto(patente, vec, tam);

    if( indice == -1)
    {
        printf("No existe el auto con esa patente\n\n");

    }
    else
    {
        mostrarAuto(vec[indice]);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}
int buscarAlumno(char patente[], eAuto vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( (strcmp(vec[i].patente,patente))==0 && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
