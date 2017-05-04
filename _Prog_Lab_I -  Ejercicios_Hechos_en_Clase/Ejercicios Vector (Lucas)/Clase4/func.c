#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100

float promedio(int edad[], int cantidad)
{

    float retornoPromedio;
    int i, suma=0;

    for(i=0; i<cantidad; i++)
    {
        suma=suma+edad[i];
    }
    retornoPromedio=(float)suma/cantidad;

    return retornoPromedio;
}

int minimo(int edad[], int a)
{
    int menor,i;
    menor=edad[0];
    for(i=0; i<a; i++)
    {
        if(edad[i]<menor)
        {
            menor=edad[i];
        }
    }
    return menor;
}

void compactar(int edad[], int indice, int size)
{
    int i;
    for(i=indice; i<size-1; i++)
    {
        edad[i]=edad[i+1];
    }
}

