#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

struct
{
    char nombre[50];
    int edad;
    int estado;
    long int dni;

}typedef EPersona;

/**
 * @brief Obtiene el primer indice libre del array.
 * @param arrayPersonas el array se pasa como parametro.
 * @param sizeArray el tamaño del array se pasa como parametro.
 * @return devuelve el primer indice disponible (o -1 si no exite ninguno disponible)
 */
int obtenerEspacioLibre(EPersona arrayPersonas[], int sizeArray);



/**
 * @brief Obtiene el indice que coincide con el dni pasado por parametro.
 * @param arrayPersonas el array se pasa como parametro.
 * @param sizeArray el tamaño del array se pasa como parametro.
 * @param dni: a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni (o -1 si no lo encuentra)
 */
int buscarPorDni(EPersona arrayPersonas[], int sizeArray, long int dni);



/**
 * @brief Realiza el ingresdo de datos de una persona.
 * @param arrayPersonas el array se pasa como parametro.
 * @param indice se pasa como parametro el indice donde se van a guardar los datos de la persona.
 * @return devuelve 1 (EL_DATO_ES_VALIDO) si el ingreso se pudo realizar correctamente.
 */
int ingresoPersona(EPersona* arrayPersonas,int indice);


#endif // FUNCIONES_H_INCLUDED
