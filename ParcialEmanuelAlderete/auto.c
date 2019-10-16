#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "auto.h"
#include "input.h"

int hardcodearAutos( eAuto vec[], int tam, int cantidad)
{
    int cont = 0;

    eAuto aux[]=
    {
        {2000,"123ABC",1000,5000,1997},
        {2001,"252HGF",1001,5001,1999},
        {2002,"555GJK",1002,5002,1874},
        {2003,"669BCA",1003,5003,2000},
        {2004,"122RTF",1004,5004,2007}
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
void listarAutos(eAuto autos[], int tam)
{
    printf(" Id            patente  idMarca   idColor  modelo  \n\n");
    for(int i=0; i < tam; i++)
    {
        mostrarAuto( autos[i]);
    }
    printf("\n");
}

void mostrarAutos(eAuto autos[], int tam)
{
    printf(" Id            patente  idMarca   idColor  modelo  \n\n");
    for(int i=0; i < tam; i++)
    {
        mostrarAuto( autos[i]);
    }
    printf("\n");
}

void mostrarAuto(eAuto aut)
{

    printf("  %d      %10s   %d    %d      %d \n", aut.idAuto, aut.patente,aut.idMarca,aut.idColor,aut.modelo);

}
int altaAuto(int id,eAuto vec[],int tamAuto,eMarca marca[],int tamMarca,eColor color[],int tamColor)
{
    int todoOk = 0;
    char patente[20];
    int indice;
    int idMarca;
    int idColor;
    int modelo;
    int yaIngresado;
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
        yaIngresado=buscarAutoPatente(patente,vec,tamAuto);
        while(yaIngresado!=-1)
        {

            printf(" Patente ya registrada :\n");
            mostrarAuto(vec[yaIngresado]);

            printf("Ingrese patente: ");
            fflush(stdin);
            gets(patente);
        }

        mostrarColores(color,tamColor);
        /*printf("Ingrese id color: ");
        scanf("%d",&idColor);*/
        getNumeroIntentos(&idColor,"Ingrese id color: ","Error.Ingrese  ID correcto: \n",5000,5004,3);//validamos
        mostrarMarcas(marca,tamMarca);
        /*printf("Ingrese id Marca: ");
        scanf("%d", &idMarca);*/
        getNumeroIntentos(&idMarca,"Ingrese id Marca: ","Error.Ingrese  ID correcto: \n",1000,1004,3);
        printf("Ingrese año de modelo : ");
        scanf("%d", &modelo);
        getNumeroIntentos(&idMarca,"Ingrese año de modelo : ","Error.Ingrese anio de modelo entre 1980 y 2019 \n",1980,2019,3);

        vec[indice] = newAuto(id, patente, idMarca, idColor, modelo);
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
int estaCargado(eAuto vec[], int tam)
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
    char confirma;
    system("cls");
    printf("***** Baja Auto *****\n\n");
    printf("Ingrese patente: ");
    gets(patente);

    indice = buscarAutoPatente(patente, vec, tam);

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
int modificarAuto(eAuto vec[], int tam,eMarca marca[],int tamMarca,eColor colores[],int tamColor)
{
    int todoOk = 0;
    char patente[20];
    int idMarca;
    int idColor;
    int indice;
    int opcion;
    system("cls");
    printf("***** Modificar Auto *****\n\n");
    printf("Ingrese patente: ");
    gets(patente);

    indice = buscarAutoPatente(patente, vec, tam);

    if( indice == -1)
    {
        printf("No existe el auto con esa patente\n\n");

    }
    else
    {
        mostrarAuto(vec[indice]);
        printf("1- Modificar color\n");
        printf("2- Modificar modelo\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        getNumero( &opcion,"Ingrese opcion: ","Error.opcion incorrecta, vuelva a ingresar opcion\n",1,2);
        switch(opcion)
        {
        case 1:
            mostrarColores(colores,tamColor);
            getNumeroIntentos(&idColor,"Ingrese id color: ","Error.Ingrese  ID correcto: \n",5000,5004,3);//validamos
            break;
            todoOk=1;
        case 2:
            mostrarMarcas(marca,tamMarca);
            getNumeroIntentos(&idMarca,"Ingrese id Marca: ","Error.Ingrese  ID correcto: \n",1000,1004,3);
            todoOk=1;
            break;
        case 3:
            printf("Se ha cancelado la mofdificacion ");
            break;

        }
    }

    return todoOk;
}
int buscarAutoPatente(char patente[], eAuto vec[], int tam)
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
void inicializarAuto(eAuto vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


void ordenarAutosMarcaPatente( eAuto vec[], int tam){

    eAuto aux;
    int swap = 0;

    for(int i=0; i < tam-1; i++){
        for(int j = i +1; j < tam; j++){
            // condicion para ordenar por MARCA ascendente
            if( vec[i].idMarca>vec[j].idMarca && vec[i].isEmpty==0 && vec[j].isEmpty==0){
                    swap = 1;
            }
            // SI TIENEN LA MISMA MARCA LOS ORDENO POR PATENTE ASCENDETE
            else if(  vec[i].idMarca==vec[j].idMarca && strcmp(vec[i].patente,vec[j].patente)>0 && vec[i].isEmpty==0 && vec[j].isEmpty==0){

                    swap = 1;
            }
            // SI ENTRO A ALGUNO DE LOS IF ANTERIORES ES PORQUE TENGO QUE SWAPEAR
            if( swap ){

                 aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }

            swap = 0;
        }
    }
}
