#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Cachorro.h"
int menu();
int main()
{
char salir='n';
    int devuelve;

    int abrirTexto = 1;
    char nombreArchivo;
//    int guardarTexto = 0;

    LinkedList* listaCachorros = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:

                // if (abrirTexto == 1)
                  //  {
                  //printf(" ingrese nombre del archivo : ");
                  //scanf("%s",nombreArchivo);
                devuelve = controller_loadFromText("cachorros.csv",listaCachorros);
                if (devuelve == 1)//si lo pudo leer
                {
                    printf("\n Archivo abierto modo text \n\n");
                }
                else
                {
                    printf("\n Ha ocurrido  un error al abrir el archivo \n\n");
                }

                    /*}
                else
                    {
                    system("cls");
                    printf("\n El archivo ya esta abierto \n\n");
                    }
//                    guardarTexto = 1;
                    abrirTexto++;*/
                break;
            case 2:

                   controller_ListCachorro(listaCachorros);
            case 3:


            case 4:


                break;
            case 5:



                break;
            /*case 6:
                devuelve = controller_ListEmployee(listaEmpleados);
                if (devuelve == -1)
                {
                printf("\n NO EXISTE LA LISTA\n\n");
                }
                else
                    {
                printf("\n EXISTE LISTA \n\n");
                    }
                break;


                break;
            case 8:
                if (guardarTexto == 1)
            {
                devuelve = controller_saveAsText("cachorros.csv",listaCachorros);
                if(devuelve == 1)
                {
                    printf("\n Archivo guardado\n\n");
                }
                else
                {
                    printf("\n No se pudo guardar archivo\n\n");
                }
            }
            else
            {
                system("cls");
                printf("\n Se debe abrir  archivo  primero \n\n");
            }


                break;*/

            case 6:
                printf("confirma salir?¿ \n");
                fflush(stdin);
                salir=getchar();

                break;

        default:
            printf("Opcion invalida \n");

        }
        system("pause");
    }
    while(salir =='n');



    return 0;
}
int menu()
{

    int option;
    system("cls");
    printf("Menu:\n\n");
    printf(" 1. Cargar archivo cachorro.csv\n");
    printf("2. Imprimir lista \n");
    printf("3. Filtrar menores de 45 dias\n");
    printf("4. Filtrar machos \n");
    printf("5. Generar listado de Callejeros \n");
    printf("6. Salir\n");
    printf("Enter option :\n");
    scanf("%d",&option);

    return option;

}
