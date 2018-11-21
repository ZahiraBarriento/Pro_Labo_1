#include <stdio.h>
#include <stdlib.h>
#define CANT 5
///Un vector o array es un conjunto de elementos
///del mismo tipo (enteros, flotantes, caracteres)
/// Tipo nombre[cantidad]
int main()
{
    int legajo [CANT], i, isEmpty[CANT];
    float salario [CANT];

    for (i=0; i<CANT; i++)
    {
        isEmpty[i]=1;
    }

    //do
    for(i=0; i<CANT; i++)
    {
        if(isEmpty[i]==1)
        {
            printf("Legajo:");
            scanf("%d",&legajo[i]);
            printf("Salario:");
            scanf("%f",&salario[i]);
            isEmpty[i]=0;
            break;
        }
    }

    return 0;
}
