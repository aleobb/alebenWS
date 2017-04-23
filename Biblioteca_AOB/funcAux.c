#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 4084
#define EL_DATO_ES_VALIDO 1
#define EL_DATO_NO_ES_VALIDO 0

void main()
{
    float dato[100]={1,50,-52,0,330};
    float valor;
    printf("el extremo es: %f",dato[maxMinArrayInt(dato,0,4,1)]);
}

/**
 * \brief halla el valor maximo o minimo de un vector de enteros
 * \param array es el vector que contiene los valores a analizar.
 * \param posInicio es la posicion del vector desde la que se va a analizar.
 * \param posFin es la posicion del vector hasta la que se va a analizar (inclusive).
 * \param maxMin parametro que indica si se van a hallar el maximo (1) o el minimo (-1).
 * \return devuelve la posicion en el array del valor maximo o minimo encontrado y si no la econtró devuelve -1.
 */
int maxMinArrayInt (int array[], int posInicio, int posFin, int maxMin)
{
    int extremo;
    int posicion = -1;
    int i;
    for ( i = posInicio ; i <= posFin ; i++ )
    {
        if( (array[i]*maxMin) > (extremo*maxMin) || i == posInicio )
        {
            extremo=array[i];
            posicion = i;
        }
    }
    return posicion;
}

/**
 * Idem maxMinArrayInt pero para un array de flotantes.
 */
float maxMinArrayFloat (float array[], int posInicio, int posFin, int maxMin)
{
    float extremo;
    int posicion = -1;
    int i;
    for ( i = posInicio ; i <= posFin ; i++ )
    {
        if( (array[i]*maxMin) > (extremo*maxMin) || i == posInicio )
        {
            extremo=array[i];
            posicion = i;
        }
    }
    return posicion;
}




