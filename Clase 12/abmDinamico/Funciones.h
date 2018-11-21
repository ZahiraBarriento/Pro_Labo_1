#ifndef FUNCIONES_INCLUDE_H
#define FUNCIONES_INCLUDE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];
} eSector;

typedef struct
{
    int id;
    char descripcion[20];
} eComida;

typedef struct
{
    int id;
    int idComida;
    int idEmpleado;
} eAlmuerzo;


void inicializarEmpleados( eEmpleado x[], int tam);
int buscarLibre( eEmpleado x[], int tam);
int buscarEmpleado(eEmpleado x[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector);
void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector);
void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);
void eliminarEmpleado(eEmpleado *empleados, int tam, eSector sectores[], int tamSector);
void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);
int elegirSector(eSector sectores[], int tam);
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);
void listarEmpleadosPorSector(eEmpleado x[], int len, eSector sectores[], int lenSector);
int menu();
void harcodeoEmpeados(eEmpleado x[]);
void cargarDescripcionComida(eComida comidas[], int tamComida, int idComida, char cadena[]);

#endif // FUNCIONES_INCLUDE_H

