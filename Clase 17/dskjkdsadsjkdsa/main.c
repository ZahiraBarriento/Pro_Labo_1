#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *pNumero;

    pNumero= (int*) malloc(sizeof(int));

    if(pNumero==NULL)
    {
        printf(" No se consigui memoria.");
        exit(1); //SALGO DEL PROGRAMA
    }

    *pNumero=15;
    printf("%d", *pNumero);

    free(pNumero); //ES PARA LIBERAR EL ESPACIO
}
