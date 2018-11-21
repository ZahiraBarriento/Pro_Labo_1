#include <stdio.h>
#include <stdlib.h>
#include "ValidadEdad.h"

int main()
{
    int edad;
    printf("Ingrese su edad: ");
    scanf("%d",&edad);

    while(!validarEdadLaboral(edad,18, 65))
    {
        printf("\nEdad incorrecta. Ingrese su edad: ");
        scanf("%d",&edad);
    }

    printf("Edad valida\n\n");
    return 0;
}
