#include "ArrayEmployees.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0

static int generarNextId()
{
    static int id = 0;
    id ++;
    return id;
}

int menu()
{
    int opcion;
    system("cls");
    printf("\n >>>MENU DE OPCIONES<<<");
    printf("\n\n 1- Alta\n");
    printf(" 2- Modificaciones\n");
    printf(" 3- Baja\n");
    printf(" 4- Informe\n");
    printf(" 10- Salir\n\n");
    printf(" Selecione una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int initEmployees(eEmployee* list, int len)
{
    int retorno = -1;
    int i;
    if(len > 0 && list != NULL)
    {
        retorno = 0;
        for(i=0; i<len; i++)
        {
            list[i].isEmpty=TRUE;
            retorno=0;
        }
    }
    return retorno;
}

int freeSpace(eEmployee* list, int len)
{
    int i;
    int retorno= -1;

    if(len>0 && list!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == TRUE)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int addEmployee(eEmployee* list, int len, int id,char name[],char lastName[],float salary,int sector)
{
    int i, retorno=-1;

    if(len>0 && list!= NULL)
    {
        i = freeSpace(list,len);

        if(i >= 0)
        {
            printf("---Alta de empleado---\n\n");

            //printf("ID: %d", id);

            if(!getValidString("Ingrese el nombre: ", "Ingrese solo letras. ","Rango: [3-30]", name, 3, 30, 3))
            {
                if(!getValidString("Ingrese el apellido: ", "Ingrese solo letras. ", "Rango: [4-30]", lastName, 4, 30, 3))
                {
                    if(!getValidFloat(&salary, "Ingrese el salario: ", "Ingrese solo numeros. ", 1, 99999999, 3))
                    {
                        if(!getValidInt(&sector,"Ingrese el sector: ", "Ingrese solo numeros. ", 1, 5, 3))
                        {
                            printf("\nSe dio de alta: %s %s\n\n", name, lastName);

                            strcpy(list[i].name, name);
                            strcpy(list[i].lastName, lastName);
                            list[i].salary=salary;
                            list[i].sector=sector;
                            list[i].id=generarNextId();
                            list[i].isEmpty = 0;
                            retorno=0;
                        }
                    }
                }
            }
        }

        else
        {

            printf("No hay espacio\n\n");
        }
    }
    return retorno;
}


int findEmployeeById(eEmployee* list, int len,int id)
{
    for(int i=0; i<len; i++)
    {
        if(list[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

int printEmployees(eEmployee* list, int length)
{
    for(int i=0; i<length; i++)
    {
        if(!list[i].isEmpty)
        {
            printf("Id: %d Name: %s Lastname: %s Salary: %f Sector: %d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }
    }
    return 0;
}

int modifyEmployee(eEmployee* list, int len, int id)
{
    int found;
    char respuesta;
    int opcion=0;


    printf("\n Ingrese el Id que desea modificar:");
    scanf("%d", &id);

    found=findEmployeeById(list, len, id);

    if(found>=0)
    {
        printf("Id: %d Name: %s Lastname: %s Salary: %f Sector: %d\n",list[found].id,list[found].name,list[found].lastName,list[found].salary,list[found].sector);
        printf("\n Desea modificar los datos? s/n");
        fflush(stdin);
        scanf("%c",&respuesta);

        if(respuesta=='s')
        {
            do
            {
                printf(">>>MENU DE MODIFICACIONES<<<\n\n");
                printf("1. Modificar nombre\n");
                printf("2. Modificar apellido\n");
                printf("3. Modificar salario\n");
                printf("4. Modificar sector\n");
                printf("5. Salir");
                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:
                    getValidString("Ingrese nuevo nombre: ", "Ingrese solo letras. ", "Rango: [3-15]", list[found].name, 3, 15, 3);
                    break;

                case 2:
                    getValidString("Ingrese nuevo apellido: ", "Ingrese solo letras. ", "Rango: [3-15]", list[found].lastName, 3, 15, 3);
                    break;

                case 3:
                    getValidFloat(&list[found].salary, "Ingrese nuevo salario: ", "Ingrese solo numeros", 1, 999999999, 3);
                    break;

                case 4:
                    getValidInt(&list[found].sector, "Ingrese nuevo sector: ", "Ingrese solo numeros. ", 1, 5, 3);
                    break;

                case 5:
                    printf("\nCambios Realizados: \nNombre: %s \nApellido: %s \nSalario: %f \nSector: %d \n", list[found].name, list[found].lastName, list[found].salary, list[found].sector);
                    break;

                default:
                    printf("Opcion incorrecta");

                }
            }
            while(opcion!=5);
        }
        system("pause");

    }

    else
    {
        printf("ERROR. Ese ID no existe");
        fflush(stdin);
        system("pause");
    }

    return -1;
}

int removeEmployee(eEmployee* list, int len, int id)
{
    int found;

    printf("\n Ingrese el id que desea eliminar: ");
    scanf("%d",&id);

    found=findEmployeeById(list, len, id);

    for(int i=0; i<len; i++)
    {
        if(found >= 0)
        {
            printf("\n El usuario fue eliminado.\n");
            list[found].isEmpty = TRUE;
            system("pause");
            break;
        }

        else
        {
            printf("\n No existe ese id.\n");
            system("pause");
            break;
        }
    }

    return -1;
}

int sortEmployees(eEmployee* list, int len, int order)
{
    eEmployee employee;

    printf("\n\n 0. Ordenar de manera descendente. \n\n 1. Ordenar de manera ascendente.\n\n Seleccione una opcion: ");
    fflush(stdin);
    scanf("%d",&order);

    if(order==1)
    {
        for(int i=0; i<len-1; i++) ///ASCENDENTE
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[j].lastName,list[i].lastName)<0)
                {
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }

                else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[i].sector>list[j].sector)
                {
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;

                }

            }
        }
    }

    if(order==0)
    {
        for(int i=0; i<len-1; i++) ///DESCENDENTE
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[j].lastName,list[i].lastName)>0)
                {
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }

                else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[i].sector<list[j].sector)
                {
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }
            }
        }
    }
    printEmployees(list,len);

    return 0;
}


//int reportSalary
