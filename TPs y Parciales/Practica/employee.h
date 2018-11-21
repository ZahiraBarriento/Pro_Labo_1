#ifndef EMPLOYEE_INCLUDE_H
#define EMPLOYEE_INCLUDE_H
///EMPLEADOS

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;//autoincremental
    char apellido[51];//validar
    char nombre[51];//validar
    char sexo;//validar
    float salario; //mayor a cero
    eFecha fechaIngreso;
    int idSector;
    int isEmpty;

} eEmployee; //alta, baja, modificacion


typedef struct
{
    int id;//autoincremental
    char descripcion[51];
    int isEmpty;
} eSector;

int menuEmployee(eEmployee employee[], int len, eSector sectores[], int lenSec);

int initEmployees(eEmployee* list, int len);

void initSectores(eSector sectores[]);

int freeSpaceEmployee(eEmployee* list, int len);

int addEmployee(eEmployee* list, int len, eSector sectores[], int lenSec);

int findEmployeeById(eEmployee* list, int len,int legajo);

void mostrarEmpleado(eEmployee list, eSector sectores[], int lenSec);

int printEmployees(eEmployee* list, int len, eSector sectores[]);

int modifyEmployee(eEmployee* list, int len, eSector[], int lenSec);

int removeEmployee(eEmployee* list, int len, eSector sectores[], int lenSec);

int elegirSector(eSector sectores[], int len);

int sortEmployees(eEmployee* list, int len);

void harcodearEmpleados(eEmployee x[]);
#endif // EMPLOYEE_INCLUDE_H
