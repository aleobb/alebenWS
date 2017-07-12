
struct ArrayList{
    void** pElements; /// array de punteros pero dinamico. Hacemos crecer dinamicamente este array de punteros
    int size; /// cantidad utilizada
    int reservedSize; /// cantidad reservada
    /// cuando la cant utilizada y la reservada se igualan hay que hacer un realloc (para agrandar) y cuando se separan mucho tambi�n (pero para achicar)

/// Estos son punteros a funciones:
    int     (*add)();
    int     (*deleteArrayList)();
    int     (*len)();
    void*   (*get)();
    int     (*contains)();
    int     (*set)();
    int     (*remove)();
    int     (*clear)();
    int     (*push)();
    int     (*indexOf)();
    int     (*removeDuplicate)();
    int     (*isEmpty)();
    void*   (*pop)();
    int     (*containsAll)();
    int     (*sort)();
    struct ArrayList* (* clone)();
    struct ArrayList* (*subListByIndexRange)();
    struct ArrayList* (*subListByElementCompare)();
    struct ArrayList* (*subListByListCompare)();
    int     (*listDuplicatesRemove)();

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


/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* pList);


/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* pList);


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* pList , int index);


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* pList, void* pElement);


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* pList, int index,void* pElement);


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* pList,int index);



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* pList);


/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* pList);


/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* pList, int index, void* pElement);



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* pList, void* pElement);


/** \brief  Find if pList contains elements duplicated in pElement and removes them
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found duplicated elements
 *                  - ( 1) if this list contains at least one element and all the elements duplicated were removed
 *
 */
int al_removeDuplicate(ArrayList* this, void* pElement);


/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* pList);



/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* pList,int index);



/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subListByIndexRange(ArrayList* pList,int from,int to);


/** \brief Returns a new arrayList with a portion of pList that meets the condition.
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param void* pCompare Pointer to Element to compare with
 * \param int filter  [0] indicates EQUAL - [1] indicates HIGHER - [-1] indicates LOWER - [2] indicates DIFFERENT
 * \return int Return (NULL) if Error [pList or pFunc are NULL pointer or invalid filter]
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subListByElementCompare(ArrayList* this, int (*pFuncCompare)(void*,void*), int comparisonType, void* pCompare);


/** \brief Returns a new arrayList with a portion of pList that meets the condition.
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param void* pCompare Pointer to Element to compare with
 * \param int filter  [0] indicates EQUAL - [1] indicates HIGHER - [-1] indicates LOWER - [2] indicates DIFFERENT
 * \return int Return (NULL) if Error [pList or pFunc are NULL pointer or invalid filter]
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subListByListCompare(ArrayList* this, int (*pFuncCompare)(void*,void*), int comparisonType, ArrayList* this2 );


/** \brief Returns a new arrayList with a portion of pList that meets the condition.
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer or invalid filter]
 *                  - ( 0) if Ok
 */
int al_listDuplicatesRemove(ArrayList* this, int (*pFuncCompare)(void*,void*) );


/** \brief compares two void elements parsed to the data type.
 * \param void* pElementA puntero del tipo void al elemento
 * \param void* pElementB puntero del tipo void al elemento
 * \param int dataType (1) int, (2) float, (3) char case sensitive, (4) char NOT case sensitive
 * \return int Return (-2) if pointer/s null or dataType not 1 to 4
 */
int compareElements ( void* pElementA, void* pElementB, int dataType );


/** \brief Returns if the comparison is true to the type looked for.
 * \param compareResult the value resulted of the comparison
 * \param type of comparison
 * \return int Return (-1) if no true and (0) if it is.
 */
int isComparisonTrue ( int compareResult, int comparisonType );


/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* pList,ArrayList* pList2);


/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* pList, int (*pFunc)(void* ,void*), int order);



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


// Private function
int resizeUp(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);
//___________________




