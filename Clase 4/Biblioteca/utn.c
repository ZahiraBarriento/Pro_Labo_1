#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * \brief Solicita un caracter al usuario y lo valida
 * \param input Se carga el caracter ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \return Si obtuvo el caracter [0] si no [-1]
 *
 */
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    char aux;

    printf("%s\n",message);
    fflush(stdin);
    scanf("%c",&aux);

    if(aux<lowLimit || aux>hiLimit)
    {
        printf("%s\n",eMessage);
        return -1;
    }

    *input=aux;

    return 0;
}

/**
 * \brief Solicita una cadena de caracteres al usuario y la valida
 * \param input Se carga el string ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Longitud mínima de la cadena
 * \param hiLimit Longitud máxima de la cadena
 * \return Si obtuvo la cadena [0] si no [-1]
 *
 */
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char aux[hiLimit];

    printf("%s\n",message);
    fflush(stdin);
    fgets(aux, hiLimit, stdin);

    if(strlen(aux)<lowLimit || strlen(aux)-1>hiLimit)
    {
        printf("%s\n", eMessage);
        return -1;
    }

    else
    {
        strcpy(input, aux);
        return 0;
    }

}

/**
 * \brief Solicita un número al usuario y lo valida
 * \param input Se carga el numero ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \return Si obtuvo el numero [0] si no [-1]
 *
 */

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int aux;

    printf("%s\n",message);
    scanf("%d",&aux);

    if(aux<lowLimit || aux>hiLimit)
    {
        printf("%s\n",eMessage);
        return -1;
    }

    *input=aux;

    return 0;
}

/**
 * \brief Solicita un número al usuario y lo valida
 * \param input Se carga el numero ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \return Si obtuvo el numero [0] si no [-1]
 *
 */

int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    float aux;

    printf("%s\n",message);
    scanf("%f",&aux);

    if(aux<lowLimit || aux>hiLimit)
    {
        printf("%s\n",eMessage);
        return -1;
    }

    *input=aux;

    return 0;
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat_1(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt_1(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar_1(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int soloNumeros(char str[])
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

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */

int soloLetras(char str[])
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


