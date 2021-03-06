#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
int getInt(char mensaje[])
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
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}
/**
 * \brief Genera un n�mero aleatorio
 * \param desde N�mero aleatorio m�nimo
 * \param hasta N�mero aleatorio m�ximo
 * \param iniciar Indica si se trata del primer n�mero solicitado 1 indica que si
 * \return retorna el n�mero aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}


/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */

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

/**
 * \brief Verifica si el valor recibido es num�rico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */

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
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
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


/**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y n�meros, y 0 si no lo es
 *
 */
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


/**
 * \brief Verifica si el valor recibido contiene solo n�meros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
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
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
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

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
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


/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */

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


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input entero donde se cargara el dato ingresado
 * \param lowLimit entero minimo que podra ingresar
 * \param highLimit enteromaximo que podra ingresar
 * \return devuelve el dato ingresado validado
 *
 */
int getValidInt(char requestMessage[],int*input, int lowLimit, int hiLimit)
{
    //int retorno=-1;
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("Debe contener solo numeros enteros\n");
            continue;
        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero debe ser mayor que %d y menor que %d\n",lowLimit,hiLimit);
            continue;
        }
        //retorno=0;
        *input=auxInt;
        break;
    }
    return *input;
}
/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param input flotante donde se cargara el dato ingresado
 * \param lowLimit flotante minimo que podra ingresar
 * \param highLimit flotante maximo que podra ingresar
 * \return retorna el dato validado
 */

int getValidFloat(char requestMessage[],float* input, float lowLimit, float highLimit)
{
    //int retorno=-1;
    char auxStr[256];
    float auxFloat;

    while(1)
    {

        if (!getStringNumerosFlotantes(requestMessage,auxStr))
        {
            printf ("Debe contener solo numeros\n");
            continue;

        }
        auxFloat = atof(auxStr);
        if(auxFloat < lowLimit || auxFloat> highLimit)
        {
            printf ("El numero debe ser mayor que %.0f y menor que %.0f\n",lowLimit,highLimit);
            continue;
        }
        *input=auxFloat;
         //retorno=0;
        break;
    }

    return *input;

}

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * \brief Solicita un string y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param input Array donde se cargara el texto ingresado
 * \param lowLimit minimo de caracteres
 * \param highLimit maximo de caracteres
 * \return -1 para error y 0 para ok
 *
 */
int getValidString(char requestMessage[], char *input, int lowLimit, int highLimit)
{
    int retorno=-1;
    char auxInput[50];

    while(1)
    {

        if (!getStringLetras(requestMessage,auxInput))
        {
            printf ("Debe contener solo letras\n");
            continue;
        }

        if(strlen(auxInput)<lowLimit || strlen(auxInput) > highLimit)
        {
            printf ("Debe tener un m�nimo de %d caracteres y un maximo de %d\n",lowLimit,highLimit);
            continue;
        }

        retorno=0;
        strcpy(input,auxInput);
        break;
    }

    return retorno;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getValidSexo(char mensaje[],char*input)
{
    int retorno=-1;
    char auxInput;
    while(1)
    {
        if (!getStringLetras(mensaje,&auxInput))
        {
            printf ("Debe contener solo letras\n");
            continue;
        }
        if(auxInput!='f'&&auxInput!='m')
        {
            printf ("Debe introducir f o m\n");
            continue;
        }
        retorno=0;
        strcpy(input,&auxInput);
        break;
    }

    return retorno;
}

/*int getValidFecha(char requestMessage[],char*input)
{
    int retorno=-1;
    int auxInput;

    while(1)
    {
        getValidInt("Ingrese la fecha de ingreso\nAnio: ",&auxInput.anio,1900,2018);
        getValidInt("Ingrese la fecha de ingreso\nMes: ",&auxInput.mes,1,12);
        getValidInt("Ingrese la fecha de ingreso\nMes: ",&auxInput.dia,1,31);

        printf("Fecha: %d/%d/d",auxInput);

        *input=auxInput;
        retorno=0;
        break;
    }

    return retorno;
}*/

