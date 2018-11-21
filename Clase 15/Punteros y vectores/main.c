#include <stdio.h>
#include <stdlib.h>

int main()
{
    Existe una estrecha relaci�n entre los punteros y los vectores. Consideremos el siguiente
    fragmento de c�digo:

    char cadena[80];
    char *p;
    p=&cadena[0]; // equivalente a: p=cadena

    Este fragmento de c�digo pone en la variable puntero 'p' la direcci�n del primer elemento del
    array 'cadena'.
    Entonces, es posible acceder al valor de la quinta posici�n del array mediante:
    cadena[4] y *(p+4) (recu�rdese que los �ndices de los arrays empiezan en 0).
    Esta estrecha relaci�n entre los arrays y los punteros queda m�s evidente si se tiene en cuenta
    que el nombre del array sin �ndice es la direcci�n de comienzo del array, y si adem�s,
    se tiene en cuenta que un puntero puede indexarse como un array unidimensional, por lo cual,
    en el ejemplo anterior, podr�amos referenciar ese elemento como p[4].
    Es posible obtener la direcci�n de un elemento cualquiera del array de la siguiente forma:

    int arrayInt[80];
    int* p1;
    int* p2;
    p1 = &arrayInt[4];
    p2 = &arrayInt;

    Entonces, el puntero 'p1' contiene la direcci�n del quinto elemento del arrayInt y el puntero
    'p2' contiene la direcci�n del primer elemento del arrayInt.
    Hasta ahora hemos declarado variables puntero aisladas. Es posible, como con cualquier otro
    tipo de datos, definir un array de variables puntero. La declaraci�n para un array de punteros

    int de tama�o 10 es:
    int* a[10];

    Para asignar una direcci�n de una variable entera, llamada 'var', al tercer elemento del array
    de punteros, se escribe:

    x[2] = &var;

    Y para obtener el valor de var:

    *x[2];
}
