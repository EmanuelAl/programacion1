#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "auto.h"
#include "input.h"
#include  "cliente.h"

int hardcodearAutos( eAuto vec[], int tam, int cantidad)
{
    int cont = 0;

    eAuto aux[]=
    {
        {2000,"123ABC",3000,1000,5000,1997},
        {2001,"252HGF",3001,1001,5001,1999},
        {2002,"555GJK",3002,1002,5002,1874},
        {2003,"669BCA",3003,1003,5003,2000},
        {2004,"122RTF",3004,1004,5004,2007}
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
void listarAutos(eAuto autos[], int tam,eColor colores[],int tamColor,eMarca marcas[],int tamMarca,eCliente clientes[],int tamCliente)
{
     int flag=0;
    system("cls");
    printf(" Id            patente   titular   Marca           Color     modelo  \n\n");
    for(int i=0; i < tam; i++)
    {   if(autos[i].isEmpty==0){
        mostrarAuto( autos[i],colores,tamColor,marcas,tamMarca,clientes,tamCliente);
        flag=1;
            }
    }
    if( flag == 0)
        {
            printf("\nNo hay trabajos que mostrar\n");
        }
      printf("\n");
}

void mostrarAutos(eAuto autos[], int tam,eColor colores[],int tamColor,eMarca marcas[],int tamMarca,eCliente clientes[],int tamCliente)
{
    int flag=0;
    system("cls");
    printf(" Id            patente   titular   Marca           Color     modelo  \n\n");
    for(int i=0; i < tam; i++)
    {   if(autos[i].isEmpty==0){
        mostrarAuto( autos[i],colores,tamColor,marcas,tamMarca,clientes,tamCliente);
        flag=1;
            }
    }
    if( flag == 0)
        {
            printf("\nNo hay trabajos que mostrar\n");
        }
      printf("\n");
}
void mostrarAuto(eAuto aut,eColor colores[],int tamColor,eMarca marcas[],int tamMarca,eCliente clientes[],int tamCliente)
{
    char descColor[20];
    char descMarca[20];
    char nombre[20];
    cargarDescColor(aut.idColor,colores,tamColor,descColor);
    cargarDescMarca(aut.idMarca,marcas,tamMarca,descMarca);
    cargarDescCliente(aut.idCliente,clientes,tamCliente,nombre);
    printf("  %d      %s  %10s  %10s    %10s      %d \n", aut.idAuto, aut.patente,nombre,descMarca,descColor,aut.modelo);

}
int altaAuto(int id,int idCliente,eAuto vec[],int tamAuto,eMarca marca[],int tamMarca,eColor color[],int tamColor,eCliente clientes[],int tamCliente)
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
            mostrarAuto(vec[yaIngresado],color,tamColor,marca,tamMarca,clientes,tamCliente);

            printf("Ingrese patente: ");
            fflush(stdin);
            gets(patente);
            yaIngresado=buscarAutoPatente(patente,vec,tamAuto);
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

        while(modelo<1980 || modelo >2020){
            printf("Error.Ingrese anio de modelo entre 1980 y 2019\n");
            scanf("%d", &modelo);
        }
        vec[indice] = newAuto(id, patente,idCliente, idMarca, idColor, modelo);
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
               int idCliente,
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
    aux.idCliente=idCliente;
    aux.isEmpty=0;

    return aux;

}
int bajaAuto(eAuto vec[], int tam,eMarca marca[],int tamMarca,eColor color[],int tamColor,eCliente clientes[],int tamCliente)
{
    int todoOk = 0;
    char patente[20];
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Auto *****\n\n");
    printf("Ingrese patente: ");
    fflush(stdin);
    gets(patente);

    indice = buscarAutoPatente(patente, vec, tam);

    if( indice == -1)
    {
        printf("No existe el auto con esa patente\n\n");

    }
    else
    {
        mostrarAuto(vec[indice],color,tamColor,marca,tamMarca,clientes,tamCliente);

        printf("\nConfirma baja?(s/n)");
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
int modificarAuto(eAuto vec[], int tam,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eCliente clientes[],int tamCliente)
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
        mostrarAuto(vec[indice],colores,tamColor,marca,tamMarca,clientes,tamCliente);
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
        if( strcmp(vec[i].patente,patente)==0 && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void mostrarAutoLocalidades( eAuto vec[],int tamAuto,eMarca marca[],int tamMarca,eColor color[],int tamColor,eCliente clientes[],int tamCliente)
{

    char localidad[20];
    mostrarClientesLocalidad(clientes,tamCliente);

    printf("Ingrese localidad: \n");
    fflush(stdin);
    gets(localidad);

    for(int i=0; i < tamAuto; i++)
    {
        for(int j=0; j < tamCliente; j++)
        {
            if(vec[i].idCliente==clientes[j].idCliente && vec[i].isEmpty == 0)
            {
                if( (strcmp(clientes[j].localidad,localidad))==0 )
                {
                   // mostrarAutos(vec,tamAuto,color,tamColor,marca,tamMarca,clientes,tamCliente);
                    mostrarAuto(vec[i],color,tamColor,marca,tamMarca,clientes,tamCliente);

                }
            }
        }
    }
}
void inicializarAuto(eAuto vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


void ordenarAutosMarcaPatente( eAuto vec[], int tam)
{

    eAuto aux;
    int swap = 0;

    for(int i=0; i < tam-1; i++)
    {
        for(int j = i +1; j < tam; j++)
        {
            // condicion para ordenar por MARCA ascendente
            if( vec[i].idMarca>vec[j].idMarca && vec[i].isEmpty==0 && vec[j].isEmpty==0)
            {
                swap = 1;
            }
            // SI TIENEN LA MISMA MARCA LOS ORDENO POR PATENTE ASCENDETE
            else if(  vec[i].idMarca==vec[j].idMarca && strcmp(vec[i].patente,vec[j].patente)>0 && vec[i].isEmpty==0 && vec[j].isEmpty==0)
            {

                swap = 1;
            }
            // SI ENTRO A ALGUNO DE LOS IF ANTERIORES ES PORQUE TENGO QUE SWAPEAR
            if( swap )
            {

                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }

            swap = 0;
        }
    }
}
