#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



/**
 *  Abre un archivo binario en modo lectura
 *  @param pFile se le pasa el puntero al archivo como parametro
 *  @param paramArch Se le pasa la ubicacion, nombre y extension del archivo
 *  @return retorna 0 si se pudo abrir correctamente o -1 si no se pudo
 */
int abrirArchBinModoLectura(FILE* pFile, char paramArch[])
{
    int retorno=-1;
    pFile = fopen(paramArch,"rb"); ///  Abrirlo como solo lectura
    if (pFile!=NULL)
        retorno=0; /// printf("Archivo abierto correctamente \n");
    else
        printf("\n El archivo %s no pudo ser abierto! \n", paramArch);
    return retorno;
}


/**
 *  Abre un archivo binario en modo lectura escritura
 *  @param pFile se le pasa el puntero al archivo como parametro
 *  @param paramArch Se le pasa la ubicacion, nombre y extension del archivo
 *  @return retorna 0 si se pudo abrir correctamente o -1 si no se pudo
 */
int abrirArchBinModoEscritura(FILE* pFile, char paramArch[])
{
    int retorno=-1;
    if (abrirArchBinModoLectura(pFile,paramArch) == 0 ) ///  Abrirlo como solo lectura
    {
        pFile = fopen(paramArch,"wb"); ///  Abrirlo como lectura escritura
        if (pFile!=NULL)
            retorno=0; /// printf("Archivo abierto correctamente \n");
        else
            printf("\n El archivo %s no puede ser abierto! \n", paramArch);
    }
    return retorno;
}


/**
 *  Abre un archivo binario
 *  @param pFile se le pasa el puntero al archivo como parametro
 *  @param paramArch Se le pasa la ubicacion, nombre y extension del archivo
 *  @return retorna 0 si se pudo abrir correctamente o -1 si no se pudo
 */
int abrirArchBinModoAppend(FILE* pFile, char paramArch[])
{
    int retorno=-1;
    printf("\n paramArch: %s",paramArch);
    printf(" \n comparac %d ", stricmp(paramArch,"\"Peliculas.bin\"") );
    pFile = fopen(paramArch,"ab"); ///  Abrirlo para agregar datos
    if (pFile!=NULL)
        retorno=0; /// printf("Archivo abierto correctamente \n");
    else
        printf("\n El archivo %s no puede ser abierto! \n", paramArch);
    return retorno;
}


/**
 *  Cierra un archivo ya abierto
 *  @param pFile se le pasa el puntero al archivo como parametro
 *  @return retorna 0 si se pudo cerrar correctamente o -1 si no se pudo
 */
int cerrarArch(FILE* pFile)
{
    int retorno=-1;
    if( fclose(pFile) != -1 ) ///  Cerrar archivo
        retorno=0; /// printf("Archivo cerrado correctamente \n");
    else
        printf("\n El archivo no pudo ser cerrado! \n");
    return retorno;
}
