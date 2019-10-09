#include <stdio.h>
#include <stdlib.h>

#include "servicio.h"
#include "marca.h"
#include "color.h"
#include "auto.h"

#define AUTO 5
#define MARCA 5
#define SERV 5
#define COLOR 5
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;





typedef struct
{
    int idTrabajo;
    char patente[20];
    int idServicio;
    eFecha fecha;
} eTrabajo;

int menu();

int main()
{
    int idAuto;
    eAuto autos[AUTO];
    eMarca marcas[MARCA];
    eColor colores[COLOR];
    char salir='n';
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

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

            break;

        case 7:

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
