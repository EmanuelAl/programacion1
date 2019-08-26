#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char opcion;
    char seguir;
    system("cls");
    printf("-------------menu de opciones----------\n");
    printf("a- sumar\n");
    printf("b- restar\n");
    printf("c- multiplicar\n");
    printf("d- dividir\n");
    printf("e- salir\n");

    printf("ingrese opcion : ");
    opcion=getche();

    switch(opcion){
case 'a':
    printf("\n usted eligio sumar ");
    system("pause");
    break;

case 'b':

default:
      printf("opcion invalida \n");
    system("pause");
    break;

    }

    return 0;
}
