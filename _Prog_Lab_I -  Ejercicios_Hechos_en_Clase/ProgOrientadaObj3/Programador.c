#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Object.h"
#include "Programador.h"


Programador* newProgamador(Object object, char* nombre, char* lenguaje)
{
    //printf(" PROGRAMADOR Object: %d \t Nombre: %s \t Lenguaje: %s\r\n", object.type, nombre, lenguaje);
    Programador* pAux = malloc( sizeof(Programador) );
    if ( pAux !=  NULL )
    {
        pAux->obj = object;
        strcpy(pAux->nombre, nombre);
        strcpy(pAux->lenguaje, lenguaje);

        //strncpy(pAux->nombre, nombre, sizeof(*nombre) );
        //strncpy(pAux->lenguaje, lenguaje, sizeof(*lenguaje) );

        //printf(" Object: %d ", pAux->obj);
        //printf(" sizeof(nombre) %d \r\n", sizeof(*nombre) );
        //printf("PROGRAMADOR. Nombre:%s. Lenguaje:%s\r\n",pAux->nombre,pAux->lenguaje);
    }
    return pAux;
}




void* myMalloc (int size)
{
    return malloc(size);
}


void* myFree (int size)
{
    return 0;
}
