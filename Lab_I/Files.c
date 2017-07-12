#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1024






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



void parseFile()
{
    char id[4096];
    char name[4096];
    char lastName[4096];
    char isEmpty[4096];

    FILE* pData;
    pData = fopen("data.csv","r"); ///  Abrirlo como solo lectura
    if (pData!=NULL)
        printf("Archivo abierto correctamente \n");
    else
        printf("El archivo no se pudo abrir! \n");

    EPersona* arrayPersonas=(EPersona*)malloc(sizeof(EPersona)*1);
    while( !feof(pData) )
    {

        /// fscanf(pData,"%s",buffer); /// file scanf que lee por línea
        fscanf(pData,"%[^,],%[^,],%[^,],%[^\n]", id, name, lastName, isEmpty); /// fscanf soporta expresiones regulares
        printf("%s \t %s %s  \t\t %s", id, name, lastName, isEmpty);  /// la consola de windows muestra una cantidad limitada porque su buffer es chico
        printf("\n");
    }
    return 0;
}



/**
 *  \brief Agrega una pelicula al archivo binario
 *  \param no recibe parametros
 *  \return retorna 0 si se pudo agregar correctamente o -2 si no se pudo grabar y -1 si se pudo grabar pero no cerrar el archivo
 */
int agregarPelicula()
{

    FILE* pArchivo=NULL;
    int retorno=-2;
    char titulo[20];

    int posPelicula=tomarTituloYchequearExistencia(titulo, TRUE);

    if ( posPelicula == -3 )
        printf("\n El ingreso ha sido cancelado. \n");
    else if( posPelicula != -1 )
    {
        EMovie movie = ingresoDatosPelicula(titulo);
        // listarDatosPelicula(movie);
        pArchivo = fopen(ARCHIVO,"ab"); // if ( abrirArchBinModoAppend(pArchivo,ARCHIVO) == 0 )
        if (pArchivo!=NULL)
        {
            // printf("pArchivo abierto correctamente \n");
            if ( fwrite(&movie,sizeof(EMovie),1,pArchivo) == 1 )
            {
                printf("\n La pelicula fue agregada en el archivo correctamente \n");
                retorno=cerrarArch(pArchivo);
            }
            else
                printf("\n Error de escritura en el archivo \"%s\"! La pelicula NO pudo ser agregada. \n", ARCHIVO);
        }
        else
            printf("\n El archivo \"%s\" NO pudo ser abierto en modo escritura! La carga de la pelicula fue cancelada. \n", ARCHIVO);
    }
    return retorno;
}


/**
 * \brief obtiene la cantidad de peliculas guardadas en el archivo
 * \param no recibe parametros
 * \return retorna la cantidad peliculas guardadas en el archivo o -1 en caso de error
 */
int contarPeliculasEnArchivo()
{
    int retorno=-1;
    FILE* pArchivo=NULL;
    pArchivo = fopen(ARCHIVO,"rb"); ///  Abrirlo como solo lectura

    //if ( pArchivo == NULL )
    //    printf("\n El archivo %s no pudo ser abierto! La ejecucion se detendra. \n", ARCHIVO);
    //else
    if ( pArchivo != NULL )
    {
        fseek(pArchivo, 0, SEEK_END);
        retorno= ( ftell(pArchivo)/sizeof(EMovie) );
        cerrarArch(pArchivo);
    }
    //printf("\n cant pelis: %d", retorno);
    return retorno;
}
