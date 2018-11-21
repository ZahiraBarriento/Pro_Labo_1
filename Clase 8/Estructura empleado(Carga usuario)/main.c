#include <stdio.h>
#include <stdlib.h>
#define TAM 3

///CARGA USURIA Y SE ORDENA LA LISTA

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
    eEmpleado empleados[TAM];

    for(int i=0; i<TAM; i++)
    {
        printf("Ingrese legajo:");
        scanf("%d",&empleados[i].legajo);

        printf("Ingrese nombre:");
        fflush(stdin);
        gets(empleados[i].nombre);

        printf("Ingrese sexo:");
        fflush(stdin);
        scanf("%c",&empleados[i].sexo);

        printf("Ingrese sueldo:");
        scanf("%f",&empleados[i].sueldo);
    }

    mostrarEmpleados(empleados, TAM);

    return 0;
}

void mostrarEmpleado(eEmpleado employee)
{
    printf("%d  %s  %c  %.2f\n\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);
}

void mostrarEmpleados(eEmpleado lista[], int tam)
{
    for (int i=0; i<tam; i++)
    {
        mostrarEmpleado(lista[i]);
    }
}

