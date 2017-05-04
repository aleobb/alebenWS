#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"

#define MAX 50
#define QTY 5

struct /// Empleados
{
    int legajo;
    char nombre[MAX];
    char apellido[MAX];
    char isEmpty; /// para saber si ese legajo está cargado o no (no se modifican o se borran los datos fisicos sino que es una info logica)
    /// int nroDocum[10];
}typedef Empleado;

int main()
{


    /// getString("\n Ingrese nombre : ", name, 'l', "\n Debe ingresar un nombre usando solo letras!")

    char buffer [4084];
    struct Empleado arrayEmpleados[QTY];  ///antes: struct Empleados arrayEmpleados[QTY];

    int i;
    for (i=0;i<5;i++)
    {
        printf("\n Edad?:");
        scanf("%s",buffer);
        if(isnumber(buffer))
        {
            edad[i]=atoi(buffer);
        }

        printf("\n Apellido?:");
        scanf("%s",buffer);
        if(strlen(buffer)<50) /// cantidad de letras para el apellido es 49
        {
            strcpy(apellido[i],buffer);
        }



        printf("\n El valor array en [i] es: %d",array[i]);
    }
    printf("\n Se termino el ingreso de datos. \n");
    return;
}getString("\n Ingrese nombre : ", name, 'l', "\n Debe ingresar un nombre usando solo letras!")
