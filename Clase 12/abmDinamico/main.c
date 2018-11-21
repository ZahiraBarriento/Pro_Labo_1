#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Funciones.h"

int main()
{

    char seguir = 's';
    eEmpleado lista[10];
    eSector sectores[] =
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };

    eComida comida[]=
    {
        {1, "Milanesa"},
        {2, "Fideos"},
        {3, "Pizzas"},
        {4, "Sopa"},
        {5, "Pescadso"}
    };

    eAlmuerzo almuerzo[]=
    {
        {100, 1111, 2},
        {101, 5555, 1},
        {102, 4545, 1},
        {103, 3232, 4},
        {104, 1111, 1},
        {105, 5555, 5},
        {106, 4545, 2},
        {107, 3232, 5},
        {108, 1111, 2},
        {109, 4545, 1},
        {110, 3232, 1},
        {111, 1111, 4},
        {112, 5555, 3},
        {113, 4545, 5},
        {114, 3232, 2},
        {115, 5555, 5},
        {116, 4545, 2},
        {117, 3232, 2},
        {118, 1111, 2},
        {119, 5555, 1},
        {120, 4545, 3}
    };

    inicializarEmpleados(lista, 10);


    do
    {
        switch(menu())
        {

        case 1:
            agregarEmpleado(lista, 10, sectores, 5);
            harcodeoEmpeados(lista);
            system("pause");
            break;
        case 2:
            eliminarEmpleado(lista, 10, sectores, 5);
            break;
        case 3:
            modificarEmpleado(lista, 10, sectores, 5);
            break;
        case 4:
            mostrarEmpleados(lista, 10, sectores, 5);
            system("pause");
            break;
        case 5:
            listarEmpleadosPorSector(lista, 10, sectores,5);
            break;
        case 6:
            ordenarPorSector(lista,10,sectores,5);
            break;
        case 7:

            break;
        case 8:
            mostrarAlmuerzos();
            break;
        case 10:
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');



    return 0;
}
