#include <stdio.h>
#include <stdlib.h>

#define TAM 3

typedef struct
{
    int legajo;
    char nombre [20];
    char sexo;
    float sueldo;

}eEmpleado;

void mostrarEmpleado(eEmpleado employes);
void mostrarEmpleados(eEmpleado listar[], int tam);

int main()
{
    eEmpleado empleados[]={
    {1234, "Juan", 'm', 123000},
    {2321, "Luisa", 'f', 14700},
    {2122, "Ariel", 'm', 113000}
    };

    mostrarEmpleados(empleados, TAM);

    return 0;
}

void mostrarEmpleado(eEmpleado employee)
{
    printf("%d  %s  %c  %.2f\n\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);
}

void mostrarEmpleados(eEmpleado lista[], int tam)
{
    system("cls");
    printf("Legajo\tNombre\tSexo\tSueldo");
    for (int i=0; i<tam; i++)
    {
        mostrarEmpleado(lista[i]);
    }
}
