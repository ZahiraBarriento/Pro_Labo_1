#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre [20];
    char sexo;
    float sueldo;        ///Estos datos estan relacionados con la estructura porque eso se hace 2 estrcuturas
    eFecha fechaIngreso; ///a esto se le llama anidada, es una estructura adentro de la otra
                         ///la estructura que se pone adentro tienen que ser declarada antes
}eEmpleado;

void mostrarEmpleado(eEmpleado employes);

int main()
{
    eEmpleado unEmpleado;
    eEmpleado otroEmpleado={1234, "Analia", 'f', 30000, {17, 9, 2018}};

    unEmpleado.legajo=1234;
    strcpy(unEmpleado.nombre, "Juan");
    unEmpleado.sexo= 'm';
    unEmpleado.sueldo=10000.5;
    unEmpleado.fechaIngreso.dia=17;
    unEmpleado.fechaIngreso.mes=9;
    unEmpleado.fechaIngreso.anio=2018;

    mostrarEmpleado(unEmpleado);
    mostrarEmpleado(otroEmpleado);
}

void mostrarEmpleado(eEmpleado employee)
{
     printf("%d  %s  %c  %.2f  %02d/%02d/%4d\n\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo, employee.fechaIngreso.dia, employee.fechaIngreso.mes, employee.fechaIngreso.anio);
}

