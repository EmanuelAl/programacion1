#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{
    int x=4;
    int y=5;
    char seguir;

    do{
        switch(menu()){
        case 1:
        case 2:
        case 3:
            sumar1(x,y);
            restar(x,y);
            dividir(x,y);
            multiplicar(x,y);
        case 4:
            printf("El resultado de A+B es: %d ",sumar1(x,y));
            printf(" El resultado de A-B es: %d ",restar(x,y));
            printf(" El resultado de A/B es: %2.f",dividir(x,y);
            printf("El resultado de A*B es: %d",multiplicar(x,y););
            printf("El factorial de A es: r1 y El factorial de B es: r2");

        case 5:
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
    }while( seguir=='s');


    printf("Calcular la suma (A+B) \n");
    printf("Calcular la resta (A-B) \n");
    printf("Calcular la division (A/B) \n");
    printf("Calcular la multiplicacion (A*B) \n");
    printf("Calcular el factorial (A!) \n");


    printf("El resultado de A+B es: %d ");
    printf(" El resultado de A-B es: %d ");
    printf(" El resultado de A/B es: %2.f");
    printf("El resultado de A*B es: %d");
    printf("El factorial de A es: r1 y El factorial de B es: r2");
    return 0;
}
