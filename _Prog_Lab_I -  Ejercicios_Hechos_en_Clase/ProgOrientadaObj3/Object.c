#include <string.h>

#include "Object.h"

#define BUFFER 1024

int parserDataInFileSTRTOK(FILE* pFile)
{
    char* pString;
    const char* delim=",";
    char* token;
    char line[BUFFER];

    int id;
    Object object;
    char name[100];
    char data[100];

    fgets(line,BUFFER,pFile); /// Salteo primer linea (si es que no es dato sino el titulo del contenido de ese archivo)

    while(1)
    {
        pString = fgets(line,BUFFER,pFile); /// leo 1 linea de una cantidad BUFFER de caracteres y lo guardo en un puntero a char
        if(pString==NULL)
            break;
    //  printf("%s",line);

        token = strtok(line,delim); /// obtengo partes y las cargo
        id = atoi(token);
        object.type = atoi(strtok(NULL,delim));
        strcpy(name,strtok(NULL,delim));
        strcpy(data,strtok(NULL,delim));

        printf("%d %d %s %s\r\n",id,object.type,name,data);
    }
    return 0;
}
