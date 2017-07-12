#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funcAux.h"
//#include "Destinatarios.h"

// funciones privadas
int resizeUp(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);
int insertionSort(void** array, int size, int order, int (*pFunc)(void*,void*) );
int bubleSort2(void** array, int size, int order, int (*pFunc)(void*,void*) );
void swapElements(void* pElement1, void* pElement2);
int quickSort(void** array, int size, int order, int (*pFunc)(void*,void*) );


#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* pList = (ArrayList*) malloc( sizeof(ArrayList) );
    void* pElements;

    if( pList != NULL )
    {
        pElements = malloc( sizeof(void*)*AL_INITIAL_VALUE ); /// no hace falta castearlo porque malloc ya devuelve un puntero void
        if( pElements == NULL )
        {
            free(pList); /// Si no se pudo reservar espacio para el array dinamico de pElements libero de la memoria el espacio reservado para pList
            pList == NULL; /// luego le cargo el valor NULL que es el que devolverá esta funcion (al_newArrayList)
        }
        else
        {
            pList->pElements = pElements;
            pList->size = 0;
            pList->reservedSize = AL_INITIAL_VALUE;

        /// Todas estas son las llamadas a los punteros de las funciones que se van cargando en el pList:
            pList->add = al_add;
            pList->len = al_len;
            pList->set = al_set;
            pList->remove = al_remove;
            pList->clear = al_clear;
            pList->clone = al_clone;
            pList->get = al_get;
            pList->contains = al_contains;
            pList->push = al_push;
            pList->indexOf = al_indexOf;
            pList->removeDuplicate = al_removeDuplicate;
            pList->isEmpty = al_isEmpty;
            pList->pop = al_pop;
            pList->subListByIndexRange = al_subListByIndexRange;
            pList->subListByElementCompare = al_subListByElementCompare;
            pList->subListByListCompare = al_subListByListCompare;
            pList->listDuplicatesRemove = al_listDuplicatesRemove;
            pList->containsAll = al_containsAll;
            pList->deleteArrayList = al_deleteArrayList;
            pList->sort = al_sort;
        }
    }
    return pList;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
    int returnAux = -1;

    if ( this != NULL && pElement != NULL )
    {
        if ( resizeUp(this) == 0 )
        {
            this->pElements[ this->size ] = pElement;
            /// *( (this->pElements)+(this->size) ) = pElement;   esta linea es igual a la de arriba
            this->size++;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;

    if ( this!= NULL )
    {
        free(this);
        this = NULL;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;

    if ( this!= NULL )
        returnAux = this->size;

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if ( this != NULL && index >= 0 && index < this->size )
        returnAux = this->pElements[index];

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if ( this != NULL && pElement != NULL )
    {
        returnAux=0;
        for ( i=0 ; i < (this->size) ; i++ )
        {
            if (  this->get(this,i) == pElement )
            {
                returnAux = 1;
                break;
            }
        }
    }
    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;

    if ( this != NULL && pElement != NULL && index >= 0 && index < this->size )
    {
        returnAux = 0;
        this->pElements[index] = pElement;
    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this, int index)
{
    int returnAux = -1;

    if ( this!= NULL && index >= 0 && index < this->size )
        if ( contract(this, index) == 0 )
            returnAux = 0;

    return returnAux;
}


/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;
 // int i;
    if ( this!= NULL )
    {
     // NO HACE FALTA ESTO:
     // for ( i=(this->size) ; i < 0 ; i-- )
     //     contract(this, i);
        this->size = 0;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;
    if ( this != NULL && pElement != NULL && index >= 0 && index <= this->size )
    {
     // if ( this->size == 0)  No hace falta hacer esta evaluación y luego un al_add ya que expand() se encarga de eso
     //     al_add(this, pElement );
        if ( expand(this, index) == 0 )
            if ( al_set( this, index, pElement ) == 0 );
                returnAux=0;
    }
    return returnAux;
}


/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if ( this != NULL && pElement != NULL )
    {
        for ( i=0 ; i < (this->size) ; i++ )
            if (  al_get(this,i) == pElement )
            {
                returnAux = i;
                break;
            }
    }
    return returnAux;
}


/** \brief  Find if pList contains elements duplicated in pElement and removes them
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found duplicated elements
 *                  - ( 1) if this list contains at least one element and all the elements duplicated were removed
 *
 */
int al_removeDuplicate(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if ( this != NULL && pElement != NULL )
    {
        returnAux=0;
        for ( i=0 ; i < (this->size) ; i++ )
        {
            if ( this->indexOf(this, pElement) != i && this->get(this,i) == pElement ) /// Con la primer condición verifico que no esté comparando un elemento consigo mismo
            {
                returnAux = 1;
                contract(this, i);
            }
        }
    }
    return returnAux;
}


/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;

    if ( this != NULL )
    {
        returnAux = 1;
        if ( al_len(this) > 0 )
            returnAux = 0;
    }
    return returnAux;
}


/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if ( this!= NULL && index >= 0 && index < this->size )
    {
        returnAux = al_get(this, index);
        if ( al_remove(this, index) != 0 )
            returnAux = NULL;
     // contract(this, index); <= funciona también con esta línea en lugar de al_remove
    }
    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subListByIndexRange(ArrayList* this, int from, int to)
{
    ArrayList* returnAux = NULL;
    ArrayList* pListClone = al_newArrayList();
    int i;

    if ( this != NULL  &&  pListClone != NULL  &&  from <= to  &&  from >= 0  &&  to <= this->size )
    {
        for ( i = from ; i < to ; i++ )
            if ( al_add( pListClone, this->pElements[i] ) == -1 )
            {
                free(pListClone);
                pListClone = NULL;
                break;
            }
        returnAux = pListClone;
    }
    return returnAux ;
}


/** \brief Returns a new arrayList with a portion of pList that meets the condition.
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param void* pCompare Pointer to Element to compare with
 * \param int filter  [1] indicates EQUAL - [2] indicates DIFFERENT - [3] indicates HIGHER - [4] indicates LOWER
                    - [5] indicates HIGHER or EQUAL - [6] indicates LOWER  or EQUAL
 * \return int Return (NULL) if Error [pList or pFunc are NULL pointer or invalid filter]
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subListByElementCompare(ArrayList* this, int (*pFuncCompare)(void*,void*), int comparisonType, void* pCompare)
{
    ArrayList* pListClone = al_newArrayList();
    int i;

    if ( this != NULL  &&  pListClone != NULL  &&  pFuncCompare != NULL  &&  comparisonType > 0  &&  comparisonType < 7 )
    {
        for ( i = 0 ; i < this->size ; i++ )
        {
            if ( isComparisonTrue( pFuncCompare(this->pElements[i], pCompare) , comparisonType ) == 0 )
                if ( this->add( pListClone, this->pElements[i] ) == -1 )
                {
                    free(pListClone);
                    pListClone = NULL;
                    break;
                }
        }
    }
    else
        pListClone = NULL;
    return pListClone ;
}


/** \brief Returns a new arrayList with a portion of pList that meets the condition.
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param void* pCompare Pointer to Element to compare with
 * \param int filter  [1] indicates EQUAL - [2] indicates DIFFERENT - [3] indicates HIGHER - [4] indicates LOWER
                    - [5] indicates HIGHER or EQUAL - [6] indicates LOWER  or EQUAL
 * \return int Return (NULL) if Error [pList or pFunc are NULL pointer or invalid filter]
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subListByListCompare(ArrayList* this, int (*pFuncCompare)(void*,void*), int comparisonType, ArrayList* this2 )
{
    ArrayList* pListClone = al_newArrayList();
    int i, j;
    int flag = 0;

    if ( this != NULL  &&  pListClone != NULL  &&  pFuncCompare != NULL  &&  comparisonType > 0  &&  comparisonType < 7 && this2 != NULL)
    {
        //printf("\n size1: %d size2: %d", this->size, this2->size);
        for ( i = 0 ; i < this->size ; i++ )
        {
            for( j = 0 ; j < this2->size ; j++ )
            {
                //printf ("\n (i)Destinatario A: (%d)%s \t (j)Destinatario B: (%d)%s ", i, ((Destinatario*)this->get(this,i))->email, j, ((Destinatario*)this2->get(this2,j))->email );
                if ( isComparisonTrue( pFuncCompare( this->get(this,i), this2->get(this2,j) ), comparisonType ) == 0 )
                {
                    //printf ("\n Destinatario A: %s \t Destinatario B: %s ", ((Destinatario*)this->get(this,i))->email, ((Destinatario*)this2->get(this2,j))->email );
                    //printf ("Destinatario %s \n", ( (Destinatario*)this->get(this,i) )->email );
                    //printf ("Destinatario %s \n", ( (Destinatario*)this2->get(this2,j) )->email );
                    flag = 1;
                    /*if ( this == this2 && i == j )
                        flag = 0;
                    else*/
                        break;
                }
            }
            if ( flag == 0 )
            {
                //printf("\n flag %d", flag);
                al_add( pListClone, this->get(this,i) );
            }
            flag = 0;
        }
    }
    else
        pListClone = NULL;
    return pListClone;
}


