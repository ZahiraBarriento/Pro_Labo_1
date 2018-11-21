#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "almuerzo.h"
#include "employee.h"
#include "menu.h"

static int generarNextId()
{
    static int idAlmuerzo = 0;
    idAlmuerzo ++;
    return idAlmuerzo;
}

int initAlmuerzo(eAlmuerzo* list, int len)
{
    int i;
    int retorno=0;

    if(list==NULL)
    {
        if(len<=0)
        {
            retorno = -1;
        }
    }
    for(i=0; i<len; i++)
    {
        list[i].isEmpty = 1;
    }

    return retorno;
}

int altaAlmuerzo(eEmployee arrayEmpleados[], eSector arraySectores[], eMenu arrayMenues[], eAlmuerzo arrayAlmuerzos[], int EMPLEADOS_CANT, int SECTORES_CANT, int MENU_CANT, int ALMUERZO_CANT)
{
    int status, check;
    int maximum;

    for(int i=0; i<ALMUERZO_CANT; i++)
    {
        if(arrayAlmuerzos[i].isEmpty == 1)
        {

            do{
            system("cls");
            check = getValidInt(&arrayAlmuerzos[i].fecha.dia, "Ingrese Dia del almuerzo: (1-31): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 31, 3);
            }while(check!=1);

            do{
            system("cls");
            check = getInt(&arrayAlmuerzos[i].fecha.mes, "Ingrese Mes del almuerzo: (1-12): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, 12, 3);
            }while(check!=1);

            do{
            system("cls");
            check = getInt(&arrayAlmuerzos[i].fecha.anio, "Ingrese Anio del almuerzo: (1960-2018): ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1960, 2018, 3);
            }while(check!=1);


            do{
            maximum = printEmployees(arrayEmpleados, EMPLEADOS_CANT, arraySectores);
            system("cls");
            check = getInt(&arrayAlmuerzos[i].legajoEmpleado, "Ingrese Legajo de empleado: ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, maximum, 3);
            }while(check!=1);

            do{
            maximum = printEmployees(arrayMenues, MENU_CANT);
            system("cls");
            check = getInt(&arrayAlmuerzos[i].legajoEmpleado, "Ingrese Codigo de Menu: ", "[ERROR] NO EN EL RANGO ESTABLECIDO\n", 1, maximum, 3);
            }while(check!=1);

            arrayAlmuerzos[i].isEmpty = 0;

            printf("INFORMACION INGRESADA\n");
            printf("ID: %d  Fecha de almuerzo %d/%d/%d  Nombre Empleado: %s %s Menu Elegido: %s\n", arrayAlmuerzos[i].codigoAlmuerzo, arrayAlmuerzos[i].fecha.dia, arrayAlmuerzos[i].fecha.mes, arrayAlmuerzos[i].fecha.anio, arrayEmpleados[(arrayAlmuerzos[i].legajoEmpleado)-1].apellido, arrayEmpleados[(arrayAlmuerzos[i].legajoEmpleado)-1].nombre, arrayMenues[arrayAlmuerzos[i].codigoMenu].descripcion);
            system("pause");
            status = 0;
            break;
        }else{
            status = -1;
        }
    }

    return status;
}
