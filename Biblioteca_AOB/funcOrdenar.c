#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcValidacion.h"
#include "funcMatematicas.h"
#include "funcOrdenar.h"

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
int compactArray(int array[], int size, int indice)
{
    for ( ;indice < size-1; indice++) /// se repite hasta size-1 porque el nuevo vector va a tener un dato menos desde indice
        array[indice] = array[indice+1]; /// quiero copiar en indice lo que tengo en la posicion siguiente (por ejemplo guardo en la posicion 2 lo que tengo en el indice 3)
    return size - 1; /// devuelvo el nuevo tamaño
}


/**
 * \brief expande un array haciendo un lugar desde la posición recibida como parametro indice.
 * \param array: es el vector a expandir.
 * \param size: es el tamaño del vector a compactar.
 * \param indice: es la posicion del vector que se va a agregar, y por tanto a partir de la cual se va a expandir.
 * \return devuelve el nuevo tamaño del array.
 */
int expandArray(int array[], int size, int indice)
{
    int i;
    for ( i=size-1 ; i >= indice; i--) /// se repite hasta size porque el nuevo vector va a tener un dato mas desde indice
        array[i+1] = array[i]; /// quiero copiar en indice lo que tengo en la posicion anterior, o sea guardo en la posicion 3 lo que tengo en el indice 2
    return size + 1; /// devuelvo el nuevo tamaño
}



void bubleSort(Empleado array[], int size)
{
    int i;
    int flagSwap = 1;
    Empleado aux;
    while(flagSwap)
    {
        flagSwap = 0;
        for(i = 0; i<size-1 ; i++)
        {
            if(strcmp(array[i].nombre,array[i+1].nombre) > 0)
            {
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                flagSwap = 1;
            }
        }
    }
}



/// todo el proceso empieza aca:  ****** NADIA SORT ******
void nadiaSort(int array[], int size,int arrayOrdenado[]) /// minimo-compactar repetidas veces hasta todo el tamaño del array
{
    int i;
    int indiceMinimo; ///variable auxiliar
    int sizeInicial = size;
    for(i=0;i<sizeInicial;i++)
    {
        indiceMinimo = calcularIndiceMinimo(array,size); ///busco en que posicion del array está guardado el minimo y lo guardo en la variable auxiliar
        arrayOrdenado[i] = array[indiceMinimo]; /// obtengo el valor guardado en el vector original correspondiente a ese indice minimo y lo guardo en la primer posicion del nuevo array (arrayOrdenado)
        size = compactar(array,size,indiceMinimo); ///al array original le elimino la posicion del minimo (lo compacto)
        /// vuelvo a empezar el ciclo
    }
}
