
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "funcAux.h"
#include "temas.h"

#define ALL 0
#define ACTIVE 1
#define DELETED 2

#define BUFFER 1024


int fileToArrayTemas()
{
    ArrayList* tList = al_newArrayList();
    parseDataInFile("temas.dat", tList);

    int i;
    for ( i = 0 ; i < tList->size ; i++ )
        printTema( tList->get(tList, i) );

    return 0;
}


int parseDataInFile(char* nombreArchivo, ArrayList* tList)
{
    int id;
    char nombre[50];
    char artista[50];

    char lineOfData[BUFFER];
    void* pAux;
    int elements = 0;


    FILE* pFile = fopen(nombreArchivo,"r");

    if ( pFile == NULL || tList == NULL )
        printf("El archivo no se pudo abrir o puntero a memoria de la lista es Null ! \n");
    else
    {
        fgets(lineOfData,sizeof(lineOfData)-1,pFile); /// Con esto leo la primer linea y la descarto
        while( fgets(lineOfData,sizeof(lineOfData)-1,pFile) != NULL )
        {
            sscanf(lineOfData,"%d,%[^,],%[^,]",&id, nombre, artista);
            //printf("Id: %d \t Object: %d \t Nombre: %s \t\t Data: %s \r\n", id, object.type, name, data);

            pAux = (void*)newTema(id, nombre, artista);

            if ( pAux != NULL )
            {
                tList->add(tList, pAux);
                elements++;
            //  imprimirObject((Object*)pAux);
            }
        }
    }
    printf("\n Cantidad de elementos cargados en la lista: %d \n", elements);
    return elements;
}



/** \brief carga un nuevo tema
 * \param se le pasan todos los datos de ese tema
 * \return int Return (NULL) si no se pudo cargar el tema - Puntero al tema si se pudo cargar correctamente.
 */
Tema* newTema(int id, char nombre[], char artista[])
{

    Tema* pTema = malloc( sizeof(Tema) );

    if(pTema != NULL)
    {
        pTema->id = id;
        strcpy(pTema->nombre,nombre);
        strcpy(pTema->artista,artista);

    }
    return pTema;
}



/**
 * @brief muetra por pantalla los datos de un tema.
 * @param pTema el puntero al tema se pasa por parametro.
 * @param flagRegistro recibe como parametro el estado del tema.
 * @return no devuelve nada.
 */
void printTema(Tema* pTema)
{
    if(pTema != NULL)
    {
        printf("\n Id: %d ",pTema->id);
        printf("\n Nombre: %s ",pTema->nombre);
        printf("\n Artista: %s ",pTema->artista);
        printf("\n ---------------------------------------------------");

    }
}
