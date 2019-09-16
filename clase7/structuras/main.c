#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;
typedef struct{
int legajo;
char nombre[20];
int edad;
char sexo;
int nota1;
int nota2;
float promedio;
eFecha fechaIngreso;
}eAlumno;

int main()
{
   eAlumno alumno1;

   printf("Ingrese nombre: ");
   gets(alumno1.nombre);
   printf("Ingrese legajo: ");
   scanf("%d",&alumno1.legajo);
   printf("Ingrese edad: ");
   scanf("%d",&alumno1.edad);
   printf("Ingrese sexo: ");
   fflush(stdin);
   scanf("%c",&alumno1.sexo);
   printf("Ingrese nota 1");
   scanf("%d",&alumno1.nota1);
   printf("Ingrese nota 2: ");
   scanf("%d",&alumno1.nota2);
   printf("Ingrese dia: ");
   scanf("%d",&alumno1.fechaIngreso.dia);
    printf("Ingrese mes: ");
   scanf("%d",&alumno1.fechaIngreso.mes);
    printf("Ingrese año: ");
   scanf("%d",&alumno1.fechaIngreso.anio);

   alumno1.promedio= (float)(alumno1.nota1 + alumno1.nota2)/2;

   printf(" Nombre: %s\n legajo: %d \n sexo: %c\n nota 1: %d\n nota 2: %d\n promedio: %2.f\n Fecha de ingreso: %02d/02%d/%d\n",
          alumno1.nombre,
          alumno1.legajo,
          alumno1.sexo,
          alumno1.nota1,
          alumno1.nota2,
          alumno1.promedio,
          alumno1.fechaIngreso.dia,
          alumno1.fechaIngreso.mes,
          alumno1.fechaIngreso.anio
          );
    return 0;
}
