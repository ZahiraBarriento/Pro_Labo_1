#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "juego.h"
#include "cliente.h"
#include "alquileres.h"

///GENERA ID DE ALQUILERES
static int generarNextId()
{
    static int idAlquiler=0;
    idAlquiler++;
    return idAlquiler;
}
///--------------------------------------
///INICIALIZA ALQUILERES
void inicializarAlquileres(eAlquileres* list, int len)
{
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty=0;
    }
}
///---------------------------------------
///ELIJIR EL CLIENTE DEL ALQUILER
int elegirCliente(eCliente clientes[], int len)
{
    int idCliente;
    int retorno=-1;
    int flag=0;

    mostrarClientes(clientes, len);
    printf("\n Seleccione un cliente: ");
    scanf("%d", &idCliente);

    for(int i=0; i < len; i++)
    {
        if(clientes[i].idCliente==idCliente && clientes[i].isEmpty == 1)
        {
            retorno=idCliente;
            break;
        }
    }

    return retorno;
}
///---------------------------------------------
///ELIJIR JUEGO
int elegirJuegos(eJuegos juegos[], int len)
{
    int idJuegos;
    int retorno= -1;

    mostrarJuegos(juegos, len);
    printf("\n Seleccione un juego: ");
    scanf("%d", &idJuegos);

    for(int i=0; i < len; i++)
    {
        if(juegos[i].idJuegos==idJuegos && juegos[i].isEmpty == 1)
        {
            retorno=idJuegos;
            break;
        }
    }

    return retorno;
}
///---------------------------------------------------------
///BUSCAR ESPACIO LIBRE EN ALQUILERES
int buscarEspacioLibreAlquileres(eAlquileres list[], int len)
{
    int i;
    int retorno = -1;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
///----------------------------------------------------------------------
///AGREGAR UN NUEVO ALQUILER
int agregarAlquiler(eAlquileres* alquiler, int lenAlquiler, eCliente cliente[], int lenCliente, eJuegos juegos[], int lenJuegos)
{
    int retorno=-1;
    int found;

    system("cls");
    printf("\n  *** ALTA ALQUILER ***\n\n");

    found = buscarEspacioLibreAlquileres(alquiler, lenAlquiler);

    if(alquiler !=NULL)
    {

        if(found == -1)
        {
            printf(" No hay lugar\n\n");
        }

        else
        {
            alquiler[found].idJuegos = elegirJuegos(juegos, lenJuegos);

            if(alquiler[found].idJuegos == -1)
            {
                printf("\n No existe el ID ingresado.\n");
                system("pause");
            }
            else
            {
                alquiler[found].idCliente=elegirCliente(cliente, lenCliente);

                if(alquiler[found].idCliente == -1)
                {
                    printf(" No existe el ID ingresado. \n");
                    system("pause");

                }

                else
                {
                    getValidInt("\n Ingrese la fecha\n Dia: ",&alquiler[found].fecha.dia,1,31);
                    getValidInt(" Mes: ",&alquiler[found].fecha.mes,1,12);
                    getValidInt(" Anio: ",&alquiler[found].fecha.anio,1900,2018);
                    alquiler[found].idAlquileres=generarNextId();//ID
                    alquiler[found].isEmpty=1;

                    printf("\n ALQUILER REALIZADO\n");
                    printf(" ID Alquiler: %d  \n Fecha del alquiler: %d/%d/%d  \n Nombre Empleado: %s %s \n Juego elegido: %s\n", alquiler[found].idAlquileres, alquiler[found].fecha.dia, alquiler[found].fecha.mes, alquiler[found].fecha.anio, cliente[(alquiler[found].idCliente)-1].apellido, cliente[(alquiler[found].idCliente)-1].nombre, juegos[(alquiler[found].idJuegos)-1].descripcion);
                    retorno=0;
                    system("pause");
                }
            }
        }
    }

    return retorno;
}
///--------------------------------------------------------------------
///CARGAR JUEGO
void cargarDescripcionJuego(eJuegos juego[], int lenJuego, int idJuego, char cadena[])
{
    for(int i=0; i < lenJuego; i++)
    {
        if( juego[i].idJuegos == idJuego)
        {
            strcpy(cadena, juego[i].descripcion);
            break;
        }
    }
}
///--------------------------------------------------------------------
///MOSTRAR ALQUILER
int mostrarAlquiler(eAlquileres alquiler, int lenAlqui, eJuegos* juegos, int lenJueg, eCliente* cliente, int lenClien)
{
    char descripcion[51];
    char apellido[31];

    cargarDescripcionJuego(juegos, lenJueg, alquiler.idJuegos, descripcion);
    cargarCliente(cliente, lenClien, alquiler.idCliente, apellido);

    printf("\n\n Juego: %s\n ID alquiler: %d\n Cliente: %s\n Fecha: %d/%d/%d\n\n", descripcion, alquiler.idAlquileres, apellido, alquiler.fecha.dia, alquiler.fecha.mes, alquiler.fecha.anio);
    return 0;
}
///---------------------------------------------------------------
///CARGAR CLIENTE
void cargarCliente(eCliente cliente[], int lenCli, int idCliente, char apellido[])
{
    for(int i=0; i < lenCli; i++)
    {
        if(cliente[i].idCliente == idCliente)
        {
            strcpy(apellido, cliente[i].apellido);
            break;
        }
    }
}
///-------------------------------------------------------------------------
///MOSTRAR ALQUILERES
int mostrarAlquileres(eAlquileres* alquiler, int lenAl, eJuegos* juegos, int lenJue, eCliente* cliente, int lenCli)
{
    for(int i = 0; i<lenAl; i++)
    {
        if(alquiler[i].isEmpty == 1)
        {
            mostrarAlquiler(alquiler[i], lenAl, juegos, lenJue, cliente, lenCli);
        }
    }
    return 0;
}
///----------------------------------------------------------------------------------------------------------------------
///MOSTRAR CLIENTE
int mostrarClienteListar(eAlquileres alquiler, int lenAlqui, eJuegos* juegos, int lenJueg, eCliente* cliente, int lenClien)
{
    char descripcion[51];
    char apellido[31];

    cargarCliente(cliente, lenClien, alquiler.idCliente, apellido);
    cargarDescripcionJuego(juegos, lenJueg, alquiler.idJuegos, descripcion);

    printf("\n\n Juego: %s\n ID alquiler: %d\n Cliente: %s\n Fecha: %d/%d/%d\n\n", descripcion, alquiler.idAlquileres, apellido, alquiler.fecha.dia, alquiler.fecha.mes, alquiler.fecha.anio);
    return 0;
}
///--------------------------------------------------------------------------------------------------------------------------
///HARCODEO ALQUILERES
void hardcodearAlquileres(eAlquileres x[])
{
    int i;

    eAlquileres y[] =
    {
        {1, 1, 2, {9, 5, 2018}, 1},
        {2, 3, 3, {9, 5, 2018}, 1},
        {3, 3, 3, {6, 6, 2008}, 1},
        {4, 2, 2, {6, 3, 2015}, 1},
        {5, 2, 5, {30, 4, 2018}, 1},
        {6, 4, 1, {30, 4, 2018}, 1}
    };
    for(i=0; i<6; i++)
    {
        x[i]=y[i];
        generarNextId();
    }
}
