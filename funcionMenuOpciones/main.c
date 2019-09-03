#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "alderete.h"
//char menu();// declaro el prototipo de la funcion menu
//int sumar1(int a, int b);
int main()
{
    char seguir='s';
    char salir='n';

    int a=0;
    int b=0;

    printf("ingrese numero A: ");
    scanf("%d",&a);
    printf("ingrese numero B: ");
    scanf("%d",&b);

    do{

    switch(menu()){//segun la opcion que devuelva la funcion menu
case 'a':
    printf("\n usted eligio sumar \n");
    printf("El resultado de A+B es: %d \n",sumar1(a,b));
    system("pause");
    break;

case 'b':
     printf("\n usted eligio restar \n");
     printf("El resultado de A-B es: %d \n",restar(a,b));
    system("pause");
    break;
case 'c':
     printf("\n usted eligio multiplicar \n ");
     printf("El resultado de A*B es: %d \n",multiplicar(a,b));

    system("pause");
    break;
case 'd':
     printf("\n usted eligio dividir \n");
     printf("El resultado de A/B es: %d \n",dividir(a,b));
    system("pause");
    break;
case 'e':
    printf("\n esta seguro que quiere salir? \n");
    salir=getche();

    if(salir=='s'){
        return 0;
    }
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
/*char menu(){
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
int sumar1(int a, int b){
    int suma;

    suma=a+b;
    return suma;

}*/
