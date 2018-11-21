#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int numeros=0, i, maximo=INT_MIN, minimo=INT_MAX, totalNumeros=0;
    float promedio;

    for(i=0; i<5; i++)
    {
        printf("Ingrese un numero:");
        scanf("%d", &numeros);

        if(numeros<minimo)
        {
            minimo=numeros;
        }

        if(numeros>maximo)
        {
            maximo=numeros;
        }

        totalNumeros=(float)numeros+totalNumeros;

    }

    promedio=totalNumeros/5;
    printf("El numero maximo es: %d\n", maximo);
    printf("El numero minimo es: %d\n", minimo);
    printf("El promedio de los numeros ingresados es: %.2f\n", promedio);

   return 0;
}
