#include "marca.h"
#include "color.h"
#include  "cliente.h"
#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
typedef struct
{
    int idAuto;
    char patente[20];
    int idCliente;
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
} eAuto;
#endif

/** \brief funcion para cargar el vector ingresado
 *
 * \param eAuto vec[] vector a ser cargado
 * \param int tam es el tamaño del vector a ser cargado
 * \param int cantidad la cantidad que cargaremos al vector
 * \return 0 si no cargo el vector, sino devuelve la cantidad cargada
 *
 */

int hardcodearAutos( eAuto vec[], int tam, int cantidad);
/** \brief Funcion para inicializar al campo isEmpty con 1,en todos  los elementos del vector
 *
 * \param eAuto vec[] es el vector que va a ser inicializado
 * \param int tam es el tamaño  del vector ingresado
 *
 */

void inicializarAuto(eAuto vec[], int tam);
/** \brief Busca el primer lugar libre del vector
 *
 * \param eAuto vec[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado

  * \return -1 si no hay lugar libre, sino devuelve la posicion en el vector que hay  libre
  *
  */

int buscarLibre(eAuto vec[], int tam);
/** \brief Busca si  el vector tiene al menos una posicion cargada
 *
 * \param eAuto vec[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado

  * \return -1 si esta vacio el vector, 1 si encuentra cargado  al menos con uno el vector
  *
  */
int estaCargado(eAuto vec[], int tam);
/** \brief Muestra todos los autos cargados
 *
 * \param eAuto autos[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector de autos
 * \param eColor colores[] vector estructura donde se guardan los colores
 * \param int tamColor tamaño del vector de colores
 * \param eMarca marcas[] vector estructura donde se guardan las marcas
 * \param int tamMarca tamaño del vector de marcas
 * \param eCliente clientes[] vector estructura donde se guardan los clientes
 * \param int tamCliente tamaño del vector de clientes

  */
void listarAutos(eAuto autos[], int tam,eColor colores[],int tamColor,eMarca marcas[],int tamMarca,eCliente clientes[],int tamCliente);
/** \brief Muestra todos los autos cargados
 *
 * \param eAuto autos[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector de autos
 * \param eColor colores[] vector estructura donde se guardan los colores
 * \param int tamColor tamaño del vector de colores
 * \param eMarca marcas[] vector estructura donde se guardan las marcas
 * \param int tamMarca tamaño del vector de marcas
 * \param eCliente clientes[] vector estructura donde se guardan los clientes
 * \param int tamCliente tamaño del vector de clientes

  */
void mostrarAutos(eAuto autos[], int tam,eColor colores[],int tamColor,eMarca marcas[],int tamMarca,eCliente clientes[],int tamCliente);
/** \brief Muestra los datos de un auto
 *
 * \param eAuto aut es el objeto a ser mostrado
 * \param eColor colores[] vector estructura donde se guardan los colores
 * \param int tamColor tamaño del vector de colores
 * \param eMarca marcas[] vector estructura donde se guardan las marcas
 * \param int tamMarca tamaño del vector de marcas
 * \param eCliente clientes[] vector estructura donde se guardan los clientes
 * \param int tamCliente tamaño del vector de clientes
  */
void mostrarAuto(eAuto aut,eColor colores[],int tamColor,eMarca marcas[],int tamMarca,eCliente clientes[],int tamCliente);
/** \brief Busca el objeto en  el vector  por id
 *
 * \param int idAuto es el id del auto a ser buscado
 * \param eAuto vec[] es el vector en el cual se buscara
 * \param int tam es el tamaño  del vector ingresado

  * \return -1 si no lo encuentra , sino devuelve la posicion en el vector donde se encontro el objeto
  *
  */
