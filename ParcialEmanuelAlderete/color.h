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
 * \param int tam es el tama�o del vector a ser cargado
 * \param int cantidad la cantidad que cargaremos al vector
 * \return 0 si no cargo el vector, sino devuelve la cantidad cargada
 *
 */
int hardcodearColores( eColor vec[], int tam, int cantidad);
/** \brief Muestra todos los colores cargados
 *
 * \param eColor color[] es el vector que va a ser analizado
 * \param int tam es el tama�o  del vector ingresado
 *
  */
void listarColores(eColor color[], int tam);
/** \brief Muestra todos los colores cargados
 *
 * \param eColor color[] es el vector que va a ser analizado
 * \param int tam es el tama�o  del vector ingresado
 *
  */
void mostrarColores(eColor color[], int tam);
/** \brief Muestra un solo color
 *
 * \param eColor color es el objeto que ser� mostrado
 *
  */
void mostrarColor(eColor color);
/** \brief Funcion que carga un parametro con la descripcion del color
 *
 * \param int id es el id del Color que se buscara en el vector en cuesti�n
 * \param eColor vec[] vector que ser� recorrido
 * \param int tam es el tama�o del vector a ser recorrido
 * \param  char desc[] parametro que terminar� siendo cargado con la descripci�n
 * \return 1 si se carg� la descripci�n, 0 si no se pudo realizar la carga
 *
 */
int cargarDescColor(int id, eColor vec[], int tam, char desc[]);


