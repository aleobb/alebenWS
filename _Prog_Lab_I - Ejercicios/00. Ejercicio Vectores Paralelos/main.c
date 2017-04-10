#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

#define MAX 100

void pruebaMain();

int main()
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