int buscarAuto(int idAuto, eAuto vec[], int tam);
/** \brief Busca el objeto en  el vector  por patente
 *
 * \param char patente[] es el id del auto a ser buscado
 * \param eAuto vec[] es el vector en el cual se buscara
 * \param int tam es el tamaño  del vector ingresado

  * \return -1 si no lo encuentra , sino devuelve la posicion en el vector donde se encontro el objeto
  *
  */
int buscarAutoPatente(char patente[], eAuto vec[], int tam);

/** \brief Funcion para dar  de alta  una entidad de  tipo auto
 *
 * \param int id que se asignará
 * \param int idCliente que se asignará
 * \param eAuto vec[] vector a ser analizado
 * \param int tamAuto tamaño del vector de tipo auto
 * \param eMarca marca[] es el vector que guarda las marcas de autos
 * \param int tamMarca tamaño del vector de tipo Marca
 * \param eColor color[] es el vector que guarda los colores
 * \param int tamColor tamaño del vector de tipo Color
 * \param eCliente clientes[] es el vector que guarda los clientes
 * \param int tamCliente tamaño del vector de tipo  Cliente
  * \return 1 si lo pudo dar de alta , 0 sino lo pudo hacer
  *
  */
int altaAuto(int id,int idCliente,eAuto vec[],int tamAuto,eMarca marca[],int tamMarca,eColor color[],int tamColor,eCliente clientes[],int tamCliente);

/** \brief Funcion para modificar color/modelo  de una entidad de  tipo auto
 *
 * \param eAuto vec[] vector a ser analizado
 * \param int tam tamaño del vector de tipo auto
 * \param eMarca marca[] es el vector que guarda las marcas de autos
 * \param int tamMarca tamaño del vector de tipo Marca
 * \param eColor colores[] es el vector que guarda los colores
 * \param int tamColor tamaño del vector de tipo Color
 * \param eCliente clientes[] es el vector que guarda los clientes
 * \param int tamCliente tamaño del vector de tipo  Cliente
 * \return 1 si se pudo modificar al objeto , 0 no se pudo modificar
  *
  */

int modificarAuto(eAuto vec[], int tam,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eCliente clientes[],int tamCliente);
/** \brief Funcion para dar  de baja a  una entidad de  tipo auto
 *
 * \param eAuto vec[] es el vector a ser analizado
 * \param int tam tamaño del vector ingresado
 * \param eMarca marca[] es el vector que guarda las marcas de autos
 * \param int tamMarca tamaño del vector de tipo Marca
 * \param eColor color[] es el vector que guarda los colores
 * \param int tamColor tamaño del vector de tipo Color
 * \param eCliente clientes[] es el vector que guarda los clientes
 * \param int tamCliente tamaño del vector de tipo  Cliente
 * \return 1 si lo pudo dar de baja , 0 sino lo pudo hacer
 *
 */
int bajaAuto(eAuto vec[], int tam,eMarca marca[],int tamMarca,eColor color[],int tamColor,eCliente clientes[],int tamCliente);
/** \brief Funcion para crear un objeto de tipo eAuto
 *
 * \param int idAuto es el id que se asignará
 * \param int idCliente es el id que se asignará
 * \param char patente[] es la patente que se asignará
 * \param int idMarca referencia a la marca del auto
 * \param int idColor referencia al color  del auto
 * \param int modelo parametro donde se cargara el año del modelo del auto que se asiganara
 * \return un objeto de tipo eAuto
 *
 */

eAuto newAuto( int idAuto,
               char patente[],
               int idCliente,
               int idMarca,
               int idColor,
               int modelo);

/** \brief Funcion que ordena al vector por marca y patente
 *
 * \param eAuto vec[] vector que se ordenará
 * \param int tam tamaño del vector
 * \return no devuelve nada
 *
 */

void ordenarAutosMarcaPatente( eAuto vec[], int tam);
void mostrarAutoLocalidades( eAuto vec[],int tamAuto,eMarca marca[],int tamMarca,eColor color[],int tamColor,eCliente clientes[],int tamCliente);
