#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "juego.h"
#include "cliente.h"
#include "alquileres.h"

int menuListar(eCliente cliente[], int lenCli, eJuegos juego[], int lenJue, eAlquileres alquiler[], int lenAl);

int totalImporte(eAlquileres* alquileres, int lenAl, eJuegos* juegos, int lenJue);

float promedioJuegos(eAlquileres* alquileres, int lenAl, eJuegos* juegos, int lenJue);

void juegosQueNoSuperanPromedio(eAlquileres* alquileres, int lenAl, eJuegos* juegos,int lenJue, float promedio);
void bubbleSort (eJuegos* juegos, int len);
void insertion(eCliente cliente[],int len);

void juegosPorFecha(eAlquileres *alquiler, int lenAl, eJuegos *juegos, int lenJueg);
void clientesPorFecha(eAlquileres *alquiler, int lenAl, eJuegos *juegos, int lenJueg, eCliente *cliente, int lenCli);

void listarClienteXJuego(eAlquileres* alquileres, int lenAl, eJuegos* juegos, int lenJue, eCliente* cliente, int lenCli);
void listarJuegoXCliente(eAlquileres* alquileres, int lenAl, eJuegos* juegos, int lenJue, eCliente* cliente, int lenCli);

void juegosMenosAlquilados(eAlquileres* alquieres, int lenAl, eJuegos* juegos, int lenJue);

void clienteMasAlquileres(eAlquileres* alquileres, int lenAl, eCliente* cliente,int lenCli);



