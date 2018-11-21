#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///STRCAT: SIRVE PARA CONCATENAR CANEDAS DE CARACTERES

int main()
{
    char nombre[20]="JUAN";
    char apellido[20]="THOMSON";

    strcat(nombre, " ");
    strcat(nombre, apellido);

    printf("%s", nombre);

    return 0;
}
