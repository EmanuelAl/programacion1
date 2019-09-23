#include "carrera.h"


#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
    int idCarrera;//foreign key clave foranea para relacionarla con la estructura carrera
    int isEmpty;
} eAlumno;

#endif
void mostrarAlumno(eAlumno x,eCarrera carreras[],int tam);
void mostrarAlumnos(eAlumno vec[],eCarrera carreras[], int tamC);
void ordenarAlumnos(eAlumno vec[], int tam);

int buscarLibre(eAlumno alumnos[],int tam);
void inicializarAlumnos(eAlumno alumnos[],int tam);


eAlumno newAlumno(int legajo,char nombre[],int edad,char sexo,int nota1,int nota2,eFecha fecha);
int buscarAlumno(int legajo,eAlumno alumnos[],int tam);
int altaAlumno(eAlumno alumnos[], int tam);
int altaAlumnoAuto(eAlumno alumnos[], int tam,int legajo);
int bajaAlumno(eAlumno alumnos[], int tam);
int modificarAlumno(eAlumno alumnos[], int tam);


int hardcodearAlumnos(eAlumno alumnos[],int tam,int cant);
