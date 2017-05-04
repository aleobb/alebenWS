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

/*void compactar(int edad[], int indice, int size)
{
    int i;
    for(i=indice; i<size-1; i++)
    {
        edad[i]=edad[i+1];
    }
}*/

/*int compactar(int edad[], int indice, int size)
{
    int i;
    for(i=indice; i<size-1; i++)
    {
        edad[i]=edad[i+1];
    }
    return size-1;
}*/

int compactar(int array[], int size, int indice)

{
    for (; indice<size-1; indice++)
        array[indice] = array[indice +1]; // quiero copiar en indice lo que tengo en la posicion siguiente o sea al indice 2 por ejemplo le copio lo del indice 3
    return size-1; // devuelvo el nuevo tamaño
}

int indiceMin(int array[], int size)
{
    int indiceMinimo = 0;
    int indice = 1;
    int minimo = 0; // int minimo = array[0];

    for (; indice<size; indice++) // declaro y uso un indice que va desde la posicion 1 hasta el final porque ya tome el 0 como minimo
    {
        if(array[indice] < minimo) // me pregunto si la posicion en donde estoy parado es mas chiquito que el minimo actual
            minimo = array[indice];
        indiceMinimo = indice;// si lo es guardo esa posicion como minimo
    }
    return indiceMinimo;
}

void ordenar (int array[], int size, int arrayOrdenado[]) // minimo-compactar repetidas veces hasta todo el tamaño del array
{
    int i;
    int sizeInicial = size;
    int indiceMinimo;
    for(i=0;i<sizeInicial;i++)
    {
        indiceMinimo = indiceMin(array,size);
        arrayOrdenado[i] = array[indiceMinimo];
        compactar(array,size,indiceMinimo);
    }
}
