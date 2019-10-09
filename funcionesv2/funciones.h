/** \brief solicita un numero por consola y lo devuelve
 *
 * \param pResultado: Puntero a variable donde se escribirá el valor ingresado en el caso de ser
correcto.
 * \param mensaje: Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al
usuario datos por consola.
 * \param mensajeError: Puntero a cadena de caracteres con mensaje de error en el caso de que
el dato ingresado no sea válido.
 * \param minimo: Valor mínimo admitido (inclusive)
 * \param maximo: Valor máximo admitido (inclusive)
 * \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato
en caso de error.
 * \return (-1) si se quedo sin intentos - (0) si pudo  cargar el dato solitado en la variable
 *
 */

int getNumero(int* pResultado,char* mensaje,
              char* mensajeError,
              int minimo,
              int maximo,
              int reintentos);
/** \brief
*
* \param char* cadena Puntero a cadena a hacer analizada
* \return -1 si no es numerica , 0 si es numerica
 */
 int esNumerica(char* cadena);
 /** \brief valida dato ingresado
  *
  * \param int* pResultado Puntero a la variable donde se escribirá el valor ingresado en el caso de ser
correcto.
  * \return (0) si pudo  cargar el dato solitado en la variable,  -1 si no pudo
  *
  */

 int getInt(int* pResultado);

 /** \brief Solicita un numero al usuario y devuelve el resultado
 *
 * \param mensaje Es el mensaje que será mostrado al usuario
 * \return Es el numero ingresado por el usuario.
 */
int getInt (char mensaje[]);


/** \brief Solicita un numero al usuario y devuelve el resultado
 *
 * \param mensaje Es el mensaje que será mostrado al usuario
 * \return Es el numero ingresado por el usuario.
 */
float getFloat (char mensaje[]);


/** \brief Solicita un caracter al usuario y devuelve el resultado
 *
 * \param mensaje Es el mensaje que será mostrado al usuario
 * \return Es el caracter ingresado por el usuario.
 */
char getChar(char mensaje[]);


/** \brief Verifica si el valor recibido es numerico.
 *
 * \param str Array con la cadena que va a ser analizada.
 * \return 1 si es numero // 0 si no es numero.
 */
int esNumerico (char str[]);



/** \brief Verifica si el valor recibido contiene solamente numeros, + y -.
 *
 * \param str Array con la cadena que va a ser analizada.
 * \return 1 si es numero, con espacios y guion // 0 si no es numero.
 */
int esTelefono (char str[]);


/** \brief Verifica si el valor recibido contiene solamente letras.
 *
 * \param str Array con la cadena que va a ser analizada.
 * \return 1 si contiene solo espacios y letras // 0 si contiene numero, etc.
 */
int esSoloLetras (char str[]);


/** \brief Verifica si el valor recibido contiene solo letras y numeros.
 *
 * \param str Array con la cadena que va a ser analizada.
 * \return 1 si contiene solo espacio o letras y numeros // 0 si no.
 */
int esAlfaNumerico (char str[]);


/** \brief Solicita un texto al usuario.
 *
 * \param mensaje Es el mensaje a ser mostrado.
 * \param input Array donde se cargara el texto ingresado.
 * \return void.
 */
void getString(char mensaje[], char input[]);


/** \brief Solicita un texto al usuario y lo devuelve.
 *
 * \param mensaje Es el mensaje a ser mostrado.
 * \param input Array donde se cargará el texto ingresado.
 * \return 1 si el texto contiene SOLO letras.
 */
int getStringLetras(char mensaje[], char input[]);


/** \brief Solicita un texto numerico al usuario y lo devuelve
 *
 * \param mensaje Es el mensaje a ser mostrado.
 * \param input Array donde se cargara el texto ingresado.
 * \return 1 si el texto contiene SOLO numeros.
 */
int getStringNumeros(char mensaje[], char input[]);


/**
 * \brief Solicita un texto Alfa numérico al usuario y lo devuelve.
 * \param char* Es el mensaje a ser mostrado.
 * \param char* puntero donde se cargará el texto ingresado.
 * \return 1 si el texto contiene solo números enteros o letras.
 */
 int getAlfaNumerico(char mensaje[], char input[]);


/** \brief  Funcion usada para verificar el ingreso de caracteres.Chequea para que
 solo sean admitidas las letras S o N.
 * \param Se ingresa void
 * \return devuelve un entero sin signo:0 si se ingreso la N y  1 si se ingreso la S
 *
 */

unsigned int verifica(void);