/** \brief Returns a new arrayList with a portion of pList that meets the condition.
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer or invalid filter]
 *                  - ( 0) if Ok
 */
int al_listDuplicatesRemove(ArrayList* this, int (*pFuncCompare)(void*,void*) )
{
    int i, j;
    int retorno = -1;

    if ( this != NULL &&  pFuncCompare != NULL )
    {
        for ( i = 0 ; i < this->size ; i++ )
        {
            for( j = 0 ; j < this->size ; j++ )
            {
                if ( i != j && isComparisonTrue( pFuncCompare( this->get(this,i), this->get(this,j) ), 1) == 0 )
                {
                    this->remove(this,j);
                    j--;
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}


/** \brief compares two void elements parsed to the data type.
 * \param void* pElementA puntero del tipo void al elemento
 * \param void* pElementB puntero del tipo void al elemento
 * \param int dataType (1) int, (2) float, (3) char case sensitive, (4) char NOT case sensitive
 * \return int Return (-2) if pointer/s null or dataType not 1 to 4
 */
int compareElements ( void* pElementA, void* pElementB, int dataType )
{
    float retorno = -2;
    float auxFloat;

    if ( pElementA != NULL && pElementB != NULL )
    {
        switch (dataType)
        {
            case 1:
                retorno = *( (int*)pElementA ) - *( (int*)pElementB );
                break;
            case 2:
                auxFloat = *( (float*)pElementA ) - *( (float*)pElementB );
                retorno = 0;
                if ( auxFloat > 0 )
                    retorno = 1;
                else if ( auxFloat < 0 )
                    retorno = -1;
                break;
            case 3:
                retorno = stricmp ( (char*)pElementA, (char*)pElementB );
                break;
            case 4:
                retorno = strcmp ( (char*)pElementA, (char*)pElementB );
                break;
        }
    }
    return retorno;
}


/** \brief Returns if the comparison is true to the type looked for.
 * \param compareResult the value resulted of the comparison
 * \param type of comparison
 * \return int Return (-1) if no true and (0) if it is.
 */
int isComparisonTrue ( int compareResult, int comparisonType )
{
    int retorno = -1;

    switch (comparisonType)
    {
        case 1: /// Igual
            if ( compareResult == 0 )
                retorno = 0;
            break;
        case 2: /// Distinto
            if ( compareResult != 0 )
                retorno = 0;
            break;
        case 3: /// Mayor
            if ( compareResult > 0 )
                retorno = 0;
            break;
        case 4: /// Menor
            if ( compareResult < 0 )
                retorno = 0;
            break;
        case 5: /// Mayor o igual
            if ( compareResult >= 0 )
                retorno = 0;
            break;
        case 6: /// Menor o igual
            if ( compareResult <= 0 )
                retorno = 0;
            break;
    }
    return retorno;
}


/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this, ArrayList* this2)
{
    int returnAux = -1;
    int i;

    if ( this != NULL && this2 != NULL )
    {
        returnAux = 0;
        for ( i=0 ; i < (this2->size) ; i++ )
        {
            returnAux = 1;
            if ( al_contains(this, this2->pElements[i] ) != 1 )
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}


/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    if ( this != NULL  &&  this->size > 1  &&  order >= 0  &&  order <= 1  &&  pFunc != NULL )
    {
        if( order == 0 ) /// Esta línea es necesaria porque pFunc compara tomando como parametros -1(DOWN) o 1(UP)
            order = -1;
        insertionSort(this->pElements, this->size, order, pFunc);
        //bubleSort2(this->pElements, this->size, order, pFunc);
        //quickSort(this->pElements, this->size, order, pFunc);
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    ArrayList* pListClone = al_newArrayList();
    int i;

    if ( this != NULL && pListClone != NULL )
    {
        for ( i=0 ; i < (this->size) ; i++ )
            if( this->add( pListClone, this->get(this,i) ) == -1)
                break;
        returnAux = pListClone;
    }
    return returnAux;
}


/* (La función pFunc no la tengo que crear sino que ya está creada)
pFunc(void* pElement1 , void* pElement2)
{
    return strcmp( pElement1 , pElement2 );
} */


int insertionSort(void** array, int size, int order, int (*pFunc)(void*,void*) )
{
    int i,j;
    int retorno = -1;
    void* auxiliar;

    if ( array != NULL  &&  size > 1  &&  ( order == -1  ||  order == 1 )  &&  pFunc != NULL )
    {
        for(i = 1; i < size; i++)
        {
            auxiliar = array[i];
            j = i;
            while(j > 0 && order == pFunc(array[j - 1], auxiliar) )
            {
                array[j] = array[j - 1];
                j--;
            }
            array[j] = auxiliar;
        }
        retorno = 0;
    }
    return retorno;
}


int bubleSort2(void** array, int size, int order, int (*pFunc)(void*,void*) )
{
       int i;
       int retorno = -1;
       void* pElementAux;

       if ( array != NULL  &&  size > 1  &&  ( order == -1  ||  order == 1 )  &&  pFunc != NULL )
       {
           while(retorno)
           {
               retorno = 0;
               for ( i = 1 ; i < size ; i++ )
               {
                    if ( pFunc(array[i-1], array[i]) == order )
                    {
                        pElementAux = array[i];
                        array[i] = array[i-1];
                        array[i-1] = pElementAux;
                        retorno = -1;
                    }
               }
           }
       }
    return retorno;
}


void swapElements(void* pElement1, void* pElement2)
{
    void* pElementAux = pElement1;
    pElement1 = pElement2;
    pElement2 = pElementAux;
}


int quickSort(void** array, int size, int order, int (*pFunc)(void*,void*) )
{
    void* pivot;
    int i, j;
    int retorno = -1;
    void* pElementAux;

    if ( array != NULL  &&  size > 1  &&  ( order == -1  ||  order == 1 )  &&  pFunc != NULL )
    {
        if (size < 2)
            return retorno = 0;

        pivot = array[size/2];

        for ( (i=0, j=size-1) ;   ; (i++, j--) )
        {
            while ( order == pFunc(pivot, array[i]) ) //(array[i] < pivot)
                i++;
            while ( order == pFunc(array[j], pivot) ) //(array[j] > pivot)
                j--;

            if ( i >= j )
                break;

            pElementAux = array[i];
            array[i] =  array[j];
            array[j] =  pElementAux;
        }

        retorno = quickSort(array, i, order, pFunc);
        retorno = quickSort(array + i, size - i, order, pFunc);
    }
    return retorno;
}



/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    //void** pElementsAux;  <= podria declararlo aca pero lo declaro directamente donde lo uso

    if ( this != NULL )
    {
        if ( this->size == this->reservedSize )
        {
 //  ?????  void** pElementsAux = (void**) realloc( this->pElements, sizeof(void*) * ( this->reservedSize + AL_INCREMENT ) );
            void* pElementsAux = realloc( this->pElements, sizeof(void*) * ( this->reservedSize + AL_INCREMENT ) ); /// no hace falta castearlo porque realloc ya devuelve un puntero void
            if ( pElementsAux != NULL )
            {
                this->pElements = pElementsAux;
                this->reservedSize += AL_INCREMENT;
                returnAux = 0;
            }
        }
        else if ( this->size < this->reservedSize ) /// Esto podría ser solo un 'else' pero tiene que estar sí o sí porque tengo que cargar el valor 0 a returnAux indicando que hay lugar en memoria para seguir cargando elementos en el array
            returnAux = 0;
    }
    return returnAux;
}


/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this, int index)
{
    int returnAux = -1;
    int auxIndex;
    if ( this != NULL && index >= 0 && index <= this->size )
    {
        returnAux=0;
        this->add(this, this->get(this, this->size-1) );  /// Con esta linea me aseguro de aumentar el espacio para la lista de elementos en caso de que size = reservedSize
        for ( auxIndex=(this->size-1); auxIndex > index ; auxIndex-- )  /// Arranco desde (this->size-1) ya que uno lo hice con al_add
            this->pElements[auxIndex] = this->pElements[auxIndex-1];
    /// this->size++;  esta linea no hace falta ya que al_add se encargó de expandirlo.
    }
    return returnAux;
}


/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this, int index)
{
    int returnAux = -1;
    if ( this != NULL && index >= 0 && index < this->size )
    {
        returnAux=0;
        for ( ; index < (this->size)-1 ; index++ )
            this->pElements[index] = this->pElements[index+1];
        //  this->set(this, index, this->get(this,index+1) );
        this->size--;
    }
    return returnAux;
}

