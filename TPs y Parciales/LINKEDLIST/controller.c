#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "employee.h"
#include "utn.h"

///CARGAR EL CSV EN FORMA DE TEXTO
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    FILE* pFile;
    pFile = fopen(path, "r");

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        parser_EmployeeFromText(pFile, pArrayListEmployee);
        retorno=0;
    }
    else
    {
        printf(" No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    return retorno;
}
///----------------------------------------------------------------------------------
///CARGAR EL CSV EN FORMA BINARIA
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=-1;

    pFile=fopen(path,"rb");

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        retorno=0;
    }

    else
    {
        printf(" No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }
    return retorno;
}
///------------------------------------------------------------------------------
///AGREGAR UN EMPLEADO
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char idStr[100];
    int auxId;
    char auxNombre[100];
    char auxHorasTrabajadas[100];
    char auxSueldo[100];
    int retorno =-1, found;

    if(pArrayListEmployee!=NULL)
    {
        Employee* this = employee_new();
        system("cls");
        printf("\n *** ALTA ***\n\n");

        //auxIdInt=getValidIntSuper(" Ingrese el ID: ", " Ingrese solo letras", 1, 2500);
        //getValidInt(" Ingrese el ID: ", &auxIdInt, 1, 2500);
        // itoa(auxIdInt, auxId, 10);
        // sprintf(auxId,"",auxIdInt);
        //puts(auxId);
        // sscanf(auxId,"%d",&auxIdInt);

        //getStringNumeros(" Ingrese el ID: ", idStr);

        getValidStringNumeros(" Ingrese ID: ", idStr, 1, 5);
        auxId = atoi(idStr);

        found=controller_findEmployee(pArrayListEmployee, auxId);

        if(found<0)
        {
            //getValidStringNumeros(" Ingrse el ID: ", auxId, 1, 4);

            getValidString("\n Ingrese el nombre: ", auxNombre, 3, 15);

            //getValidStringNumeros(" Ingrese las horas trabajadas: ", auxHorasTrabajadas, 1, 5);

            /*getValidInt(" Ingrese hs. trabajadas: ", &auxHorasTrabajadasInt, 1, 600);
            itoa(auxHorasTrabajadasInt, auxHorasTrabajadas, 10);*/

            getStringNumeros("\n Ingrese hs. trababajadas: ", auxHorasTrabajadas);

            getValidStringNumerosFlotantes("\n Ingrese el sueldo: ", auxSueldo, 1, 15);


            this = employee_newParametros(idStr, auxNombre, auxHorasTrabajadas, auxSueldo);


            ll_add(pArrayListEmployee, this);
            printf("\n Se agrego el nuevo empleado.\n");
            retorno =0;
        }

        else
        {
            printf("\n El ID ingresado ya existe.\n\n");
        }

    }

    else
    {
        printf("\n Datos ingresados no validos.\n\n");
    }

    return retorno;
}
///---------------------------------------------------------------------------
///MODIFICAR UN EMPLEADO
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1, opcion, idAux, id, horasTrabajadasAux, found;
    float sueldoAux;
    char respuesta;
    char nombreAux[100];
    Employee* this;


    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("\n *** MODIFICACIONES ***");

        printf("\n\n Ingrese ID del empleado: ");
        scanf("%d", &idAux);

        found=controller_findEmployee(pArrayListEmployee, idAux);


        if(found>=0)
        {
            /*printf("\n   ID\t\tNOMBRE\tHS. TRABAJADAS\t  SUELDO\n\n");
            printf(" %4d\t%12s\t\t%4d\t$ %.2f\n\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);*/

            respuesta = getCharPregunta("\n Desea modifacer al empleado? (s/n): ", "\n Error, ingreso un caracter no valido, reintente.");

            this = (Employee*)ll_get(pArrayListEmployee,found);

            if(respuesta=='s')
            {
                do
                {
                    system("cls");
                    printf("\n *** MENU MODIFICACIONES ***");
                    printf("\n\n 1. Modificar ID.");
                    printf("\n 2. Modificar nombre.");
                    printf("\n 3. Modificar Hs. Trabajadas.");
                    printf("\n 4. Modificar Sueldo.");
                    printf("\n 5. Salir.");
                    printf("\n\n Seleccione una opcion: ");
                    scanf("%d",&opcion);

                    switch(opcion)
                    {
                    case 1:
                        getValidInt("\n Ingrese el nuevo ID: ", &id, 1, 2500);

                        found=controller_findEmployee(pArrayListEmployee, id);

                        if(found>=0)
                        {
                            printf("\n El ID ingresado ya existe.\n\n");
                            system("pause");
                        }

                        else
                            employee_setId(this, id);

                        //employee_getId(this, id);
                        break;
                    case 2:
                        getValidString(" Ingrese un nuevo nombre: ", nombreAux, 3, 15);
                        employee_setNombre(this, nombreAux);
                        break;
                    case 3:
                        getValidInt(" Ingrese nueva hs. trabajadas: ", &horasTrabajadasAux, 1, 600);
                        employee_setHorasTrabajadas(this, horasTrabajadasAux);
                        break;
                    case 4:
                        getValidFloat(&sueldoAux, " Ingrese nuevo sueldo: ", 1, 99999999);
                        employee_setSueldo(this, sueldoAux);
                        break;
                    case 5:
                        printf("\n Saliendo...\n\n");
                        break;
                    default:
                        printf("\n ERROR. Ingrese una opcion del 1 al 5");
                        break;
                    }
                    //system("pause");
                }
                while(opcion!=5);
            }

            else
            {
                printf("\n Modificacion cancelada.\n\n");
            }
        }

        else
        {
            printf("\n El ID ingresado no existe.\n\n");
        }
    }


    return retorno;
}
///-----------------------------------------------------------------------
///ELIMINAR UN EMPLEADO
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0, found, id;
    char respuesta;
