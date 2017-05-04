#include <stdio.h>
#include <stdlib.h>
#include "BiblFunciones.h"

#define CANTVECTOR 100

int main()
{
    int array[CANTVECTOR], i, edad ;
    char preg;
    float promedio;

    for (i=0;i<CANTVECTOR;i++)
    {
        printf("\n Ingrese la edad de la persona %d: \n",i+1);
        scanf("%d",&edad);
        while (edad < 0 || edad > 120 )
        {
            printf("\n El dato ingresado es incorrecto! ");
            printf("\n Ingrese la edad de la persona %d: ",i+1);
            scanf("%d",&edad);

        }
        array[i]=edad;

        printf("\n Desea seguir ingresando valores? [s]");
        fflush(stdin); // con esto limpio el buffer
        scanf("%c",&preg);

        if(preg != 's' && preg != 'S')
            { break; }

        system("cls"); // la funcion system manda ordenes al sistema operativo por la consola
    }

    promedio = prom(array,i+1);
    printf("El promedio de edad es: %.3f", promedio);

    return 0;
}
