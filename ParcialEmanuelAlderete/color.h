 #ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
 typedef struct
{
    int idColor;
    char nombreColor[20];

} eColor;
#endif
/** \brief funcion para cargar el vector ingresado
 *
 * \param eMarca vec[] vector a ser cargado
 * \param int tam es el tamaño del vector a ser cargado
 * \param int cantidad la cantidad que cargaremos al vector
 * \return 0 si no cargo el vector, sino devuelve la cantidad cargada
 *
 */
int hardcodearColores( eColor vec[], int tam, int cantidad);
/** \brief Muestra todos los colores cargados
 *
 * \param eColor color[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado
 *
  */
void listarColores(eColor color[], int tam);
/** \brief Muestra todos los colores cargados
 *
 * \param eColor color[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado
 *
  */
void mostrarColores(eColor color[], int tam);
/** \brief Muestra un solo color
 *
 * \param eColor color es el objeto que será mostrado
 *
  */
void mostrarColor(eColor color);
/** \brief Funcion que carga un parametro con la descripcion del color
 *
 * \param int id es el id del Color que se buscara en el vector en cuestión
 * \param eColor vec[] vector que será recorrido
 * \param int tam es el tamaño del vector a ser recorrido
 * \param  char desc[] parametro que terminará siendo cargado con la descripción
 * \return 1 si se cargó la descripción, 0 si no se pudo realizar la carga
 *
 */
int cargarDescColor(int id, eColor vec[], int tam, char desc[]);


