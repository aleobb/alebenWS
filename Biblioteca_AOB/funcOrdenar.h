#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcValidacion.h"
#include "funcMatematicas.h"
#include "funcOrdenar.h"
#include "funcEstructuras.h"

#define BUFFER 4084
#define EL_DATO_ES_VALIDO 1
#define EL_DATO_NO_ES_VALIDO 0


/**
 * \brief compacta un array eliminando el nro. de posición recibido como parametro indice.
 * \param array: es el vector a compactar.
 * \param size: es el tamaño del vector a compactar.
 * \param indice: es la posicion del vector que se va a eliminar, y por tanto a partir de la cual se va a compactar.
 * \return devuelve el nuevo tamaño del array.
 */
int compactArray(int array[], int size, int indice);



/**
 * \brief expande un array haciendo un lugar desde la posición recibida como parametro indice.
 * \param array: es el vector a expandir.
 * \param size: es el tamaño del vector a compactar.
 * \param indice: es la posicion del vector que se va a agregar, y por tanto a partir de la cual se va a expandir.
 * \return devuelve el nuevo tamaño del array.
 */
int expandArray(int array[], int size, int indice);



void bubleSort(Empleado array[], int size);



int comparar(Empleado empleadoA, Empleado empleadoB);


/// todo el proceso empieza aca:  ****** NADIA SORT ******
void nadiaSort(int array[], int size,int arrayOrdenado[]); /// minimo-compactar repetidas veces hasta todo el tamaño del array

