#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "servicio.h"
#include "marca.h"
#include "color.h"
#include "auto.h"
#include "trabajo.h"
#include "input.h"

#define AUTO 10
#define MARCA 5
#define SERV 4
#define COLOR 5
#define TRABAJO 5
#define CLIENTE 10
int menu();

int main()
{

    eAuto autos[AUTO];
    eTrabajo trabajos[TRABAJO];
    eMarca marcas[MARCA];
    eColor colores[COLOR];
    eServicio servicios[SERV];
    eCliente clientes[CLIENTE];
    char salir='n';
     int idAuto=2000;
     int idCliente=0;
     int idTrabajo=0;

    inicializarAuto(autos,AUTO);
    inicializarTrabajo(trabajos,TRABAJO);
    inicializarCliente(clientes,CLIENTE);
    //harcodeos
    hardcodearColores(colores,COLOR,5);
    hardcodearMarcas(marcas,MARCA,5);
    hardcodearServicios(servicios,SERV,4);
   idCliente= idCliente+ hardcodearClientes(clientes,CLIENTE,5);

    idAuto= idAuto + hardcodearAutos(autos,AUTO,5);



    do{
        switch( menu())
        {
        case 1:
            if(altaAuto( idAuto,idCliente,autos,AUTO, marcas,MARCA,colores,COLOR,clientes,CLIENTE))
            {
                idAuto++;
                idCliente++;
            }
            break;

        case 2:
            if( estaCargado(autos,AUTO)==-1){
                printf(" Sistema vacio. No se puede gestionar baja \n");
            }else{
                 bajaAuto(autos,AUTO,marcas,MARCA,colores,COLOR,clientes,CLIENTE);
            }


            break;

        case 3:
             if( estaCargado(autos,AUTO)==-1){
                printf(" Sistema vacio. No se puede gestionar Modificar \n");
            }else{
                 modificarAuto(autos,AUTO,marcas,MARCA,colores,COLOR,clientes,CLIENTE);

            }
            break;

        case 4:
                ordenarAutosMarcaPatente2(autos,AUTO,marcas,MARCA);
                mostrarAutos(autos,AUTO,colores,COLOR,marcas,MARCA,clientes,CLIENTE);
            break;

        case 5:
                listarMarcas(marcas,MARCA);
            break;

        case 6:
                listarColores(colores,COLOR);
            break;

        case 7:
                listarServicios(servicios,SERV);
            break;

        case 8:
                if(altaTrabajo(trabajos,TRABAJO,idTrabajo,servicios,SERV,autos,AUTO,marcas,MARCA,colores,COLOR,clientes,CLIENTE))
            {
                idTrabajo++;
            }
            break;
        case 9:

              if( estaCargadoTrabajo(trabajos,TRABAJO)==-1){
                printf(" Sistema vacio \n");
            }else{
                 listarTrabajos(trabajos,TRABAJO,servicios,SERV);
            }

            break;
        case 10:
                if(mostrarAutoLocalidades(autos,AUTO,marcas,MARCA,colores,COLOR,clientes,CLIENTE)==0){
                    printf(" no existe esa localidad ");
                }
             break;
        case 11:
                mostrarImporteTotal(trabajos,TRABAJO,servicios,SERV,autos,AUTO,clientes,CLIENTE);
             break;
        case 12:
            /*printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();*/
            salir= validar();
            break;

        default:
            printf("\n Opcion Invalida \n");

        }
        system("pause");
    }
    while(salir == 'n');


    return 0;
}
int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM  AUTOS *******\n\n");
    printf("1-Alta auto\n");
    printf("2-Baja auto\n");
    printf("3-Modificar auto\n");
    printf("4-Listar autos\n");
    printf("5-Listar Marcas\n");
    printf("6-Listar colores\n");
    printf("7-Listar servicios\n");
    printf("8-Alta trabajo\n");
    printf("9-Listar trabajos \n\n");
    printf("10-Autos por localidad\n\n");
    printf("11-Importe a pagar\n\n");
    printf("12-Salir\n\n");

    getNumero(&opcion,"\n Ingrese opcion: "," \n Error.opcion invalida ",1,12);
    /*printf("Ingrese opcion: ");
    scanf("%d",&opcion);
*/
    return opcion;
}
