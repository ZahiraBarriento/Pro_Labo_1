#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "menu.h"
#include "utn.h"
#include "employee.h"
#include "almuerzo.h"
#define CANT 5

int menuMenues()
{
    eMenu menu[CANT];
    initMenu(menu, CANT);
    int opcionMenu;

    do
    {
        system("cls");
        printf("\n MENUES");
        printf("\n\n 1- Alta\n");
        printf(" 2- Baja\n");
        printf(" 3- Modifaciones\n");
        printf(" 4- Ordenar\n");
        printf(" 5- Salir\n\n");
        printf(" Selecione una opcion: ");
        fflush(stdin);
        scanf("%d",&opcionMenu);

        switch(opcionMenu)
        {
        case 1:
            agregarMenu(menu, CANT);
            break;
        case 2:
            eliminarMenu(menu, CANT);
            break;
        case 3:
            modificarMenu(menu,CANT);
            break;
        case 4:
            sortMenu(menu,CANT);
            break;
        case 5:
            printf(" Volviendo al menu principal...\n\n");
            break;
        default:
            printf(" Opcion incorrecta. ");
            break;
        }
        system("pause");
    }
    while(opcionMenu!=5);

    return opcionMenu;
}

static int generarNextId()
{
    static int idMenu = 0;
    idMenu ++;
    return idMenu;
}

int initMenu(eMenu* list, int len)
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

int freeSpaceMenu(eMenu* list, int len)
{
    int i;
    int retorno = -1;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int printMenu(eMenu* list, int len)
{
    printf(" ID\t    DESCRIPCION\t    IMPORTE\n");
    for(int i=0; i<len; i++)
    {
        if(!list[i].isEmpty)
        {
            printf(" %d\t    %s\t    %f\t\n",list[i].idComida,list[i].descripcion,list[i].importe);
        }
    }
    return 0;
}

int agregarMenu(eMenu* list, int len)
{
    eMenu nuevoMenu;
    int found;
    int retorno=-1;


    found = freeSpaceMenu(list, len);

    if(found == -1)
    {
        printf("\n No hay lugar\n\n");
        system("pause");
    }

    else
    {
        system("cls");
        printf("\n\n  *** Alta Menu ***\n\n");
        getValidString(" Ingrese la descripcion: ", " Ingrese solo letras. ", " Rango de caracteres [3-51]. ", nuevoMenu.descripcion, 3, 51, 3);

        getValidFloat(&nuevoMenu.importe," Ingrese el importe: ", " Ingrese solo numeros. ", 1, 200, 3);

        nuevoMenu.idComida=generarNextId();//ID
        nuevoMenu.isEmpty=0; ///ESTA LIBRE?
        list[found]=nuevoMenu;

        retorno=0;
        printf("\n Se dio de alta el menu: \n\n ID:%d  Descripcion:%s   Importe: %f\n\n", list[found].idComida, list[found].descripcion, list[found].importe);
        system("pause");
    }

    return retorno;

}

int buscarMenu(eMenu* list, int len,int id)
{
    for(int i=0; i<len; i++)
    {
        if(list[i].idComida == id)
        {
            return i;
        }
    }

    return -1;
}

int eliminarMenu(eMenu* list, int len)
{
    int found;
    int id;
    char borrar;

    printf("\n Ingrese ID: ");
    scanf("%d", &id);

    found = buscarMenu(list,len,id);

    if( found == -1)
    {
        printf("\n No hay ningun menu con el ID %d\n", id);
        system("pause");
    }

    else
    {
        printf("\n ID: %d  Descripcion: %s  Importe: %f", list[found].idComida, list[found].descripcion, list[found].importe);

        printf("\n Desea borrar este menu? s/n ");
        fflush(stdin);
        scanf("%c", &borrar);

        if(borrar != 's')
        {
            printf(" Borrado cancelado\n\n");
        }

        else
        {
            printf(" Se ha eliminado el menu\n\n");
            list[found].isEmpty = 1;
        }
        system("pause");
    }

    return -1;
}

int modificarMenu(eMenu* list, int len)
{
    int found;
    char respuesta;
    int opcion=0;
    int id;

    printf("\n Ingrese el ID que desea modificar:");
    scanf("%d", &id);

    found=buscarMenu(list, len, id);

    if(found>=0 && list[found].isEmpty==0)
    {
        //printf(" ID: %d  Descripcion: %s  Importe: %f",list[found].idComida, list[found].descripcion, list[found].importe);
        printMenu(list,len);
        printf("\n Desea modificar los datos? s/n");
        fflush(stdin);
        scanf("%c",&respuesta);

        if(respuesta=='s')
        {
            do
            {
                system("cls");
                printf("\n >>>MENU DE MODIFICACIONES<<<\n\n");
                printf(" 1. Modificar descripcion\n");
                printf(" 2. Modificar importe\n");
                printf(" 3. Salir");
                printf("\n Ingrese una opcion: ");
                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:
                    getValidString(" Ingrese nueva descripcion: ", " Ingrese solo letras. ", " Rango: [3-51]. ", list[found].descripcion, 3, 51, 3);
                    break;

                case 2:
                    getValidFloat(&list[found].importe, " Ingrese nuevo importe: ", " Rango: [3-200]. ", 3, 200, 3);
                    break;

                case 3:
                    printf(" Modificaciones finalizadas\n");
                    printf(" Descripcion: %s \nImporte: %f\n\n", list[found].descripcion, list[found].importe);
                    system("pause");
                    break;

                default:
                    printf(" Opcion incorrecta");
                    system("pause");
                    break;
                }
            }
            while(opcion!=3);
        }
    }

    else
    {
        printf("\n ERROR. Ese ID no existe. \n\n");
        fflush(stdin);
        system("pause");
    }

    return -1;
}

int sortMenu(eMenu* list, int len)
{
    eMenu menu;

    for(int i=0; i<len-1; i++) ///ASCENDENTE
    {
        for(int j=i+1; j<len; j++)
        {
            if(list[i].importe<list[j].importe)
            {
                menu = list[i];
                list[i] = list[j];
                list[j] = menu;
            }

            else if(list[i].importe==list[j].importe && strcmp(list[j].descripcion,list[i].descripcion)>0)
            {
                menu = list[i];
                list[i] = list[j];
                list[j] = menu;
            }
        }
    }
    printMenu(list,len);
    system("pause");

    return 0;
}