//    int len;

    if(pArrayListEmployee!=NULL)
    {
        //len=ll_len(pArrayListEmployee);

        system("cls");
        printf("\n *** BAJAS *** \n");

        printf("\n Ingrese el ID del empleado: ");
        scanf("%d",&id);

        found=controller_findEmployee(pArrayListEmployee, id);

        if(found>=0)
        {
            respuesta = getCharPregunta("\n Desea eliminar al empleado? (s/n): ", "\n Error, ingreso un caracter no valido, reintente.");

            if(respuesta=='s')
            {
                ll_remove(pArrayListEmployee,found);
                printf("\n Empleado dado de baja.\n\n");
                retorno=0;

            }

            else
            {
                printf("\n Baja cancelada.\n\n");
            }
        }

        else
        {
            printf("\n El ID ingresado no existe.\n\n");
        }
    }

    return retorno;
}


///-------------------------------------------------------------------------------------
///LISTAR EMPLEADOS
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1, len;
    Employee* this;
    int idAuxiliar;
    char nombreAuxiliar[100];
    int horasAuxiliar;
    float sueldoAuxiliar;

    len=ll_len(pArrayListEmployee);

    if(len>0)
    {
        system("cls");
        printf("\n\t   *** LISTA DE EMPLEADOS ***\n\n");
        printf("   ID\t\tNOMBRE\tHS. TRABAJADAS\t  SUELDO\n\n");

        for(int i=0; i<len; i++)
        {
            this = (Employee*) ll_get(pArrayListEmployee,i);
            employee_getId(this, &idAuxiliar);
            employee_getNombre(this,nombreAuxiliar);
            employee_getHorasTrabajadas(this,&horasAuxiliar);
            employee_getSueldo(this,&sueldoAuxiliar);

            printf(" %4d\t%12s\t\t%4d\t$ %.2f\n\n",idAuxiliar,nombreAuxiliar,horasAuxiliar,sueldoAuxiliar);
            retorno = 0;
        }
    }

    else
    {
        printf("\n No hay datos cargados.\n\n");
    }

    return retorno;

}
///------------------------------------------------------------------------------------
///ORDENAR EMPLEADO
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;

    do
    {
        system("cls");
        printf("\n *** ORDENAMIENTO ***\n\n");
        printf(" 1. Ordenar por ID.\n");
        printf(" 2. Ordenar por nombre.\n");
        printf(" 3. Ordenar por hs. trabajadas.\n");
        printf(" 4. Ordenar por sueldo.\n");
        printf(" 5. Salir.\n\n");
        printf(" Seleccione una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            ll_sort(pArrayListEmployee, employee_sortById, 0);
            printf("\n Se ha ordenado correctamente.\n\n");
            system("pause");
            break;
        case 2:
            ll_sort(pArrayListEmployee, employee_sortByName, 0);
            printf("\n Se ha ordenado correctamente.\n\n");
            system("pause");
            break;
        case 3:
            ll_sort(pArrayListEmployee, employee_sortByHsWorked, 0);
            printf("\n Se ha ordenado correctamente.\n\n");
            system("pause");
            break;
        case 4:
            ll_sort(pArrayListEmployee, employee_sortBySalary, 0);
            printf("\n Se ha ordenado correctamente.\n\n");
            system("pause");
            break;
        case 5:
            printf("\n Saliendo..\n\n");
            break;
        }
    }
    while(opcion!=5);

    return 1;
}
///------------------------------------------------------------------------
///GUARDAR EN FORMA DE TEXTO
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* this;
    int retorno = -1, len;

    pFile = fopen(path, "w");
    len=ll_len(pArrayListEmployee);

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
        //fprintf(pFile, "%d,%s,%d,%f\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        for(int i=0; i<len; i++)
        {
            this = (Employee*) ll_get(pArrayListEmployee, i);
            fprintf(pFile, "%d,%s,%d,%f\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        }
        printf("\n Datos guardados con exito.\n\n");
        retorno = 0;
    }

    fclose(pFile);
    return retorno;
}
///---------------------------------------------------------------------------------------
///GUARDAR EN FORMA BINARIA
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* this;

    int retorno = -1, len;

    pFile = fopen(path, "wb");

    len=ll_len(pArrayListEmployee);

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        //fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
        //fprintf(pFile, "%d,%s,%d,%f\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        for(int i=0; i<len; i++)
        {
            this = (Employee*) ll_get(pArrayListEmployee, i);
            fwrite(this, sizeof(Employee), 1, pFile);
            //fprintf(pFile, "%d,%s,%d,%f\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        }

        printf("\n Datos guardados con exito.\n\n");
        retorno = 0;
    }

    fclose(pFile);
    return retorno;
}
///---------------------------------------------------------------------------------------
///BUSCAR EMPLEADO
int controller_findEmployee(LinkedList* pArrayListEmployee, int id)
{
    Employee* this;
    int retorno=-1, len;

    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);

        for(int i=0; i<len; i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee,i);

            if(id == this->id)
            {
                printf("\n   ID\t\tNOMBRE\tHS. TRABAJADAS\t  SUELDO\n\n");
                printf(" %4d\t%12s\t\t%4d\t$ %.2f\n\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
                retorno=i;
                break;
            }
        }

        /*if(id != this->id)
        {
            printf("\n El ID ingresado no existe.\n\n");
        }*/
    }

    return retorno;
}
///-------------------------------------------------------------------------
///FILTRAR EMPLEADO
int controller_filter(LinkedList * pArrayListEmployee)
{
    LinkedList * listaEmpleadosFiltrados;

    int opcion, retorno=-1;

    do
    {
        system("cls");
        printf("\n *** FILTRAR EMPLEADOS *** \n");
        printf("\n 1. Filtrar por nombre.");
        printf("\n 2. Filtrar por horas trabajadas.");
        printf("\n 3. Filtrar por sueldo.");
        printf("\n 4. Salir.\n");
        printf("\n Seleccion una opcion: " );
        //fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            listaEmpleadosFiltrados=ll_filter(pArrayListEmployee, employee_filterByNombre);

            if(listaEmpleadosFiltrados != NULL)
            {
                controller_ListEmployee(listaEmpleadosFiltrados);
            }
            system("pause");
            //printf(" Lista filtrada por nombres.\n\n");
            break;
        case 2:
            listaEmpleadosFiltrados=ll_filter(pArrayListEmployee, employee_filterByHorasTrabajadas);

            if(listaEmpleadosFiltrados != NULL)
            {
                controller_ListEmployee(listaEmpleadosFiltrados);
            }
            system("pause");
            break;
        case 3:
            listaEmpleadosFiltrados=ll_filter(pArrayListEmployee, employee_filterBySueldo);

            if(listaEmpleadosFiltrados != NULL)
            {
                controller_ListEmployee(listaEmpleadosFiltrados);
            }
            system("pause");
            break;
        case 4:
            printf("\n Saliendo...\n\n");
            break;
        default:
            printf("\n Opcion incorrecta, selecciones una opcion del 1 al 4.\n\n");
            system("pause");
            break;
        }
       // system("pause");
    }
    while(opcion!=4);

    return retorno;
}

