#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Alumno.h"

void mostrarAlumno(eAlumno x,eCarrera carreras[],int tam)
{
    char descCarrera[20];
    cargarDescCarrera(x.idCarrera,carreras,tam,descCarrera);
    printf("  %d  %10s  %d     %c      %d   %d      %.2f   %02d/%02d/%d    %s\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio,
           descCarrera);
}

void mostrarAlumnos(eAlumno vec[],eCarrera carreras[], int tamC)
{
    int flag=0;
    system("cls");
    printf("**** Listado de Alumnos ****\n\n");

    printf(" Legajo      Nombre Edad Sexo    Nota1 Nota2 Promedio FIngreso\n");
    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty==0)
        {
            mostrarAlumno(vec[i]);
            flag=1;
        }

    }
    if(flag==0)
    {
        system("cls");
        printf("---No hay alumnos que mostrar---");
    }
    printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam)
{

    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].legajo > vec[j].legajo && vec[i].isEmpty==0 && vec[j].isEmpty==0)//ordeno de menor a mayor por legajo y pregunto si esta o no vacio
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }

    printf("\n**** Alumnos ordenados por legajo******\n");


}


void inicializarAlumnos(eAlumno alumnos[],int tam)
{

    for(int i=0; i<tam; i++)
    {
        alumnos[i].isEmpty=1;
    }

}

int buscarLibre(eAlumno alumnos[],int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(alumnos[i].isEmpty==1)
        {
            indice=i;
            break;//para que frene en el primer lugar libre que encuentra
        }

    }
    return indice;
}
int buscarAlumno(int legajo,eAlumno alumnos[],int tam)
{
    int indice=-1;//si no lo encuentra

    for(int i=0; i<tam; i++)
    {
        if(alumnos[i].isEmpty == 0 && alumnos[i].legajo == legajo)// cero significa que existe
        {
            indice=i;//me devuelve el indice donde esta el alumno en el vector de alumnos
            break;//para que frene cuando lo encontro
        }

    }
    return indice;
}

int altaAlumno(eAlumno alumnos[], int tam)
{
    int todoOk=0;// cero es el false  1 es el true
    int indice;
    int esta;

    int legajo;
    int edad;
    int nota1;
    int nota2;
    char sexo;
    char nombre[20];
    eFecha fecha;


    system("cls");
    printf("***** alta alumno ******");

     indice = buscarLibre(alumnos,tam);

    if(indice == -1)
    {
        printf("\nSistema Completo.No se pueden agregar mas alumnos\n ");
        system("pause");
    }
    else
    {
        printf("\ningrese legajo: ");
        scanf("%d",&legajo);

        esta=buscarAlumno(legajo, alumnos, tam);//si lo encuentra le cargara a "esta" con el indice donde esta ubicado el alumno

        if (esta != -1)
        {

            printf("\nlegajo ya registrado\n");
            mostrarAlumno(alumnos[esta]);
        }
        else
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombre);

            printf("Ingrese edad:");
            scanf("%d", &edad);

            printf("Ingrese sexo:");
            fflush(stdin);
            scanf("%c", &sexo);

            printf("Ingrese nota parcial 1:");
            scanf("%d", &nota1);

            printf("Ingrese nota parcial 2:");
            scanf("%d", &nota2);

            //promedio=(float)(nota1 +nota2)/2;

            printf("Ingrese fecha ingreso: dd/mm/aaaa ");
            scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

            alumnos[indice]=newAlumno(legajo,nombre,edad,sexo,nota1,nota2,fecha,idCarrera);
            todoOk=1;
        }
    }
    return todoOk;

}
eAlumno newAlumno(int legajo,char nombre[],int edad,char sexo,int nota1,int nota2,eFecha fecha,int idCarrera)
{

    eAlumno nuevoAlumno;
    nuevoAlumno.legajo= legajo;
    strcpy(nuevoAlumno.nombre, nombre);
    nuevoAlumno.edad =edad;
    nuevoAlumno.sexo =sexo;
    nuevoAlumno.nota1 =nota1;
    nuevoAlumno.nota2 =nota2;
    nuevoAlumno.promedio =(nota1 +nota2)/2;
    nuevoAlumno.fechaIngreso =fecha;
    nuevoAlumno.isEmpty=0;
    nuevoAlumno.idCarrera=idCarrera;

    return nuevoAlumno;
}

