#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* openFile(char* mode)
{
    FILE *pFile;
    char fileName[100];
    printf("\nIngrese el nombre y ruta del archivo que desea abrir: ");
    fflush(stdin);
    gets(fileName);

    if( ( pFile = fopen(fileName,"r") ) == NULL )
        if( ( pFile = fopen(fileName,"w") ) == NULL )
            printf("\nEl archivo %s no puede ser abierto",fileName);
    if ( pFile != NULL )
        printf("\nEl archivo %s SI pudo ser abierto ",fileName);

    return pFile;
}


