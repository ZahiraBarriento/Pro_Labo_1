#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec[5], *p;
    p=vec;

    for(int i=0; i<5; i++)
    {
        vec[i]=i+3;
    }

    for(int i=0; i<5; i++)//CADA VEZ QUE VUELVE INCREMENTA HASTA LLEGAR AL VALOR 5
    {
        *(p+i)=i+5;
    }
}
