#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Object.h"
#include "Programador.h"
#include "Administrativo.h"

#include "ArrayList.h"
#include "funcAux.h"

#define AREA_COMPRAS    0
#define AREA_VENTAS     1

#define TYPE_PROGRAMADOR    1
#define TYPE_ADMINISTRATIVO 2


void imprimirObject(Object* o);

int mainTest()
{

    ArrayList* listaObjects = al_newArrayList();
    FILE* pFile = fopen("data.txt","r"); ///  Abrirlo como solo lectura

    if ( pFile == NULL || listaObjects == NULL )
    {
        printf("El archivo no se pudo abrir! \n");
        return 0;
    }

    parserObjects(pFile, listaObjects);

    return 0;
}

/*int mainTest()
{
    Programador p;
    p.obj.type=TYPE_PROGRAMADOR;
    sprintf(p.nombre,"juan");
    sprintf(p.lenguaje,"JAVA");

    Administrativo a;
    a.obj.type = TYPE_ADMINISTRATIVO;
    sprintf(a.nombre,"pepe");
    a.area = AREA_VENTAS;

    Object* o1;
    Object* o2;

    /// Lo siguiente se hace para evitar un warning de compilacion:
    o1 = (Object*)&p; /// &p devuelve un puntero a Programador o Programador*
    o2 = (Object*)&a; /// (Object*) castea el puntero Administrativo a Object*


    imprimirObject(o1);
    imprimirObject(o2);


    return 0;
}*/


void imprimirObject(Object* o)
{
    Programador* p;
    Administrativo* a;

    switch(o->type)
    {
        case TYPE_PROGRAMADOR:
            p = (Programador*) o;
            printf("PROGRAMADOR. Nombre:%s. Lenguaje:%s\r\n",p->nombre,p->lenguaje);
            break;

        case TYPE_ADMINISTRATIVO:
            a = (Administrativo*) o;
            printf("ADMINISTRATIVO. Nombre:%s. Area:%d\r\n",a->nombre,a->area);
            break;
    }

}

/// Todo esto es herencia y poliformismo
