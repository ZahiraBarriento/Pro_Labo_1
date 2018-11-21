#include <stdio.h>
#include <stdlib.h>

int main()
{
    Existe una estrecha relación entre los punteros y los vectores. Consideremos el siguiente
    fragmento de código:

    char cadena[80];
    char *p;
    p=&cadena[0]; // equivalente a: p=cadena

    Este fragmento de código pone en la variable puntero 'p' la dirección del primer elemento del
    array 'cadena'.
    Entonces, es posible acceder al valor de la quinta posición del array mediante:
    cadena[4] y *(p+4) (recuérdese que los índices de los arrays empiezan en 0).
    Esta estrecha relación entre los arrays y los punteros queda más evidente si se tiene en cuenta
    que el nombre del array sin índice es la dirección de comienzo del array, y si además,
    se tiene en cuenta que un puntero puede indexarse como un array unidimensional, por lo cual,
    en el ejemplo anterior, podríamos referenciar ese elemento como p[4].
    Es posible obtener la dirección de un elemento cualquiera del array de la siguiente forma:

    int arrayInt[80];
    int* p1;
    int* p2;
    p1 = &arrayInt[4];
    p2 = &arrayInt;

    Entonces, el puntero 'p1' contiene la dirección del quinto elemento del arrayInt y el puntero
    'p2' contiene la dirección del primer elemento del arrayInt.
    Hasta ahora hemos declarado variables puntero aisladas. Es posible, como con cualquier otro
    tipo de datos, definir un array de variables puntero. La declaración para un array de punteros

    int de tamaño 10 es:
    int* a[10];

    Para asignar una dirección de una variable entera, llamada 'var', al tercer elemento del array
    de punteros, se escribe:

    x[2] = &var;

    Y para obtener el valor de var:

    *x[2];
}
