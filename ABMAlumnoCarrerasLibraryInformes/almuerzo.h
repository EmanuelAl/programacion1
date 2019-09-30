#include "comida.h"
#include "alumno.h"
#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

typedef struct{
int id;
int legajo;
int idComida;
eFecha fecha;
int isEmpty;

}eAlmuerzo;

#endif // ALMUERZO_H_INCLUDED
void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam);
int hardcodearAlmuerzos( eAlmuerzo almuerzos[], int tam, int cantidad);

void mostrarAlmuerzos(eAlmuerzo almuerzos[], int tam,eComida comidas[], int tamC);
void mostrarAlmuerzo(eAlmuerzo x, eComida comidas[], int tam);
int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam);
eAlmuerzo newAlmuerzo(int id,int leg,int idComida,eFecha fecha);
int altaAlmuerzo(eAlmuerzo almuerzos[], int tAlmuerzo,int idAlmuerzo,eAlumno alumnos[], int tAlumno,eComida comidas[],int tComida, eCarrera carreras[], int tCarreras);
