#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[20];
    float sueldo;
} eEmpleado;

eEmpleado* newEmpleadoParam( int id, char* nombre, float sueldo);
eEmpleado** agrandarLista(eEmpleado** vec, int tam);
int setIdEmpleado(eEmpleado* e, int id);
int setNombreEmpleado(eEmpleado* e, char* nombre);
int setSueldoEmpleado(eEmpleado* e, float sueldo);
int mostrarEmpleado( eEmpleado* e);
int mostrarEmpleados( eEmpleado** e, int tam);

int guardarEmpleadoBinario(eEmpleado** lista, int tam, char* path);
int guardarEmpleadosCSV( eEmpleado** lista ,int tam,char* path);
int leerEmpleadosBinario()


int main()
{
    int tam = 0; // dice la cantidad de elementos en el array y dice el indice del lugar libre
    int tam2 = 0;
    char buffer[3][30];
    int cant;//cuenta las variables cargadas por fscanf
    eEmpleado* auxEmpleado = NULL;
    eEmpleado** lista = (eEmpleado**) malloc( sizeof(eEmpleado*));
    //int auxInt;
    // float auxFloat;
    // char auxCad[100];


    if( lista == NULL)
    {
        printf("No se pudo asignar memoria\n");
        system("pause");
        exit(EXIT_FAILURE);
    }



    /* printf("Ingrese id: ");
     scanf("%d", &auxInt);

     printf("Ingrese nombre: ");
     fflush(stdin);
     gets(auxCad);

     printf("Ingrese sueldo: ");
     scanf("%f", &auxFloat);

     auxEmpleado = newEmpleadoParam(auxInt, auxCad, auxFloat);
     if( auxEmpleado == NULL)
     {
         printf("No se pudo crear el empleado\n");
     }
     else
     {
         printf("Empleado creado con exito");


         *(lista + tam) = auxEmpleado;

         if(agrandarLista(lista, tam +1 ) != NULL)
         {
             printf("Empleado agregado a la lista");
             tam++;
         }
     }


     system("pause");

     auxEmpleado = newEmpleadoParam(18700, "Jose", 24500);
     if( auxEmpleado == NULL)
     {
         printf("No se pudo crear el empleado\n");
     }
     else
     {
         printf("Empleado creado con exito");


         *(lista + tam) = auxEmpleado;

         if(agrandarLista(lista, tam +1 ) != NULL)
         {
             printf("Empleado agregado a la lista");
             tam++;
         }
     }


     system("pause");

     mostrarEmpleados(lista, tam);



    */



    FILE* f = fopen("empleados.csv", "r");
    if( f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        system("pause");
        exit(1);
    }

    fscanf(f, "%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2] );//hace una primera lectura para saltar el encabezado del archivo

    while( !feof(f))
    {

        cant = fscanf(f, "%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2] );//%[^,], esto sirve para que lea y se salte las comas
        if( cant == 3)
        {
            //la funcion de atoi le pasamos como parametro la cadena que quiero parsear a entero
            //la funcion atof lo mismo que atoi pero parsea a flotante es decir a float

            //id     nombre      sueldo
            auxEmpleado = newEmpleadoParam(atoi(buffer[0]), buffer[1], atof(buffer[2]));//auxEmpleado recibe la direccion de memoria donde esta cargado el empleado

            if( auxEmpleado != NULL)
            {
                *(lista + tam) = auxEmpleado;//lo usamos a tam para los desplazamientos
                //mostrarEmpleado(auxEmpleado);
                tam++;
                // system("pause");

                if((lista=agrandarLista(lista, tam + 1 )) == NULL)
                {
                    printf("no se pudo agrandar lista\n");
                }

            }
        }
        else
        {
            break;
        }
    }
    fclose(f);
    //
    mostrarEmpleados(lista, tam);

    if(guardarEmpleadoBinario(lista,tam,"empleados.bin"))
    {
        printf(" Empleados guardados con exito\n");

    }
    else
    {
        printf("No se pudieron serializar los empleados \n");
    }


    //-----------------------------------------leo desde binario -----------------------------

    eEmpleado** lista2 = (eEmpleado**) malloc(sizeof(eEmpleado));


    if( lista2 == NULL)
    {
        printf("No se pudo asignar memoria\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    f = fopen("empleados.bin", "rb");
    if( f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        system("pause");
        exit(1);
    }

    while( !feof(f))
    {
        auxEmpleado= newEmpleado();
        if(auxEmpleado!=NULL)
        {

            cant = fread( auxEmpleado,sizeof(eEmpleado), 1, f);
            if( cant == 1)
            {
                *(lista2 + tam2) = auxEmpleado;//lo usamos a tam para los desplazamientos
                //mostrarEmpleado(auxEmpleado);
                tam2++;
                // system("pause");

                if((lista2=agrandarLista(lista2, tam2 + 1 )) == NULL)
                {
                    printf("no se pudo agrandar lista\n");
                }

            }
        }
        else
        {
            break;
        }
    }

    //
    mostrarEmpleados(lista, tam);

    if(guardarEmpleadoBinario(lista,tam,"empleados.bin"))
    {
        printf(" Empleados guardados con exito\n");

    }
    else
    {
        printf("No se pudieron serializar los empleados \n");
    }
    fclose(f);


    //-----------------------crear un archivo csv de empleados

    if( guardarEmpleadosCSV(lista2, tam2,"listaEmpleados.csv") !){


    }




    return 0;
}

eEmpleado* newEmpleado()
{
    eEmpleado* nuevo = (eEmpleado*) malloc( sizeof(eEmpleado));
    if(nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->sueldo = 0;
    }
    return nuevo;
}

eEmpleado* newEmpleadoParam( int id, char* nombre, float sueldo)
{
    eEmpleado* nuevo = newEmpleado();
    if( nuevo != NULL)
    {
        if(setIdEmpleado(nuevo, id) &&
                setNombreEmpleado(nuevo, nombre)&&
                setSueldoEmpleado(nuevo, sueldo))
        {
            // printf("Empleado creado correctamente\n");
        }
        else
        {
            nuevo = NULL;
        }
    }

    return nuevo;
}

int setIdEmpleado(eEmpleado* e, int id)
{
    int todoOk = 0;
    if( e != NULL && id >= 10000 && id <= 20000)
    {
        e->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int setSueldoEmpleado(eEmpleado* e, float sueldo)
{
    int todoOk = 0;
    if( e != NULL && sueldo > 0)
    {
        e->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int setNombreEmpleado(eEmpleado* e, char* nombre)
{
    int todoOk = 0;
    if( e != NULL && nombre != NULL && strlen(nombre) < 20)
    {
        strcpy(e->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int getIdEmpleado(eEmpleado* e, int* id)
{
    int todoOk = 0;

    if( e != NULL && id != NULL)
    {
        *id = e->id;
        todoOk = 1;
    }
    return todoOk;
}

int getSueldoEmpleado(eEmpleado* e, float* sueldo)
{
    int todoOk = 0;

    if( e != NULL && sueldo != NULL)
    {
        *sueldo = e->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int getNombreEmpleado(eEmpleado* e, char* nombre)
{
    int todoOk = 0;

    if( e != NULL && nombre != NULL)
    {
        strcpy(nombre, e->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarEmpleado( eEmpleado* e)
{
    int todoOk = 0;

    if( e != NULL)
    {

        printf("%d %s %.2f\n", e->id, e->nombre, e->sueldo);
        todoOk = 1;
    }

    return todoOk;

}

int mostrarEmpleados( eEmpleado** e, int tam)
{
    int todoOk = 0;

    if( e != NULL && tam > 0)
    {
        printf("Id   Nombre   Sueldo\n\n");
        for( int i=0; i < tam; i++)
        {
            mostrarEmpleado(*(e + i));
        }
        todoOk = 1;
    }

    return todoOk;

}


eEmpleado** agrandarLista(eEmpleado** vec, int tam)
{
    eEmpleado** aux = (eEmpleado**) realloc(vec, sizeof(eEmpleado*) * tam);
    if( aux != NULL)
    {
        vec = aux;
    }
    return vec;
}

int guardarEmpleadoBinario(eEmpleado** lista, int tam, char* path)
{
    int todoOk=0;
    int cant;
    FILE* f;
    if( lista != NULL && path != NULL && tam > 0)
    {
        f=fopen(path, "wb");
        if(f == NULL)
        {
            return todoOk;
        }
        for(int i=0; i< tam; i++)
        {
            cant =  fwrite( *(lista + i), sizeof(eEmpleado), 1, f);
            if(cant < 1)
            {

                return todoOk;
            }

        }
        fclose(f);
        todoOk=1;

    }
    return todoOk;
}

int guardarEmpleadosCSV( eEmpleado** lista ,int tam,char* path){


    int todoOk=0;
    int cant;
    eEmpleado auxEmp;

    FILE* f;
    if( lista != NULL && path != NULL && tam > 0)
    {
        f=fopen(path, "w");
        if(f == NULL)
        {
            return todoOk;
        }
        fprintf(f,"  " );
        for(int i=0; i< tam; i++)
        {
            auxEmp=*(lista + i));
            //cant =  fwrite( *(lista + i), sizeof(eEmpleado), 1, f);
           // cant = fprintf(f,"%d, %s, %.2f\n",(*(lista + i))->id,(*(lista + i))->nombre,(*(lista + i))->sueldo);
            cant = fprintf(f,"%d, %s, %.2f\n",auxEmp->id,auxEmp->nombre,auxEmp)->sueldo);
            if(cant < 1)
            {
                return todoOk;
            }

        }
        fclose(f);
        todoOk=1;

    }
    return todoOk;


}
