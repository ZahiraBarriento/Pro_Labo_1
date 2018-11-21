#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero,suma,contador;
    float promedio;
    char respuesta='s';

    contador=0;

    do
    {
        contador++;
        printf("Ingrese un numero:");
        scanf("%d",&numero);
        suma=suma+numero;
        printf("Desea ingresar mas numeros?:");

    }while(respuesta=='s');

    promedio=(float) suma/contador;
    system("pause");
    printf("El promedio es:%f\n",promedio);

    return 0;
}
