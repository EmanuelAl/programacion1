#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED
typedef struct
{
    int idMarca;
    char descMarca[20];

} eMarca;
#endif
/** \brief funcion para cargar el vector ingresado
 *
 * \param eMarca vec[] vector a ser cargado
 * \param int tam es el tamaño del vector a ser cargado
 * \param int cantidad la cantidad que cargaremos al vector
 * \return 0 si no cargo el vector, sino devuelve la cantidad cargada
 *
 */

int hardcodearMarcas(eMarca vec[], int tam, int cantidad);
/** \brief Muestra todos las Marcas cargadas
 *
 * \param eMarca marcas[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado
 *
  */
void listarMarcas(eMarca marcas[], int tam);
/** \brief Muestra todos las Marcas cargadas
 *
 * \param eMarca marcas[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado
 *
  */
void mostrarMarcas(eMarca marcas[], int tam);
/** \brief Muestra una sola Marca
 *
 * \param eMarca marca es el objeto que será mostrado
 *
  */
void mostrarMarca(eMarca marca);
/** \brief Funcion que carga un parametro con la descripcion de la Marca
 *
 * \param int id es el id de la Marca que se buscara en el vector en cuestión
 * \param eMarca vec[] vector que será recorrido
 * \param int tam es el tamaño del vector a ser recorrido
 * \param  char desc[] parametro que terminará siendo cargado con la descripción
 * \return 1 si se cargó la descripción, 0 si no se pudo realizar la carga
 *
 */
int cargarDescMarca(int id, eMarca vec[], int tam, char desc[]);
