#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int calcIndice(int vector[], int size, int minMax); // calcula indice minimo y maximo
int expandirCompactarV(int vector[], int tamVector, int indice, int compExp);
void ordenar(int vectorOriginal[],int sizeVector, int vectOrdenado[]);

int main()
{
    int i;
    int vector[MAX] = {5148,3,487,31,14555};
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

int calcIndice(int vector[], int size, int minMax) // El auxiliar minMax sirve para, segun el valor (-1 o 1), calcular el min o maximo
{
    int i = 1; // i=indice
    int valorMinVector = vector[0];
    int indiceMin = 0;
    for ( ; i<size; i++)
    {
        if ( (vector[i]*minMax) > (valorMinVector*minMax) )
        {
            valorMinVector = vector[i];
            indiceMin = i;
        }
    }
    return indiceMin;
}


int expandirCompactarV(int vector[], int tamVector, int indice, int compExp) // El auxiliar compExp sirve para, segun el valor (-1 o 1), compactar o expandir el vector
{
    for (;indice<tamVector-1;indice++) //chequear el 1 y multiplicar por compExp ??
    {
        vector[indice] = vector[indice+1]; //chequear el 1
    }
    return tamVector-1;
}

void ordenar(int vectorOriginal[],int sizeVector, int vectOrdenado[])
{
    int i;
    int indMinMax;
    int sizeOriginal = sizeVector; //
    for ( i=0; i<sizeOriginal; i++)
    {
        indMinMax = calcIndice(vectorOriginal, sizeVector, 1);
        vectOrdenado[i] = vectorOriginal[indMinMax];
        sizeVector = expandirCompactarV(vectorOriginal, sizeVector, indMinMax, -1);
    }
}
