#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///CARGAR UNA NETBOOK A TRAVES DE UNA ESTRUCTURA CON PUNTEROS

typedef struct
{
    int codigo;
    char marca[20];
    int capacidad;
    float precio;
    int isEmpty;
} ePendrive;

int cargarPendrive(ePendrive *pendrive);
void mostrarPendrive(ePendrive *pendrive);
int cargarPendriveParam(ePendrive *pen, int codigo, char marca[], int cap, float precio);

int main()
{
    ePendrive pendrive;

    ///HARCODEO
    /*ePendrive pen2;
    ePendrive pen3;
    cargarPendriveParam(&pen2, 125, "Sony", 16, 160);
    cargarPendriveParam(&pen3, 256, "Kington", 8, 100);
    mostrarPendrive(&pen2);
    mostrarPendrive(&pen3);*/

    ///CARGA UN PENDRIVE CON PARAMETROS
    /*if((cargarPendriveParam(&pendrive, pendrive.codigo, pendrive.marca, pendrive.capacidad, pendrive.precio)) ==0)
        mostrarPendrive(&pendrive);*/

    ///CARGA UN PENDRIVE
    if((cargarPendrive(&pendrive)) ==0)
        mostrarPendrive(&pendrive);

    return 0;
}

int cargarPendrive(ePendrive *pendrive)
{
    int retorno=-1;

    if(pendrive!=NULL)
    {
        printf(" Ingrese el codigo:");
        scanf("%d",& pendrive->codigo);

        printf(" Ingrese la marca:");
        fflush(stdin);
        gets(pendrive->marca);

        printf(" Ingrese la capacidad:");
        scanf("%d", &pendrive->capacidad);

        printf(" Ingrese el precio:");
        scanf("%f", &pendrive->precio);

        retorno=0;
    }

    return retorno;
}

void mostrarPendrive(ePendrive *pendrive)
{
    if(pendrive!=NULL)
    {
        printf("\n CODIGO\t MARCA\t CAPACIDAD\t PRECIO\t\n");
        printf(" %d\t %s\t %d\t %.2f\n", pendrive->codigo, pendrive->marca, pendrive->capacidad, pendrive->precio);
    }
}

int cargarPendriveParam(ePendrive *pen, int codigo, char marca[], int cap, float precio)
{
    int retorno= -1;

    if(pen!=NULL)
    {
        pen->codigo=codigo;
        strcpy(pen->marca, marca);
        pen->capacidad=cap;
        pen->precio=precio;
        ///cargarPendrive(pen); CARGA Y HARCODEA
        retorno=0;
    }

    return retorno;
}


