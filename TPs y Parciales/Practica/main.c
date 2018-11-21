#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "menu.h"
#include "almuerzo.h"
#define ELEMENTS_EMPLOYEE 100
#define ELEMENTS_SECTORES 5
#define ELEMENTS_MENUES 20
#define ELEMENTS_ALMUERZO 1000

int main()
{
    int opcion;
    eEmployee employee[ELEMENTS_EMPLOYEE];
    eSector sectores[ELEMENTS_SECTORES];
    eMenu menu[ELEMENTS_MENUES];
    eAlmuerzo almuerzo[ELEMENTS_ALMUERZO];

    initEmployees(employee, ELEMENTS_EMPLOYEE);
    initSectores(sectores);
    initAlmuerzo(almuerzo, ELEMENTS_ALMUERZO);
    initMenu(menu, ELEMENTS_MENUES);

    do
    {
        system("cls");
        printf("\n  >>> ABM ALMUERZOS <<<");
        printf("\n\n MENU DE OPCIONES");
        printf("\n\n 1- Menues\n");
        printf(" 2- Empleados\n");
        printf(" 3- Almuerzo\n\n");
        printf(" 4- Salir\n\n");
        printf(" Selecione una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:///MENUES
                menuMenues();
            break;

        case 2:
            menuEmployee(employee, ELEMENTS_EMPLOYEE, sectores, ELEMENTS_SECTORES);
            break;
        case 3:
                menuAlmuerzo(employee, menu, almuerzo, ELEMENTS_EMPLOYEE, ELEMENTS_MENUES, ELEMENTS_ALMUERZO);
                break;
        case 4:
                printf("Saliendo...");
                break;
        default:
                printf("Opcion incorrecta");
                break;
        }
    }
    while(opcion!=3);
}
