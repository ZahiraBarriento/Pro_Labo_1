#include <stdio.h>
#include <stdlib.h>

/*1. Limpie la pantalla
2. Solicite dos valores numéricos al usuario distintos de cero
3. Asigne a las variables numero1 y numero2 los valores obtenidos
4. Realice la resta de dichas variables
5. Muestre el resultado por pantalla
6. Muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor
7. Muestre por pantalla la leyenda "Resultado negativo" si es menor que cero*/

int main()
{
    int numeroUno;
    int numeroDos;
    int resultado;

    system("cls");

    printf("\nIngrese el primer numero:");
    scanf("%d",&numeroUno);

    printf("\nIngrese el segundo nuero numero: ");
	scanf("%d",&numeroDos);

    resultado=numeroUno-numeroDos;

    if (resultado>=0)
    {
        printf("El resultado es: %d. Es un numero positivo.", resultado);
    }

    else
    {
        printf("El resultado es: %d. Es un numero negativo.", resultado);
    }


}
