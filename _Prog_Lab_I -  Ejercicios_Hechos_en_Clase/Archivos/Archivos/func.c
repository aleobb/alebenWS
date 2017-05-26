#include <stdio.h>
#include <stdlib.h>


struct
{
    int id;
    char name[50];
    char lastName[50];
    int isEmpty;

}typedef EPersona;

void cargarArrayPersonas (EPersona* arrayPersonas, FILE* pData)
{
    int id;
    int isEmpty;
    int i=0;

    while( !feof(pData) )
    {

        fscanf(pData,"%[^,],%[^,],%[^,],%[^\n]", id, (arrayPersonas+i)->name, (arrayPersonas+i)->lastName, isEmpty);
        (arrayPersonas+i)->id=atoi(id);
        (arrayPersonas+i)->isEmpty=atoi(isEmpty);
        i++;

    }

}

