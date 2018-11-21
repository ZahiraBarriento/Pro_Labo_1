#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct eEmpleado ///la "e" viene de estructura
{
    int legajo;
    char nombre [25];        DECLARANDO UN ESTRUCTURA QUE TIENE EL NOMBRE eEmpleado
    char sexo;
    float sueldo;
};///se tiene que terminar con ;*/

typedef struct
{
    int legajo;
    char nombre [25];    ///DECLARAR UN NUEVO TIPO DE DATO ENTRA LA LLAVE DE Y EL ; PONGO EL NOMBRE
    char sexo;
    float sueldo;
} eEmpleado;

void mostrarEmpleado(eEmpleado employes);///se pone abajo porque primero tengo que definir la estrctura

int main()
{
    //struct empleado unEmpleado; Tengo que declarar la extrustura y luego la variable PRIMERA OPCION

    eEmpleado unEmpleado; //Otro empleado con esa estructura no hace falta aclarar SEGUNDA OPCION
    eEmpleado otroEmpleado;
    eEmpleado emp3 = {2222,"Jose", 'm', 20000};//solo puedo hacerlo en la linea de declaracion(inicializado por extension)
    eEmpleado emp4;

    emp4 = emp3;

    unEmpleado.legajo=1234; //con el operador "." accedo a las variables de la ficha
    strcpy(unEmpleado.nombre, "Juan"); //para pasar el nombre a la variable nombre
    unEmpleado.sexo= 'm';
    unEmpleado.sueldo=10000.5;

    //Cargamos otro emplado de la misma manera pero cambiando los datos

    otroEmpleado.legajo=1122;
    strcpy(otroEmpleado.nombre, "Lucia");
    otroEmpleado.sexo= 'f';
    otroEmpleado.sueldo=15000.75;

    mostrarEmpleado(unEmpleado);
    mostrarEmpleado(otroEmpleado);
    mostrarEmpleado(emp3);
    mostrarEmpleado(emp4);

    return 0;
}
///FUNCION DE MOSTRAR EMPLEADO
void mostrarEmpleado(eEmpleado employee)
{
    printf("%d  %s  %c  %.2f\n\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);
}

