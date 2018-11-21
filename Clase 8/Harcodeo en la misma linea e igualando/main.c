#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
} eEmpleado;

void mostrarEmpleado(eEmpleado employee);

int main()
{


    eEmpleado unEmpleado;
    eEmpleado otroEmpleado;
    eEmpleado emp3 = {2222, "Jose", 'm', 20000};
    eEmpleado emp4;

    emp4 = emp3;


    unEmpleado.legajo = 1234;
    strcpy(unEmpleado.nombre,"Juan");
    unEmpleado.sexo = 'm';
    unEmpleado.sueldo = 10000.5;

    otroEmpleado.legajo = 1122;
    strcpy(otroEmpleado.nombre,"Lucia");
    otroEmpleado.sexo = 'f';
    otroEmpleado.sueldo = 15000.75;

    mostrarEmpleado(unEmpleado);

    mostrarEmpleado(otroEmpleado);

    mostrarEmpleado(emp3);

    mostrarEmpleado(emp4);


    return 0;
}

void mostrarEmpleado(eEmpleado employee)
{

    printf("%d   %s   %c   %.2f\n\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);

}



