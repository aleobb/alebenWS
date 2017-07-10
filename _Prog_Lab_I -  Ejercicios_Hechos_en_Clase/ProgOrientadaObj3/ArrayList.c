#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funcAux.h"


// funciones privadas
//int resizeUp(ArrayList* pList);
//int expand(ArrayList* pList,int index);
//int contract(ArrayList* pList,int index);



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
    ArrayList* pList;
    ArrayList* returnAux = NULL;
    void* pElements;
    pList=(ArrayList *)malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            ///todas estas son las llamadas a los punteros de las funciones que se van cargando en el pList
            pList->size=0;
            pList->pElements=pElements;
            pList->reservedSize=AL_INITIAL_VALUE;
            pList->add=al_add;

            pList->get=al_get;


            returnAux = pList;
        }
        else
        {
            free(pList);
        }
    }

    return returnAux;
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


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if ( this != NULL && index >= 0 && index <= this->size )
        returnAux = this->pElements[index];

    return returnAux;
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
            void** pElementsAux = (void**) realloc( this->pElements, sizeof(void*) * ( this->reservedSize + AL_INCREMENT ) );
            if ( pElementsAux != NULL )
            {
                this->pElements = pElementsAux;
                this->reservedSize += AL_INCREMENT;
                returnAux = 0;
            }
        }
        else if ( this->size < this->reservedSize )
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
        al_add(this, this->pElements[ (this->size)-1 ]);  /// Con esta linea me aseguro de aumentar el espacio para la lista de elementos en caso de que size = reservedSize
        returnAux=0;
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
        this->size--;
    }
    return returnAux;
}


