#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcionesAuxiliares.h"
#include "funciones.h"

#define EL_DATO_ES_VALIDO 1
#define EL_DATO_NO_ES_VALIDO 0
#define QTYPERSONA 20

/**
 * @brief Obtiene el primer indice libre del array.
 * @param arrayPersonas el array se pasa como parametro.
 * @param sizeArray el tamaño del array se pasa como parametro.
 * @return devuelve el primer indice disponible (o -1 si no exite ninguno disponible)
 */
int obtenerEspacioLibre(EPersona arrayPersonas[], int sizeArray)
{
    int i;
    for (i=0; i<sizeArray; i++)
    {
        if (arrayPersonas[i].estado==-1);
            return i;
    }
    return -1;
}


/**
 * @brief Obtiene el indice que coincide con el dni pasado por parametro.
 * @param arrayPersonas el array se pasa como parametro.
 * @param sizeArray el tamaño del array se pasa como parametro.
 * @param dni: a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni (o -1 si no lo encuentra)
 */
int buscarPorDni(EPersona arrayPersonas[], int sizeArray, long int dni)
{
    int i;
    for (i=0; i<sizeArray; i++)
        if ( arrayPersonas[i].dni == dni)
            return i;
    return -1;
}


/**
 * @brief Realiza el ingresdo de datos de una persona.
 * @param arrayPersonas el array se pasa como parametro.
 * @param indice se pasa como parametro el indice donde se van a guardar los datos de la persona.
 * @return devuelve 1 (EL_DATO_ES_VALIDO) si el ingreso se pudo realizar correctamente.
 */
int ingresoPersona(EPersona* arrayPersonas,int indice)
{
    int noDuplicado=0;
    char salir='n';
    char arrayCharsAdmitidos[2]=" '";
    EPersona arrayAuxiliar[1];

    while (salir!='s' || salir!='S');
    {
        getLongInt(&arrayAuxiliar[0].dni, "\n Ingrese el DNI de la persona (sin puntos): ", "\n El dato ingresado es invalido!\
            \n El DNI debe ser un numero positvo entre 1 y 99.999.999",1,1,1,1,99999999);
        noDuplicado=buscarPorDni(arrayPersonas,1,arrayAuxiliar[0].dni);
        if (noDuplicado>=0)
        {
            getType("\n Ingrese el nombre de la persona: ", "\n El dato ingresado es invalido!\
                \n Solo se adminten letras, espacios y el caracter [']",1,1,arrayCharsAdmitidos,50,*arrayAuxiliar[0].nombre);
            getInt(&arrayAuxiliar[0].edad, "\n Ingrese la edad de la persona: ", "\n El dato ingresado es invalido!\
                \n La edad debe ser un numero positvo entre 0 y 150",1,1,0,1,150);
            arrayAuxiliar[0].estado=1;
            arrayPersonas[indice]=arrayAuxiliar[0];
            return EL_DATO_ES_VALIDO;
        }
        getString("\n El nro. de DNI ya se encuentra ingresado! \
            \n Ingrese 'S' para salir de la carga de datos o cualquier otra tecla para continuar.",salir);
    }
    return EL_DATO_NO_ES_VALIDO;
}



/**
 * @brief Realiza la inicializacion del arrayPersonas ingresando el valor -1 en el campo estado.
 * @param arrayPersonas el array se pasa como parametro.
 * @param sizeArray el tamaño del array se pasa como parametro.
 * @return no devuelve nada.
 */
void initArray(EPersona arrayPersonas[],int sizeArray)
{
    int i;
    for (i=0; i<sizeArray; i++)
        arrayPersonas[i].estado=-1;
}


