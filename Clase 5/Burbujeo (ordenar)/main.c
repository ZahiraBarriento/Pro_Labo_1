#include <stdio.h>
#include <stdlib.h>
#define CANT 5

int main()
{
    int i,CANT, legajo, aux, j;

    for(i=0; i<CANT-1; i++)
    {
        for(j=i+1; j<CANT; j++)
        {
            if(legajo[i]>legajo[j])
            {
                aux=legajo[i];
                legajo[i]=legajo[j];
                legajo[j]=aux;
            }
        }
    }
}
