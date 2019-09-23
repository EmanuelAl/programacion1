#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TAM 1


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
    int isEmpty;
} eAlumno;

void mostrarAlumno(eAlumno x);
void mostrarAlumnos(eAlumno vec[], int tam);
void ordenarAlumnos(eAlumno vec[], int tam);
int menu();
int buscarLibre(eAlumno alumnos[],int tam);
void inicializarAlumnos(eAlumno alumnos[],int tam);


eAlumno newAlumno(int legajo,char nombre[],int edad,char sexo,int nota1,int nota2,eFecha fecha);
int buscarAlumno(int legajo,eAlumno alumnos[],int tam);
int altaAlumno(eAlumno alumnos[], int tam);
int bajaAlumno(eAlumno alumnos[], int tam);
int modificarAlumno(eAlumno alumnos[], int tam);

int main()
{


    eAlumno lista[TAM];

    char salir='n';

    inicializarAlumnos(lista,TAM);

    do
    {
        switch(menu())
        {

        case 1:
            //printf("Alta alumnos \n");
            altaAlumno(lista,TAM);
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
            printf("Confirma salir?¿ \n");
            fflush(stdin);
            salir=getch();
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

void mostrarAlumno(eAlumno x)
{
    printf("  %d  %s  %d     %c      %d   %d      %.2f   %02d/%02d/%d\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio);
}

void mostrarAlumnos(eAlumno vec[], int tam)
{
    int flag=0;
    system("cls");
    printf("**** Listado de Alumnos ****\n\n");

    printf(" Legajo Nombre Edad Sexo Nota1 Nota2 Promedio FIngreso\n");
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
    printf("7-Salir \n");
    printf("Ingrese opcion :\n");
    scanf("%d",&opcion);

    return opcion;

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

            alumnos[indice]=newAlumno(legajo,nombre,edad,sexo,nota1,nota2,fecha);
            todoOk=1;
        }
    }
    return todoOk;

}
eAlumno newAlumno(int legajo,char nombre[],int edad,char sexo,int nota1,int nota2,eFecha fecha)
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
