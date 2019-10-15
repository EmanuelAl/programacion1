#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "servicio.h"
#include "marca.h"
#include "color.h"
#include "auto.h"
#include "trabajo.h"

#define AUTO 5
#define MARCA 5
#define SERV 5
#define COLOR 5
#define TRABAJO 5

int menu();

int main()
{

    eAuto autos[AUTO];
    eTrabajo trabajos[TRABAJO];
    eMarca marcas[MARCA];
    eColor colores[COLOR];
    eServicio servicios[SERV];
    char salir='n';
     int idAuto;

    inicializarAuto(autos,AUTO);
    inicializarTrabajo(trabajos,TRABAJO);
    //harcodeos
    hardcodearColores(colores,COLOR,5);
    hardcodearMarcas(marcas,MARCA,5);
    hardcodearServicios(servicios,SERV,5);

    idAuto= idAuto + hardcodearAutos(autos,AUTO);



do
    {
        switch( menu())
        {
        case 1:
            if(altaAuto( idAuto,autos,AUTO, marcas,MARCA,colores,COLOR))
            {
                idAuto++;
            }
            break;

        case 2:
            if( estaCargado(autos,AUTO)==-1){
                printf(" Sistema vacio. No se puede gestionar baja \n");
            }else{
                 bajaAuto(autos,AUTO);
            }


            break;

        case 3:
             if( estaCargado(autos,AUTO)==-1){
                printf(" Sistema vacio. No se puede gestionar Modificar \n");
            }else{
                 modificarAuto(autos,AUTO,marcas,MARCA,colores,COLOR);

            }
            break;

        case 4:

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

            break;
        case 9:

            break;
        case 10:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
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
    printf("4-Listar Marcas\n");
    printf("5-Listar colores\n");
    printf("6-Listar servicios\n");
    printf("7-Alta trabajo\n");
    printf("8-Mostrar comidas\n\n");
    printf("9-Listar trabajos \n\n");
    printf("10-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
