#include <stdio.h>
#include <stdlib.h>

float pedirNumero();
float calcularAreaCirculo(float radio);

int main()
{
    float area, numero;

    numero=pedirNumero();
    area=calcularAreaCirculo(numero);

    printf("El area del circulo es: %f", area);

    return 0;
}

/**
 * \brief Solicita un número y lo retorna
 * \return Número ingresado por el usuario
 *
 */
float pedirNumero()
{
    float numero;

    printf("Ingrese un numero:");
    scanf("%f",&numero);

    return numero;
}

/**
 * \brief Recibe el radio y calcula el área del círculo
 * \param Radio correspondiente al radio del círculo
 * \return El área del círculo
 *
 */
float calcularAreaCirculo(float radio)
{
    float resultado;

    resultado= 3.14*radio*radio;

    return resultado;
}




