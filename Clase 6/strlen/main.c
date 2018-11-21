#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///STRLEN: SIRVE PARA CONTAR LA CANTIDAD DE CARACTERES

int main()
{
    char nombre[20]="JUAN"; // J U A N
    int cantidadLetras;

    cantidadLetras= strlen(nombre);//Muestra la cantidad de caracteres
    printf("%d\n\n", cantidadLetras);

    return 0;
}
