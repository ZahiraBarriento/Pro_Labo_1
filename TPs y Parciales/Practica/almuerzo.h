#ifndef ALMUERZO_INCLUDE_H
#define ALMUERZO_INCLUDE_H
#include "menu.h"
#include "employee.h"

///ALMUERZOS
typedef struct{
    int dia;
    int mes;
    int anio;
} eFechaAlmuerzo;

typedef struct
{
    int id; //autoincremental
    int idComida; //Debe existir
    int lejagoEmpleado; //debe existir
    eFechaAlmuerzo fecha;
    int isEmpty;
} eAlmuerzo;


int initAlmuerzo(eAlmuerzo* list, int len);

int menuAlmuerzo(eEmployee employee[], eMenu menu[], eAlmuerzo almuerzo[], int EMPLOYEE_ELEMENTS, int MENU_ELEMENTS, int ALMUERZO_ELEMENTS);
int altaAlmuerzo(eEmployee arrayEmpleados[], eSector arraySectores[], eMenu arrayMenues[], eAlmuerzo arrayAlmuerzos[], int EMPLEADOS_CANT, int SECTORES_CANT, int MENU_CANT, int ALMUERZO_CANT);
#endif // ALMUERZO_INCLUDE_H
