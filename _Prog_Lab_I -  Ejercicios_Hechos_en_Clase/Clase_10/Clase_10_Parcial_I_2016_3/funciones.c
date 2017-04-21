#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"

#define QTYPELICULA 1000
#define QTYDIRECTOR 500

#define BUFFER 4084


/**
 * \brief Solicitar al usuario una cadena de caracteres.
 * \param mensajeIngreso: es el mensaje a mostrar para pedir el ingreso.
 * \param input es el array donde se va a guardar la cadena.
 * \return Si obtuvo un ingreso no nulo devuelve [1] sino devuelve [0].
 */
int getString(char mensajeIngreso[], char input[])
{
    char buffer[BUFFER];
    printf("%s",mensajeIngreso);
    fflush(stdin);
    scanf("%[^\n]s",buffer);
    if ( strlen(buffer)==0 || buffer[0]=='\0' )
        return 0;
    strcpy(input,buffer);
    return 1;
}


/**
 * \brief Verifica que una array esté compuesto solo por numeros.
 * \param vector: es el array a evaluar
 * \param admitePunto: si se recibe 1 como parametro, valida que la cadena pueda incluir hasta 1 punto ('.'), sino no.
  * \param admitePunto: si se recibe 1 como parametro, acepta como valido una cadena que empieza con el signo '-', sino no.
 * \return Si el array esta compuesto solo por numeros devuelve [1] sino devuelve [0].
 */
int esCadenaSoloNumeros (char vector[], int cantPuntos, int admiteNegativos)
{
    int i=0;
    int contadorPuntos=cantPuntos;
    while (vector[i]!='\0')
    {
        if (vector[i]<'0' || vector[i]>'9')
        {
            if (vector[0]=='-' && admiteNegativos!=1)
                return 0;
            if (vector[i]=='.')
                contadorPuntos--;
            if ( cantPuntos==0 || contadorPuntos<0 )
                return 0;
        }
        i++;
    }
    return 1;
}

/// 1.Alta directores
/// 2.Alta Peliculas
/// 3.Imprimir peliculas

/*
    char nombre[50];
    char fechaNacimiento[10];
    char paisOrigen[50];
*/

void altaDirector(Director arrayDirectores[], int indexArrayDirectores, int idDirector)
{
///    int cargaNombreValida=0;
///    while ()
    getString("\n Ingrese el nombre del director: ", arrayDirectores[indexArrayDirectores].nombre);
    getString("\n Ingrese la fecha de nacimiento del director: ", arrayDirectores[indexArrayDirectores].fechaNacimiento);
    getString("\n Ingrese el pais de origen del director: ", arrayDirectores[indexArrayDirectores].paisOrigen);
    arrayDirectores[indexArrayDirectores].id = idDirector;
    return;
}


void inicializarArrays(Director arrayDirectores[], Pelicula arrayPeliculas[])
{
    int i;
    for (i=0; i<QTYDIRECTOR; i++)
        arrayDirectores[i].id=-1;
    for (i=0; i<QTYPELICULA; i++)
        arrayPeliculas[i].id=-1;
}


int buscarDirector(Director arrayDirectores[], int sizeArrayDirectores, int idDirector)
{
    int i;
    for (i=0; i<sizeArrayDirectores; i++)
        if ( arrayDirectores[i].id == idDirector)
            return i;
    return -1;
}

int buscarIndexVacioEnArrayDirectores(Director arrayDirectores[], int sizeArrayDirectores)
{
    int i;
    for (i=0; i<sizeArrayDirectores; i++)
        if ( arrayDirectores[i].id == -1 )
            return i;
    return -1;  /// si se supero el tamaño del array de directores devuelve -1 (no se pueden cargar mas directores)
}
