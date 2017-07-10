
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESTINOS_SIZE 10
#define VIAJEROS_SIZE 10

#define FALSE 0
#define TRUE 1

void bubbleSort2(int* array, int size)
{
    int i, aux;
    int salir = 1 ;

    while ( salir )
    {
        salir = 0;
        for ( i = 1 ; i < size; i++)
            if ( array[i] < array [i-1] )
            {
                aux = array[i];
                array[i] = array[i-1];
                array[i-1] = aux;
                salir = 1;
            }
    }
}


void quickSort(int* array, int size)
{
    int i, j, pivot, aux;

    if (size < 2)
        return;

    pivot = array[size/2];

    for ( i=0 , j=size-1 ; ; i++, j--)
    {
        while ( array[i] < pivot )
            i++;

        while ( array[j] > pivot )
            j--;

        if ( i >= j )
            break;

        aux = array [j];
        array[j] = array[i];
        array[i] = aux;

    }
    quickSort(array,i);
    quickSort(array+i,size-i);
}
