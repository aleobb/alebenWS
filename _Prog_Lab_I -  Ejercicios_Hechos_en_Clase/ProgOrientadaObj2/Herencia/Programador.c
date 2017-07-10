#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Object.h"
#include "Programador.h"


Programador* newProgamador(Object object, char nombre[], char lenguaje[])
{
    Programador* pAux = malloc( sizeof(Programador) );
    if ( pAux !=  NULL )
    {
            pAux->obj = object;
            strcpy(nombre, pAux->nombre);
            strcpy(lenguaje, pAux->lenguaje);
    }
    return pAux;
}




void* myMalloc (int size)
{
    return malloc(size);
}


void* myFree (int size)
{

}
