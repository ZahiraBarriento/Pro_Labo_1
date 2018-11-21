#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *pFile;
    int r;
    int a,b,c,d;
    pFile = fopen("data.csv","r");
    if(pFile == NULL)
    {
        printf("El archivo no existe");
        exit(EXIT_FAILURE);
    }
    do
    {
        r = fscanf(pFile,"%d,%d,%d,%d\n",&a,&b,&c,&d);
        if(r==4)
        {
            printf("Lei %d %d %d %d\n",a,b,c,d);
        }
        else
            break;
    }
    while(!feof(pFile));
    fclose(pFile);
    exit(EXIT_SUCCESS);
}
