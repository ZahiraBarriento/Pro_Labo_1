#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define ELEMENTS 3

int main()
{
    eEmployee employee[ELEMENTS];
    char seguir='s';
    char name[20];
    char lastName[20];
    int sector;
    float salary;
    int id;
    int flag=0;

    initEmployees(employee,ELEMENTS);

    do
    {
        switch(menu())
        {
        case 1: //Altas de empleados
            addEmployee(employee,ELEMENTS, id, name, lastName, salary, sector);
            flag=1;
            system("pause");
            break;
        case 2://Modificar empleados
            if (flag==1)
            {
                system("cls");
                modifyEmployee(employee, ELEMENTS, id);
            }
            else
            {
                printf("No ha ingresado ningun empleado");
            }
            break;
        case 3://Baja de empleados
            if(flag==1)
            {
                removeEmployee(employee,ELEMENTS, employee[ELEMENTS].id);
            }
            break;
        case 4:
            sortEmployees(employee, ELEMENTS, 0);
            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Wrong option!");
        }
    }
    while(seguir=='s');

    return 0;
}


