/** \brief Solicita un numero - devuelve el resultado
 *
 * \param mensaje - EL mensaje que será mostrado al usuario
 * \return Es el numero ingresado.
 */
int getInt (char mensaje[]);



/** \brief Solicita un numero - devuelve el resultado
 *
 * \param mensaje - El mensaje que será mostrado al usuario
 * \return Es el numero ingresado.
 */
float getFloat (char mensaje[]);



/** \brief Solicita un caracter - devuelve el resultado
 *
 * \param mensaje - El mensaje que será mostrado al usuario
 * \return Es el caracter ingresado.
 */
char getChar(char mensaje[]);


/** \brief Verifica si el valor ingresado es numerico.
 *
 * \param str Array con la cadena que sera analizada.
 * \return 1 si es numero - 0 si no lo es .
 */
int esNumerico (char str[]);


/** \brief Verifica si el valor ingresado contiene solamente letras.
 *
 * \param str Array con la cadena que sera analizada.
 * \return 1 si contiene solo espacios y letras - 0 si contiene numero, etc.
 */
int esSoloLetras(char str[]);



/** \brief Verifica si el valor ingresado contiene solo letras y numeros.
 *
 * \param str Array con la cadena que sera analizada.
 * \return 1 si contiene solo espacio o letras y numeros - 0 si no.
 */
int isAlphaNumeric (char str[]);

/** \brief concatena dos cadenas de caracteres
 *
 * \param char destino[] donde se guardara la concadenación
 * \param char str1[] primer cadena
 * \param char str2[]  segunda cadena
 * \return (void)
 *
 */

void  concatenar(char destino[],char str1[],char str2[]);
/** \brief Funcion para validar que solo se ingrese s/n o S/N
 *
 * \return char letra validada
 *
 */

char validar();
