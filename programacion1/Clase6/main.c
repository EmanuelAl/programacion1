#include <stdio.h>
#include <stdlib.h>
#define TAM 2
void mostrarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[],float prom[],int tam);
void mostrarAlumno(int leg, int age, char sex, int n1, int n2, float promedio);
int main()
{

   int legajo[TAM];
   int edades[TAM];
   char sexo[TAM];
   int nota1[TAM];
   int nota2[TAM];
   float promedio[TAM];

    for(int i = 0; i < TAM; i++)
        {

        printf("Ingrese legajo: ");
        scanf("%d",&legajo[i]);

        printf("Ingrese edad: ");
        scanf("%d",&edades[i]);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c",&sexo[i]);

        printf("Ingrese nota del primer parcial: ");
        scanf("%d",&nota1[i]);

        printf("Ingrese nota del segundo parcial: ");
        scanf("%d",&nota2[i]);

        promedio[i]= (float)(nota1[i]+nota2[i])/2;

        }
        mostrarAlumnos(legajo,edades,sexo,nota1,nota2,promedio,TAM);

    return 0;
}

void mostrarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[],float prom[],int tam){

        printf(" legajo edad  sexo  nota1  nota2  promedio \n");

        for(int i=0; i<tam; i++){

        mostrarAlumno(leg[i],age[i],sex[i],n1[i],n2[i],prom[i]);
        }




}

void mostrarAlumno(int leg, int age, char sex, int n1, int n2, float promedio){


         printf("   %d   %d     %c    %d     %d      %.2f  \n",leg,age,sex,n1,n2,promedio);
}
