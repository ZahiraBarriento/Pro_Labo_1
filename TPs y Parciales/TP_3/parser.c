#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

///----------------------------------------------------------------------------
///ABRIR EN FORMA DE TEXTO
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee = employee_new();
    int r, i;
    char auxId[50], auxNombre[50], auxHorasTrabajadas[50], auxSueldo[50];

    r = fscanf(pFile, "%[^,],%[^,],%[^,],%s\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

    while(!feof(pFile))
    {
        r = fscanf(pFile, "%[^,],%[^,],%[^,],%s\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

        if(r == 4)
        {
            auxEmployee = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            ll_add(pArrayListEmployee,auxEmployee);
            i++;
        }
        else
        {
            printf("\n ERROR. No se ha leido correctamente.\n\n");
        }
    }

    printf("\n Empleados cargados correctamente (modo texto).\n\n");
    fclose(pFile);
    return 1;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee employee;
    int i = 0;

    fread(&employee, sizeof(Employee), 1, pFile);

    while(!feof(pFile))
    {
        Employee* this = employee_new();
        employee_setId(this,employee.id);
        employee_setHorasTrabajadas(this,employee.horasTrabajadas);
        employee_setNombre(this,employee.nombre);
        employee_setSueldo(this,employee.sueldo);

        i ++;
        ll_add(pArrayListEmployee, this);
        fread(&employee, sizeof(Employee), 1, pFile);
    }

    printf("\n Empleados cargados correctamente (modo binario).\n\n");
    return 1;
}


