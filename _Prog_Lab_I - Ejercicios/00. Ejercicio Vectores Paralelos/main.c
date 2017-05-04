#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#include "funciones.h"

#define MAX 100

void pruebaMain();
void pruebaMain2();

int main()
{
    int i;
    int array[MAX]={288,54555,1583,3,99,3,775};
    ordenarVector(array, 7, -1);
    for (i=0;i<7;i++)
    {
        printf("\n El valor array en [i] es: %d",array[i]);
    }
    printf("\n Se termino el ingreso de datos. \n");
    return;
}

void pruebaMain2()
{
    char array[MAX];
    //  printf("El retorno es: %d",getString("\n Ingrese numeros: ",array,'n',"\n Error! Debe ingresar solo numeros."));
    if( getString("\n Ingrese letras: ",array,'a',"\n Error! Debe ingresar solo letras.") == 1 )
        printf("\n El array ingresado es: %s",array);
    printf("\n Se termino el ingreso de datos. \n");
    return 0;
}


void pruebaMain()
{
    int aux;
    aux = getInt("\n Ingrese un numero del 1 al 10: ", "\n El dato ingresado es invalido!", 1, 10, 3);
    if (aux!=0)
    {
        printf("\n El dato ingresado es: %d",aux);
    }
    //return 0;
}
