#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{
    int x=4;
    int y=4;
    char seguir='s';
    char salir='n';

    do{
        switch(menu(x,y)){
        case 1:
        case 2:
        case 3:
            sumar1(x,y);
            restar(x,y);
            dividir(x,y);
            multiplicar(x,y);

            printf("todo  cargado \n");
            //system("pause");
            break;
        case 4:
            printf(" \nEl resultado de A+B es: %d \n",sumar1(x,y));
            printf(" \nEl resultado de A-B es: %d \n",restar(x,y));
            printf(" \nEl resultado de A/B es: %f \n",dividir(x,y));
            printf(" \nEl resultado de A*B es: %d \n",multiplicar(x,y));
            printf(" \nEl factorial de A es: %d y El factorial de B es: %d \n",factorizar(x),factorizar(y));
            //system("pause");
            break;

        case 5:
            printf("\n esta seguro que quiere salir? s/n \n");
            fflush(stdin);
            salir=getche();

            if(salir=='s'){
                return 0;
            }
            system("pause");
            break;
        default:
            printf("opcion invalida.Reingrese opcion: \n");
            system("pause");
            break;
        }

        printf("\n desea continuar? s/n \n");
        fflush(stdin);//borra si hay basura en la memoria
        seguir=getch();// toma dato y lo pasa a la variable seguir
        system("cls");
    }while( seguir=='s');


    /*printf("Calcular la suma (A+B) \n");
    printf("Calcular la resta (A-B) \n");
    printf("Calcular la division (A/B) \n");
    printf("Calcular la multiplicacion (A*B) \n");
    printf("Calcular el factorial (A!) \n");



    printf("El resultado de A+B es: %d ");
    printf(" El resultado de A-B es: %d ");
    printf(" El resultado de A/B es: %2.f");
    printf("El resultado de A*B es: %d");
    printf("El factorial de A es: r1 y El factorial de B es: r2");*/
    return 0;
}
