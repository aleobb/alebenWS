

struct ArrayList{
    void** pElements; /// array de punteros pero dinamico. Hacemos crecer dinamicamente este array de punteros
    int size; /// cantidad utilizada
    int reservedSize; /// cantidad reservada
    /// cuando la cant utilizada y la reservada se igualan hay que hacer un realloc (para agrandar) y cuando se separan mucho también (pero para achicar)


/// Estos son punteros a funciones:
    int     (*add)();

    void*   (*get)();


}typedef ArrayList;


/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void);


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* pList,void* pElement);



/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* pList , int index);




/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* pList);


/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pList,int index);


/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pList,int index);


/** \brief Returns a new arrayList with a portion of pList that meets the condition.
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param void* pCompare Pointer to Element to compare with
 * \param int filter  [0] indicates EQUAL - [1] indicates HIGHER - [-1] indicates LOWER - [2] indicates DIFFERENT
 * \return int Return (NULL) if Error [pList or pFunc are NULL pointer or invalid filter]
 *                  - ( pointer to new array) if Ok
 */
//ArrayList* al_subListByElementCompare(ArrayList* this, int (*pFuncCompare)(void*,void*), int comparisonType, void* pCompare);


/** \brief Returns a new arrayList with a portion of pList that meets the condition.
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param void* pCompare Pointer to Element to compare with
 * \param int filter  [0] indicates EQUAL - [1] indicates HIGHER - [-1] indicates LOWER - [2] indicates DIFFERENT
 * \return int Return (NULL) if Error [pList or pFunc are NULL pointer or invalid filter]
 *                  - ( pointer to new array) if Ok
 */
//ArrayList* al_subListByListCompare(ArrayList* this, int (*pFuncCompare)(void*,void*), int comparisonType, ArrayList* this2 );






