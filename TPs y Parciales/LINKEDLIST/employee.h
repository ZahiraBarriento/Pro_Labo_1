
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();///NO SE PARA QUE SIRVE ESTA FUNCION

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);

int employee_sortById(void* employeeA, void* employeeB);
int employee_sortByName(void* employeeA, void* employeeB);
int employee_sortByHsWorked(void* employeeA, void* employeeB);
int employee_sortBySalary(void* employeeA, void* employeeB);

int employee_filterByNombre(void* auxEmpleado);
int employee_filterByHorasTrabajadas(void* auxEmpleado);
int employee_filterBySueldo(void* auxEmpleado);

#endif // employee_H_INCLUDED
