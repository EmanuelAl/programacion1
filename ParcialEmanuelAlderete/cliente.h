
#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct{
    int idCliente;
    char nombre[20];
    char localidad[25];
    int isEmpty;
}eCliente;
#endif
/** \brief funcion para cargar el vector ingresado
 *
 * \param eCliente vec[] vector a ser cargado
 * \param int tam es el tamaño del vector a ser cargado
 * \param int cantidad la cantidad que cargaremos al vector
 * \return 0 si no cargo el vector, sino devuelve la cantidad cargada
 *
  */
int hardcodearClientes( eCliente vec[], int tam, int cantidad);
/** \brief Muestra todos los clientes cargados
 *
 * \param eCliente clientes[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado

  */
void listarClientes( eCliente clientes[], int tam);
/** \brief Muestra todos los clientes cargados
 *
 * \param eCliente clientes[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado

  */
void mostrarClientes(eCliente clientes[], int tam);
/** \brief Funcion que  muestra un Cliente
 *
 * \param eCliente cliente es el objeto a ser mostrado

  */
void mostrarCliente(eCliente cliente);
/** \brief Funcion que carga un parametro con el nombre del cliente
 *
 * \param int id es el id del cliente que se buscara en el vector en cuestión
 * \param eCliente vec[] vestor que será recorrido
 * \param int tam es el tamaño del vector a ser recorrido
 * \param  char desc[] parametro que terminará siendo cargado con el nombre del cliente
 * \return 1 si se cargó la descripción, 0 si no se pudo realizar la carga
 *
  */
int cargarDescCliente(int id, eCliente vec[], int tam, char desc[]);
/** \brief Muestra las localidades que hay en el vector estructura
 *
 * \param eCliente clientes[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado

  */
void mostrarClientesLocalidad(eCliente clientes[], int tam);
/** \brief Funcion que  muestra solo la localidad del cliente ingresado
 *
 * \param eCliente cliente es el objeto a ser mostrado

  */
void mostrarClienteLocalidad(eCliente cliente);
/** \brief Funcion para inicializar al campo isEmpty con 1,en todos  los elementos del vector
 *
 * \param eCliente vec[] es el vector que va a ser inicializado
 * \param int tam es el tamaño  del vector ingresado
 *
 */
void inicializarCliente(eCliente vec[], int tam);
/** \brief Busca el primer lugar libre del vector
 *
 * \param eCliente vec[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado

  * \return -1 si no hay lugar libre, sino devuelve la posicion en el vector que hay  libre
  *
  */
int buscarLibreCliente(eCliente vec[], int tam);
/** \brief Funcion para crear un objeto de tipo ecliente
 *
 * \param int idCliente es el id que se asignará
 * \param char nombre[] es el nombre del titular que se asignará
 * \param char localidad[] es la localidad del titular
 * \return un objeto de tipo eCliente
 *
 */

eCliente newCliente(int idCliente, char nombre[],char localidad[]);
/** \brief Funcion para dar de alta a un nuevo cliente.
 *
 * \param int idCliente es el id que se asignará
 * \param eCliente vec[] vector que contiene los clientes
 * \param int tam el tamaño del vector
* \return 1 si lo pudo dar de alta , 0 si no lo pudo hacer
 *
 */

int altaCliente( int idCliente,eCliente vec[], int tam);
