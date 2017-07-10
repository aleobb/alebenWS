#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Object.h"
#include "Administrativo.h"


Administrativo* newAdministrativo(Object object, char nombre[], int area)
{
    Administrativo* pAux = malloc( sizeof(Administrativo) );
    if ( pAux !=  NULL )
    {
            pAux->obj = object;
            strcpy(nombre, pAux->nombre);
            pAux->area = area;
    }
    return pAux;
}
