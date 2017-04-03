#include <stdio.h>
#include <stdlib.h>


int compactar(int array[], int size, int indice)
{
    for ( ;indice < size-1; indice++) // se repite hasta size-1 porque el nuevo vector va a tener un dato menos desde indice
        array[indice] = array[indice+1]; // quiero copiar en indice lo que tengo en la posicion siguiente o sea guardo en la posicion 2 lo que tengo en el indice 3
    return size - 1; // devuelvo el nuevo tamaño
}

int calcularIndiceMinimo(int array[], int size)
{
    int indice=1; // arranco el recorrido del vector desde la posicion 1 ya que el la posicion cero es el primer min
    int minimo = array[0]; //lo necesito para saber cual es el indice min
    int indiceMinimo = 0; // hasta no recorrer el array el primer valor es el minimo

    //recorro el array hasta encontrar el minimo y lo guardo
    for ( ;indice < size; indice++) // declaro y uso un indice que va desde la posicion 1 hasta el final porque ya tome el 0 como minimo
    {
       if(array[indice] < minimo) // me pregunto si la posicion en donde estoy parado es mas chiquito que el minimo actual
       {
           minimo = array[indice];
           indiceMinimo = indice; // si lo es guardo esa posicion como minimo
       }

    }
    return indiceMinimo; // devuelvo la posicion del donde esta guardado el minimo
}

// todo el proceso empieza aca:
void nadiaSort(int array[], int size,int arrayOrdenado[]) // minimo-compactar repetidas veces hasta todo el tamaño del array
{
    int i;
    int indiceMinimo; //variable auxiliar
    int sizeInicial = size;
    for(i=0;i<sizeInicial;i++)
    {
        indiceMinimo = calcularIndiceMinimo(array,size); //busco en que posicion del array está guardado el minimo y lo guardo en la variable auxiliar
        arrayOrdenado[i] = array[indiceMinimo]; // obtengo el valor guardado en el vector original correspondiente a ese indice minimo y lo guardo en la primer posicion del nuevo array (arrayOrdenado)
        size = compactar(array,size,indiceMinimo); //al array original le elimino la posicion del minimo (lo compacto)
        // vuelvo a empezar el ciclo
    }
}



float promedio(int edad[], int cantidad){

    float retornoPromedio;
    int i, suma=0;

    for(i=0;i<cantidad;i++){
        suma=suma+edad[i];
    }
    retornoPromedio=(float)suma/cantidad;

    return retornoPromedio;
}
