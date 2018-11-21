#include <stdio.h>
#include <stdlib.h>
#define CANT 50 //PARA NO REPETIR 50 VECES PRINTF Y SCANF HAGO UNA VARIABLE GLOBAL

//ARRAY
//CARGA DE DATOS
int main ()
{
    int legajo [CANT];
    int salario [CANT];
    int contador;

    for(contador=0; contador<CANT; contador++)
    {
        printf("Legajo:");
        scanf("%d",&legajo[contador]);
        printf("Salario:");
        scanf("%d",&salario[contador]);
    }

    printf("Legajo\tSalario\n");

    for(contador=0; contador<CANT; contador++)
    {
        printf("Legajo:%d\tSalario:%.2f\n",legajo[contador],salario[contador]);
    }
}
