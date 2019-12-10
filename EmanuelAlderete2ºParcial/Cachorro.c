#include "Cachorro.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/** \brief Crea un nuevo Cachorro en memoria de manera dinamica
 *
 * \param
 * \return Cachorro* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 *
 */

Cachorro* cachorro_new()//devuelve un puntero
{
    Cachorro* nuevo = NULL;
    nuevo=(Cachorro*) malloc( sizeof(Cachorro));
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
/** \brief Crea un nuevo Cachorro en memoria de manera dinamica ingresando le parametros
 *
 * \param char* idStr el id que recibirá el Cachorro
 * \param char* nombreStr el nomgre que recibirá el Cachorro
 * \param char* dias la cantidad de dias de vida
 * \param char* raza la raza de perro
 * \param char* reservado puede ser SI o NO
 * \param char*genero puede ser M para macho O H para hembra
 * \return Cachorro* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 *
 */
Cachorro* cachorro_newParametros(char* idStr,char* nombreStr,char* dias,char* raza,char* reservado,char*genero)
{
    int id=atoi(idStr);
    int auxDias=atoi(dias);
    Cachorro* nuevo = NULL;

    nuevo = cachorro_new();//puntero con la direccion dinamina
    if( nuevo != NULL && idStr!=NULL && nombreStr!=NULL && dias!=NULL && raza!=NULL && reservado!=NULL && genero!=NULL)
    {
        cachorro_setId(nuevo, id) ;
        cachorro_setNombre(nuevo, nombreStr);
        cachorro_setDias(nuevo,auxDias);
        cachorro_setRaza(nuevo, raza) ;
        cachorro_setReservado(nuevo,reservado) ;
        cachorro_getGenero(nuevo,genero);
    }

    return nuevo;
}
/** \brief modifica el id de un elemento de tipo puntero a Cachorro
 *
 * \param Cachorro* this puntero al elemento a ser modificado
 * \param int id  valor del id que se asignará
 * \return (0) si no puede modificar el id
            (1) si lo pudo modificar
 *
 */

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
/** \brief Permite obtener el campo id del elemento
 *
 * \param Cachorro* this puntero al elemento del cual obtendremos el campo
 * \param int* id puntero en el cual se guardara el campo buscado
 * \return Retorna (0) si no puede realizarlo
                   (1) si lo pudo realizar
 *
 */
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
/** \brief modifica el nombre de un elemento de tipo puntero a Cachorro
 *
 * \param Cachorro* this puntero al elemento a ser modificado
 * \param char* nombre  puntero al nombre que se asignará
 * \return (0) si no puede modificar el nombre
            (1) si lo pudo modificar
 *
 */
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
/** \brief Permite obtener el campo nombre del elemento
 *
 * \param Cachorro* this puntero al elemento del cual obtendremos el campo
 * \param char* nombre puntero en el cual se guardara el campo buscado
 * \return Retorna (0) si no puede realizarlo
                   (1) si lo pudo realizar
 *
 */
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
/** \brief modifica los dias de un elemento de tipo puntero a Cachorro
 *
 * \param Cachorro* this puntero al elemento a ser modificado
 * \param int dias valor de los dias que se asignarán
 * \return (0) si no puede modificar
            (1) si lo pudo modificar
 *
 */
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
/** \brief Permite obtener el campo dias del elemento
 *
 * \param Cachorro* this puntero al elemento del cual obtendremos el campo
 * \param int* dias  puntero en el cual se guardara el campo buscado
 * \return Retorna (0) si no puede realizarlo
                   (1) si lo pudo realizar
 *
 */
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
/** \brief modifica la raza de un elemento de tipo puntero a Cachorro
 *
 * \param Cachorro* this puntero al elemento a ser modificado
 * \param char* raza puntero a la raza que se asignará
 * \return (0) si no puede modificar
            (1) si lo pudo modificar
 *
 */
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
/** \brief Permite obtener el campo raza del elemento
 *
 * \param Cachorro* this puntero al elemento del cual obtendremos el campo
 * \param char* raza  puntero en el cual se guardara el campo buscado
 * \return Retorna (0) si no puede realizarlo
                   (1) si lo pudo realizar
 *
 */
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
/** \brief modifica un elemento de tipo puntero a Cachorro
 *
 * \param Cachorro* this puntero al elemento a ser modificado
 * \param char* reservado puntero al tipo de reserva  que se asignará
 * \return (0) si no puede modificar
            (1) si lo pudo modificar
 *
 */
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
/** \brief Permite obtener el campo reservado del elemento
 *
 * \param Cachorro* this puntero al elemento del cual obtendremos el campo
 * \param char* reservado  puntero en el cual se guardara el campo buscado
 * \return Retorna (0) si no puede realizarlo
                   (1) si lo pudo realizar
 *
 */
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
/** \brief modifica un elemento de tipo puntero a Cachorro
 *
 * \param Cachorro* this puntero al elemento a ser modificado
 * \param char* genero puntero al genero  que se asignará
 * \return (0) si no puede modificar
            (1) si lo pudo modificar
 *
 */
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
/** \brief Permite obtener el campo genero del elemento
 *
 * \param Cachorro* this puntero al elemento del cual obtendremos el campo
 * \param char* genero  puntero en el cual se guardara el campo buscado
 * \return Retorna (0) si no puede realizarlo
                   (1) si lo pudo realizar
 *
 */
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
/** \brief permite saber si es el elemento mayor a 45 dias
 *
 * \param (void* element) puntero al elemento que sera analizado
 * \return int Retorna  (-1) Error: si el puntero al elemento es NULL
                        (0) si es mayor o igual a 45 dias
                        (1) si es menor a 45 dias
 *
 */

int cachorro_esMenor45Dias(void* element)
{
    int todoOk=-1;
    int dias;
if(element!=NULL){
    cachorro_getDias(element,&dias);
    if(dias < 45)
    {
        todoOk=1;
    }
    else if(dias >= 45)
    {
        todoOk=0;
    }
}
    return todoOk;
}
/** \brief permite saber si el elemento es macho
 *
 * \param (void* element) puntero al elemento que sera analizado
 * \return int Retorna  (-1) Error: si el puntero al elemento es NULL
                        (0) si no es macho
                        (1) si es macho
 *
 */
int cachorro_esMacho(void* element)
{
    int todoOk=-1;
    char macho[5]="M";
    char hembra[5]="H";
    char genero[10];
    if(element!=NULL){
    cachorro_getGenero(element,genero);

    if(strcmp(genero,macho)== 0)
    {
        todoOk=1;
    }
    else if(strcmp(genero,hembra)== 0)
    {
        todoOk=0;
    }
    }

    return todoOk;
}
/** \brief permite saber si el elemento es de raza callejero
 *
 * \param (void* element) puntero al elemento que sera analizado
 * \return int Retorna  (-1) Error: si el puntero al elemento es NULL
                        (0) si no es callejero
                        (1) si es callejero
 *
 */
int cachorro_esCallejero(void* element)
{
    int todoOk=-1;
    char raza[50];
    char callejero[50]="callejero";

if(element!=NULL){
    //strcpy(callejero,"Callejero");
    cachorro_getRaza(element,raza);

    if(stricmp(raza,callejero)== 0)
    {
        todoOk=1;
    }
    else
    {
        todoOk=0;
    }
}
    return todoOk;
}
