#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "servicio.h"
#include "auto.h"
#include "input.h"
#include "trabajo.h"

void listarTrabajos(eTrabajo trabajo[], int tam,eServicio servicio[],int tamS)
{
    printf(" Id        patente    Servicio      fecha  \n\n");
    for(int i=0; i < tam; i++)
    {
        mostrarTrabajo( trabajo[i], servicio, tamS);
    }
    printf("\n");
}

void mostrarTrabajos(eTrabajo trabajo[], int tam,eServicio servicio[],int tamS)
{
    int flag = 0;
    system("cls");
    printf(" Id        patente    Servicio      fecha  \n\n");
    for(int i=0; i < tam; i++)
    {
        if( trabajo[i].isEmpty == 0)
        {
            mostrarTrabajo( trabajo[i], servicio, tamS);
            flag = 1;
        }

    }
    if( flag == 0)
    {
        printf("\nNo hay trabajos que mostrar\n");
    }
    printf("\n");
}

void mostrarTrabajo(eTrabajo trabajo,eServicio servicio[],int tamS)
{
    char descServicio[20];
    cargarDescServicio(trabajo.idServicio,servicio,tamS,descServicio);
    printf("  %d      %10s    %s    %02d/%02d/%d \n", trabajo.idTrabajo, trabajo.patente,descServicio,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);

}

int altaTrabajo(eTrabajo vec[], int tam,int idTrabajo,eServicio servicios[], int tamS,eAuto autos[],int tamAuto)
{
    int todoOk = 0;
    int indice;
    char patente[20];
//    int yaIngresado;
    int idServicio;
    eFecha fecha;

    system("cls");

    printf("***** Alta Trabajo *****\n\n");

    indice = buscarLibreTrabajo(vec, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {

        mostrarAutos(autos,tamAuto);
        printf("Ingrese patente: ");
        fflush(stdin);
        gets(patente);
        /*yaIngresado=buscarTrabajoPatente(patente,vec,tamAuto);
        while(yaIngresado==-1)
        {

            printf(" Patente no encontrada!\n");

            printf("Ingrese patente nuevamente: ");
            fflush(stdin);
            gets(patente);
            system("cls");
        }*/

        mostrarServicios(servicios,tamS);
        getNumeroIntentos(&idServicio,"Ingrese id de servicio: ","Error.Ingrese  ID correcto: \n",20000,20003,3);//validamos
        printf("Ingrese fecha dd/mm/aaaa: ");
        scanf("%d %d %d", &fecha.dia, &fecha.mes, &fecha.anio);


        vec[indice] = newTrabajo(idTrabajo,patente,idServicio,fecha);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}
int buscarLibreTrabajo(eTrabajo vec[], int tam)
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
int estaCargadoTrabajo(eTrabajo vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty==0)
        {
            indice=1;
            break;
        }
    }
    return indice;
}
int buscarTrabajo(int idTrabajo, eTrabajo vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].idTrabajo == idTrabajo && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
eTrabajo newTrabajo( int idTrabajo,
                     char patente[],
                     int idServicio,
                     eFecha fecha)
{
    eTrabajo aux;
    aux.idTrabajo=idTrabajo;
    aux.idServicio=idServicio;
    strcpy(aux.patente,patente);
    aux.isEmpty=0;

    return aux;

}
int bajaTrabajo(eTrabajo vec[], int tam,eServicio servicio[],int tamS)
{
    int todoOk = 0;
    char patente[20];
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Trabajo *****\n\n");
    printf("Ingrese patente: ");
    gets(patente);

    indice = buscarTrabajoPatente(patente, vec, tam);

    if( indice == -1)
    {
        printf("No existe el Trabajo con esa patente\n\n");

    }
    else
    {
        mostrarTrabajo(vec[indice],servicio,tamS);

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
int modificarTrabajo(eTrabajo vec[], int tam,eServicio servicio[], int tamS)
{
    int todoOk = 0;
    char patente[20];
    int indice;
    int opcion;
    int idServicio;
    system("cls");
    printf("***** Modificar Trabajo *****\n\n");
    printf("Ingrese patente: ");
    gets(patente);

    indice = buscarTrabajoPatente(patente, vec, tam);

    if( indice == -1)
    {
        printf("No existe el trabajo con esa patente\n\n");

    }
    else
    {
        mostrarTrabajo(vec[indice],servicio,tamS);
        printf("1- Modificar servicio\n");
        printf("2- Modificar fecha\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        getNumero( &opcion,"Ingrese opcion: ","Error.opcion incorrecta, vuelva a ingresar opcion\n",1,3);
        switch(opcion)
        {
        case 1:
            mostrarServicios(servicio,tamS);
            getNumeroIntentos(&idServicio,"Ingrese id del servicio : ","Error.Ingrese  ID correcto: \n",20000,20003,3);//validamos
            break;
            todoOk=1;
        case 2:

            todoOk=1;
            break;
        case 3:
            printf("Se ha cancelado la modificacion ");
            break;

        }
    }

    return todoOk;
}
int buscarTrabajoPatente(char patente[], eTrabajo vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( strcmp(vec[i].patente,patente)==0 && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void inicializarTrabajo(eTrabajo vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}
