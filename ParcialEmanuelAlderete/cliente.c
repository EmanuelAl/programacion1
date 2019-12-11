#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include  "cliente.h"
int hardcodearClientes( eCliente vec[], int tam, int cantidad)
{
    int cont = 0;

    eCliente aux[]={
    {3000,"Pepe","burzaco"},
    {3001,"Roberto","adrogue"},
    {3002,"Romina","avellaneda"},
   {3003,"Carla","lanus"},
   {3004,"Lautaro","marmol"}
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
void listarClientes( eCliente clientes[], int tam){
    printf(" Id          Nombre        Localidad \n\n");
    for(int i=0; i < tam; i++){
        mostrarCliente( clientes[i]);
    }
    printf("\n");
}

void mostrarClientes(eCliente clientes[], int tam){
      printf(" Id          Nombre        Localidad \n\n");
    for(int i=0; i < tam; i++){
        mostrarCliente( clientes[i]);
    }
    printf("\n");
}

void mostrarCliente(eCliente cliente){

    printf("  %d        %10s     %10s \n",cliente.idCliente, cliente.nombre,cliente.localidad);

}

void mostrarClientesLocalidad(eCliente clientes[], int tam){
      printf(" Localidades \n\n");
    for(int i=0; i < tam; i++){
        mostrarClienteLocalidad( clientes[i]);
    }
    printf("\n");
}

void mostrarClienteLocalidad(eCliente cliente){

    printf(" %10s \n",cliente.localidad);

}
int cargarDescCliente(int id, eCliente vec[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == vec[i].idCliente){
            strcpy(desc, vec[i].nombre);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}
void inicializarCliente(eCliente vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}
int buscarLibreCliente(eCliente vec[], int tam)
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
int altaCliente( int idCliente,eCliente vec[], int tam){
 int todoOk = 0;
 char nombre[50];
 char localidad[50];
    int indice;
         indice = buscarLibreCliente(vec, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("ingrese nombre del titular: ");
        gets(nombre);
        printf("ingrese localidad: ");
        gets(localidad);
        vec[indice] = newCliente(idCliente,nombre,localidad);
        todoOk = 1;
    }
    return todoOk;
}
eCliente newCliente(int idCliente, char nombre[],char localidad[]){
eCliente aux;

aux.idCliente=idCliente;
strcpy(aux.nombre,nombre);
strcpy(aux.localidad,localidad);
aux.isEmpty=0;
return aux;
}
