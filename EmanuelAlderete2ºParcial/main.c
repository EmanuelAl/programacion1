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

   // int abrirTexto = 1;
   // char nombreArchivo;
//    int guardarTexto = 0;

    LinkedList* listaCachorros = ll_newLinkedList();
    LinkedList* listaCachorros2 = ll_newLinkedList();
       LinkedList* listaCachorros3 = ll_newLinkedList();
       LinkedList* listaCachorros4 = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:

                devuelve = controller_loadFromText("cachorros.csv",listaCachorros);
                if (devuelve == 1)//si lo pudo leer
                {
                    printf("\n Archivo abierto modo text \n\n");
                }
                else
                {
                    printf("\n Ha ocurrido  un error al abrir el archivo \n\n");
                }

                break;
            case 2:

                   controller_ListCachorro(listaCachorros);
                    break;
            case 3:

                     listaCachorros2=ll_filter(listaCachorros,cachorro_esMenor45Dias);
                    if(listaCachorros2!=NULL){
                        controller_ListCachorro(listaCachorros2);
                         controller_saveAsText("listaCachorros2.txt",listaCachorros2);// se genera el archivo para los que tienen menos de 45 dias
                    }

                    break;
            case 4:
                    listaCachorros3=ll_filter(listaCachorros,cachorro_esMacho);
                    if(listaCachorros3!=NULL){
                        controller_ListCachorro(listaCachorros3);
                        controller_saveAsText("listaCachorros3.txt",listaCachorros3);//se genera el archivo para solo machos
                    }

                break;
            case 5:

                     listaCachorros4=ll_filter(listaCachorros,cachorro_esCallejero);
                    if(listaCachorros4!=NULL){
                        controller_ListCachorro(listaCachorros4);
                    }
                   // controller_saveAsText("lista4.txt",listaCachorros4);

                break;

            case 6:
                printf("confirma salir?s/n \n");
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
