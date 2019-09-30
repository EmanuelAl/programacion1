#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "alumno.h"
#include "almuerzo.h"
#include "comida.h"

void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        almuerzos[i].isEmpty = 1;
    }
}
int hardcodearAlmuerzos( eAlmuerzo almuerzos[], int tam, int cantidad)
{
    int cont = 0;

    eAlmuerzo suplentes[]=
    {
        { 60000, 20005, 5004,{30,9,2019}, 0},
        { 60001, 20003, 5000,{30,9,2019}, 0},
        { 60002, 20001, 5004,{30,9,2019}, 0},
        { 60003, 20000, 5002,{30,9,2019}, 0},
        { 60004, 20004, 5003,{30,9,2019}, 0},
        { 60005, 20005, 5004,{1,10,2019}, 0},
        { 60006, 20003, 5004,{1,10,2019}, 0},
        { 60007, 20006, 5001,{1,10,2019}, 0},
        { 60008, 20000, 5002,{1,10,2019}, 0},
        { 60009, 20005, 5004,{2,10,2019}, 0},
        { 60010, 20001, 5000,{2,10,2019}, 0},
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            almuerzos[i] = suplentes[i];
            cont++;
        }
    }

    return cont;

}
void mostrarAlmuerzo(eAlmuerzo x, eComida comidas[], int tam)
{
    char descComida[20];

    cargarDescComida(x.idComida, comidas, tam, descComida);
    printf("  %d   %d   %10s  %02d/%02d/%d  \n",
           x.id,
           x.legajo,
           descComida,
           x.fecha.dia,
           x.fecha.mes,
           x.fecha.anio,
           );
}

void mostrarAlmuerzos(eAlmuerzo almuerzos[], int tam,  eComida comidas[], int tamC)
{

    int flag = 0;
    system("cls");

    printf("  id   Legajo    descricion    Fecha \n\n");

    for(int i=0; i < tam; i++)
    {
        if( almuerzos[i].isEmpty == 0)
        {
            mostrarAlmuerzo(almuerzos[i], comidas, tamC);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay almuerzos que mostrar\n");
    }

    printf("\n\n");
}

int altaAlmuerzo(eAlmuerzo almuerzos[], int tAlmuerzo,int idAlmuerzo,eAlumno alumnos[], int tAlumno,eComida comidas[],int tComida, eCarrera carreras[], int tCarreras)
{
    int todoOk = 0;
    int indice;
    int legajo;
    int idComida;
    eFecha fecha;

    system("cls");

    printf("*****Alta Almuerzo *****\n\n");

    indice = buscarLibreAlmuerzo(vec, tAlmuerzo);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {

        mostrarAlumnos(alumnos,tAlumno,carreras,tCarreras);
        printf("Ingrese legajo: ");
        scanf("%d"&legajo);
        mostrarComidas(comidas,tComida);
        printf("Ingrese id Comida: ");
        scanf("%d",&idComida);
        printf("Ingrese fecha dd/mm/aaaa: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

        mostrarCarreras(carreras, tamC);
        printf("Ingrese id carrera: ");
        scanf("%d", &idCarrera);

        almuerzos[indice] = newAlmuerzo(idAlmuerzo,legajo,idComida,fecha);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}

eAlmuerzo newAlmuerzo(

    int id,
    int leg,
    char idComida,
    eFecha fecha,
    )
{

    eAlmuerzo al;
    al.id = id;
    al.legajo=leg;
    al.idComida=comida;
    al.fecha = fecha;

    al.isEmpty = 0;

    return al;
}
int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

