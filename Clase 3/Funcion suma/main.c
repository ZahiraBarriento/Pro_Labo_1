#include <stdio.h>
#include <stdlib.h>
int suma(int,int);//PROTOTIIPO DECLARACION
//int suma(int op1,int op2) SE PUEDE PONER DE AMBAS MANERAS

int main()
{
    int num1,num2,resultado;
    printf("Ingrese el primer numero:");
    scanf("%d",&num1);
    printf("Ingrese el segundo numero:");
    scanf("%d",&num2);
    //SE DETIENE UNA FUNCION Y EMPIEZA A EJECUTARSE LA OTRA

    //LLAMAR FUNCION
    resultado= suma(num1,num2);
    system("cls");//LIMPIA PANTALLA, DE TODO LO ANTERIOR Y SOLO MUESTRA EL RESULTADO
    printf("Resultado: %d",resultado);
    return 0;
}

//CUERPO DE PROTOTIPO, FUNCION
int suma(int op1, int op2)
{
    int resultado;
    resultado=op1+op2;
    return resultado;
}
