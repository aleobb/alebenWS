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

#define BUFFER 1024


void imprimirObject(Object* o);

int parserDataInFile(char* nombreArchivo, ArrayList* listaObjects);



int main()
{
    ArrayList* listaObjects = al_newArrayList();

    parserDataInFile("data.txt", listaObjects);

    int i;
    for ( i = 0 ; i < listaObjects->size ; i++ )
        imprimirObject( listaObjects->get(listaObjects, i) );

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



int parserDataInFile(char* nombreArchivo, ArrayList* listaObjects)
{
    int id;
    Object object;
    char name[100];
    char data[100];
    char lineOfData[BUFFER];
    void* pAux;
    int elements = 0;

 // Programador* p;
 // Administrativo* a;

    FILE* pFile = fopen(nombreArchivo,"r");

    if ( pFile == NULL || listaObjects == NULL )
        printf("El archivo no se pudo abrir o puntero a memoria de la lista es Null ! \n");
    else
    {
        fgets(lineOfData,sizeof(lineOfData)-1,pFile); /// Con esto leo la primer linea y la descarto
        while( fgets(lineOfData,sizeof(lineOfData)-1,pFile) != NULL )
        {
            sscanf(lineOfData,"%d,%d,%[^,],%[^,]",&id,&(object.type),name,data);
            //printf("Id: %d \t Object: %d \t Nombre: %s \t\t Data: %s \r\n", id, object.type, name, data);

            switch ( object.type )
            {
                case TYPE_PROGRAMADOR:
                    pAux = (void*)newProgamador(object, name, data);
                //  p = (Programador*) pAux;
                //  printf("Object: %d \t Nombre: %s \t\t Data: %s \r\n", p->obj.type, p->nombre, p->lenguaje);
                    break;
                case TYPE_ADMINISTRATIVO:
                    pAux = (void*)newAdministrativo(object, name, atoi(data) );
                //  a = (Administrativo*) pAux;
                //  printf("Object: %d \t Nombre: %s \t\t Data: %d \r\n", a->obj.type, a->nombre, a->area);
                    break;
            }
            if ( pAux != NULL )
            {
                listaObjects->add(listaObjects, pAux);
                elements++;
            //  imprimirObject((Object*)pAux);
            }
        }
    }
    printf("\n Cantidad de elementos cargados en la lista: %d \n", elements);
    return elements;
}

