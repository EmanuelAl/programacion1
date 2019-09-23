#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Alumno.h"
#include "carrera.h"

#define TAM 10
typedef struct
{

    int id;
    char descripcion[20];

} eCarrera;

void mostrarCarreras(eCarrera carreras[],int tam);
void mostrarCarrera(eCarrera carrera);
void cargarDescCarrera(int idCarrera,eCarrera carreras[],int tam,char descripcion[]);

int menu();
int main()
{


    eAlumno lista[TAM];
    eCarrera carreras[]= {{1000," TUP"},{1001," TUSI"},{1002," LIC"}}; //HARCODEARMOS 3 CARRERAS
    int legajo= 20000;
    char salir='n';

    inicializarAlumnos(lista,TAM);



    legajo= legajo + hardcodearAlumnos(lista,TAM, 10);//esta linea despues se va,solo es para testing

    do
    {
        switch(menu())
        {

        case 1:
            //printf("Alta alumnos \n");
            //altaAlumno(lista,TAM);
            if(altaAlumnoAuto(lista,TAM,legajo)) //si legajo devuelve true osea 1 se hace lo que esta dentro dela condicion.
            {
                legajo++;
            }

            //aca ya el alta alumno
            break;

        case 2:
            bajaAlumno(lista,TAM);
            //printf("Baja alumnos \n");
            //aca ya el alta alumno
            break;

        case 3:
            //printf("Modificar alumnos \n");
            modificarAlumno(lista,TAM);
            break;

        case 4:
            mostrarAlumnos(lista,TAM);
            //
            break;

        case 5:
            // printf("Ordenar alumnos \n");
            ordenarAlumnos(lista,TAM);
            break;
        case 6:
            printf("Informes \n");
            //
            break;

        case 7:
            mostrarCarreras(carreras,3);
            //
            break;

        case 8:
            printf("Confirma salir?¿ \n");
            fflush(stdin);
            salir=getchar();
            //
            break;
        default:
            printf("Opcion invalida\n");

        }
        system("pause");
    }
    while(salir =='n');


    return 0;
}

int menu()
{

    int opcion;
    system("cls");
    printf("menu de opciones\n\n");
    printf("1-Alta alumno\n");
    printf("2-Baja alumno\n");
    printf("3-Modificar alumno\n");
    printf("4-Listar alumno\n");
    printf("5-Ordenar alumno\n");
    printf("6-Informes \n");
    printf("7-carrera \n");
    printf("8-salir \n");
    printf("Ingrese opcion :\n");
    scanf("%d",&opcion);

    return opcion;

}


