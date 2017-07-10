#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Object.h"
#include "ArrayList.h"
#include "Programador.h"
#include "Administrativo.h"

#define TYPE_PROGRAMADOR    1
#define TYPE_ADMINISTRATIVO 2


int parserObjects(FILE* pFile, ArrayList* listaObjects)
{
    int retorno = 0;

    int id;
    Object object;
    char name[100];
    char data[100];

    while(!feof(pFile))
    {
        fscanf(pFile,"%d,%d,%[^,],%[^\n],%[^\n]\n",&id,&(object.type),name,data);
        switch ( object.type )
        {
            case TYPE_PROGRAMADOR:
                newProgamador(object,name,data);
                break;
            case TYPE_ADMINISTRATIVO:
                newAdministrativo(object,name,atoi(data));
                break;
        }

    }
    return retorno;
}
