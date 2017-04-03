#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int calcIndiceMin(int vector[], int size);
int compactar(int vector[], int tamVector, int indice);
void ordenar(int vectorOriginal[],int sizeVector, int vectOrdenado[]);

int main()
{
    int i;
    int vector[MAX] = {5148,487,3,31,14555};
    int tamVector = 5;

    int vectorOrdenado[MAX];

    for(i = 0 ; i < tamVector ; i++)  // para mostrar los valores ordenados
        printf(" %d \n",vector[i]);

    ordenar(vector, tamVector, vectorOrdenado);

    printf("\n");
    for(i = 0 ; i < tamVector ; i++)  // para mostrar los valores ordenados
        printf(" %d \n",vectorOrdenado[i]);

    return 0;
}

int calcIndiceMin(int vector[], int size)
{
    int i = 1; // i=indice
    int valorMinVector = vector[0];
    int indiceMin = 0;
    for ( ; i<size; i++)
    {
        if ( vector[i] < valorMinVector)
        {
            valorMinVector = vector[i];
            indiceMin = i;
        }
    }
    return indiceMin;
}


int compactar(int vector[], int tamVector, int indice)
{
    for (;indice<tamVector-1;indice++)
    {
        vector[indice] = vector[indice+1];
    }
    return tamVector-1;
}

void ordenar(int vectorOriginal[],int sizeVector, int vectOrdenado[])
{
    int i;
    int indMin;
    int sizeOriginal = sizeVector; //
    for ( i=0; i<sizeOriginal; i++)
    {
        indMin = calcIndiceMin(vectorOriginal, sizeVector);
        vectOrdenado[i] = vectorOriginal[indMin];
        sizeVector = compactar(vectorOriginal, sizeVector, indMin);
    }
}
