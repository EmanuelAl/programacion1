#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
char menu();// declaro el prototipo de la funcion menu
int main()
{
    char seguir='s';

    do{

    switch(menu()){//segun la opcion que devuelva la funcion menu
case 'a':
    printf("\n usted eligio sumar \n");
    system("pause");
    break;

case 'b':
     printf("\n usted eligio restar \n");
    system("pause");
    break;
case 'c':
     printf("\n usted eligio multiplicar \n ");
    system("pause");
    break;
case 'd':
     printf("\n usted eligio dividir \n");
    system("pause");
    break;
case 'e':
    system("pause");
    break;
default:
      printf("opcion invalida \n");
    system("pause");
    break;

    }

    printf("desea continuar? s/n");
    fflush(stdin);//borra si hay basura en la memoria
    seguir=getch();// toma dato y lo pasa a la variable seguir

    }while(seguir=='s');

    return 0;
}
char menu(){
     char opcion;
    system("cls");
    printf("-------------menu de opciones----------\n");
    printf("a- sumar\n");
    printf("b- restar\n");
    printf("c- multiplicar\n");
    printf("d- dividir\n");
    printf("e- salir\n");

    printf("ingrese opcion : ");
    opcion=getche();
    system("cls");
    return opcion;
}
