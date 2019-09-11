#include <stdio.h>
#include <stdlib.h>
#define TAM 5
void mostrarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[],float prom[],int tam);
void ordenarAlumnosLeg(int leg[], int age[], char sex[], int n1[], int n2[],float prom[],int tam);
void mostrarAlumno(int leg, int age, char sex, int n1, int n2, float promedio);
void ordenarAlumnosSexLeg( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void ordenarAlumnosSex( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
int main()
{

    int legajo[TAM]= { 212, 258,123,233,800};
    int edades[TAM]= { 20,21, 23,19,25};
    char sexo[TAM]= { 'f','m','f','m','f'};
    int nota1[TAM]= { 8, 7, 8, 9, 4};
    int nota2[TAM]= { 5, 6, 7, 8, 2};
    float promedio[TAM]= { 10.52, 9.5, 20.10, 23.5, 56.2};

    /* for(int i = 0; i < TAM; i++)
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

         }*/
    mostrarAlumnos(legajo,edades,sexo,nota1,nota2,promedio,TAM);

    ordenarAlumnosLeg(legajo,edades,sexo,nota1,nota2,promedio,TAM);
    mostrarAlumnos(legajo,edades,sexo,nota1,nota2,promedio,TAM);

    ordenarAlumnosSex(legajo,edades,sexo,nota1,nota2,promedio,TAM);
    mostrarAlumnos(legajo,edades,sexo,nota1,nota2,promedio,TAM);
    ordenarAlumnosSexLeg(legajo,edades,sexo,nota1,nota2,promedio,TAM);
    mostrarAlumnos(legajo,edades,sexo,nota1,nota2,promedio,TAM);

    return 0;
}

void mostrarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[],float prom[],int tam)
{

    printf(" legajo edad  sexo  nota1  nota2  promedio \n");

    for(int i=0; i<tam; i++)
    {

        mostrarAlumno(leg[i],age[i],sex[i],n1[i],n2[i],prom[i]);
    }




}

void mostrarAlumno(int leg, int age, char sex, int n1, int n2, float promedio)
{


    printf("   %d   %d     %c    %d     %d      %.2f  \n",leg,age,sex,n1,n2,promedio);
}

void ordenarAlumnosLeg(int leg[], int age[], char sex[], int n1[], int n2[],float prom[],int tam)
{

    int auxInt;
    float auxFloat;
    char auxChar;

    for(int i = 0; i < tam-1; i++)
    {

        for(int j = i + 1; j < tam; j++)
        {

            if( leg[j] < leg[i] )
            {

                auxInt = leg[j];
                leg[j] = leg[i];
                leg[i] = auxInt;

                auxInt =age[j];
                age[j] = age[i];
                age[i] = auxInt;

                auxChar=sex[j];
                sex[j]=sex[i];
                sex[i]=auxChar;

                auxInt =n1[j];
                n1[j] = n1[i];
                n1[i] = auxInt;

                auxInt =n2[j];
                n2[j] = n2[i];
                n2[i] = auxInt;

                auxFloat=prom[j];
                prom[j]=prom[i];
                prom[i]=auxFloat;

            }
        }
    }

}
void ordenarAlumnosSexLeg( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam)
{

    int auxInt;
    float auxFloat;
    char auxChar;
    int swap = 0;

    for(int i=0; i < tam-1; i++)
    {
        for(int j = i +1; j < tam; j++)
        {

            if( sex[i] > sex[j])  //cond. para ordenar por sexo ascendente
            {
                swap = 1;
            }
            else if( sex[i] == sex[j] && leg[i] > leg[j])  //si tienen el mismo sexo los ordeno por legajo ascendente
            {

                swap = 1;
            }
//si entro a algunos de los if anteriores es porque los tengo que swapear
            if( swap )
            {

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = age[i];
                age[i] = age[j];
                age[j] = auxInt;

                auxChar = sex[i];
                sex[i] = sex[j];
                sex[j] = auxChar;

                auxInt = n1[i];
                n1[i] = n1[j];
                n1[j] = auxInt;

                auxInt = n2[i];
                n2[i] = n2[j];
                n2[j] = auxInt;

                auxFloat = prom[i];
                prom[i] = prom[j];
                prom[j] = auxFloat;
            }

            swap = 0;
        }
    }
}

void ordenarAlumnosSex( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam)
{

    int auxInt;
    float auxFloat;
    char auxChar;

    for(int i=0; i < tam-1; i++)
    {
        for(int j = i +1; j < tam; j++)
        {

            if( sex[i] > sex[j])
            {

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = age[i];
                age[i] = age[j];
                age[j] = auxInt;

                auxChar = sex[i];
                sex[i] = sex[j];
                sex[j] = auxChar;

                auxInt = n1[i];
                n1[i] = n1[j];
                n1[j] = auxInt;

                auxInt = n2[i];
                n2[i] = n2[j];
                n2[j] = auxInt;

                auxFloat = prom[i];
                prom[i] = prom[j];
                prom[j] = auxFloat;
            }
        }
    }
}
