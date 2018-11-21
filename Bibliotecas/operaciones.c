
//SUMA

/** \brief Suma dos enteros
 *
 * \param Primer entero a sumar
 * \param Segundo entero a sumar
 * \return La suma de los parametros de entrada
 *
 */

 float sum(float num1, float num2)
{
    float result;
    result=num1+num2;
    return result;
}

//RESTA

/** \brief Resta dos enteros
 *
 * \param Entero minuendo
 * \param Entero sustraendo
 * \return La resta de los parametros de entrada
 *
 */

 float subtract(float num1, float num2)
{
    float result;
    result=num1-num2;
    return result;
}

//DIVISION

/** \brief Division de dos enteros
 *
 * \param Numero dividendo
 * \param Numero divisor
 * \return La division de los parametros de entrada
 *
 */


 float division(float num1, float num2)
{
    float result;

    if (num2==0)
    {

    }
    else
    {
        result=(float)num1/num2;
    }
    return result;
}

//MULTIPLICACION

/** \brief Multiplicacion de dos enteros
 *
 * \param Primer entero a multiplicar
 * \param Segundo entero a multiplicar
 * \return La multiplicacion de los parametros
 *
 */


float multiplication(float num1, float num2)
{
    float result;
    result=num1*num2;
    return result;
}

/** \brief Producto de todos los números enteros positivos desde 1 hasta n
 *
 * \param  Numero para hacer factorial
 * \return Factorial
 *
 */


int factorial_A (int num1)
{
    int i;
    long resultFactorialA=1;

    for (i=1;i<=num1;i++)
    {
        resultFactorialA=resultFactorialA*i;
    }

    return resultFactorialA;
}

/** \brief Producto de todos los números enteros positivos desde 1 hasta n
 *
 * \param  Numero para hacer factorial
 * \return Factorial
 *
 */

int factorial_B (int num2)
{
    int i;
    long resultFactorialB=1;

    for (i=1;i<=num2;i++)
    {
        resultFactorialB=resultFactorialB*i;
    }

    return resultFactorialB;
}


