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

    printf("Ingrese legajo: ");
    scanf("%d",&unEmpleado.legajo);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(unEmpleado.nombre);

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c",&unEmpleado.sexo);

    printf("Ingrese sueldo: ");
    scanf("%f",&unEmpleado.sueldo);

    mostrarEmpleado(unEmpleado);

    return 0;
}

void mostrarEmpleado(eEmpleado employee)
{

    printf("%d   %s   %c   %.2f\n\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);

}
