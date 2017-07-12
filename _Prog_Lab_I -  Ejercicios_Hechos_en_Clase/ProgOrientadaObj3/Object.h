#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int type;
}Object;

void bubbleSort2(int* array, int size)
{
    int i, aux;
    int salir = 1;


    while ( salir )
    {
        salir = 0;
        for ( i=1; i<size ; i++)
        {
            if ( array[i] < aux[i-1] )
            {
                aux = array[i];
                array[i] = array[i-1];
                array[i-1] = aux;
                salir = 1;
            }
        }
    }

}


void quickSort(int* array, int size)
{
    int i, j, aux;

    int pivot = array [size/2];

    if (size<=2)
        return;

    for ( i=0,j=size-1 ; ; i++, i-- )
    {
        while ( array[i] < pivot) i++;

        while ( array[j] > pivot) i++;

        if (i>=j) break;

        aux = array[i];
        array[i] = array[j];
        array[j] = aux;

    }


    quickSort(array,i);
    quickSort(array+i,size-i);
}
