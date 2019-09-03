#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "alderete.h"
char menu(){
     char opcion;
    //system("cls");
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

}
int restar(int a,int b){
    int resta;

    resta=a-b;

    return  resta;
}
int multiplicar(int a,int b){
    int producto;

    producto=a*b;
    return producto;
}
float dividir(int a,int b){
    float resultado;
    if(b==0){
        printf("Error. no se puede dividir por cero");
    }
    if(b!=0){
    resultado=a/b;
    }
    return resultado;
}
