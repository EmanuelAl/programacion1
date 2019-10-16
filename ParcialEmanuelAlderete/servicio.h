#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
typedef struct
{
    int idServicio;
    char descServicio[25];
    float precio;
} eServicio;
#endif
/** \brief funcion para cargar el vector ingresado
 *
 * \param eServicio vec[] vector a ser cargado
 * \param int tam es el tamaño del vector a ser cargado
 * \param int cantidad la cantidad que cargaremos al vector
 * \return 0 si no cargo el vector, sino devuelve la cantidad cargada
 *
  */
int hardcodearServicios( eServicio vec[], int tam, int cantidad);
/** \brief Muestra todos los servicios cargados
 *
 * \param eServicio servicios[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado
 *
  */
void listarServicios(eServicio servicios[], int tam);
/** \brief Muestra todos los servicios cargados
 *
 * \param eServicio servicios[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado
 *
  */
void mostrarServicios(eServicio servicios[], int tam);
/** \brief Muestra un servicio
 *
 * \param eServicio servicio es el objeto que será mostrado
 *
  */
void mostrarServicio(eServicio servicio);
/** \brief Funcion que carga un parametro con la descripcion del servicio
 *
 * \param int id es el id del servicio que se buscara en el vector en cuestión
 * \param eServicio vec[] vestor que será recorrido
 * \param int tam es el tamaño del vector a ser recorrido
 * \param  char desc[] parametro que terminará siendo cargado con la descripción
 * \return 1 si se cargó la descripción, 0 si no se pudo realizar la carga
 *
  */

int cargarDescServicio(int id, eServicio vec[], int tam, char desc[]);
