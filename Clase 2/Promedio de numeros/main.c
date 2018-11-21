#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero,contador,sumaNumeros;
    float promedio;

    contador=0;
    sumaNumeros=0;
    promedio=0;

    while(contador<5)
    {
        contador++;
        printf("Ingrese un numero:");
        scanf("%d",&numero);
        sumaNumeros=numero+sumaNumeros;
    }

    promedio=(float)sumaNumeros/5;
    printf("El promedio es:%f\n",promedio);
    system("pause");
    return 0;
}
