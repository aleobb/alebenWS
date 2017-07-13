
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "funcAux.h"
#include "Estadisticas.h"
#include "Usuarios.h"

#define ALL 0
#define ACTIVE 1
#define DELETED 2

#define BUFFER 1024





int fileToArrayEstadisticas()
{
    ArrayList* eList = al_newArrayList();
    void* pAux;

    if ( eList == NULL )
        printf("\n size %d",eList->size);

    pAux = (void*)newEstadistica(44238, 1535);
    eList->add(eList,pAux);
 //   printf("\n%d,%d%",((Estadistica*)pAux)->idUsuario, ((Estadistica*)pAux)->idTema);//

    pAux = (void*)newEstadistica(113, 18885);
    eList->add(eList,pAux);

  // printf("\n size %d",eList->size);//pAux->idUsuario, pAux->idTema);//
    estadisticaToFile("estadisticas.dat", eList);
/*
    int i;
    for ( i = 0 ; i < eList->size ; i++ )
        printEstadistica( eList->get(eList, i) );
*/
    return 0;
}


int estadisticaToFile(char* nombreArchivo, ArrayList* eList)
{
    char lineOfData[BUFFER];
    Estadistica* pAux;
    int elements = 0;
    int i;

    FILE* pFile = fopen(nombreArchivo,"a");

    if ( pFile == NULL || eList == NULL )
        printf("El archivo no se pudo abrir o puntero a memoria de la lista es Null ! \n");
    else
    {
        for(i=0; i<eList->size; i++ )
        {
            pAux = (Estadistica*)eList->get(eList, i);
            sprintf(lineOfData,"%d,%d%\n",pAux->idUsuario, pAux->idTema);//
            printf("%s",lineOfData);
            fputs(lineOfData,pFile); //!= NULL //,sizeof(lineOfData)-1

            //printf("Id: %d \t Object: %d \t Nombre: %s \t\t Data: %s \r\n", id, object.type, name, data);

            if ( pAux != NULL )
            {

                elements++;
            //  imprimirObject((Object*)pAux);
            }
        }
    }
    printf("\n Cantidad de elementos cargados en la lista: %d \n", elements);
    return elements;
}



/** \brief carga un nuevo estadistica
 * \param se le pasan todos los datos de ese estadistica
 * \return int Return (NULL) si no se pudo cargar el estadistica - Puntero al estadistica si se pudo cargar correctamente.
 */

Estadistica* newEstadistica(int idUsuario, int idTema)
{

    Estadistica* pEstadistica = malloc( sizeof(Estadistica) );

    if(pEstadistica != NULL)
    {
        pEstadistica->idTema = idTema;
        pEstadistica->idUsuario = idUsuario;
    }
    //printf("\n%d,%d%",pEstadistica->idUsuario, pEstadistica->idTema);//
    return pEstadistica;
}



/**
 * @brief muetra por pantalla los datos de un estadistica.
 * @param pEstadistica el puntero al estadistica se pasa por parametro.
 * @param flagRegistro recibe como parametro el estado del estadistica.
 * @return no devuelve nada.
 */
 /*
void printEstadistica(Estadistica* pEstadistica)
{
    if(pEstadistica != NULL)
    {
        printf("\n Id: %d ",pEstadistica->id);
        printf("\n Nombre: %s ",pEstadistica->nombre);
        printf("\n Artista: %s ",pEstadistica->artista);
        printf("\n ---------------------------------------------------");

    }
}*/

