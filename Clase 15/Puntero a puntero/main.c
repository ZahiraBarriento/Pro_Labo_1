#include <stdio.h>
#include <stdlib.h>

int main()
{
    Dado además, que un puntero es también una variable, es posible definir un puntero a un
    puntero. Supongamos que tenemos lo siguiente:

    int a;
    int *punteroInt;
    int **punteroPuntero;

    punteroInt = &a; // Obtenemos la posición de memoria
    punteroPuntero = &punteroInt; // Obtenemos la posición de memoria

    Y entonces, ¿De qué formas podemos ahora acceder al valor de la variable 'a'?
    a (forma habitual)

    *punteroInt (a través del puntero)
    **punteroPuntero (a través del puntero a puntero)

    Esto es debido a que 'punteroPuntero' contiene la dirección de 'punteroInt', que contiene la
    dirección de 'a'.
    Este concepto de puntero a puntero podría extenderse a puntero a puntero a puntero, etc.,
    además, existe el concepto de puntero a una función, al cual nos referiremos más adelante.
}
