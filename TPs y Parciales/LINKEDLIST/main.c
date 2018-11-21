#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "LinkedList.h"

int main()
{
    int opcion;
    int flag1=0, flag2=0, flag3=0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        system("cls");
        printf("\n >>> ABM <<<\n\n");
        printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf(" 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
        printf(" 3. Alta de empleado.\n");
        printf(" 4. Modificar datos de empleado.\n");
        printf(" 5. Baja de empleado.\n");
        printf(" 6. Listar empleados.\n");
        printf(" 7. Ordenar empleados.\n");
        printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf(" 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
        printf(" 10. Filtrar empleados\n");
        printf(" 11. Salir.\n\n");
        printf(" Seleccione una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1://CARGAR DATOS MODO TEXTO
            controller_loadFromText("data.csv",listaEmpleados);
            flag1=1;
            break;
        case 2://CARGAR DATOS MODO BINARIO
            controller_loadFromBinary("data.bin", listaEmpleados);
            flag2=1;
            break;
        case 3://AGREGAR EMPLEADO
            controller_addEmployee(listaEmpleados);
            flag3=1;
            break;
        case 4://MODIFICAR EMPLEADO
            if(flag1==1 || flag2==1 || flag3==1)
                controller_editEmployee(listaEmpleados);
            else
                printf("\n No se ha ingresado ningun dato.\n\n");
            break;
        case 5://BAJA EMPLEADO
            if(flag1==1 || flag2==1 || flag3==1)
                controller_removeEmployee(listaEmpleados);
            else
                printf("\n No se ha ingresado ningun dato.\n\n");
            break;
        case 6://LISTAR EMPLEADO
            if(flag1==1 || flag2==1 || flag3==1)
                controller_ListEmployee(listaEmpleados);
            else
                printf("\n No se ha ingresado ningun dato.\n\n");
            break;
        case 7://ORDENAR EMPLEADO
            if(flag1==1 || flag2==1 || flag3==1)
                controller_sortEmployee(listaEmpleados);
            else
                printf("\n No se ha ingresado ningun dato.\n\n");
            break;
        case 8://GUARDAR DATOS MODO TEXTO
            if(flag1==1 || flag2==1 || flag3==1)
                controller_saveAsText("data.csv", listaEmpleados);
            else
                printf("\n No se ha ingresado ningun dato.\n\n");
            break;
        case 9://GUARDAR DATOS MODO BINARIO
            if(flag1==1 || flag2==1 || flag3==1)
                controller_saveAsBinary("data.bin", listaEmpleados);
            else
                printf("\n No se ha ingresado ningun dato.\n\n");
            break;
        case 10:
            controller_filter(listaEmpleados);
            break;
        case 11:
            printf(" Vuelva pronto.\n\n");
            break;
        default:
            printf(" Opcion incorrecta, ingrese una opcion del 1 al 10.\n\n");
            break;
        }
        system("pause");
    }
    while(opcion!=11);

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}

