#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10


///

struct
{
    char nombre[10];
    int edad;
}typedef EPersona;

void imprimir(EPersona* arrayPunterosPersonas[], int sizeArray);

void cargarArrayPunteros(EPersona arrayPersonas[], EPersona* arrayPunterosPersonas[], int sizeArray);

int ordenarPorEdad(EPersona* arrayPunterosPersonas[], int sizeArray);

int ordenarPorNombre(EPersona* arrayPunterosPersonas[], int sizeArray);

void cargarValores(EPersona arrayPersonas[], int sizeArray);

int main()
{

    /// EFotos* arrayFotos = (EFotos*) malloc(sizeof(EFotos)*4);
    /// EFotos** arrayPunterosFotos = (EFotos**) malloc(sizeof(EFotos*)*4);


    EPersona arrayPersonas[SIZE];
    EPersona* arrayPunterosPersonas[SIZE];

    cargarValores(arrayPersonas, SIZE);
    cargarArrayPunteros(arrayPersonas,arrayPunterosPersonas,SIZE);

    imprimir(arrayPunterosPersonas,SIZE);

    ordenarPorEdad(arrayPunterosPersonas,SIZE);
    printf("\n\n");
    imprimir(arrayPunterosPersonas,SIZE);

    ordenarPorNombre(arrayPunterosPersonas,SIZE);
    printf("\n\n");
    imprimir(arrayPunterosPersonas,SIZE);

    return 0;
}

void imprimir(EPersona* arrayPunterosPersonas[], int sizeArray)
{
    int i;
    for (i = 0; i < sizeArray; i++)
        printf("indiceArray  %d \t Nombre  %s \t Edad  %d \t dirMemoria  0x%x \n", i, arrayPunterosPersonas[i]->nombre, arrayPunterosPersonas[i]->edad, arrayPunterosPersonas[i] );
}

void cargarArrayPunteros(EPersona arrayPersonas[], EPersona* arrayPunterosPersonas[], int sizeArray)
/// EPersona arrayPersonas[]            es igual a   EPersona* arrayPersonas      y
/// EPersona* arrayPunterosPersonas[]   es igual a   EPersona** arrayPunterosPersonas
{
    int i;
    for (i = 0; i < sizeArray; i++)
        ///  &(arrayPersonas[i])   es igual a   &( *(arrayPersonas+i) )   y es igual a   arrayPersonas+i
        arrayPunterosPersonas[i]=&(arrayPersonas[i]);
}


int ordenarPorEdad(EPersona* arrayPunterosPersonas[], int sizeArray)
{
    int i;
    EPersona* auxiliar;
    int retorno = 1;

    while(retorno)
    {
        retorno = 0;
        for (i = 1; i < sizeArray; i++)
        {
            if ( arrayPunterosPersonas[i]->edad  < arrayPunterosPersonas[i-1]->edad )
            {
                auxiliar = arrayPunterosPersonas[i];
                arrayPunterosPersonas[i] = arrayPunterosPersonas[i-1];
                arrayPunterosPersonas[i-1] = auxiliar;
                retorno = 1;
            }
        }
    }
    return retorno;
}


int ordenarPorNombre(EPersona* arrayPunterosPersonas[], int sizeArray)
{
    int i;
    EPersona* auxiliar;
    int retorno = 1;

    while(retorno)
    {
        retorno = 0;
        for (i = 1; i < sizeArray; i++)
        {
            if ( stricmp(arrayPunterosPersonas[i]->nombre, arrayPunterosPersonas[i-1]->nombre) <0 )
            {
                auxiliar = arrayPunterosPersonas[i];
                arrayPunterosPersonas[i] = arrayPunterosPersonas[i-1];
                arrayPunterosPersonas[i-1] = auxiliar;
                retorno = 1;
            }
        }
    }
    return retorno;
}



void cargarValores(EPersona arrayPersonas[], int sizeArray)
{
    int i;
    int edad;
    char arrayNombres[20][SIZE]={"ccc","hhh","aaa","bbb","rrr","jjj","eee","mmm","ppp","www"};


    for (i=0; i < sizeArray-5; i++)
    {
        strcpy( (arrayPersonas+i)->nombre, arrayNombres[i] );
        (arrayPersonas+i)->edad = 1+ (i*6);
    }

    for (i=sizeArray-5; i < sizeArray; i++)
    {
        strcpy( (arrayPersonas+i)->nombre, arrayNombres[i] );
        (arrayPersonas+i)->edad = 60-(i*4);
    }

    edad=(arrayPersonas+3)->edad;
    (arrayPersonas+3)->edad=(arrayPersonas+7)->edad;
    (arrayPersonas+7)->edad=edad;

}