int bajaAlumno(eAlumno alumnos[], int tam)
{

    int todoOk=0;
    int indice;
    int legajo;
    char confirma='n';

    system("cls");
    printf("**** Baja Alumno ****\n\n");

    printf(" ingrese legajo : ");
    scanf("%d",&legajo);

    indice=buscarAlumno(legajo,alumnos,tam);

    if( indice==-1)
    {
        printf(" No existe el alumno ");
        system("pause");
    }
    else
    {
        mostrarAlumno(alumnos[indice]);//mostramos el alumno en la posicion que esta
        printf("confirma eliminacion ? :");
        fflush(stdin);
        confirma =getche();

        if(confirma=='s')
        {
            alumnos[indice].isEmpty=1;
            printf("\n\nSe ha eliminado el alumno\n");
            todoOk=1;
        }
        else
        {
            printf("\n\nSe ha cancelado la baja\n");
        }
        system("pause");
    }
    return todoOk;

}
int modificarAlumno(eAlumno alumnos[], int tam){

    int todoOk=0;
    int indice;
    int legajo;
    int nota;
    int opcion;

    system("cls");
    printf("******modificar alumno*****\n");

    printf("Ingrese nro de legajo: ");
    scanf("%d",&legajo);

    indice = buscarAlumno(legajo,alumnos,tam);

    if(indice==-1){

        printf("\nNo tenemos registrado ese legajo\n");
        system("pause");
    }else{
        mostrarAlumno(alumnos[indice]);

        printf("Modificar\n\n");
        printf("Nota parcial 1\n");
        printf("Nota parcial 2\n");

        printf("Ingrese opcion:");
        scanf("%d",&opcion);

        if(opcion==1){

            printf(" ingrese nota 1: \n ");
            scanf("%d",&nota);

            alumnos[indice].nota1=nota;
            alumnos[indice].promedio= (float)(alumnos[indice].nota1+alumnos[indice].nota2) /2;
            printf("Se actualizo la nota");
            todoOk = 1;
        }else if(opcion==2){

            printf(" ingrese nota 2: \n ");
            scanf("%d",&nota);

            alumnos[indice].nota2=nota;
            alumnos[indice].promedio= (float)(alumnos[indice].nota1+alumnos[indice].nota2) /2;
            printf("Se actualizo la nota");
            todoOk = 1;
        }else{
            printf(" No es una opcion valida! \n ");
        }
        system("pause");
        }

    return todoOk;

}
int altaAlumnoAuto(eAlumno alumnos[], int tam,int legajo)
{
    int todoOk=0;// cero es el false  1 es el true
    int indice;

    int edad;
    int nota1;
    int nota2;
    char sexo;
    char nombre[20];
    eFecha fecha;


    system("cls");
    printf("***** alta alumno ******\n");

     indice = buscarLibre(alumnos,tam);

    if(indice == -1)
    {
        printf("\nSistema Completo.No se pueden agregar mas alumnos\n ");
        system("pause");
        }
        else
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombre);

            printf("Ingrese edad:");
            scanf("%d", &edad);

            printf("Ingrese sexo:");
            fflush(stdin);
            scanf("%c", &sexo);

            printf("Ingrese nota parcial 1:");
            scanf("%d", &nota1);

            printf("Ingrese nota parcial 2:");
            scanf("%d", &nota2);

            //promedio=(float)(nota1 +nota2)/2;

            printf("Ingrese fecha ingreso: dd/mm/aaaa ");
            scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

            alumnos[indice]=newAlumno(legajo,nombre,edad,sexo,nota1,nota2,fecha);
            todoOk=1;
        }

    return todoOk;
}
int hardcodearAlumnos(eAlumno alumnos[],int tam,int cant){


    int cont=0;
    eAlumno listaAuxiliar[10] ={
     { 20000, "Juan", 21, 'm', 2, 10, 6,{12, 5, 2018}, 0},
     { 20001, "Ana", 20, 'f', 2, 10, 6,{12, 5, 2018}, 0},
     { 20002, "Alicia", 25, 'f', 5, 8, 6,{12, 5, 2018}, 0},
     { 20003, "Miguel", 24, 'm', 8, 8, 8,{12, 5, 2018}, 0},
     { 20004, "Gaston", 26, 'm', 5, 2, 6,{12, 5, 2018}, 0},
     { 20005, "Amalia", 22, 'f', 6, 5, 6,{12, 5, 2018}, 0},
     { 20006, "Sofia", 19, 'f', 8, 9, 8,{12, 5, 2018}, 0},
     { 20007, "Diego", 23, 'm', 1, 6, 3,{12, 5, 2018}, 0},
     { 20008, "Fernando", 27, 'm', 8, 7, 6,{12, 5, 2018}, 0},
     { 20009, "Clara", 26, 'f', 4, 6, 6,{12, 5, 2018}, 0}
    };

    if(cant <=tam && cant <11){//cantidad no puede ser mayor a 10 ya que solo cargamos 10 personas como  maximo en esta funcion

        for(int i=0;i<cant;i++){
            alumnos[i]=listaAuxiliar[i];
            cont++;
        }
    }

    return cont;

}

