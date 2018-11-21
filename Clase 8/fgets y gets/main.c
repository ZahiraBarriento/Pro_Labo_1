#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[20];
    char auxCad[100];

    printf("Ingrese nombre: ");
    fgets(nombre, 19, stdin); ///Pones la cantidad de caracteres para que el usuario no pueda desbordar el programa

  //  while( strlen(auxCad) > 19){
   //     printf("Error. Nombre demasiado largo. Reingrese nombre; "); //Con este es mas probable que se desborde el programa
  //      gets(auxCad);
  //  }

  //  strcpy(nombre, auxCad);

    printf("Usted se llama %s\n\n", nombre);


    return 0;
}
