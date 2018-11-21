#include <stdio.h>
#include <stdlib.h>
//int validarEdadLaboral(int valor);
int validarEdadLaboral(int valor, int lInf, int lSup);

int main()
{
    int edad;
    printf("Ingrese su edad: ");
    scanf("%d",&edad);
    /*
    if(validarEdadLaboral(edad))
    {
       printf("Esta habilitado para trabajar\n\n");
    }
    else
    {
       printf("Usted no esta habilitado para trabajar");
    }
    return 0;
    */
    while(!validarEdadLaboral(edad, 18, 65))
    {
        printf("\nEdad incorrecta. Ingrese su edad: ");
        scanf("%d",&edad);
    }

    printf("Edad valida\n\n");
    return 0;
}
//int validarEdadLaboral(int valor)
/*
OPCION 1
int esValido;
if(valor<18 || valor>65)
{
   esValido=0;
}
else
{
   esValido=0;
}
return esValido;
OPCION 2
int esValido=1;
if(valor<18 || valor>65)
{
   esValido=0;
}
return esValido;*/
/** \brief Valida si un entero esta dentro de un rango de valores
*
* \param valor a validar
* \param limite inferior del rango
* \param limite superior del rango
* \return 1 si el primer parametro esta dentro del rango. o si no lo esta
*
*/
int validarEdadLaboral(int valor, int lInf, int lSup)
{
    int esValido=1;

    if (valor<lInf || valor>lSup)
    {
        esValido=0;
    }

    return esValido;
}
