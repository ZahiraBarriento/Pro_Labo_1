#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "juego.h"
#include "cliente.h"
#include "alquileres.h"
#include "informes.h"

///-------------------------------------------------------------------------
///MENU LISTAR
int menuListar(eCliente cliente[], int lenCli, eJuegos juego[], int lenJue, eAlquileres alquiler[], int lenAl)
{
    int opcionListar=0;
    float promedio;

    do
    {
        system("cls");
        printf("\n *** MENU LISTAR *** \n\n");
        printf(" 1. Listar promedio, total y que juego supera el promedio\n");
        printf(" 2. Juegos que NO supera el promedio\n");
        printf(" 3. Cantidad de clientes que alquilaron un juego determinado\n");
        printf(" 4. Cantidad de juegos que alquilo un cliente determinado\n");
        printf(" 5. Juegos con menos alquileres\n");
        printf(" 6. Clientes con mas alquileres\n");
        printf(" 7. Juegos alquilados en determinada fecha\n");
        printf(" 8. Clientes que realizaron un alquiler en determinada fecha\n");
        printf(" 9. Todos los juegos ordenados por importe(DESCENDENTE)\n");
        printf(" 10. Todos los clientes ordenados por apellido(ASCENDENTE)\n");
        printf(" 11. Salir\n");
        printf("\n Seleccione una opcion: ");
        fflush(stdin);
        scanf("%d",&opcionListar);

        switch(opcionListar)
        {
        case 1://PROMEDIO JUEGOS ALQUILADOS
            promedio=promedioJuegos(alquiler, lenAl, juego, lenJue);
            break;
        case 2://JUEGOS QUE NO SUPERAN EL PROMEDIO
            juegosQueNoSuperanPromedio(alquiler, lenAl, juego, lenJue, promedio);
            break;
        case 3://TODOS LOS CLIENTES DE UN JUEGO DETERMINADO
            listarClienteXJuego(alquiler, lenAl, juego, lenJue, cliente, lenCli);
            break;
        case 4://TODOS LOS ALQUILERES DE UN CLIENTE
            listarJuegoXCliente(alquiler, lenAl, juego, lenJue, cliente, lenCli);
            break;
        case 5://JUEGOS MENOS ALQUILADOS
            juegosMenosAlquilados(alquiler, lenAl, juego, lenJue);
            break;
        case 6://CLIENTES CON MAS ALQUILERES
            clienteMasAlquileres(alquiler, lenAl, cliente, lenCli);
            break;
        case 7://JUEGO POR FECHA
            juegosPorFecha(alquiler, lenAl, juego, lenJue);
            break;
        case 8://CLIENTES POR FECHA
            clientesPorFecha(alquiler, lenAl, juego, lenJue, cliente, lenCli);
            break;
        case 9://TODOS LOS JUEGOS ORDENADOS POR IMPORTE
            bubbleSort(juego, lenJue);
            break;
        case 10://TODOS LOS CLIENTES ORDENADOS POR APELLIDO
            insertion(cliente, lenCli);
            break;
        case 11:
            printf("\n Saliendo..\n\n");
            break;
        default:
            printf("\n Opcion incorrecta\n\n");
            break;
        }
        system("pause");
    }
    while(opcionListar!=10);

    return opcionListar;
}

