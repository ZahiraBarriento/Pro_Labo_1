#include <stdio.h>
#include <stdlib.h>

int main()
{
    Dado adem�s, que un puntero es tambi�n una variable, es posible definir un puntero a un
    puntero. Supongamos que tenemos lo siguiente:

    int a;
    int *punteroInt;
    int **punteroPuntero;

    punteroInt = &a; // Obtenemos la posici�n de memoria
    punteroPuntero = &punteroInt; // Obtenemos la posici�n de memoria

    Y entonces, �De qu� formas podemos ahora acceder al valor de la variable 'a'?
    a (forma habitual)

    *punteroInt (a trav�s del puntero)
    **punteroPuntero (a trav�s del puntero a puntero)

    Esto es debido a que 'punteroPuntero' contiene la direcci�n de 'punteroInt', que contiene la
    direcci�n de 'a'.
    Este concepto de puntero a puntero podr�a extenderse a puntero a puntero a puntero, etc.,
    adem�s, existe el concepto de puntero a una funci�n, al cual nos referiremos m�s adelante.
}
