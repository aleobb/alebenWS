
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESTINOS_SIZE 10
#define VIAJEROS_SIZE 10

#define FALSE 0
#define TRUE 1

struct{
    int isEmpty;
}typedef This;


struct{
    int isEmpty;
    int idDestino;
    char destino[100];
    float precio;
}typedef Destino;

struct{
    int isEmpty;
    int idViajero;
    char nombre[100];
    int idDestino;
}typedef Viajero;

int mainDestinos_Viajeros();
int listarViajeros(Destino* destinos, int sizeDestinos, Viajero* viajeros, int sizeViajeros);
char* findDestinyById(Destino* destinos, int sizeDestinos, int idDestino);
int findDestinyByName(Destino* destinos, int sizeDestinos, char* destino);
int initThis(This* this, int size);
int hardcodearDestino(Destino* destinos, int index, int idDestino, char* destino, float precio);
int hardcodearViajero(Viajero* viajeros, int index, int idViajero, char* nombre, int idDestino);

int mainDestinos_Viajeros()
{
    int i=0;
    Destino destinos[DESTINOS_SIZE];
    Viajero viajeros[VIAJEROS_SIZE];

    initThis( (This*)destinos, DESTINOS_SIZE);
    initThis( (This*)viajeros, VIAJEROS_SIZE);

    hardcodearDestino(destinos, i, i+1, "Necochea", 300);
    hardcodearViajero(viajeros, i, i+1, "Pablo", 1);
    i++;

    hardcodearDestino(destinos, i, i+1, "MDQ", 500);
    hardcodearViajero(viajeros, i, i+1, "ariel", 2);
    i++;

    hardcodearDestino(destinos, i, i+1, "Pinamar", 800);
    hardcodearViajero(viajeros, i, i+1, "alfredo", 1);


    listarViajeros(destinos, DESTINOS_SIZE, viajeros, VIAJEROS_SIZE);
    return 0;
}

int listarViajeros(Destino* destinos, int sizeDestinos, Viajero* viajeros, int sizeViajeros)
{
    int i;
    char nombreDestino[100];
    for ( i = 0 ; i < sizeViajeros; i++)
        if ( (viajeros+i)->isEmpty != TRUE )
        {
            strcpy(nombreDestino, findDestinyById(destinos,sizeDestinos,(viajeros+i)->idDestino) );
            printf("\n Nombre viajero %s \t Destino %s", (viajeros+i)->nombre, nombreDestino);
        }
    return 0;
}

char* findDestinyById(Destino* destinos, int sizeDestinos, int idDestino)
{
    int i;
    for ( i = 0 ; i < sizeDestinos; i++)
        if ( (destinos+i)->isEmpty != TRUE && (destinos+i)->idDestino == idDestino )
            return (destinos+i)->destino;
        return "destino no encontrado";
}


int findDestinyByName(Destino* destinos, int sizeDestinos, char* destino)
{
    int i;
    for ( i = 0 ; i < sizeDestinos; i++)
        if ( (destinos+i)->isEmpty != TRUE && stricmp( (destinos+i)->destino, destino ) == 0 )
            return 0;
    return -1;
}

int initThis(This* this, int size)
{
    int i;
    for ( i = 0 ; i < size; i++)
        (this+i)->isEmpty = TRUE;
    return 0;
}


int hardcodearDestino(Destino* destinos, int index, int idDestino, char* destino, float precio)
{
    (destinos+index)->isEmpty == FALSE;
    (destinos+index)->idDestino == idDestino;
    strcpy( (destinos+index)->destino, destino);
    (destinos+index)->precio == precio;
    return 0;
}

int hardcodearViajero(Viajero* viajeros, int index, int idViajero, char* nombre, int idDestino)
{
    (viajeros+index)->isEmpty == FALSE;
    (viajeros+index)->idViajero == idViajero;
    strcpy( (viajeros+index)->nombre, nombre);
    (viajeros+index)->idDestino == idDestino;
    return 0;
}


