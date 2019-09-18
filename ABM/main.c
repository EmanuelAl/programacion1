#include <stdio.h>
#include <stdlib.h>

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


eAlumno newAlumno(int legajo,char nombre[],int edad,char sexo,int nota1,int nota2,float promedio,eFecha fecha);
int buscarAlumno(int legajo,eAlumno alumnos[],int tam);
int altaAlumno(eAlumno alumnos[], int tam);

int bajaAlumno(eAlumno alumnos[], int tam);

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
            printf("Alta alumnos \n");
            altaAlumno(lista,TAM);
            //aca ya el alta alumno
            break;

        case 2:
            bajaAlumno(lista,TAM);
            printf("Baja alumnos \n");
            //aca ya el alta alumno
            break;

        case 3:
            printf("Modificar alumnos \n");
            //aca ya el alta alumno
            break;

        case 4:
            printf(" Listar alumnos \n");
            //aca ya el alta alumno
            break;

        case 5:
            printf("Ordenar alumnos \n");
            //aca ya el alta alumno
            break;
        case 6:
            printf("Informes \n");
            //aca ya el alta alumno
            break;

        case 7:
            printf("Confirma salir?¿ \n");
            fflush(stdin);
            salir=getch();
            //aca ya el alta alumno
            break;

        default:
            printf("Opcion incorrecta\n");

        }
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
    printf(" Legajo Nombre Edad Sexo Nota1 Nota2 Promedio FIngreso\n");
    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty==0)
        {
            mostrarAlumno(vec[i]);
        }
        flag=1;
    }
    if(flag==0)
    {
        system("cls");
        printf("No hay alumnos que mostrar---");
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
            if( vec[i].legajo > vec[j].legajo)
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

            indice==i;
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
            indice==i;//me devuelve el indice donde esta el alumno en el vector de alumnos
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
    float promedio;
    indice = buscarLibre(alumnos,tam);

    printf("*****alta alumno ********");
    system("cls");
    if(indice == -1)
    {
        printf("Sistema Completo.No se pueden agregar mas alumnos\n ");
        system("pause");
    }
    else
    {
        printf("ingrese legajo: ");
        scanf("%d",&legajo);

        esta=buscarAlumno(legajo, alumnos, tam);//si lo encuentra le cargara a "esta" con el indice donde esta ubicado el alumno

        if (esta != -1)
        {

            printf("legajo ya registrado\n");
            mostrarAlumno(alumnos[esta]);
        }
        else
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombre);

            printf("Ingrese legajo:");
            scanf("%d", &legajo);

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

            eAlumno alumno=newAlumno(legajo,nombre,edad,sexo,nota1,nota2,promedio,fecha);
            todoOk=1;
        }
    }
    return todoOk;

}
eAlumno newAlumno(int legajo,char nombre[],int edad,char sexo,int nota1,int nota2,float promedio,eFecha fecha)
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

    printf(" ingrese legajo : ");
    scanf("%d",&legajo);

    indice=buscarAlumno(legajo,alumnos,tam);

    if( indice==-1)
    {
        printf(" No existe el alumno ");

    }
    else
    {
        mostrarAlumno(alumnos[indice]);
        printf("confirma eliminacion ? :");
        fflush(stdin);
        confirma =getche();

        if(confirma=='s')
        {
            alumnos.isEmpty=1;
            printf("se ha eliminado alumno ");
            todoOk=1;
        }
        else
        {
            printf("se ha cancelado la baja");
        }

    }
    return todoOk;

}
int modificarAlumno(eAlumno alumnos[], int tam){

    int todoOk=0;




    returno todoOk;

}
