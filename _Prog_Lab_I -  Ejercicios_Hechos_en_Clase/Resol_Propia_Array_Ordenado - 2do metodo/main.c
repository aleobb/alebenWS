#include <stdio.h>
#include <stdlib.h>

#include "funcionesVector.h"
//#include "funciones.c"

#define MAX 100



int main()
{
    int i;
    int vectorRdo[MAX];
    int vector[MAX] = {5148,3,487,31,14555};
    int tamVector = 5;


    for(i = 0 ; i < tamVector ; i++)  // para mostrar los valores ordenados
        printf(" %d \n",vector[i]);


    ordenarMetodoAlternativo(vector, tamVector, 1);
///    ordenarV(vector, tamVector, vectorOrdenado, -1);


    printf("\n");
    for(i = 0 ; i < tamVector ; i++)  // para mostrar los valores ordenados
        printf(" %d \n",vectorRdo[i]);

    return 0;
}

