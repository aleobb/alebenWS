#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "my_func.h"
#define QTY 5

struct
{
    char nombre[50];
    char apellido[50];
    char legajo[8];

}typedef Empleado;




int isnumber(char aux[])
{
    int i=0;
    int retorno = 0;

    if(aux[i] == '-') i++;

    while(aux[i]!='\0')
    {
        if(isdigit(aux[i]) == 0)
        {
            retorno = 0;
            break;
        }
        retorno = 1;
        i++;
    }
    return retorno;
}

void mostrar(Empleado array[], int size)
{
    int i;

    for(i = 0; i<size ; i++)
    {
        printf("\n%s-%s-%s",array[i].nombre,array[i].apellido,array[i].legajo);
    }
    printf("\n----------------------------------------------\n");
}



int comparar (Empleado empleadoA, Empleado empleadoB)
{
    int retorno = 0;
    if(strcmp(empleadoA.nombre,empleadoB.nombre) > 0)
        retorno = 1;
    else if(strcmp(empleadoA.nombre,empleadoB.nombre) < 0)
        retorno = -1;
    else
    {
        if(strcmp(empleadoA.apellido,empleadoB.apellido) > 0)
            retorno = 1;
        else if(strcmp(empleadoA.apellido,empleadoB.apellido) < 0)
            retorno = -1;
        else
        {
            if(strcmp(empleadoA.legajo,empleadoB.legajo) > 0)
                retorno = 1;
            else if(strcmp(empleadoA.legajo,empleadoB.legajo) < 0)
                retorno = -1;
            else
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}


void bubleSort(Empleado array[], int size)
{
    int i;
    int flagSwap = 1;
    Empleado aux;
    while(flagSwap)
    {
        flagSwap = 0;
        for(i = 0; i<size-1 ; i++)
        {
            if(strcmp(array[i].nombre,array[i+1].nombre) > 0)
            {
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                flagSwap = 1;
            }
        }
    }
}

int main()
{

    Empleado arrayEmpleados[QTY];

    strcpy(arrayEmpleados[0].nombre,"CC");
    strcpy(arrayEmpleados[1].nombre,"CC");
    strcpy(arrayEmpleados[2].nombre,"CC");
    strcpy(arrayEmpleados[0].apellido,"ii");
    strcpy(arrayEmpleados[1].apellido,"ee");
    strcpy(arrayEmpleados[2].apellido,"cc");
    strcpy(arrayEmpleados[0].legajo,"15");
    strcpy(arrayEmpleados[1].legajo,"12");
    strcpy(arrayEmpleados[2].legajo,"84");
    mostrar(arrayEmpleados,3);
    bubleSort(arrayEmpleados,3);
        mostrar(arrayEmpleados,3);



    return 0;

}
