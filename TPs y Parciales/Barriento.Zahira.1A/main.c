#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "alquileres.h"
#include "juego.h"
#include "informes.h"
#define ELEMENTS_CLIENTE 200
#define ELEMENTS_JUEGOS 200
#define ELEMENTS_ALQUILER 200

int main()
{
    int opcion=0;

    //INICIALIZO, DECLARO y HARCODEO CLIENTES
    eCliente cliente[ELEMENTS_CLIENTE];
    inicializarCliente(cliente, ELEMENTS_CLIENTE);
    harcodearCliente(cliente);

    //INICIALIZO, DECLARO Y HARCODEO JUEGOS
    eJuegos juegos[ELEMENTS_JUEGOS];
    inicializarJuego(juegos, ELEMENTS_JUEGOS);
    hardcodearJuegos(juegos);

    //INICIALIZO, DECLARO Y HARCODEO ALQUILERES
    eAlquileres alquiler[ELEMENTS_ALQUILER];
    inicializarAlquileres(alquiler, ELEMENTS_ALQUILER);
    hardcodearAlquileres(alquiler);

    do
    {
        system("cls");
        printf("\n *** ABM *** \n\n");
        printf(" 1. JUEGOS\n");
        printf(" 2. CLIENTES\n");
        printf(" 3. ALTA ALQUILERES\n");
        printf(" 4. LISTAR\n");
        printf(" 5. SALIR\n");
        printf("\n Seleccione una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1://JUEGOS
            menuJuegos(juegos, ELEMENTS_CLIENTE);
            break;
        case 2://CLIENTES
            menuClientes(cliente, ELEMENTS_CLIENTE);
            break;
        case 3://ALQUILERES
            agregarAlquiler(alquiler, ELEMENTS_ALQUILER, cliente, ELEMENTS_CLIENTE, juegos, ELEMENTS_JUEGOS);
            break;
        case 4:
            menuListar(cliente, ELEMENTS_CLIENTE, juegos, ELEMENTS_JUEGOS, alquiler, ELEMENTS_ALQUILER);
            break;
        case 5:
            printf(" Saliendo..\n\n");
            break;
        default:
            printf(" Opcion incorrecta\n\n");
            break;
        }
    }while(opcion!=5);

    return 0;
}
