#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Bicicleta.h"
#include "imput.h"
int menu();
//srand (time(NULL));
int funcionRandom(void* element);
int main()
{
char salir='n';
    int devuelve;
    int opcionsubMenu;
    char nombreArchivo[50];
   char extensionArchivo[10]="csv";

    char destino[70];
    LinkedList* listaBicicletas= ll_newLinkedList();
    LinkedList* listaTipo= ll_newLinkedList();
    LinkedList* listaMap= ll_newLinkedList();
do{
        switch(menu())
        {
            case 1:
                    printf("Ingrese nombre del archivo \n");
                    fflush(stdin);
                    //gets(nombreArchivo);
                    scanf("%s",nombreArchivo);
                    concatenar(destino,nombreArchivo,extensionArchivo);//concatena el nombre del archivo con la extension

                    devuelve = controller_loadFromText(destino,listaBicicletas);
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

                   devuelve=controller_ListBicicletas(listaBicicletas);//muestra por pantalla la lista generada
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
                    listaMap=ll_map(listaBicicletas,funcionRandom);
                    controller_ListBicicletas(listaMap);

                    break;
            case 4:


                    printf(" ordenar por tipos de bicicletas :\n");
                    printf(" 1-BMX:\n");
                    printf(" 2-PLAYERA :\n");
                    printf(" 3-MTB :\n");
                    printf(" 4-PASEO :\n");
                      printf("Enter option :\n");
                    scanf("%d",&opcionsubMenu);
                    //getNumero(&opcionsubMenu,"Ingrese opcion ", "Error. opcion incorrecta\n",1,4);
                    switch(opcionsubMenu){
                        case 1:
                            listaTipo=ll_filter(listaBicicletas,bicicleta_esBMX);
                            controller_saveAsText("listaTipo.txt",listaTipo);
                            printf("Archivo generado !\n");
                        break;
                        case 2:
                             listaTipo=ll_filter(listaBicicletas,bicicleta_esPLAYERA);
                             controller_saveAsText("listaTipo.txt",listaTipo);
                              printf("Archivo generado !\n");
                        break;
                        case 3:
                             listaTipo=ll_filter(listaBicicletas,bicicleta_esMTB);
                             controller_saveAsText("listaTipo.txt",listaTipo);
                              printf("Archivo generado !\n");
                        break;
                        case 4:
                             listaTipo=ll_filter(listaBicicletas,bicicleta_esPASEO);
                             controller_saveAsText("listaTipo.txt",listaTipo);
                              printf("Archivo generado !\n");
                        break;
                default:
                        printf("Opcion invalida \n");
                    }




                break;
            case 5:
                     printf(" ordenar por tipos de bicicletas :\n");
                    printf(" 1-BMX:\n");
                    printf(" 2-PLAYERA :\n");
                    printf(" 3-MTB :\n");
                    printf(" 4-PASEO :\n");
                      printf("Enter option :\n");
                    scanf("%d",&opcionsubMenu);
                    //getNumero(&opcionsubMenu,"Ingrese opcion ", "Error. opcion incorrecta\n",1,4);
                    switch(opcionsubMenu){
                        case 1:

                        break;
                        case 2:

                        break;
                        case 3:

                        break;
                        case 4:

                        break;
                default:
                        printf("Opcion invalida \n");
                    }

                break;

            case 6:

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
    printf(" 1. Cargar archivo \n");
    printf("2. Imprimir lista \n");
    printf("3. Asignar tiempos\n");
    printf("4. Filtrar por tipo\n");
    printf("5. mostrar posiciones\n");
    printf("6. Salir\n");
    printf("Enter option :\n");
    scanf("%d",&option);

    return option;

}
int funcionRandom(void* element){
int aleatorio;
int todoOk=0;
    if(element!=NULL){
        aleatorio = rand()%(71)+50;
        bicicleta_setTiempo((Bicicleta*)element,aleatorio);
        todoOk=1;
    }

    return todoOk;
}

