#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///STRCMP:COMPARA POR TABLA DE ASCII

int main()
{
    char password[50]= "ABC";
    char password2[50]="abc";
    int validacion;

    validacion=strcmp(password,password2);

    ///-1 si la primera es mas chica
    /// 1 si la primera es mas grande
    /// 0 si son iguales


    if(validacion==0)
    {
        printf("entraste");
    }

    printf("%d",validacion);

    return 0;
}
