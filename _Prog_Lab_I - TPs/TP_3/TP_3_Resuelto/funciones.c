#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "funcArchivos.h"
#include "funcionesAuxiliares.h"

#define EMPTY 0
#define USED 1
#define DELETED 2

#define ARCHIVO "Peliculas.bin" // Cadena con comillas: \"


/**
 * \brief Realiza el ingreso de datos de una pelicula
 * \param la cadena del campo titulo se le pasa como parametro
 * \return devuelve (0) si Tamaño invalido o puntero NULL pointer o sin espacio disponible - (1) si la carga se pudo realizar.
 */
EMovie ingresoDatosPelicula(char* titulo)
{
    EMovie auxPelicula; /// es la variable donde se van a guardar provisoriamente los datos
    char arrayCharsAdmitidos[1]="-";

    strcpy(auxPelicula.titulo,titulo);
    getType("\n Ingrese el genero: ", "\n El dato ingresado es invalido!\n Solo se adminten letras, numeros,\
             el caracter '-' y que no exceda los 19 caracteres \n",1,2,arrayCharsAdmitidos,19,auxPelicula.genero);
    getInt(&auxPelicula.duracion, "\n Ingrese la duracion de la pelicula en minutos: ", "\n El dato ingresado es invalido!\
            \n La duracion debe ser un numero positvo entre 1 y 500",1,1,1,1,500);
    getType("\n Ingrese la descripcion: ", "\n El dato ingresado es invalido!\n Solo se adminten letras, numeros,\
             el caracter '-' y que no exceda los 49 caracteres \n",1,2,arrayCharsAdmitidos,49,auxPelicula.descripcion);
    getInt(&auxPelicula.puntaje, "\n Ingrese el puntaje de la pelicula del 1 al 10: ", "\n El dato ingresado es invalido!\
            \n El puntaje debe ser un numero positvo entre 1 y 10",1,1,1,1,10);

    strcpy(arrayCharsAdmitidos,"-.");
    getType("\n Ingrese el link de la Imagen: ", "\n El dato ingresado es invalido!\n Solo se adminten letras, numeros,\
             el caracter '-' y que no exceda los 49 caracteres \n",1,2,arrayCharsAdmitidos,49,auxPelicula.linkImagen);

    return auxPelicula;
}


/**
 * \brief Pide al usuario el ingreso del titulo de una pelicula
 * \param no recibe parametros
 * \return no devuelve nada.
 */
void ingresoTitulo(char* titulo)
{
    char arrayCharsAdmitidos[1]="-";
    getType("\n Ingrese el titulo: ", "\n El dato ingresado es invalido!\n Solo se adminten letras, numeros,\
             el caracter '-' y que no exceda los 19 caracteres \n",1,2,arrayCharsAdmitidos,19,titulo);
    // printf("\n %s",titulo);
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
    ingresoTitulo(titulo);
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
    }
    else
        printf("\n El archivo \"%s\" NO pudo ser abierto en modo escritura! La carga de la pelicula fue cancelada. \n", ARCHIVO);
    return retorno;
}


/**
 * \brief Lista por pantalla los datos de una pelicula
 * \param la variable que contiene los datos de la pelicula del tipo EMovie se le pasa como parametro
 * \return no devuelve nada.
 */
void listarDatosPelicula(EMovie movie)
{
    printf("\n Titulo: \t %s",movie.titulo);
    printf("\n Genero: \t %s",movie.genero);
    printf("\n Duracion: \t %d",movie.duracion);
    printf("\n Descripcion: \t %s",movie.descripcion);
    printf("\n Puntaje: \t %d",movie.puntaje);
    printf("\n Link Imagen: \t %s",movie.linkImagen);
    printf("\n");
}


///int borrarPelicula(EMovie movie)

///void generarPagina(EMovie* lista[], char nombre[])



///static void initialize(EMovie* movie, int age, int something);


/**
 * \brief  Reseva espacio en memoria para una cantidad de peliculas e inicializa el array
 * \param  sizeArray se le pasa el tamaño inicial del array
 * \return EMovie* Retorna un puntero al array de peliculas o NULL en caso de error
 */
 /*
EMovie* initArrayPeliculas(int sizeArray)
{
    int i;
    EMovie* pPeliculas = (EMovie*)malloc(sizeof(EMovie)*sizeArray);
    if(pPeliculas != NULL)
        for (i=0;i<sizeArray;i++)
            (pPeliculas+i)->flagRegistro=EMPTY;
    else
        printf("\n La ejecucion se detendra! No se pudo asignar espacio en memoria. \n");

    return pPeliculas;
}
*/

/**
 * @brief Obtiene el primer indice libre del array.
 * @param arrayPeliculas el array se pasa como parametro.
 * @param sizeArrayPeliculas el tamaño del array se pasa como parametro.
 * @return devuelve el primer indice disponible (o -1 si no exite ninguno disponible o -2 si el tamaño del array es invalido o un puntero NULO)
 */
 /*
int obtenerPosicionLibreArrayPeliculas(EMovie* arrayPeliculas, int sizeArrayPeliculas)
{
    int i;
    int retorno=-2
    if ( arrayPeliculas==NULL || sizeArrayPeliculas<=0 )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
    {
        for (i=0; i<sizeArrayPeliculas; i++)
            if ( (pPeliculas+i)->flagRegistro == EMPTY )
                return i;
        retorno++;
    }
    return retorno;
}

*/


/**
 * \brief  Reseva espacio en memoria para una cantidad de peliculas e inicializa el array
 * \param  arrayPeliculas se pasa el array de estructuras a incrementar
 * \param increase: incremento de memoria en cantidad de registros (0 para inicializar la primera vez)
 * \return EMovie* Retorna un puntero al array de peliculas o NULL en caso de error
 */
 /*
EMovie* memoryAsign(EMovie* arrayPeliculas,int indiceSiguiente, int increase)
{
    int i;
    EMovie* pPeliculas;
    if (increase==0)
    {
        increase=SIZE;
        indiceSiguiente=0;
        pPeliculas = (EMovie*)malloc(sizeof(EMovie)*increase);
    }
    else
        pPeliculas = (EMovie*)realloc(arrayPeliculas, sizeof(EMovie)*increase);

    if(arrayPeliculas != NULL)
        for (i=indiceSiguiente;i<increase;i++)
            (arrayPeliculas+i)->flagRegistro=0;
    else
        printf("\n La ejecucion se detendra! No se pudo asignar espacio en memoria. \n");

    return pPeliculas;
}
*/







/** \brief  Inicializa a una pelicula recibida como parametro
 * \param EMovie* movie Puntero a la pelicula
 * \param int age Edad de la pelicula
 * \param int something Otros datos
 * \return void
 */

 /*
static void initialize(EMovie* movie, int age, int something)
{
    movie->age = age;
    movie->something = something;
}
*/
