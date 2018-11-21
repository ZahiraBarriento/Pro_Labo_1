#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(EPersona lista[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        lista[i].isEmpty = 1;
    }
}

int obtenerEspacioLibre(EPersona lista[], int len)
{
    int i;
    int retorno = -1;

    for(i=0; i<len; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


void alta(EPersona lista[], int len)
{
    int index;

    index = obtenerEspacioLibre(lista, len);

    if(index != -1)
    {
        printf("Ingrese apellido:");
        fflush(stdin);
        gets(lista[index].apellido);

        printf("Ingrese nombre:");
        fflush(stdin);
        gets(lista[index].nombre);

        printf("Ingrese DNI:");
        scanf("%ld",&lista[index].dni);

        printf("Ingrese fecha de nacimiento: ");
        scanf("%d",&lista[index].feNac.dia);

        printf("Ingrese mes de nacimiento: ");
        scanf("%d",&lista[index].feNac.mes);

        printf("Ingrese anio de nacimiento: ");
        scanf("%d",&lista[index].feNac.anio);
        lista[index].isEmpty=0;

        system("cls");

    }

    else
    {
        printf("No hay espacio");
    }
    return;
}

int buscarOcurrencia(EPersona lista[], int len, int valor)
{
    for(int i=0; i<len; i++)
    {
        if(lista[i].dni == valor)
        {
            return i;
        }
    }

    return -1;
}


void baja(EPersona lista[], int len)
{
    int buscar;
    long int doc;

    printf("Ingrese el DNI que desea eliminar:");
    scanf("%ld",&doc);

    buscar= buscarOcurrencia(lista, len, doc);

    for(int i=0; i<len; i++)
    {
        if(buscar >= 0)
        {
            printf("El usuario fue eliminado");
            lista[buscar].isEmpty = 1;
            system("pause");
            break;
        }

        else
        {
            printf("No existe ese DNI");
            system("pause");
            break;
        }
    }
}

void modificar(EPersona lista[], int len)
{
    int index;
    long int doc;
    char respuesta;
    int opcion=0;

    printf("Ingrese el DNI que desea modificar:");
    scanf("%ld", &doc);

    index=buscarOcurrencia(lista, len, doc);

        if(index>=0)
        {
            printf("%s\t%s\t%ld\t%d/%d/%d", lista[index].apellido, lista[index].nombre, lista[index].dni, lista[index].feNac.dia, lista[index].feNac.mes, lista[index].feNac.anio);
            printf("Desea modficar los datos? s/n");
            fflush(stdin);
            scanf("%c",&respuesta);

            if(respuesta=='s')
            {
                do
                {
                    printf(">>>MENU DE MODIFICAIONES<<<\n\n");
                    printf("1. Modificar apellido\n");
                    printf("2. Modificar nombre\n");
                    printf("3. Modificar dni\n");
                    printf("4. Modificar fecha de nacimiento\n");
                    printf("5. Salir");
                    scanf("%d",&opcion);

                    switch(opcion)
                    {
                    case 1:
                        printf("Nuevo apellido:");
                        fflush(stdin);
                        gets(lista[index].apellido);
                        break;

                    case 2:
                        printf("Nuevo nombre:");
                        fflush(stdin);
                        gets(lista[index].nombre);
                        break;

                    case 3:
                        printf("Nuevo DNI:");
                        scanf("%ld",&lista[index].dni);
                        break;

                    case 4:
                        printf("Ingrese nueva fecha de nacimiento: ");
                        scanf("%d",&lista[index].feNac.dia);

                        printf("Ingrese nuevo mes de nacimiento: ");
                        scanf("%d",&lista[index].feNac.mes);

                        printf("Ingrese nuevo anio de nacimiento: ");
                        scanf("%d",&lista[index].feNac.anio);
                        break;

                    default:
                        printf("Opcion incorrecta");

                    }
                }while(opcion!=5);
            }
        }
}

void ordenar(EPersona lista[], int len)
{
    int i, j;
    EPersona auxPersona;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(strcmp(lista[i].apellido, lista[j].apellido) >0)
            {
                auxPersona = lista[i];
                lista[i] = lista[j];
                lista[j] = auxPersona;
            }

            else if(strcmp(lista[i].apellido, lista[j].apellido) == 0  && strcmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                auxPersona = lista[i];
                lista[i] = lista[j];
                lista[j] = auxPersona;
            }
        }
    }

    printf("Apellido \t Nombre \tDNI \tFecha de nacimiento\n");
    for(int i = 0; i < len; i++)
    {
            printf("%s \t%s \t%ld \t%d/%d/%d\n", lista[i].apellido, lista[i].nombre, lista[i].dni,lista[i].feNac.dia, lista[i].feNac.mes, lista[i].feNac.anio);
    }
}

/*void mostrarPerson(EPersona lista[], int len)
{
   printf("Apellido \t Nombre \tDNI \tFecha de nacimiento\n");
    for(int i = 0; i < len; i++)
    {
            printf("%s \t%s \t%ld \t%d/%d/%d\n", lista[i].apellido, lista[i].nombre, lista[i].dni,lista[i].feNac.dia, lista[i].feNac.mes, lista[i].feNac.anio);
    }
}*/


