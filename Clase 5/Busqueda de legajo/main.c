#include <stdio.h>
#include <stdlib.h>
#define CANT 999

int main()
{
    int legajo[CANT],legajoAux, i, flag=0;

    printf("Ingrese legajo a buscar:\n");
    scanf("%d",&legajoAux);

    for(i=0; i<CANT; i++)
    {
        if(legajoAux==legajo[i])
        {
            printf("Dato encontrado");
            flag=1;
            break;//para romper el for una vez que encuentra el dato
        }
        if (flag==0)
        {
            printf("No encontrado");
        }
        /*else
        {
           printf("No encontrado:");    ASI ESTA MAL
        }*/
    }
    return 0;
}
