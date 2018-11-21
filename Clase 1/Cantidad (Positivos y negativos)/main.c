#include <stdio.h>
#include <stdlib.h>

/*1. Solicite al usuario 10 números
2. Calcule cuántos son negativos y cuantos son positivos
3. Muestre por pantalla la cantidad de negativos y la cantidad de positivos*/

int main()
{
    int i;
    int negativo=0;
    int positivo=0;
    int numero;

    for(i=0; i<10; i++)
    {
        printf("Ingrese un numero:");
        scanf("%d",&numero);

        if(numero>=0)
        {
            positivo+=+1;
        }

        else
        {
            negativo+=+1;
        }

    }

    printf("\nLa cantidad de positivos es: %d\n", positivo);
    printf("La cantidad de negativos es: %d\n", negativo);


    return 0;
}

