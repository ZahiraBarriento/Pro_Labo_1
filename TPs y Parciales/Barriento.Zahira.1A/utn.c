#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}
/*
char getNumeroAleatorio(int desde, int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}*/

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esNumericoFlotante(char str[])
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {

        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}
/*
int esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}*/

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);


    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidInt(char requestMessage[],int*input, int lowLimit, int hiLimit)
{
    //int retorno=-1;
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf (" Debe contener solo numeros enteros. \n");
            continue;
        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf (" El numero debe ser mayor que %d y menor que %d\n",lowLimit,hiLimit);
            continue;
        }
        //retorno=0;
        *input=auxInt;
        break;
    }
    return *input;
}

int getValidFloat(float* input,char requestMessage[],char errorMessage[], float lowLimit, float hiLimit, int attemps)
{
    char auxStr[256];
    float auxFloat;
    int retorno=-1;

    for(int i=0; i<attemps; i++)
    {
        if (!getStringNumerosFlotantes(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            attemps++;
            continue;

        }
        auxFloat = atof(auxStr);
        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf ("  El numero del debe ser mayor a %f y menor a %f\n",lowLimit,hiLimit);
            continue;

        }

        *input = auxFloat;
        retorno=0;
        break;
    }

    return retorno;


}

void cleanStdin(void)
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != '\n' && c != EOF);
}

int getValidString(char requestMessage[], char *input, int lowLimit, int highLimit)
{
    int retorno=-1;
    char auxInput[50];

    while(1)
    {

        if (!getStringLetras(requestMessage,auxInput))
        {
            printf (" Debe contener solo letras\n");
            continue;
        }

        if(strlen(auxInput)<lowLimit || strlen(auxInput) > highLimit)
        {
            printf (" Debe tener un minimo de %d caracteres y un maximo de %d\n",lowLimit,highLimit);
            continue;
        }

        retorno=0;
        strcpy(input,auxInput);
        break;
    }

    return retorno;
}

char getValidSexo(char mensaje[],char*input)
{
    int retorno=-1;
    char auxInput;
    while(1)
    {
        if (!getStringLetras(mensaje,&auxInput))
        {
            printf (" Debe contener solo letras. \n");
            continue;
        }
        if(auxInput!='f'&&auxInput!='m')
        {
            printf (" Debe introducir f o m. \n");
            continue;
        }
        retorno=0;
        strcpy(input,&auxInput);
        break;
    }

    return retorno;
}

void arreglarCadena(char lista[], int len)
{
    for(int i=0; i<len; i++)
    {
        if(lista[i]=='\n')
        {
            lista[i]='\0';
            break;
        }
        else if(lista[i]=='\0')
        {
            break;
        }
    }
}

void getStringConEspacio(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
    arreglarCadena(input, 51);
}

int getStringAlfaNumerico(char mensaje[],char input[])
{
    char aux[256];
    getStringConEspacio(mensaje,aux);
    if(esAlfaNumerico(aux) && aux[0]!='\0')
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidAlfaNumerico(char requestMessage[], char input[], int lowLimit, int highLimit)
{
    int retorno=-1;

    while(1)
    {
        if (!getStringAlfaNumerico(requestMessage,input))
        {
            printf (" Debe contener solo letras y numeros\n");
            continue;
        }

        if(strlen(input)<lowLimit || strlen(input) > highLimit)
        {
            printf (" Debe tener un minimo de %d caracteres y un maximo de %d\n",lowLimit,highLimit);
            continue;
        }
        break;
        retorno=0;
    }

    return retorno;
}



