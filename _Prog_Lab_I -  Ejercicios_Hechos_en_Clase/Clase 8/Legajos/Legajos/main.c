#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define QTY 5

struct
{
    char nombre[50];
    char apellido[50];
    char legajo[8];

}typedef Empleado;

int main()
{
    Empleado arrayEmpleados[QTY];
    char buffer[4084];

    int i;
    for(i = 0; i<QTY ; i++)
    {

        printf("\n Ingrese Nombre: ");
        scanf("%s",buffer);
        if(strlen(buffer) < 50)
        {
           strcpy(arrayEmpleados[i].nombre,buffer);
        }

        printf("\n Ingrese Apellido: ");
        scanf("%s",buffer);
        if(strlen(buffer) < 50)
        {
           strcpy(arrayEmpleados[i].apellido,buffer);
        }

        printf("\n Ingrese legajo: ");
        scanf("%s",arrayEmpleados[i].legajo);
        if(strlen(buffer) < 50)
        {
           strcpy(arrayEmpleados[i].legajo,buffer);
        }
    }

/**    for(i = 0; i<QTY ; i++)
    {
        printf("\n Nro. legajo: %s",arrayEmpleados[i].nombre);

    }
    */

    return 0;

}

void ordenar(Empleado arrayEmpleados*, int size) ///al array lo defino con el mismo nombre en la funcion ordenar que en la funcion main
{
    int i, j;
    Empleado aux;
    int flagSwap=1;
    while (flagSwap)
    {
        flagSwap=0;
        for(i=0; i<size-1; i++)
        {
            /// funcion comparar ()
            if ()

            /// hacer swap
            aux=arrayEmpleados[i];
            arrayEmpleados[i]=arrayEmpleados[i+1];
            arrayEmpleados[i+1]=aux;
            flagSwap=1 ;
        }

    }
}


