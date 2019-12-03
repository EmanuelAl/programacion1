#include "Cachorro.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


Cachorro* cachorro_new()//devuelve un puntero
{
    Cachorro* nuevo = (Cachorro*) malloc( sizeof(Cachorro));
    if(nuevo != NULL)//si no es null inicializo los campos de la variable de tipo estructura a la que apunta nuevo
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->dias = 0;
        strcpy(nuevo->raza, " ");
        strcpy(nuevo->reservado, " ");
        strcpy(nuevo->genero, " ");

    }
    return nuevo;
}
Cachorro* cachorro_newParametros(char* idStr,char* nombreStr,char* dias,char* raza,char* reservado,char*genero)
{
    int id=atoi(idStr);
    int auxDias=atoi(dias);

    Cachorro* nuevo = cachorro_new();//puntero con la direccion dinamina
    if( nuevo != NULL && idStr!=NULL && nombreStr!=NULL && dias!=NULL && raza!=NULL && reservado!=NULL && genero!=NULL)
    {
        cachorro_setId(nuevo, id) ;
                cachorro_setNombre(nuevo, nombreStr);
           cachorro_setDias(nuevo,auxDias);
                cachorro_setRaza(nuevo, raza) ;
                cachorro_setReservado(nuevo,reservado) ;
                cachorro_getGenero(nuevo,genero);
        /*{
            printf("cachorro creado correctamente\n");
        }
        else
        {
            nuevo = NULL;
        }*/
    }

    return nuevo;
}
int cachorro_setId(Cachorro* this,int id)
{
    int todoOk = 0;

    if( this != NULL && id >= 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}
int cachorro_getId(Cachorro* this,int* id)
{
    int todoOk = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}
int cachorro_setNombre(Cachorro* this,char* nombre)
{
    int todoOk = 0;
    if( this != NULL && nombre != NULL && strlen(nombre) < 128)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int cachorro_getNombre(Cachorro* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}
int cachorro_setDias(Cachorro* this,int dias)
{
    int todoOk = 0;
    if( this != NULL && dias>=0)
    {
        this->dias= dias;
        todoOk = 1;
    }
    return todoOk;
}
int cachorro_getDias(Cachorro* this,int* dias)
{
    int todoOk = 0;

    if( this != NULL && dias != NULL)
    {
        *dias = this->dias;
        todoOk = 1;
    }
    return todoOk;
}
int cachorro_setRaza(Cachorro* this,char* raza)
{
    int todoOk = 0;
    if( this != NULL && raza != NULL && strlen(raza) < 128)
    {
        strcpy(this->raza, raza);
        todoOk = 1;
    }
    return todoOk;
}
int cachorro_getRaza(Cachorro* this,char* raza)
{
    int todoOk = 0;

    if( this != NULL && raza != NULL)
    {
        strcpy(raza, this->raza);
        todoOk = 1;
    }
    return todoOk;
}
int cachorro_setReservado(Cachorro* this,char* reservado)
{
    int todoOk = 0;
    if( this != NULL && reservado != NULL && strlen(reservado) < 10)
    {
        strcpy(this->reservado, reservado);
        todoOk = 1;
    }
    return todoOk;
}
int cachorro_getReservado(Cachorro* this,char* reservado)
{
    int todoOk = 0;

    if( this != NULL && reservado != NULL)
    {
        strcpy(reservado, this->reservado);
        todoOk = 1;
    }
    return todoOk;
}
int cachorro_setGenero(Cachorro* this,char* genero)
{
    int todoOk = 0;
    if( this != NULL && genero != NULL && strlen(genero) < 10)
    {
        strcpy(this->genero, genero);
        todoOk = 1;
    }
    return todoOk;
}
int cachorro_getGenero(Cachorro* this,char* genero)
{
    int todoOk = 0;

    if( this != NULL && genero != NULL)
    {
        strcpy(genero, this->genero);
        todoOk = 1;
    }
    return todoOk;
}
