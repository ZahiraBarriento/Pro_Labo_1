#include <stdio.h>
#include <stdlib.h>
struct persona
{
    char nombre[50];
    int edad;
};

int main()
{
    int seguirCargando;
    int i;
    int auxNuevaLogitud;
    int logitudPersonas = 1; ///SE INICIALIZA EL UNO O SE VA A PISAR EL PRIMER DATO CARGADO
    struct persona* pArrayPersona;
    struct persona* pAuxPersona;
    /// Creamos el array de personas
    pArrayPersona = malloc(sizeof(struct persona));
    if (pArrayPersona == NULL)
    {
        printf("\nNo hay lugar en memoria\n");
        exit(0);
    }
    while(1)
    {
        printf("\nIngrese nombre: ");
        scanf("%s",(pArrayPersona+logitudPersonas-1)->nombre);
        printf("\nIngrese edad: ");
        scanf("%d",&((pArrayPersona+logitudPersonas-1)->edad)); ///SE RESTA UNO PARA QUE VALGA 0
        printf("\nSi desea cargar otra persona ingrese (1): ");
        scanf("%d",&seguirCargando);
        if(seguirCargando == 1)
        {
        /// Calculamos el nuevo tama�o del array
            logitudPersonas++; ///Incremento el contador de personas
            auxNuevaLogitud = sizeof(struct persona) * logitudPersonas;
            /// Redimencionamos la lista
            pAuxPersona = realloc( pArrayPersona, auxNuevaLogitud);
            if (pAuxPersona == NULL)
            {
                printf("\nNo hay lugar en memoria\n");
                break;
            }
            pArrayPersona = pAuxPersona;
            //logitudPersonas++; ///Incremento el contador de personas
        }
        else
        {
            break;
        }
    }

    for(i = 0; i < logitudPersonas; i++)
    {
        printf("\nNombre: %s - ",(pArrayPersona+i)->nombre);
        printf("Edad: %d",(pArrayPersona+i)->edad);
    }
    free(pArrayPersona); /// Liberamos la memoria
    return 0;
}