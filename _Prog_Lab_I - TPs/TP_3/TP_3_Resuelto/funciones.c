#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "funcionesAuxiliares.h"

#define EMPTY 0
#define USED 1
#define DELETED 2


/**
 * \brief Realiza el ingresdo de datos de una pelicula
 * \param arrayPeliculas se le pasa como parametro el array-estructura donde se van a cargar los datos
 * \param sizeArrayPeliculas es el tamaño del array-estructura donde se van a guardar los datos
 * \return devuelve (0) si Tamaño invalido o puntero NULL pointer o sin espacio disponible - (1) si la carga se pudo realizar.
 */
EMovie ingresoDatosPelicula()
{
    EMovie auxPelicula[1]; /// es el array-estructura donde se van a guardar provisoriamente los datos
    char arrayCharsAdmitidos[1]="-";
    getType("\n Ingrese el titulo: ", "\n El dato ingresado es invalido!\n Solo se adminten letras, numeros,\
             el caracter '-' y que no exceda los 19 caracteres \n",1,2,arrayCharsAdmitidos,19,auxPelicula->titulo);
    getType("\n Ingrese el genero: ", "\n El dato ingresado es invalido!\n Solo se adminten letras, numeros,\
             el caracter '-' y que no exceda los 19 caracteres \n",1,2,arrayCharsAdmitidos,19,auxPelicula->genero);
    getInt(auxPelicula->duracion, "\n Ingrese la duracion de la pelicula en minutos: ", "\n El dato ingresado es invalido!\
            \n La duracion debe ser un numero positvo entre 1 y 500",1,1,1,1,500);
    getType("\n Ingrese la descripcion: ", "\n El dato ingresado es invalido!\n Solo se adminten letras, numeros,\
             el caracter '-' y que no exceda los 49 caracteres \n",1,2,arrayCharsAdmitidos,49,auxPelicula->descripcion);
    getInt(auxPelicula->puntaje, "\n Ingrese el puntaje de la pelicula en minutos: ", "\n El dato ingresado es invalido!\
            \n El puntaje debe ser un numero positvo entre 1 y 10",1,1,1,1,10);
    getType("\n Ingrese el link de la Imagen: ", "\n El dato ingresado es invalido!\n Solo se adminten letras, numeros,\
             el caracter '-' y que no exceda los 49 caracteres \n",1,2,arrayCharsAdmitidos,49,auxPelicula->linkImagen);

    auxPelicula->flagRegistro=USED;

    return *auxPelicula;
}



/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie movie)
{


}




///int borrarPelicula(EMovie movie)

///void generarPagina(EMovie* lista[], char nombre[])



///static void initialize(EMovie* movie, int age, int something);


/**
 * \brief  Reseva espacio en memoria para una cantidad de peliculas e inicializa el array
 * \param  sizeArray se le pasa el tamaño inicial del array
 * \return EMovie* Retorna un puntero al array de peliculas o NULL en caso de error
 */
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


/**
 * @brief Obtiene el primer indice libre del array.
 * @param arrayPeliculas el array se pasa como parametro.
 * @param sizeArrayPeliculas el tamaño del array se pasa como parametro.
 * @return devuelve el primer indice disponible (o -1 si no exite ninguno disponible o -2 si el tamaño del array es invalido o un puntero NULO)
 */
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
