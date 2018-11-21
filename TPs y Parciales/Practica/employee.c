#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "employee.h"
#include "utn.h"
#include "almuerzo.h"
#include "menu.h"

void initSectores(eSector sectores[])
{
    sectores[0].id = 1;
    strcpy(sectores[0].descripcion, "CONTABILIDAD");

    sectores[1].id = 2;
    strcpy(sectores[1].descripcion, "AUDITORIA");

    sectores[2].id = 3;
    strcpy(sectores[2].descripcion, "RRHH");

    sectores[3].id = 4;
    strcpy(sectores[3].descripcion, "COMPRAS");

    sectores[4].id = 5;
    strcpy(sectores[4].descripcion, "VENTAS");
}

static int generarNextLegajo()
{
    static int legajoEmpleado = 0;
    legajoEmpleado ++;
    return legajoEmpleado;
}

int menuEmployee(eEmployee employee[], int len, eSector sectores[], int lenSec)
{
    int opcionEmpleados;

    do
    {
        system("cls");
        printf("\n EMPLEADOS");
        printf("\n\n 1- Alta\n");
        printf(" 2- Baja\n");
        printf(" 3- Modifaciones\n");
        printf(" 4- Ordenar\n");
        printf(" 5- Salir\n\n");
        printf(" Selecione una opcion: ");
        fflush(stdin);
        scanf("%d",&opcionEmpleados);

        switch(opcionEmpleados)
        {
        case 1://ALTA
            addEmployee(employee, len, sectores, lenSec);
            break;
        case 2://BAJA
            removeEmployee(employee, len, sectores, lenSec);
            break;
        case 3://MODIFICAR
            modifyEmployee(employee, len, sectores, lenSec);
            break;
        case 4://ORDENAR
            sortEmployees(employee, len);
            printEmployees(employee, len, sectores);
            break;
        default:
            printf("Opcion incorrecta");
            break;
        }
        system("pause");
    }
    while(opcionEmpleados!=5);

    return opcionEmpleados;
}

int initEmployees(eEmployee* list, int len)
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

