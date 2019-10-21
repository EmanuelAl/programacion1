
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int idTrabajo;
    char patente[20];
    int idServicio;
    eFecha fecha;
    int isEmpty;

} eTrabajo;
/** \brief Muestra todos los trabajos cargados
 *
 * \param eTrabajo trabajo[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado
 * \param eServicio servicio[] guarda los servicios
 * \param int tamS tamaño del vector servicio

  */
void listarTrabajos(eTrabajo trabajo[], int tam,eServicio servicio[],int tamS);
/** \brief Muestra todos los trabajos cargados
 *
 * \param eTrabajo trabajo[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado
 * \param eServicio servicio[] guarda los servicios
 * \param int tamS tamaño del vector servicio

  */
void mostrarTrabajos(eTrabajo trabajo[], int tam,eServicio servicio[],int tamS);
/** \brief Funcion que  muestra un Trabajo
 *
 * \param eTrabajo trabajo es el objeto a ser mostrado
 * \param eServicio servicio[] vector necesario para mostrar el servicio que tiene el trabajo
 * \param int tamS  es el tamaño  del vector ingresado
  */
void mostrarTrabajo(eTrabajo trabajo,eServicio servicio[],int tamS);
/** \brief Funcion para dar  de alta  un Trabajo de  tipo eTrabajo
 *
 * \param eTrabajo vec[] vector que será cargado con un objeto de tipo eTrabajo
 * \param int tam tamaño del vector de tipo eTrabajo
 * \param int idTrabajo es el id que se asignará al nuevo objeto de tipo eTrabajo
 * \param eServicio servicios[] vector que guarda los servicios
 * \param int tamS tamaño del vector de tipo eServicio
 * \param eAuto autos[] es el vector que guarda objetos de tipo eAuto
 * \param int tamAuto tamaño del vector de tipo eAuto
 * \param eMarca marca[] vector que guarda las marcas
 * \param int tamMarca tamaño del vector de tipo eMarca
 * \param eColor color[] vector que guarda los colores
 * \param int tamColor tamaño del vector de tipo eColor
 * \param eCliente clientes[] vector que guarda los clientes
 * \param int tamCliente tamaño del vector de tipo eCliente

  * \return 1 si lo pudo dar de alta , 0 sino lo pudo hacer
  *
  */
int altaTrabajo(eTrabajo vec[], int tam,int idTrabajo,eServicio servicios[], int tamS,eAuto autos[],int tamAuto,eMarca marca[],int tamMarca,eColor color[],int tamColor,eCliente clientes[],int tamCliente);
/** \brief Funcion para dar  de baja un Trabajo de manera logica
 *
 * \param eTrabajo vec[] vector que será analizado
 * \param int tam tamaño del vector de tipo eTrabajo
 * \param eServicio servicios[] vector que guarda los servicios
 * \param int tamS tamaño del vector de tipo eServicio
  * \return 1 si lo pudo dar de baja , 0 sino lo pudo hacer
  *
  */
int bajaTrabajo(eTrabajo vec[], int tam,eServicio servicio[],int tamS);
/** \brief Funcion para dar modificar un Trabajo
 *
 * \param eTrabajo vec[] vector que será analizado
 * \param int tam tamaño del vector de tipo eTrabajo
 * \param eServicio servicios[] vector que guarda los servicios
 * \param int tamS tamaño del vector de tipo eServicio
  * \return 1 si lo pudo modificar , 0 sino lo pudo hacer
  *
  */
int modificarTrabajo(eTrabajo vec[], int tam,eServicio servicios[], int tamS);
/** \brief Busca el primer lugar libre del vector
 *
 * \param eTrabajo vec[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado

  * \return -1 si no hay lugar libre, sino devuelve la posicion en el vector que hay  libre
  *
  */

int buscarLibreTrabajo(eTrabajo vec[], int tam);
/** \brief Busca si  el vector tiene al menos una posicion cargada
 *
 * \param eTrabajo vec[] es el vector que va a ser analizado
 * \param int tam es el tamaño  del vector ingresado

  * \return -1 si esta vacio el vector, 1 si encuentra cargado  al menos con uno el vector
  *
  */
int estaCargadoTrabajo(eTrabajo vec[], int tam);
/** \brief Busca el objeto en  el vector  por id
 *
 * \param int idTrabajo es el id del trabajo a ser buscado
 * \param eTrabajo vec[] es el vector en el cual se buscara
 * \param int tam es el tamaño  del vector ingresado

  * \return -1 si no lo encuentra , sino devuelve la posicion en el vector donde se encontro el objeto
  *
  */
int buscarTrabajo(int idTrabajo, eTrabajo vec[], int tam);
/** \brief Funcion para crear un objeto de tipo eTrabajo
 *
 * \param int idTrabajo es el id que se asignará
 * \param char patente[] es la patente que se asignará
 * \param int idServicio referencia al servicio que se realizo en el trabajo
 * \param eFecha fecha  es la fecha del trabajo
 * \return un objeto de tipo eTrabajo
 *
 */

eTrabajo newTrabajo( int idTrabajo,
               char patente[],
               int idServicio,
               eFecha fecha);
/** \brief Busca el objeto en  el vector  por patente
 *
 * \param char patente[] es la patente del trabajo a ser buscada
 * \param eTrabajo vec[] es el vector en el cual se buscara
 * \param int tam es el tamaño  del vector ingresado

  * \return -1 si no lo encuentra , sino devuelve la posicion en el vector donde se encontro el objeto
  *
  */
int buscarTrabajoPatente(char patente[], eTrabajo vec[], int tam);
/** \brief Funcion para inicializar al campo isEmpty con 1,en todos  los elementos del vector
 *
 * \param eTrabajo vec[] es el vector que va a ser inicializado
 * \param int tam es el tamaño  del vector ingresado
 *
 */
void inicializarTrabajo(eTrabajo vec[], int tam);
/** \brief Funcion que calcula el importe a pagar
 *
 * \param eTrabajo vec[] vector que será analizado
 * \param int tam tamaño del vector de tipo eTrabajo
 * \param eServicio servicios[] vector que guarda los servicios
 * \param int tamS tamaño del vector de tipo eServicio
 * \param eAuto autos[] es el vector que guarda objetos de tipo eAuto
 * \param int tamAuto tamaño del vector de tipo eAuto
 * \param eCliente clientes[] vector que guarda los clientes
 * \param int tamCliente tamaño del vector de tipo eCliente

  * \return 1 si lo pudo dar de alta , 0 sino lo pudo hacer
  *
  */
void  mostrarImporteTotal(eTrabajo vec[], int tam,eServicio servicios[], int tamS,eAuto autos[],int tamAuto,eCliente clientes[],int tamCliente);
