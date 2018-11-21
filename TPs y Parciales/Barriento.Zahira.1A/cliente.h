#ifndef CLIENTE_INCLUDE_H
#define CLIENTE_INCLUDE_H
#include "juego.h"

/**
 * Estructura de los clientes
 */
typedef struct
{
    int idCliente;
    char apellido[51];
    char nombre[51];
    char sexo;
    char domicilio[51];
    int isEmpty;
} eCliente;

/**
 *	Menu de clientes
 */

int menuClientes(eCliente cliente[], int len);

/** \brief Para indicar que todas las posiciones en la matriz están vacías,
  * esta función puso la bandera (isEmpty) en 0
  * posición de la matriz
  * \param list eCliente * Puntero a matriz de clientes
  * \param len int Longitud de la matriz
  * \return --------
  *
  */
void inicializarCliente(eCliente* list, int len);

/** \brief busca un espacio libre en la matriz
 *
 * \param list Array de la estructura eCliente
 * \param len tamaño del array
 * \return el espacio libre o -1 si no hay espacio
 *
 */
int buscarEspacioLibreCliente(eCliente list[], int len);

/** \brief agrega un clientes en la primera posición vacía
  * \param lista cliente
  * \param len int
  * \return int Retorno (-1) si hay error - (0) si Ok
  */
int agregarCliente(eCliente list[], int len);

/** \brief find a cliente by Id en devuelve la posición del índice en la matriz.
* * \param list cliente
* * \param len int
  * \return Devuelva la posición del índice del empleado o (-1)
  */
int buscarClientePorID(eCliente list[], int len, int idCliente);

/** \brief modifica un cliente ya ingresado
 *
 * \param list cliente
 * \param len int
 * \return inr Retorno (-1) si hay error - (0) si Ok
 *
 */
int modificarCliente(eCliente* list, int len);

/** \brief imprimir un solo cliente *
  * \param list eCliente*
  * \param longitud int
  * \return int * */
void mostrarCliente(eCliente list);

/** \brief imprimir el contenido de la matriz de clientes *
  * \param list eCliente *
  * \param longitud int
  * \return int * */
void mostrarClientes(eCliente* list, int len);

/** \brief Eliminar un cliento por ID*
  * \param list eCliente *
  * \param len int
  * \return int Devuelva (-1) si Error - (0) si está bien * */
int borrarCliente(eCliente list[], int len);

/** \brief Ordena los elementos en la matriz de clientes*
  * \ param list eCliente *
  * \ param len int
  * \ return int Retorno (-1) si Error - (0) si está bien * */
int ordenarCliente(eCliente* list, int len);

/**
 *	Harcodeo de clientes
 */

void harcodearCliente(eCliente y[]);


#endif // CLIENTE_INCLUDE_H