int freeSpaceEmployee(eEmployee* list, int len)
{
    int i;
    int retorno= -1;

    if(len>0 && list!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int addEmployee(eEmployee* list, int len, eSector sectores[], int lenSec)
{
    int found, retorno=-1;

    if(len>0 && list!= NULL)
    {
        found = freeSpaceEmployee(list,len);

        if(found >= 0)
        {
            system("cls");
            printf("\n *** Alta de empleado ***\n\n");
            //APELLIDO
            getValidString(" Ingrese apellido: ", " Ingrese solo letras. ", " Rango: [4-51]. ", list[found].apellido, 4,51, 3);
            //NOMBRE
            getValidString(" Ingrese nombre: ", " Ingrese solo letras. "," Rango: [3-51]. ", list[found].nombre, 3, 51, 3);
            //SEXO
            getValidSexo(&list[found].sexo, " Ingrese sexo: ", 3);
            //SALARIO
            getValidFloat(&list[found].salario, " Ingrese el salario: ", " Ingrese solo numeros. Rango: [1-9999999]. ", 1, 999999, 3);
            //FECHA DE INGRESO
            getValidInt(&list[found].fechaIngreso.dia, " Fecha de ingreso: \n Dia: ", " Ingrese solo numeros. Rango[1-31]", 1, 31, 3);
            getValidInt(&list[found].fechaIngreso.mes, " Mes: ", " Ingrese solo numeros. Rango[1-12]", 1, 12, 3);
            getValidInt(&list[found].fechaIngreso.anio, " Anio: ", " Ingrese solo numeros. Rango[1900-2018]", 1900, 2018, 3);
            //SECTOR
                for(int j=0; j<lenSec; j++)
                {
                    printf("ID: %d  //  SECTOR:  %s  \n", sectores[j].id, sectores[j].descripcion);
                }
getValidInt(&list[found].idSector, " Ingrese Sector: ", " Ingrese solo numeros. Rango [1-5]. ", 1, 5, 3);
            //LEGAJO
            list[found].legajo=generarNextLegajo();//ID
            list[found].isEmpty=0; ///ESTA LIBRE?
            printf("INFORMACION INGRESADA\n");
            printf("Legajo: %d  Apellido: %s   Nombre: %s  Sexo: %c  Sueldo: %.2f  Fecha de ingreso: %d/%d/%d sector:  %s\n", list[found].idSector, list[found].apellido, list[found].nombre, list[found].sexo, list[found].salario, list[found].fechaIngreso.dia, list[found].fechaIngreso.mes, list[found].fechaIngreso.anio, sectores[found].descripcion);
        }

        else
        {
            printf("No hay lugar");
        }

    }

    return retorno;
}

int findEmployeeById(eEmployee* list, int len,int legajo)
{
    for(int i=0; i<len; i++)
    {
        if(list[i].legajo == legajo)
        {
            return i;
        }
    }

    return -1;
}

int printEmployees(eEmployee* list, int len, eSector sectores[])
{
    for (int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            printf("\n Legajo: %d  Apellido: %s   Nombre: %s  Sexo: %c  Sueldo: %.2f  Fecha de ingreso: %d/%d/%d sector:  %s\n", list[i].legajo, list[i].apellido, list[i].nombre, list[i].sexo, list[i].salario, list[i].fechaIngreso.dia, list[i].fechaIngreso.mes, list[i].fechaIngreso.anio, sectores[list[i].idSector].descripcion);
        }
    }
    system("pause");
    return 0;
}

int modifyEmployee(eEmployee* list, int len, eSector sectores[], int lenSec)
{
    int found;
    char respuesta;
    int opcion=0;
    int legajo;

    getValidInt(&legajo, "\n Ingrese legajo que desea modificar: ", " Ingrese solo numeros. Rango [1-100]. ", 1, 100, 3);

    found=findEmployeeById(list, len, legajo);

    if(found>=0)
    {
        printEmployees(list, len, sectores);
        printf("\n Desea modificar los datos? s/n: ");
        fflush(stdin);
        scanf("%c",&respuesta);

        if(respuesta=='s')
        {
            do
            {
                system("cls");
                printf("\n >>>MENU DE MODIFICACIONES<<<\n\n");
                printf(" 1. Modificar nombre\n");
                printf(" 2. Modificar apellido\n");
                printf(" 3. Modificar salario\n");
                printf(" 4. Modificar sector\n");
                printf(" 5. Salir\n");
                printf(" Selecione una opcion: ");
                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:// APELLIDO
                    getValidString("\n Ingrese nuevo apellido: ", " Ingrese solo letras. ", " Rango: [3-15]", list[found].apellido, 3,15, 3);
                    system("pause");
                    break;

                case 2://NOMBRE
                    getValidString("\n Ingrese nuevo nombre: ", " Ingrese solo letras. ", " Rango: [3-15]", list[found].nombre, 3,15, 3);
                    break;

                case 3://SEXO
                    getValidSexo(&list[found].sexo, " Ingrese nuevo sexo: ", 3);
                    break;

                case 4://SALARIO
                    getValidFloat(&list[found].salario, "\n Ingrese nuevo salario: ", " Ingrese solo numeros", 1, 9999999, 3);
                    break;

                case 5://FECHA
                    getValidInt(&list[found].fechaIngreso.dia, " Ingrese nuevo dia de ingreso: ", " Ingrese solo numeros. Rango [1-31] ", 1, 31, 3);
                    getValidInt(&list[found].fechaIngreso.mes, " Ingrese nuevo mes de ingreso: ", " Ingrese solo numeros. Rango [1-12] ", 1, 12, 3);
                    getValidInt(&list[found].fechaIngreso.anio, " Ingrese nuevo anio de ingreso: ", " Ingrese solo numeros. Rango [1900-2018] ", 1900, 2018, 3);
                    break;

                case 6://SECTORES
                    for(int j=0; j<lenSec; j++)
                    {
                        printf("ID: %d  //  SECTOR:  %s  \n", sectores[j].id, sectores[j].descripcion);
                    }
                    getValidInt(&list[found].idSector, " Ingrese Sector: ", " Ingrese solo numeros. Rango [1-5]. ", 1, 5, 3);
                    break;

                case 7:
                    printf(" Modificaciones finalizadas\n");
                    printEmployees(list, len, sectores);
                    system("pause");
                    break;

                default:
                    printf("\n Opcion incorrecta.\n\n");
                    system("pause");
                    break;
                }
            }
            while(opcion!=7);
        }
        system("pause");

    }

    else
    {
        printf("\n ERROR. Ese ID no existe\n\n");
        fflush(stdin);
        system("pause");
    }

    return -1;
}

int removeEmployee(eEmployee* list, int len, eSector sectores[], int lenSec)
{
    int found;
    char borrar;
    int legajo;

    getValidInt(&legajo, " Ingrese legajo que desea modificar: ", " Ingrese solo numeros. Rango [1-100]. ", 1, 100, 3);

    found=findEmployeeById(list, len, legajo);

    if( found == -1)
    {
        printf("\n No hay ningun empleado con el legajo %d\n", legajo);
        system("pause");
    }

    else
    {
        printEmployees(list, len, sectores);

        printf("\n Desea borrar este empleado? s/n ");
        fflush(stdin);
        scanf("%c", &borrar);

        if(borrar != 's')
        {
            printf(" Borrado cancelado\n\n");
        }

        else
        {
            printf(" Se ha eliminado el empleado\n\n");
            list[found].isEmpty = 1;
        }
        system("pause");
    }

    return -1;
}

int sortEmployees(eEmployee* list, int len)
{
    eEmployee employee;

    for(int i=0; i<len-1; i++) ///ASCENDENTE
    {
        for(int j=i+1; j<len; j++)
        {
            if(strcmp(list[j].apellido,list[i].apellido)<0)
            {
                employee = list[i];
                list[i] = list[j];
                list[j] = employee;
            }

            else if(strcmp(list[j].apellido, list[i].apellido) == 0 && strcmp(list[j].nombre,list[i].nombre)<0)
            {
                employee = list[i];
                list[i] = list[j];
                list[j] = employee;

            }

        }
    }

    system("pause");

    return 0;
}
