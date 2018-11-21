#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    float sueldo;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];
} eSector;

typedef struct
{
    int id;
    char descripcio[31];
    int isEmpty;
} eMenu;

typedef struct
{
    int idEmpleado;
    int idMenu;
    int isEmpty;
} eEmpleadoMenu;

/// LA PRIMERA Y LA TERCERA TIENE QUE SER UNA DE LAS ESTRCUTURAS SIMPLESY LA DEL MEDIO TIENE QUE SER LA QUE UNE A LAS DOS
///4 es igual a la cantidad de empleados por la cantidad del menu

///LO QUE ESTO HACE ES RECORRER EL MENU

int main()
{
    eEmpleadoMenu empMenu;
    eMenu menu;

    for(int i=0; i<2; i++) ///eEmpleado
    {
        for(int j=0; j<4; j++) ///eEmpleadomenu
        {
            if(empMenu[j].idEmpleado == eEmpleado[i].id)
            {
                for(int k=0; k<2; k++) ///eMenu
                {
                    if(menu[k].id == empMenu[j].idMenu)
                }
            }
        }
    }
}
