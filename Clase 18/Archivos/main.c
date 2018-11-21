#include <stdio.h>
#include <stdlib.h>


void main (void)
{
    FILE *parch;
    if((parch=fopen("banco.dat","rb"))==NULL)///ABRE EL ARCHIVO DE FORMA DE LECTURA
    {
        printf("\nEl archivo no puede ser abierto");
        exit (1);
    }
    fclose(parch);
}

En el ejemplo se utiliza un if para detectar la correcta apertura del archivo. Se debe recordar
que cuando la función 'fopen()' retorna NULL significa que se ha fallado en abrir el archivo en
el modo solicitado.

void main (void)
{
    FILE *parch;
    ///Se abre en modo lectura
    if((parch=fopen("banco.dat","rb"))==NULL)
    {
        ///Si el modo anterior dio error el archivo
        if((parch=fopen("banco.dat","wb"))==NULL)
        {
            printf("\nEl archivo no puede ser abierto");
            exit (1);
        }
        ///no existe, por lo tanto se crea
        fclose(parch);
    }
}
