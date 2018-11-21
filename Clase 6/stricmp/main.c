#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///STRICMP:COMPARA POR TABLA DE ASCII A DIFERENCIA
///DE STRCMP ESTE NO ES SENSIBLE A MAYUS. Y MINUS.

int main()
{
    char password[50]= "ABC";
    char password2[50]="abc";
    int validacion;

    validacion=stricmp(password,password2);

    ///-1 si la primera es mas chica
    /// 1 si la primera es mas grande
    /// 0 si son iguales


    if(validacion==0)
    {
        printf("entraste");
    }

    printf("%d",validacion);

    return validacion;
}
