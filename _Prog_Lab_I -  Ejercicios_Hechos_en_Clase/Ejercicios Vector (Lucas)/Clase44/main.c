#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define MAX 100

int main()
{
    int i=5;
    int size=5;
    int sizeEdad = 5;
    int edad[MAX] = {22,11,33,55,66};
    int edadOrdenada[MAX]; // creo el array para guardar el nuevo array ordenado

    printf("\nEl promedio de las edades ingresadas es %.2f\n\n", promedio(edad, i+1));
    printf("\nEl minimo es %d\n\n", minimo(edad,5));


    /*   compactar(edad,size,2);
       for(i=0;i<size-1;i++)
       {
       printf("%d",edad[i]);
       }*/

    printf("INDEX: %d\n\n",indiceMin(edad, sizeEdad));
    sizeEdad = compactar(edad,sizeEdad,2);


    printf("Array compactado: \n\n");
    for(i=0; i<sizeEdad; i++)
    {
        printf("\n %d\n",edad[i]);
    }

    ordenar(edad, sizeEdad, edadOrdenada);

    printf("Array ordenado: \n\n");
    for(i=0; i<sizeEdad; i++)
    {
        printf("\n %d\n",edadOrdenada[i]);
    }


/* expandir / ordenamiento por insercion
sacar, compactar, nuevo array sin ese valor, genero una funcion que crea un array sin ese valor
si no quiero duplicar puedo crear otra variable que vaya guardando el valor y comparando y moviendo a la izq (i-1)
i+1
la flechita es el indice del for*/


    return 0;
}
