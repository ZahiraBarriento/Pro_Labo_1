#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Biblioteca de los string

///STRING: ES UNA CADENA DE CARACTERES
///STRCPY: ESTE COMANDO SIRVE PARA COPIAR UN STRING A OTRA VARIABLE Y CONCATENAR
///"strcpy=(variable donde se va a copiar, variable a copiar)

int main()
{
    char nombre[20]= {"Ana"};
    char apellido[20] = {"Perez"};
    char nombreCompleto[40];//Se pone la suma de ambas variables

    strcpy(nombreCompleto, nombre);//Le asigno a nombreCompleto el nombre "ana"
    strcat(nombreCompleto, " ");//Debo agrega un espacio para que no salgo todo junto
    strcat(nombreCompleto, apellido);//Agrego el apellido
    printf("%s\n", nombreCompleto);//Lo imprimo

    return 0;
}
