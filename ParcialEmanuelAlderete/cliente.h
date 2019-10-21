
#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct{
    int idCliente;
    char nombre[20];
    char localidad[25];
}eCliente;
#endif
/** \brief funcion para cargar el vector ingresado
 *
 * \param eCliente vec[] vector a ser cargado
 * \param int tam es el tama�o del vector a ser cargado
 * \param int cantidad la cantidad que cargaremos al vector
 * \return 0 si no cargo el vector, sino devuelve la cantidad cargada
 *
  */
int hardcodearClientes( eCliente vec[], int tam, int cantidad);
/** \brief Muestra todos los clientes cargados
 *
 * \param eCliente clientes[] es el vector que va a ser analizado
 * \param int tam es el tama�o  del vector ingresado

  */
void listarClientes( eCliente clientes[], int tam);
/** \brief Muestra todos los clientes cargados
 *
 * \param eCliente clientes[] es el vector que va a ser analizado
 * \param int tam es el tama�o  del vector ingresado

  */
void mostrarClientes(eCliente clientes[], int tam);
/** \brief Funcion que  muestra un Cliente
 *
 * \param eCliente cliente es el objeto a ser mostrado

  */
void mostrarCliente(eCliente cliente);
/** \brief Funcion que carga un parametro con el nombre del cliente
 *
 * \param int id es el id del cliente que se buscara en el vector en cuesti�n
 * \param eCliente vec[] vestor que ser� recorrido
 * \param int tam es el tama�o del vector a ser recorrido
 * \param  char desc[] parametro que terminar� siendo cargado con el nombre del cliente
 * \return 1 si se carg� la descripci�n, 0 si no se pudo realizar la carga
 *
  */
int cargarDescCliente(int id, eCliente vec[], int tam, char desc[]);
/** \brief Muestra las localidades que hay en el vector estructura
 *
 * \param eCliente clientes[] es el vector que va a ser analizado
 * \param int tam es el tama�o  del vector ingresado

  */
void mostrarClientesLocalidad(eCliente clientes[], int tam);
/** \brief Funcion que  muestra solo la localidad del cliente ingresado
 *
 * \param eCliente cliente es el objeto a ser mostrado

  */
void mostrarClienteLocalidad(eCliente cliente);

