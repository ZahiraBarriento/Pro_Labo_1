#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

///NEW EMPLOYEE
Employee* employee_new()
{
    Employee* empleadoAux;

    empleadoAux = (Employee*) malloc(sizeof(Employee));

    return empleadoAux;
}
///-----------------------------------------------------------
///NEW EMPLOYEE PARAMETROS
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    int auxHorasTrabajadas;
    int auxId;
    float auxSueldo;

    Employee* this;

    this = employee_new();
    if(this != NULL)
    {
        auxId = atoi(idStr);
        employee_setId(this,auxId);

        auxHorasTrabajadas = atoi(horasTrabajadasStr);
        employee_setHorasTrabajadas(this,auxHorasTrabajadas);

        employee_setNombre(this,nombreStr);

        auxSueldo = atof(sueldoStr);
        employee_setSueldo(this, auxSueldo);

    }

    return this;
}
///---------------------------------------------------------
///SET ID
int employee_setId(Employee* this,int id)
{
    int retorno = 0;

    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno=1;
    }

    return retorno;
}
///GET ID
int employee_getId(Employee* this, int* id)
{
    int retorno= -1;

    if(this != NULL && id != NULL)
    {
        *id= this->id;
        retorno=0;
    }

    return retorno;
}
///---------------------------------------------------------
///SET NOMBRE
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;
    if(this != NULL && strlen(nombre) > 0)
    {
        strcpy(this->nombre, nombre);
        //strcpy(nombre, this->nombre);
        retorno=1;
    }
    return retorno;
}
///GET NOMBRE
int employee_getNombre(Employee* this, char* nombre)
{
    int retorno=-1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno=0;
    }

    return retorno;
}
///---------------------------------------------------------
///SET HORAS TRABAJADAS
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno=1;
    }
    return retorno;
}
///GET HORAS TRABAJADAS
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno= -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas= this->horasTrabajadas;
        retorno=0;
    }

    return retorno;
}
///----------------------------------------------------------
///SET SUELDO
int employee_setSueldo(Employee* this,float sueldo)
{
    int retorno=0;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno=1;
    }
    return retorno;
}
///GET SUELDO
int employee_getSueldo(Employee* this, float* sueldo)
{
    int retorno= -1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo= this->sueldo;
        retorno=0;
    }

    return retorno;
}
///--------------------------------------------------------
///ORDENAR POR ID
int employee_sortById(void* employeeA, void* employeeB)
{
    int retorno;

    Employee* empA;
    Employee* empB;

    if(employeeA != NULL && employeeB != NULL)
    {
        empA = (Employee*) employeeA;
        empB = (Employee*) employeeB;

        if(empA->id == empB->id)
        {
            retorno=0;
        }

         if(empA->id > empB->id)
        {
            retorno=-1;
        }

         if(empA->id < empB->id)
        {
            retorno=1;
        }
    }

    return retorno;
}
///---------------------------------------------------------
///ORDENAR POR NOMBRE
int employee_sortByName(void* employeeA, void* employeeB)
{
    int retorno=-1;

    Employee* empA;
    Employee* empB;

    if(employeeA != NULL && employeeB != NULL)
    {
        empA = (Employee*) employeeA;
        empB = (Employee*) employeeB;

        retorno= strcmp(empB->nombre, empA->nombre);
    }

    return retorno;
}
///-----------------------------------------------------------
///ORDENAR POR HS. TRABAJADAS
int employee_sortByHsWorked(void* employeeA, void* employeeB)
{
    int retorno;

    Employee* empA;
    Employee* empB;

    if(employeeA != NULL && employeeB != NULL)
    {
        empA = (Employee*) employeeA;
        empB = (Employee*) employeeB;

        if(empA->horasTrabajadas == empB->horasTrabajadas)
        {
            retorno=0;
        }

         if(empA->horasTrabajadas > empB->horasTrabajadas)
        {
            retorno=-1;
        }

         if(empA->horasTrabajadas < empB->horasTrabajadas)
        {
            retorno=1;
        }
    }

    return retorno;
}
///----------------------------------------------------------------
///ORDENAR POR SUELDO
int employee_sortBySalary(void* employeeA, void* employeeB)
{
    int retorno;

    Employee* empA;
    Employee* empB;

    if(employeeA != NULL && employeeB != NULL)
    {
        empA = (Employee*) employeeA;
        empB = (Employee*) employeeB;

        if(empA->sueldo == empB->sueldo)
        {
            retorno=0;
        }

         if(empA->sueldo > empB->sueldo)
        {
            retorno=-1;
        }

         if(empA->sueldo < empB->sueldo)
        {
            retorno=1;
        }
    }

    return retorno;
}
///---------------------------------------------------------------------
