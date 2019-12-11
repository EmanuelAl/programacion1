#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Bicicleta.h"
/** \brief Crea un nueva  bicicleta en memoria de manera dinamica
 *
 * \param
 * \return Cachorro* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 *
 */

Bicicleta* bicicleta_new()//devuelve un puntero
{
    Bicicleta* nuevo = NULL;
    nuevo=(Bicicleta*) malloc( sizeof(Bicicleta));
    if(nuevo != NULL)//si no es null inicializo los campos de la variable de tipo estructura a la que apunta nuevo
    {
        nuevo->idBici = 0;
        strcpy(nuevo->nombre, " ");

        strcpy(nuevo->tipo, " ");
        nuevo->tiempo = 0;

    }
    return nuevo;
}


/** \brief modifica el id de un elemento de tipo puntero a Bicicleta
 *
 * \param Bicicleta* this puntero al elemento a ser modificado
 * \param int id  valor del id que se asignará
 * \return (0) si no puede modificar el id
            (1) si lo pudo modificar
 *
 */

int bicicleta_setId(Bicicleta* this,int id)
{
    int todoOk = 0;

    if( this != NULL && id >= 51)
    {
        this->idBici= id;
        todoOk = 1;
    }
    return todoOk;
}
/** \brief Permite obtener el campo id del elemento
 *
 * \param Bicicleta* this puntero al elemento del cual obtendremos el campo
 * \param int* id puntero en el cual se guardara el campo buscado
 * \return Retorna (0) si no puede realizarlo
                   (1) si lo pudo realizar
 *
 */
int bicicleta_getId(Bicicleta* this,int* id)
{
    int todoOk = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->idBici;
        todoOk = 1;
    }
    return todoOk;
}
/** \brief modifica el nombre de un elemento de tipo puntero a Bicicleta
 *
 * \param Bicicleta* this puntero al elemento a ser modificado
 * \param char* nombre  puntero al nombre que se asignará
 * \return (0) si no puede modificar el nombre
            (1) si lo pudo modificar
 *
 */
int bicicleta_setNombre(Bicicleta* this,char* nombre)
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
 * \param Bicicleta* this puntero al elemento del cual obtendremos el campo
 * \param char* nombre puntero en el cual se guardara el campo buscado
 * \return Retorna (0) si no puede realizarlo
                   (1) si lo pudo realizar
 *
 */
int bicicleta_getNombre(Bicicleta* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

 /** \brief modifica el tipo de un elemento de tipo puntero a Bicicleta
 *
 * \param Bicicleta* this puntero al elemento a ser modificado
 * \param char* nombre  puntero al nombre que se asignará
 * \return (0) si no puede modificar el nombre
            (1) si lo pudo modificar
 *
 */
int bicicleta_setTipo(Bicicleta* this,char* tipo)
{
    int todoOk = 0;
    if( this != NULL && tipo != NULL && strlen(tipo) < 128)
    {
        strcpy(this->tipo, tipo);
        todoOk = 1;
    }
    return todoOk;
}
 /** \brief Permite obtener el campo nombre del elemento
 *
 * \param Bicicleta* this puntero al elemento del cual obtendremos el campo
 * \param char* tipo puntero en el cual se guardara el campo buscado
 * \return Retorna (0) si no puede realizarlo
                   (1) si lo pudo realizar
 *
 */
int bicicleta_getTipo(Bicicleta* this,char* tipo)
{
    int todoOk = 0;

    if( this != NULL && tipo != NULL)
    {
        strcpy(tipo, this->tipo);
        todoOk = 1;
    }
    return todoOk;
}



 /** \brief modifica el tiempo de un elemento de tipo puntero a Bicicleta
 *
 * \param Bicicleta* this puntero al elemento a ser modificado
 * \param int dias valor de los dias que se asignarán
 * \return (0) si no puede modificar
            (1) si lo pudo modificar
 *
 */

int bicicleta_setTiempo(Bicicleta* this,int tiempo)
{
    int todoOk = 0;
    if( this != NULL && tiempo>=0)
    {
        this->tiempo= tiempo;
        todoOk = 1;
    }
    return todoOk;
}
/** \brief Permite obtener el campo tiempo del elemento
 *
 * \param Bicicleta* this puntero al elemento del cual obtendremos el campo
 * \param int* tiempo  puntero en el cual se guardara el campo buscado
 * \return Retorna (0) si no puede realizarlo
                   (1) si lo pudo realizar
 *
 */
int bicicleta_getTiempo(Bicicleta* this,int* tiempo)
{
    int todoOk = 0;

    if( this != NULL && tiempo != NULL)
    {
        *tiempo = this->tiempo;
        todoOk = 1;
    }
    return todoOk;
}

int bicicleta_esBMX(void* element){


  int todoOk=-1;
    char aux[5]="BMX";
    char tipo[10];

    if(element!=NULL){
    bicicleta_getTipo(element,tipo);

    if(strcmp(tipo,aux)== 0)
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

int bicicleta_esPLAYERA(void* element){


  int todoOk=-1;
    char aux[10]="PLAYERA";
    char tipo[10];

    if(element!=NULL){
    bicicleta_getTipo(element,tipo);

    if(strcmp(tipo,aux)== 0)
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
int bicicleta_esMTB(void* element){


  int todoOk=-1;
    char aux[5]="MTB";
    char tipo[10];

    if(element!=NULL){
    bicicleta_getTipo(element,tipo);

    if(strcmp(tipo,aux)== 0)
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
int bicicleta_esPASEO(void* element){


  int todoOk=-1;
    char aux[5]="PASEO";
    char tipo[10];

    if(element!=NULL){
    bicicleta_getTipo(element,tipo);

    if(strcmp(tipo,aux)== 0)
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
