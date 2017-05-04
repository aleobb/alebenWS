#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "my_func.h"
#define QTY 5

structscanf("%s",arrayEmpleado[i].nombre);
{
    int legajo;
    char nombre[50];
    char apellido[50];
    char isEmpty;

}typedef Empleado;




int isnumber(char* aux)
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
    return retoscanf("%s",arrayEmpleado[i].nombre);rno;
}


int main()
{
    char buffer[4084];
    Empleado arrayEmpleados[QTY];
    Empleado aux;

    aux.legajo = 99;


    int i;
    for(i = 0; i<5 ; i++)
    {
        printf("\nEDAD?");
        scanf("%s",buffer);
        if(isnumber(buffer))
        {
           arrayEmpleados[i].legajo = atoi(buffer);
        }


        printf("\nApellido?");
        scanf("%s",buffer);
        if(strlen(buffer) < 50)
        {
            strcpy(arrayEmpleados[i].apellido,buffer);
        }


    }

    return 0;

}
