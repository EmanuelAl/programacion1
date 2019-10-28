#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[20];
    float sueldo;
} eEmpleado;
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int id,char* nombre,float sueldo);

int setIdEmpleado(eEmpleado* e,int id);
int setSueldoEmpleado(eEmpleado* e,float sueldo);
int setNombreEmpleado(eEmpleado* e,char* nombre);
int getIdEmpleado(eEmpleado* e, int*id);
int getSueldoEmpleado(eEmpleado* e, float*sueldo);
int getNombreEmpleado(eEmpleado* e, char* nombre);
int mostrarEmpleado(eEmpleado* e);
int mostrarEmpleados(eEmpleado** e,int tam);
int mostrarEmpleados(eEmpleado** e,int tam);

int main()
{
    int tam= 0;
    eEmpleado* auxEmpleado = NULL;
    eEmpleado** lista= (eEmpleado**) malloc(sizeof(eEmpleado*));
    int auxInt;
    float auxFloat;
    char auxCad[20];
    if(lista == NULL)
    {
        printf("No se pudo asignar memoria\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

/*
    printf("Ingrese id: ");
    scanf("%d",&auxInt);
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(auxCad);
    printf("Ingrese sueldo: ");
    scanf("%f",&auxFloat);

    auxEmpleado =  newEmpleadoParam(18700,"Jose",24500);

    if(auxEmpleado==NULL)
    {
        printf("No se pudo crear empleado \n");
    }
    else
    {
        printf(" Empleado creado con exito\n");

        *(lista + tam) = auxEmpleado;

        if(agrandarLista(lista,tam + 1) != NULL)
        {
            printf("Empleado agregado a la lista\n");
            tam++;
        }

    }
    system("pause");

    mostrarEmpleados(lista,tam);
    */

    char buffer[3][30];

    FILE* f = fopen("empleados.csv","r");
    if( f == NULL){
        exit(1);
    }
    while(!feof(f)){
    cant =fscanf(f, "%[^,],%[^,],%[^\n]\n",buffer[0].buffer[1],buffer[3]);//lee todo hasta que encuenctra la coma y salta la coma,menos la comas
    if(cant == 3){

        auxEmpleado = newEmpleadoParam(atoi(buffer[0]),buffer[1],atof(buffer[3]));
        if( auxEmpleado != NULL){

        *(lista + tam) = auxEmpleado;

        if(agrandarLista(lista,tam + 1) != NULL)
        {
            tam++;
        }
        }
    }
    }
    mostrarEmpleado(lista,tam);
    fclose(f);

    return 0;
}
eEmpleado* newEmpleado()
{
    eEmpleado* nuevo = (eEmpleado*) malloc(sizeof(eEmpleado));
    if(nuevo!=NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->sueldo=0;
    }
    return nuevo;
}
eEmpleado* newEmpleadoParam(int id,char* nombre,float sueldo)
{
    eEmpleado* nuevo = newEmpleado();
    if(nuevo != NULL)
    {
        if(setIdEmpleado(nuevo, id) && setNombreEmpleado(nuevo, nombre) && setSueldoEmpleado(nuevo, sueldo) )
        {
            printf("Empleado creado correctamente \n");
        }
    }
    return nuevo;
}
int setIdEmpleado(eEmpleado* e,int id)
{
    int todoOk=0;
    if(e != NULL && id >= 10000 && id <= 20000)
    {
        e->id = id;
        todoOk=1;
    }
    return todoOk;
}

int setSueldoEmpleado(eEmpleado* e,float sueldo)
{
    int todoOk=0;
    if(e != NULL && sueldo >0)
    {
        e->sueldo = sueldo;
        todoOk=1;
    }
    return todoOk;
}
int setNombreEmpleado(eEmpleado* e,char* nombre)
{
    int todoOk=0;
    if(e != NULL && nombre != NULL && strlen(nombre)<20)
    {
        strcpy(e->nombre, nombre);
        todoOk=1;
    }
    return todoOk;
}
int getIdEmpleado(eEmpleado* e, int*id)
{
    int todoOk=0;
    if(e != NULL && id!= NULL )
    {
        *id = e->id;
        todoOk=1;
    }
    return todoOk;
}
int getSueldoEmpleado(eEmpleado* e, float*sueldo)
{
    int todoOk=0;
    if(e != NULL && sueldo!= NULL )
    {
        *sueldo = e->sueldo;
        todoOk=1;
    }
    return todoOk;
}
int getNombreEmpleado(eEmpleado* e, char* nombre)
{
    int todoOk=0;
    if(e != NULL && nombre!= NULL )
    {
        strcpy(nombre, e->nombre);
        todoOk=1;
    }
    return todoOk;
}
int mostrarEmpleado(eEmpleado* e)
{
    int todoOk=0;

    if(e != NULL)
    {
        printf("%d  %s  %.2f \n",e->id,e->nombre,e->sueldo);
        todoOk=1;
    }
    return todoOk;
}
int mostrarEmpleados(eEmpleado** e,int tam)
{
    int todoOk=0;
    printf(" Id   Nombre    Sueldo \n\n");
    if( e != NULL && tam > 0)
    {
        for(int i=0; i < tam ; i++)
        {
            mostrarEmpleado(*(e + i));
        }

        todoOk=1;
    }
    return todoOk;
}
eEmpleado* agrandarLista(eEmpleado* vec, int tam)
{
    eEmpleado** aux = (eEmpleado**) realloc(vec, sizeof(eEmpleado*)+ 1);
    if( aux!= NULL)
    {
        vec= aux;

    }
    return aux;
}
