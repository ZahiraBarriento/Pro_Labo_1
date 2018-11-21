#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

///-----------------------------------------------------------------
///NEW LINKED LIST
///Crea un nuevo LinkedList en memoria de manera dinamica
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }

    return this;
}
///---------------------------------------------------------------
///LEN LINKED LIST
///Retorna la cantidad de elementos de la lista
int ll_len(LinkedList* this)
{
    int returnAux=-1;

    if(this != NULL)
    {
        returnAux=this->size;//retorna el largo de la lista si es que el this es distinto de NULL
    }

    return returnAux;
}
///-----------------------------------------------------
///GET NODE
///Obtiene un nodo de la lista
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    //int len= ll_len(this);

    if(this!=NULL)
    {
        if(nodeIndex>=0 && nodeIndex < ll_len(this))
        {
            pNode = this->pFirstNode;
        }

        for(int i=0; i<ll_len(this); i++)
        {
            if(pNode == NULL || i == nodeIndex)
            {
                break;//Si el nodo es igual que i o si la lista es igual a NULL deja de buscar
            }

            else
            {
                pNode = pNode->pNextNode;//Retorna el nodo a obtener
            }
        }
    }

    return pNode;
}
///-------------------------------------------------------------
///TEST GET NODE
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}
///-------------------------------------------------------------
/// ADD NODE
///Agrega y enlaza un nuevo nodo a la lista
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{

int returnAux = -1;

    Node* pNode = (Node*) calloc(1,sizeof(Node)); //Se crea el nuevo nodo a agregar
    Node* pNodeAux = NULL; //anterior
    Node* pNodeAux2 = NULL; //siguiente

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        pNode->pElement = pElement;

        if(pNode != NULL)//Se verifica si se pudo conseguir memoria
        {
            if(nodeIndex == 0)//Si el index es igual a cero es decir que es locomotora del tren
            {
                pNode->pNextNode = this->pFirstNode;//De ser asi el siguiente nodo es igual al primer nodo
                this->pFirstNode = pNode;//Y el primero nodo es el nuevo nodo creado
            }

            else if(nodeIndex > 0 && nodeIndex <= ll_len(this))
            {
                pNodeAux = getNode(this, nodeIndex-1);
                pNodeAux2 = pNodeAux->pNextNode;
                pNodeAux->pNextNode = pNode;
                pNode->pNextNode = pNodeAux2;
            }
        }

        this->size++;
        returnAux = 0;
    }
    return returnAux;

}
///---------------------------------------------------------------
///TEST ADD NODE
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}
///----------------------------------------------------------------
///LL ADD
///Agrega un elemento a la lista
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL) //pElement no entra porque puede ser igual a NULL
    {
        addNode(this,ll_len(this),pElement);//Si la lista no es NULL agrega un nodo
        returnAux=0;//Cambio el valor del retorno si es que esta todo Ok
    }

    return returnAux;
}
///--------------------------------------------------------
///LL GET
///Permite realizar el test de la funcion addNode la cual es privada
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;

    if(this != NULL && index>=0 && index<ll_len(this))
    {
        pNode = getNode(this, index); //Busco el nodo del index ingresado
        returnAux = pNode->pElement; //Retorno el elemento
    }

    return returnAux;
}
///------------------------------------------------------------
///LL SET
///Modifica un elemento de la lista
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;

    if(this != NULL && index>=0 && index<ll_len(this))
    {
        pNode = getNode(this, index); //Busco el nodo del index ingresado
        pNode->pElement = pElement; //Retorno el elemento si es igual que al de la lista
        returnAux=0;
    }

    return returnAux;
}
///--------------------------------------------------------
///LL REMOVE
///Elimina un elemento de la lista
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodeAux= NULL;
    Node* pNode= NULL;

    if(this != NULL && index>=0 && index < ll_len(this))
    {
        if(index == ll_len(this))//Si el nodo que se quiere eliminar esta al final el index es igual al largo
        {
            free(pNode); //elimino el nodo
        }

        else if(index == 0)//Si el nodo que se quiere eliminar es el de la locomotora el index tiene que ser igual a cero
        {
            pNode = getNode(this, index);
            this->pFirstNode = pNode->pNextNode;
            free(pNode);
        }

        else if(index !=0 && index != (ll_len(this))) //Si el nodo que se quiere eliminar no esta al principio ni al final es distinto al largo y distinto a 0
        {
            pNodeAux = getNode(this,(index-1));
            pNode = getNode(this,index);
            pNodeAux->pNextNode = pNode->pNextNode;
            free(pNode);
        }

        this->size--;//Se reduce la lista una vez eliminado el nodo
        returnAux=0;//Si esta todo Ok cambio el retorno a 0
    }

    return returnAux;
}
///--------------------------------------------------------------------
///LL CLEAR
///Elimina todos los elementos de la lista
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        //La variable i tiene que ser igual al tamaño de la lista ya que tiene que recorrer de atras para adelante
        //Una vez que valga cero deja de recorre, por eso la sunga condicion "i" tiene que ser mayor o igual a 0
        for(int i=ll_len(this); i>=0; i--)//Recorreo de atras para adelante porque si borro el primero pierdo la direccion del segundo nodo
        {
            ll_remove(this, i);//Llamo a la funcion de remover y elimino el nodo
            //free(this);
        }

        returnAux=0;//Si esta todo Ok cambio el valor del retorno
    }

    return returnAux;
}
///-------------------------------------------------
///DELETE LINKED LIST
///Elimina todos los elementos de la lista y la lista
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux=-1;

    if(this!=NULL)
    {
        //if(ll_len(this)>0) //En la funcion clear ya lo valida
        //{
        ll_clear(this);//Llamo a la funcion clear para eliminar
        free(this);
        returnAux=0;//Si esta todo Ok cambio el valor del retorno
        //}
    }

    return returnAux;
}
///----------------------------------------------------------
///LL INDEXOF
///Busca el indice de la primer ocurrencia del elemento pasado como parametro
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;

    if(this != NULL)
    {
        for(int i=0; i<ll_len(this); i++)
        {
            pNode=getNode(this, i);

            if(pNode->pElement == pElement)//Si el pElement ingresado es igual a alguno que este en la lista
            {
                returnAux = i/*pNode->pElement*/;//Retorno el indice
                break;
            }
        }
    }

    return returnAux;
}
///-------------------------------------------------------
///LL ISEMPTY
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(this->size > 0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}
///------------------------------------------------------
///LL PUSH
///Inserta un nuevo elemento en la lista en la posicion indicada
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index>=0 && index<=ll_len(this))
    {
        returnAux = addNode(this, index, pElement); //Llamo a la funcion add node para crear un nuevo nodo en la posicion indicada
    }

    return returnAux;
}
///-------------------------------------------------------
///LL POP
///Elimina el elemento de la posicion indicada y retorna su puntero
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index>=0 && index<=ll_len(this))
    {
        returnAux = ll_get(this, index);

        if(returnAux != NULL)
        {
            ll_remove(this, index); //Llamo a la funcion remove para eliminar el nodo de la posicion indicada
        }
    }

    return returnAux;
}
///--------------------------------------------------------
///LL CONTAINS
///Determina si la lista contiene o no el elemento pasado como parametro
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    //Node* pNode = NULL;
    int index;

    if(this != NULL /*&& pElement != NULL*/)//El pElement puede ser NULL
    {
        //returnAux=0;
        //for(int i=0; i<ll_len(this); i++)
        //pNode= getNode(this, i);
        index = ll_indexOf(this, pElement);

        if(index != -1/*pNode->pElement == pElement*/)
        {
            returnAux = 1;
        }

        else
        {
            returnAux = 0;
        }
    }
    return returnAux;
}
///--------------------------------------------------------------
///LL CONTAINS ALL
///Determina si todos los elementos de la lista (this2)
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* auxThis2 = NULL;
    int auxThis = NULL;

    if(this != NULL &&  this2 != NULL)
    {
        returnAux=1;

        for(int i=0; i<ll_len(this2); i++)//Recorro la lista 2
        {
            auxThis2 = ll_get(this2, i);
            auxThis=ll_contains(this, auxThis2);//Verifica si los elementos esta en la lista 1
            //returnAux=1;

            if(auxThis == 0)//Si todos los elementos estan en la lista es igual a 0
            {
                returnAux=0;
                break;
            }
        }
    }

    return returnAux;
}
///----------------------------------------------------------
///LL SUB LIST
///Crea y retorna una nueva lista con los elementos indicados
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pAuxiliar = NULL;

    if( (this!=NULL) && (from>=0) && (from<this->size) && (to>0) && (to<=this->size) && (from<to) )
    {
        cloneArray= ll_newLinkedList();//Creo un nuevo linkesList para clonar la lista

        if(cloneArray!=NULL)
        {
            for(int i=from; i<to ; i++)
            {
                pAuxiliar = ll_get(this, i);
                ll_add(cloneArray,pAuxiliar);
            }
        }
    }

    return cloneArray;
}
///---------------------------------------------------------
///LL CLONE
///Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
        cloneArray=ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}
