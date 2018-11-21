#include <stdio.h>
#include <stdlib.h>

/*1. Limpie la pantalla
2. Asigne a las variables numero1 y numero2 los valores obtenidos
3. Realice la resta de dichas variables
4. Muestre el resultado por pantalla*/

int main()
{

	int numeroUno;
	int numeroDos;
	int resultado;

	system("cls");

	printf("\nIngrese el primer numero: ");
	scanf("%d",&numeroUno);

	printf("\nIngrese el segundo nuero numero: ");
	scanf("%d",&numeroDos);

	resultado=numeroUno-numeroDos;

	printf("\nEl resultado de la resta de ambos numeros es %d\n", resultado);

	return 0;
}

