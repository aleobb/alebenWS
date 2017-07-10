
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcAux.h"
//#include "Usuarios.h"
//#include "Productos.h"

#define ARCHIVO "Peliculas.bin" // Para cadena con comillas usar: \"

int cerrarArchivo(FILE* pArchivo);

/**
 * \brief obtiene la cantidad de elementos guardados en el archivo
 * \param recibe el puntero al archivo como parametro
 * \return retorna la cantidad de elementos guardados en el archivo o -1 en caso de error
 */
int contarElementosEnArchivo(FILE* pArchivo)
{
    int retorno=-1;
    //FILE* pArchivo=NULL;
    //pArchivo = fopen(ARCHIVO,"rb"); ///  Abrirlo como solo lectura

    if ( pArchivo == NULL )
        printf("\n El archivo %s no pudo ser leido! La ejecucion se detendra. \n", ARCHIVO);
    else
    //if ( pArchivo != NULL )
    {
        fseek(pArchivo, 0, SEEK_END);
        retorno= ( ftell(pArchivo)/sizeof(void*) );
        cerrarArchivo(pArchivo);
    }
    //printf("\n cantitdad de elementos: %d", retorno);
    return retorno;
}


/**
 *  Cierra un archivo ya abierto
 *  @param pFile se le pasa el puntero al archivo como parametro
 *  @return retorna 0 si se pudo cerrar correctamente o -1 si no se pudo
 */
int cerrarArchivo(FILE* pArchivo)
{
    int retorno=-1;
    if ( pArchivo == NULL ) ///  Cerrar archivo
        printf("\n Error de puntero. El archivo no pudo ser leido! \n  La ejecucion se detendra. \n");
    if( fclose(pArchivo) == -1 )
        printf("\n El archivo no pudo ser cerrado! \n");
    else
    {
        retorno=0;
        printf("\n Archivo cerrado correctamente \n");
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
    int retorno=-1;/*
    printf("\n paramArch: %s",paramArch);
    printf(" \n comparac %d ", stricmp(paramArch,"\"Peliculas.bin\"") );
    pFile = fopen(paramArch,"ab"); ///  Abrirlo para agregar datos
    if (pFile!=NULL)
        retorno=0; /// printf("Archivo abierto correctamente \n");
    else
        printf("\n El archivo %s no puede ser abierto! \n", paramArch);
        */
    return retorno;
}


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



/*************************//**ARCHIVOS******************************************************/

void actualizarArchivoBinario(void* elemento,char* nombreArchivo,int size)
{
    FILE* pFile=fopen(nombreArchivo,"ab");
    if(pFile!=NULL)
        fwrite(elemento,size,1,pFile);
    fclose(pFile);
}

/*
void sobreEscribirArchivo(ArrayList* lista,int size,char* nombre)
{
    int index;
    E_Usuario* usuario;
    FILE* pFile=fopen(nombre,"wb");
    if(pFile==NULL)
        return;
    for(index=0; index<lista->len(lista); index++)
    {
        usuario=lista->get(lista,index);
        fwrite(usuario,size,1,pFile);
    }
    fclose(pFile);
}*/


/*
void imprimirArchivo()
{
    int i;
    FILE* pArchivo=NULL;
    int sizeArrayPeliculas;
    EMovie* arrayPeliculas=cargarPeliculasEnArray(&sizeArrayPeliculas);

    if ( sizeArrayPeliculas==0 )
        printf("\n No hay ninguna pelicula cargada en el archivo! \n");
    else if ( arrayPeliculas==NULL || sizeArrayPeliculas<0 )
        printf("\n El archivo que contiene las peliculas a listar NO se pudo abrir. \n");
    else
    {
        pArchivo = fopen(HTMLFILE,"w");
        if (pArchivo!=NULL)
        {
            for (i=0; i<sizeArrayPeliculas; i++)
            {
                fwrite(LINK,sizeof(char),strlen(LINK),pArchivo);
                fwrite(arrayPeliculas[i].linkImagen,sizeof(char),strlen(arrayPeliculas[i].linkImagen),pArchivo);

                fwrite(TITULO,sizeof(char),strlen(TITULO),pArchivo);
                fwrite(arrayPeliculas[i].titulo,sizeof(char),strlen(arrayPeliculas[i].titulo),pArchivo);

                fwrite(GENERO,sizeof(char),strlen(GENERO),pArchivo);
                fwrite(arrayPeliculas[i].genero,sizeof(char),strlen(arrayPeliculas[i].genero),pArchivo);

                //itoa(arrayPeliculas[i].puntaje,puntaje,10);
                fwrite(PUNTAJE,sizeof(char),strlen(PUNTAJE),pArchivo);
                fwrite(arrayPeliculas[i].puntaje,sizeof(char),strlen(arrayPeliculas[i].puntaje),pArchivo);

                fwrite(DURACION,sizeof(char),strlen(DURACION),pArchivo);
                fwrite(arrayPeliculas[i].duracion,sizeof(char),strlen(arrayPeliculas[i].duracion),pArchivo);
                //fwrite(*itoa(arrayPeliculas[i].duracion),sizeof(int),sizeof(arrayPeliculas[i].duracion)-1,pArchivo);

                fwrite(DESCRIPCION,sizeof(char),strlen(DESCRIPCION),pArchivo);
                fwrite(arrayPeliculas[i].descripcion,sizeof(char),strlen(arrayPeliculas[i].descripcion),pArchivo);

                fwrite(END,sizeof(char),strlen(END),pArchivo);
            }
            printf("\n El archivo HTMLFILE se pudo generar exitosamente! \n");
            free(arrayPeliculas);
            fclose(pArchivo);
        }
        else
            printf("\n Error de escritura del archivo html! El archivo HTMLFILE no se pudo generar. \n");
    }
}
*/

