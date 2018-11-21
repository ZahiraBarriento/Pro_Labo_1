#ifndef JUEGOS_INCLUDE_H
#define JUEGOS_INCLUDE_H

/**
 * Estructura de los juegos
 */
typedef struct
{
    int idJuegos;
    char descripcion[51];
    float importe;
    int isEmpty;
} eJuegos;

/** \brief Para indicar que todas las posiciones en la matriz están vacías,
  * esta función puso la bandera (isEmpty) en 0
  * posición de la matriz
  * \param list eJuegos * Puntero a matriz de clientes
  * \param len int Longitud de la matriz
  * \return --------
  *
  */
void inicializarJuego(eJuegos* list, int len);

/** \brief busca un espacio libre en la matriz
 *
 * \param list Array de la estructura eJuegos
 * \param len tamaño del array
 * \return el espacio libre o -1 si no hay espacio
 *
 */
int buscarEspacioLibreJuego(eJuegos list[], int len);

/** \brief agrega un juego en la primera posición vacía
  * \param lista eJuegos
  * \param len int
  * \return int Retorno (-1) si hay error - (0) si Ok
  */
int agregarJuego(eJuegos list[], int len);

/**
 *	Menu de juegos
 */
int menuJuegos(eJuegos juegos[], int len);

/** \brief imprimir un solo juego *
  * \param list eJuego*
  * \param longitud int
  * \return ------- * */
void mostrarJuego(eJuegos list);

/** \brief imprimir el contenido de la matriz de juegos *
  * \param list eJuego *
  * \param longitud int
  * \return int * */
void mostrarJuegos(eJuegos list[], int len);

/** \brief find a juego by Id en devuelve la posición del índice en la matriz.
* * \param list eJuegos
* * \param len int
  * \return Devuelva la posición del índice del empleado o (-1)
  */
int buscarJuegoPorID(eJuegos list[], int len, int idJuego);

/** \brief modifica un juego ya ingresado
 *
 * \param list juego
 * \param len int
 * \return inr Retorno (-1) si hay error - (0) si Ok
 *
 */
int mofidificarJuego(eJuegos list[], int len);

/** \brief Eliminar un juego por ID*
  * \param list eJuego *
  * \param len int
  * \return int Devuelva (-1) si Error - (0) si está bien * */
int borrarJuego(eJuegos list[], int len);

/** \brief Ordena los elementos en la matriz de juegos*
  * \ param list eJuegos *
  * \ param len int
  * \ return int Retorno (-1) si Error - (0) si está bien * */
int ordenarJuego(eJuegos* list, int len);

void hardcodearJuegos(eJuegos x[]);

#endif // JUEGOS_INCLUDE_H
