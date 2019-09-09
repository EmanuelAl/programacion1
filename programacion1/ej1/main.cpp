#include <iostream>
#include<string.h>

using namespace std;

int main()
{

    int nota=0;
    int notaMax=0;
    int notaMin=0;
    int acumNotas=0;
    int contNotas=0;
    int bandera=0;
    char respuesta[20];
    char nomMax[20];
    char nomMin[20];
    char nombre[20];
    char sexo;
    float promTotal=0;
    while(respuesta){


    //(cout << "Hello world!" << endl;
    printf("ingrese el nombre \n");
    fflush(stdin);
     //nombre=getch();
    gets(nombre);

    printf("sexo f/m: \n");
     fflush(stdin);
     sexo=getch();

    printf("ingrese nota: \n");
     fflush(stdin);
     scanf("%d",&nota);
     //validamos
     while(sexo!='f' || sexo!='m'){
        printf("Error. ingrese sexo f/m: ");
         fflush(stdin);
        sexo=getch();
     }

     while(nota<0 || nota >10){
        printf("Error. ingrese nota 0-10: ");
        scanf("%d";&nota);
     }

     if(bandera==0){
        notaMax=nota;
        notaMin=nota;
        nomMax=nombre;
        nomMin=nombre;
        bandera=1;
     }

     if(nota>notaMax){
        notaMax=nota;
        nomMax=nombre;
     }
     if(nota<notaMin){
        notaMin=nota;
        nomMin=nombre;
     }
    acumNotas+=notas;
    contNotas++;

    printf("quiere continuar?s/n \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    }
    promTotal=acumNotas/contNotas;
    printf("el promedio total de notas es: \n");
    return 0;
}
