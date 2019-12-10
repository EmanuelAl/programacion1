#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Cachorro.h"
#include "imput.h"
int menu();
int main()
{
char salir='n';
    int devuelve;
    char nombreArchivo[50];
   char extensionArchivo[10]="csv";
    //char extensionArchivo[10]={'c','s','v','\0'};
    char destino[70];
    LinkedList* listaCachorros = ll_newLinkedList();
    LinkedList* listaCachorros2 = ll_newLinkedList();
       LinkedList* listaCachorros3 = ll_newLinkedList();
       LinkedList* listaCachorros4 = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:
                    printf("Ingrese nombre del archivo \n");
                    fflush(stdin);
                    //gets(nombreArchivo);
                    scanf("%s",nombreArchivo);
                    concatenar(destino,nombreArchivo,extensionArchivo);//concatena el nombre del archivo con la extension
                //devuelve = controller_loadFromText("cachorros.csv",listaCachorros);
                    devuelve = controller_loadFromText(destino,listaCachorros);
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

                   devuelve=controller_ListCachorro(listaCachorros);//muestra por pantalla la lista generada
                  if (devuelve == -1)
                    {
                    printf("\n  LISTA VACIA \n\n");
                    }
                    else
                        {
                        printf("\n EXISTE LISTA \n\n");
                        }
                break;
            case 3:

                     listaCachorros2=ll_filter(listaCachorros,cachorro_esMenor45Dias);
                    if(listaCachorros2!=NULL){
                        controller_ListCachorro(listaCachorros2);//muestra por pantalla la lista generada
                         controller_saveAsText("listaCachorros2.txt",listaCachorros2);// se genera el archivo para los que tienen menos de 45 dias
                    }

                    break;
            case 4:
                    listaCachorros3=ll_filter(listaCachorros,cachorro_esMacho);
                    if(listaCachorros3!=NULL){
                        controller_ListCachorro(listaCachorros3);//muestra por pantalla la lista generada
                        controller_saveAsText("listaCachorros3.txt",listaCachorros3);//se genera el archivo para solo machos
                    }

                break;
            case 5:

                     listaCachorros4=ll_filter(listaCachorros,cachorro_esCallejero);
                    if(listaCachorros4!=NULL){
                        controller_ListCachorro(listaCachorros4);//muestra por pantalla la lista generada
                    }
                   // controller_saveAsText("lista4.txt",listaCachorros4);

                break;

            case 6:
               // printf("confirma salir?s/n \n");
                // fflush(stdin);
                //salir=getchar();
                salir=validar();

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
