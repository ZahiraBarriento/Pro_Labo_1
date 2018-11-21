#ifndef ALQUILERES_INCLUDE_H
#define ALQUILERES_INCLUDE_H
#include "juego.h"
#include "cliente.h"

/**
 * Estructura de fecha
 */
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

/**
 * Estructura de alquileres
 */
typedef struct
{
    int idAlquileres;
    int idJuegos;
    int idCliente;
    eFecha fecha;
    int isEmpty;
} eAlquileres;

/** \brief Para indicar que todas las posiciones en la matriz están vacías,
  * esta función puso la bandera (isEmpty) en 0
  * posición de la matriz
  * \param list eAlquileres * Puntero a matriz de clientes
  * \param len int Longitud de la matriz
  * \return --------
  *
  */
void inicializarAlquileres(eAlquileres* list, int len);

/** \brief busca un espacio libre en la matriz
 *
 * \param list Array de la estructura eAlquileres
 * \param len tamaño del array
 * \return el espacio libre o -1 si no hay espacio
 *
 */
int buscarEspacioLibreAlquileres(eAlquileres list[], int len);

/** \brief agrega un juego en la primera posición vacía
  * \param lista eAquileres
  * \param len int
  * \param lista eCliente
  * \param len int
  * \param lista eJuegos
  * \param len int
  * \return int Retorno (-1) si hay error - (0) si Ok
  */
int agregarAlquiler(eAlquileres* alquiler, int lenAlquiler, eCliente cliente[], int lenCliente, eJuegos juegos[], int lenJuegos);
/** \brief Elige un cliente ya ingresado para poder relacionarlo con alquileres
 *
 * \param lista eClientes
 * \param int len
 * \return int Retorno (-1) si hay error - (0) si Ok
 *
 */

int elegirCliente(eCliente clientes[], int len);

/** \brief Elige un juego ya ingresado para poder relacionarlo con alquileres
 *
 * \param lista eJuegos
 * \param int len
 * \return int Retorno (-1) si hay error - (0) si Ok
 *
 */

void hardcodearAlquileres(eAlquileres x[]);

int elegirJuegos(eJuegos juegos[], int len);

void cargarDescripcionJuego(eJuegos juego[], int lenJuego, int idJuego, char cadena[]);

int mostrarAlquiler(eAlquileres alquiler, int lenAlqui, eJuegos* juegos, int lenJueg, eCliente* cliente, int lenClien);

void cargarCliente(eCliente cliente[], int lenCli, int idCliente, char apellido[]);

int mostrarAlquileres(eAlquileres* alquiler, int lenAl, eJuegos* juegos, int lenJue, eCliente* cliente, int lenCli);

int mostrarClienteListar(eAlquileres alquiler, int lenAlqui, eJuegos* juegos, int lenJueg, eCliente* cliente, int lenClien);

#endif // ALQUILERES_INCLUDE_H
