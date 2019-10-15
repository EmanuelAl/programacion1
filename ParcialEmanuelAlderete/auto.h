#include "marca.h"
#include "color.h"
typedef struct
{
    int idAuto;
    char patente[20];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
} eAuto;
/** \brief Funcion para cargar el vector analizado
 *
 * \param eAuto vec[] es el vector que va a ser cargado
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
 * \param eAuto vec[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado

  */
void listarAutos(eAuto autos[], int tam);
/** \brief Muestra todos los autos cargados
 *
 * \param eAuto vec[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado

  */
void mostrarAutos(eAuto autos[], int tam);
/** \brief Muestra un auto ingresado por parametro
 *
 * \param eAuto aut es el objeto a ser mostrado

  */
void mostrarAuto(eAuto aut);
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
 * \param eAuto vec[] vector a ser analizado
 * \param int tamAuto tamaño del vector de tipo auto
 * \param eMarca marca[] es el vector que guarda las marcas de autos
 * \param int tamMarca tamaño del vector de tipo Marca
 * \param eColor color[] es el vector que guarda los colores
 * \param int tamColor tamaño del vector de tipo Color
  * \return 1 si lo pudo dar de alta , 0 sino lo pudo hacer
  *
  */
int altaAuto(int id,eAuto vec[],int tamAuto,eMarca marca[],int tamMarca,eColor color[],int tamColor);

/** \brief Funcion para modificar color/modelo  de una entidad de  tipo auto
 *
 * \param eAuto vec[] vector a ser analizado
 * \param int tam tamaño del vector de tipo auto
 * \param eMarca marca[] es el vector que guarda las marcas de autos
 * \param int tamMarca tamaño del vector de tipo Marca
 * \param eColor colores[] es el vector que guarda los colores
 * \param int tamColor tamaño del vector de tipo Color
 * \return 1 si se pudo modificar al objeto , 0 no se pudo modificar
  *
  */

int modificarAuto(eAuto vec[], int tam,eMarca marca[],int tamMarca,eColor colores[],int tamColor);
/** \brief Funcion para dar  de baja a  una entidad de  tipo auto
 *
 * \param eAuto vec[] es el vector a ser analizado
 * \param int tam tamaño del vector ingresado
 * \return 1 si lo pudo dar de baja , 0 sino lo pudo hacer
 *
 */
int bajaAuto(eAuto vec[], int tam);
/** \brief Funcion para crear un objeto de tipo eAuto
 *
 * \param int idAuto es el id que se asignará
 * \param char patente[] es la patente que se asignará
 * \param int idMarca referencia a la marca del auto
 * \param int idColor referencia al color  del auto
 * \param int modelo parametro donde se cargara el año del modelo del auto que se asiganara
 * \return un objeto de tipo eAuto
 *
 */

eAuto newAuto( int idAuto,
    char patente[],
    int idMarca,
    int idColor,
    int modelo);
