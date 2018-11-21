#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[10]="CARLOS";

    strlwr(nombre);

    printf("%s",nombre);

    return 0;
}
