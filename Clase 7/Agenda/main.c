#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "utn.h"
#define TAM 200

typedef struct
{
    char nombre [20];
    char apellido [20];
    int legajo;

} eEmpleado;

void inicializarArray(int array[], int cantidad, int valor);
 int buscarOcurrencia(int array[], int cantidad, int valor);

int main()
{

    int opcion;
    int lugarLibre;
    eEmpleado empleados[TAM];

    do
    {
        opcion=getInt(" >>> Agenda <<<\n  \n1. Altas\n  \n2. Bajas\n  \n3. Modificaciones\n  \n4. Listado ordenado por apellido\n");

       switch(opcion)
        {
        case 1:

            for(int i=0; i<TAM; i++)
            {
                printf("Ingrese nombre:");
                fflush(stdin);
                gets(empleados[i].nombre);

                printf("Ingrese apellido:");
                fflush(stdin);
                gets(empleados[i].apellido);

                printf("Ingrese legajo:");
                scanf("%d",&empleados[i].legajo);
            }
            break;

        case 2:


        }
    }while(opcion!=6);
}

/** \brief Inicializa un array de enteros con el valor recibido
 *
 * \param array Es el array a ser inicializado
 * \param cantidad Indica el largo del array
 * \param valor Es el valor que sera cargado en casa posicion
 * \return -
 *
 */

void inicializarArray(int array[], int cantidad, int valor)
{
    int i;

    for(i=0; i<cantidad; i++)//Para recorrer todo el array y coloca un -1 donde hay una posicion libre
    {
        array[i]=valor;
    }
}

/** \brief Busca la primera ocurrencia de un valor en un array de enteros
 *
 * \param array Es el array en el cual buscar
 * \param cantidad Indica el largo del array
 * \param valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay (1)
 *
 */
 //Hago una funcion para buscar ocurrencia para encontrar un -1 y saber que
 //hay un lugar libre

 int buscarOcurrencia(int array[], int cantidad, int valor)
 {
     int i;

     for(i=0; i<cantidad; i++)
     {
         if(array[i]==valor)
         {
             return 1;
         }
     }

     return -1;
 }

 ///El -1 indica tanto como el nombre, apellido, legajo se encuentran libres
