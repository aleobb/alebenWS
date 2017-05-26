#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct
{
    int id;
    char name[50];
    char lastName[50];
    int isEmpty;

}typedef EPersona;

void cargarArrayPersonas (EPersona* arrayPersonas, FILE* pFile);

int main()
{
    FILE* pFile;
    EPersona* arrayPersonas=(EPersona*)malloc(sizeof(EPersona)*1);

    if(arrayPersonas == NULL)
        printf("\n La ejecucion se detendra! No se pudo asignar espacio en memoria. \n");
    else
        cargarArrayPersonas(arrayPersonas,pFile);

    return 0;
}


void cargarArrayPersonas (EPersona* arrayPersonas, FILE* pFile)
{
    char id[6];
    char isEmpty[10];
    int i=0;
    EPersona* pPersonaAux;
    /// char* encabezado;

    pFile = fopen("data.csv","r"); ///  Abrirlo como solo lectura

    if (pFile!=NULL)
        printf("Archivo abierto correctamente \n");
    else
    {
        printf("El archivo no se pudo abrir! \n");
        return;
    }
    /// fscanf(pFile,"%[^\n]", &encabezado);
    /// printf("%s \n",&encabezado);

    while( !feof(pFile) )
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]", id, (arrayPersonas+i)->name, (arrayPersonas+i)->lastName, isEmpty);
        (arrayPersonas+i)->id=atoi(id);
        (arrayPersonas+i)->isEmpty=0;
        if(strcmp(isEmpty,"true")==0)
            (arrayPersonas+i)->isEmpty=1;

        printf("%d \t (isEmpty=%s) \t %s %s \n", (arrayPersonas+i)->id, isEmpty, (arrayPersonas+i)->name, (arrayPersonas+i)->lastName );  /// la consola de windows muestra una cantidad limitada porque su buffer es chico
        i++;

        pPersonaAux=(EPersona*)realloc(arrayPersonas, sizeof(EPersona)*(i+1) );
        if( pPersonaAux == NULL )
        {
            printf("\n La ejecucion se detendra! No se pudo asignar nuevo espacio en memoria. \n");
            break;
        }
        else
            arrayPersonas=pPersonaAux;
    }

    fclose(pFile);

}