///-----------------------------------------------------------------------------
///PROMEDIO Y TOTAL DE LOS IMPORTES ALQUILADOS
float promedioJuegos(eAlquileres* alquileres, int lenAl, eJuegos* juegos, int lenJue)
{
    float promedio=0;
    int contadorImporte=0, totalImporte=0;

    if(alquileres!=NULL && juegos!=NULL)
    {
        for(int i=0; i<lenAl; i++)
        {
            if(alquileres[i].isEmpty==1)
            {
                for(int j=0; j<lenJue; j++)
                {
                    if(alquileres[i].idJuegos == juegos[j].idJuegos && juegos[j].isEmpty==1)
                    {
                        totalImporte=totalImporte+juegos[j].importe;
                        contadorImporte++;
                        promedio=totalImporte/contadorImporte;
                    }
                }
            }
        }
    }


    printf("\n *** PROMEDIO JUEGOS ALQUILADOS ***");
    printf("\n\n El total de los juegos alquilados es: %d", totalImporte);
    printf("\n El promedio de los juegos alquilados es: %.2f\n\n", promedio);


    return promedio;

}
///------------------------------------------------------------------------------------------------------+
///JUEGPS QUE NO SUPEREN EL PROMEDIO
void juegosQueNoSuperanPromedio(eAlquileres* alquileres, int lenAl, eJuegos* juegos,int lenJue, float promedio)
{
    int contadorSuperanElpromedio=0;

    for(int i=0; i<lenJue ; i++)
    {
        if(juegos[i].importe < promedio && juegos[i].isEmpty ==1)
        {
            contadorSuperanElpromedio ++;
        }
    }

    printf("\n La cantidad de juegos cuyo importe NO superan el promedio son: %d \n\n", contadorSuperanElpromedio);

}
///--------------------------------------------------------------------------------------------------------------------------
///ORDENAR JUEGOS POR IMPORTE
void bubbleSort(eJuegos* juegos, int len)
{
    int j;
    eJuegos aux;
    int flagNoEstaOrdenado = 1;
    system("cls");
    printf("  ***  JUEGOS ***\n\n");

    while (flagNoEstaOrdenado==1)
    {
        flagNoEstaOrdenado = 0;
        for (j = 1; j < len; j++)
        {
            if (juegos[j].importe > juegos[j - 1].importe)
            {
                aux = juegos[j];
                juegos[j] = juegos[j - 1];
                juegos[j - 1] = aux;
                flagNoEstaOrdenado = 1;
            }
        }
    }
    mostrarJuegos(juegos, len);
}
///--------------------------------------------------------------------------------------------------------------------------
///ORDENAR CLIENTES POR APELLIDO
void insertion(eCliente cliente[], int len)
{
    eCliente auxCliente;
    int i,j;

    for(i=1; i<len; i++)
    {
        auxCliente = cliente[i];
        j=i-1;

        while(strcmp(cliente[j].apellido, auxCliente.apellido)>0 && j>=0)
        {
            cliente[j+1] = cliente[j];
            j--;
        }
        cliente[j+1]=auxCliente;
    }
    mostrarClientes(cliente, len);
}
///------------------------------------------------------------------------------
///JUEGOS POR FECHA
void juegosPorFecha(eAlquileres *alquiler, int lenAl, eJuegos *juegos, int lenJueg)
{
    int dia, mes, anio;

    system("cls");

    getValidInt(" Ingrese una fecha\n\n Dia: ", &dia, 1, 31);
    getValidInt(" Mes:  ", &mes, 1, 12);
    getValidInt(" Anio: ", &anio, 1900, 2018);

    for (int i=0; i<lenAl; i++)
    {
        if (alquiler[i].isEmpty == 1 && alquiler[i].fecha.dia == dia && alquiler[i].fecha.mes == mes && alquiler[i].fecha.anio == anio)
        {
            for (int j=0; j<lenJueg; j++)
            {
                if (alquiler[i].idJuegos == juegos[j].idJuegos)
                {
                    mostrarJuego(juegos[j]);
                }
            }
        }
    }
}
///--------------------------------------------------------------------------------------------
///TODOS LOS CLIENTES QUE ALQUILARON UN JUEGO DETERMINADO
void listarClienteXJuego(eAlquileres* alquileres, int lenAl, eJuegos* juegos, int lenJue, eCliente* cliente, int lenCli)
{
    int idJuego;
    char descripcion[51];
    int flag=0;

    idJuego=elegirJuegos(juegos, lenJue);
    cargarDescripcionJuego(juegos, lenJue, idJuego, descripcion);

    system("cls");
    printf("\n CLIENTES DEL JUEGO: %s\n\n", descripcion);

    for(int i=0; i<lenAl; i++)
    {
        if(alquileres[i].isEmpty == 1 && idJuego == alquileres[i].idJuegos)
        {
            for(int j=0; j<lenCli; j++)
            {
                if(alquileres[i].idCliente == cliente[j].idCliente)
                {
                    mostrarCliente(cliente[j]);
                    flag=1;
                }
            }
        }
    }

    if(flag==0)
    {
        printf(" No hay alquileres para mostrar.\n");
    }
}
///--------------------------------------------------------------------------------------------
///TODOS LOS JUEGOS QUE ALQUILARON UN CLIENTE
void listarJuegoXCliente(eAlquileres* alquileres, int lenAl, eJuegos* juegos, int lenJue, eCliente* cliente, int lenCli)
{
    int flag=0;
    int idCliente;

    idCliente=elegirCliente(cliente, lenCli);

    system("cls");
    printf("\n JUEGOS DEL CLIENTE: \n\n");

    for(int i=0; i<lenAl; i++)
    {
        if(alquileres[i].isEmpty == 1 && alquileres[i].idCliente == idCliente)
        {
            for(int j=0; j<lenJue; j++)
            {
                if(alquileres[i].idJuegos == juegos[j].idJuegos)
                {
                    mostrarJuego(juegos[j]);
                    flag=1;
                }
            }
        }
    }

    if(flag==0)
    {
        printf("\n No hay alquileres para mostrar.\n");
    }
}
///------------------------------------------------------------------------------------------------------------------
///CLIENTES POR FECHA
void clientesPorFecha(eAlquileres *alquiler, int lenAl, eJuegos *juegos, int lenJueg, eCliente *cliente, int lenCli)
{
    int dia, mes, anio, flag=0;

    system("cls");

    getValidInt(" Ingrese una fecha\n\n Dia: ", &dia, 1, 31);
    getValidInt(" Mes: ", &mes, 1, 12);
    getValidInt(" Anio: ", &anio, 1900, 2018);

    for (int i=0; i<lenAl; i++)
    {
        if (alquiler[i].isEmpty == 1 && alquiler[i].fecha.dia == dia && alquiler[i].fecha.mes == mes && alquiler[i].fecha.anio == anio)
        {
            for (int j=0; j<lenJueg; j++)
            {
                if (alquiler[i].idCliente == cliente[j].idCliente && cliente[j].isEmpty == 1)
                {
                    mostrarCliente(cliente[j]);
                    flag=1;
                }
            }
        }
    }
    if(flag==0)
    {
        printf("\n No hay alquileres para mostrar.\n");
    }
}
///--------------------------------------------------------------------------------------------------
///JUEGOS MENOS ALQUILADOS
void juegosMenosAlquilados(eAlquileres* alquieres, int lenAl, eJuegos* juegos, int lenJue)
{
    int contadorCliente=0, contadorClienteMin=0;

    for (int i=0; i<lenJue; i++)
    {
        if(juegos[i].isEmpty==1)
        {
            contadorCliente = 0;
            for (int j=0; j<lenAl; j++)
            {
                if (alquieres[j].idJuegos == juegos[i].idJuegos && alquieres[j].isEmpty== 1)
                {
                    contadorCliente++;
                }
            }

            if (contadorCliente < contadorClienteMin)
            {
                contadorClienteMin = contadorCliente;
            }
            /*if (contadorCliente == contadorClienteMin)
            {
                mostrarJuego(juegos[i]);
            }*/

        }
    }

    for (int i=0; i<lenJue; i++)
    {
        if(juegos[i].isEmpty==1)
        {
            contadorCliente = 0;
            for (int j=0; j<lenAl; j++)
            {
                if (alquieres[j].idJuegos == juegos[i].idJuegos && alquieres[j].isEmpty==1)
                {
                    contadorCliente++;
                }
            }
            if (contadorCliente == contadorClienteMin)
            {
                mostrarJuego(juegos[i]);
            }
        }
    }
}


///--------------------------------------------------------------------------------------------------------------
///CLIENTES MAS ALQUILERES
void clienteMasAlquileres(eAlquileres* alquileres, int lenAl, eCliente* cliente,int lenCli)
{
    int contadorClienteMax=0;
    int contadorCliente=0;

    if(alquileres!=NULL && cliente!=NULL)
    {
        for(int i=0; i<lenCli; i++)
        {
            contadorCliente=0;
            for(int j=0; j<lenAl; j++)
            {
                if(cliente[i].idCliente == alquileres[j].idCliente && alquileres[j].isEmpty==1 && cliente[i].isEmpty==1)
                {
                    contadorCliente++;
                }
            }
            if(contadorCliente>contadorClienteMax)
            {
                contadorClienteMax=contadorCliente;
            }

        }

        for(int i=0; i<lenCli; i++)
        {
            contadorCliente=0;
            for(int j=0; j<lenAl; j++)
            {
                if(cliente[i].idCliente == alquileres[j].idCliente && alquileres[j].isEmpty==1 && cliente[i].isEmpty==1)
                {
                    contadorCliente++;
                }
            }

            if(contadorCliente == contadorClienteMax)
            {
                mostrarCliente(cliente[i]);
            }
        }
    }
}
