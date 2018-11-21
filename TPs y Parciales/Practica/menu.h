#ifndef COMIDA_INCLUDE_H
#define COMIDA_INGLUDE_H
///MENU
typedef struct
{
    int idComida;//autoincremental
    char descripcion[51];//validar
    float importe;//validar mayor a cero
    int isEmpty;
} eMenu;

int menuMenues();

int initMenu(eMenu* list, int len);

int freeSpace(eMenu* list, int len);

int agregarMenu(eMenu* list, int len);

int buscarMenu(eMenu* list, int len,int id);

int eliminarMenu(eMenu* list, int len);

int modificarMenu(eMenu* list, int len);

int sortMenu(eMenu* list, int len);

int printMenu(eMenu* list, int len);
#endif // COMIDA_INCLUDE_H