///-----------------------------------------------------------------
///LL SORT
///Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    void* pElementA = NULL;
    void* pElementB = NULL;
    void* pAuxiliar = NULL;

    if(this != NULL && pFunc != NULL && (order == 1 || order ==0))
    {
        for(int i=0; i<ll_len(this)-1; i++)
        {
            pElementA = ll_get(this, i); //Obtengo el elemento de la posicion i

            for(int j=i+1; j<ll_len(this); j++)
            {
                pElementB = ll_get(this, j); //Obtengo el elemento de la posicion j

                if(!order)
                {
                    if(pFunc(pElementA, pElementB) == -1)
                    {
                        //Realizo metodo de borbujeo
                        pAuxiliar = pElementB;
                        pElementB = pElementA;
                        pElementA = pAuxiliar;
                    }
                }

                else
                {
                    if(pFunc(pElementA, pElementB) == 1)
                    {
                        //Realizo metodo de borbujeo
                        pAuxiliar = pElementA;
                        pElementA = pElementB;
                        pElementB = pAuxiliar;
                    }
                }

                //Modifico el pElement A y pElement B
                ll_set(this, i, pElementA);
                ll_set(this, j, pElementB);
            }
        }
        returnAux = 0;
    }
    return returnAux;
}
///---------------------------------------------------------------
///LL FILTER
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* filterList;

    if(this != NULL && pFunc != NULL)
    {
        filterList = ll_newLinkedList();

        if(filterList != NULL)
        {
            for(int i=0; i<this->size; i++)
            {
                if(pFunc(ll_get(this, i)))
                {
                    ll_add(filterList, ll_get(this, i));
                }
            }
        }
    }

    return filterList;
}
