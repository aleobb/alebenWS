#include <stdio.h>
#include <stdlib.h>

#include "func.c"

#define SIZEBUFFER 60


void

int main()
{
   /* id,first_name,last_name,is_empty */

    char id[4096];
    char name[4096];
    char lastName[4096];
    char isEmpty[4096];

    FILE* pData;

    EPersona* arrayPersonas;

    /*
    char* buffer=(char*)malloc(sizeof(char)*SIZEBUFFER+1+100000);
    int qty=SIZEBUFFER;

    int candidadLeidos;
    char* pChar;
    */

    pData = fopen("data.csv","r"); ///  Abrirlo como solo lectura

    if (pData!=NULL)
        printf("Archivo abierto correctamente \n");
    else
        printf("El archivo no se pudo abrir! \n");



    while( !feof(pData) )
    {
        /* candidadLeidos=fread(buffer+(qty-SIZEBUFFER),sizeof(char),SIZEBUFFER,pData);
        /// if( candidadLeidos != SIZEBUFFER ); /// chequear esto me va a indicar donde tengo que ponder el '\0'



        pChar=realloc(buffer, sizeof(char)*(qty+SIZEBUFFER) );

        if(pChar != NULL)
            break;

        buffer=pChar;
        qty+=60;*/


        /// fscanf(pData,"%s",buffer); /// file scanf que lee por línea
        fscanf(pData,"%[^,],%[^,],%[^,],%[^\n]", id, name, lastName, isEmpty); /// fscanf soporta expresiones regulares
        printf("%s \t %s %s  \t\t %s", id, name, lastName, isEmpty);  /// la consola de windows muestra una cantidad limitada porque su buffer es chico
        printf("\n");
    }
    /*
    buffer[qty] != '\0';

    printf("%s",buffer);
    printf("%d",qty);
    */


    return 0;
}
