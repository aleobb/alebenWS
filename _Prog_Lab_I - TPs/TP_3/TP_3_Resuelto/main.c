/********************************************************************************************
 * Programa: Trabajo Practico Nº 3
 *
 * Realizar un programa que permita agregar, borrar y modificar peliculas en un archivo binario
 * mediante un menú:
 * 1. Agregar película
 * 2. Borrar película
 * 3. Modificar película
 * 4. Generar página web
 * 5. Salir
 *
 * Version: 1.0 31 de Mayo de 2017.
 * Autor: Ben Alejandro
 *
 ********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"
#include "funcArchivos.h"
#include "funcionesAuxiliares.h"

#define SIZE 100

#define ARCHIVO "\"Peliculas.bin\""

int main()
{
    int opcion=0;

    ///int sizeArrayPeliculas=SIZE
///    EMovie* arrayPeliculas = initArrayPeliculas(SIZE);  /// Declaro el array de peliculas usando memoria dinamica

 ///   if ( arrayPeliculas==NULL )
 ///       opcion=5;

    while(opcion!=5)
    {
        printf("\n");
        printf(" 1- Agregar pelicula\n");
        printf(" 2- Borrar pelicula\n");
        printf(" 3- Modificar pelicula\n");
        printf(" 4- Generar pagina web\n");
        printf("\n");
        printf(" 5- Salir\n");

        getInt(&opcion,"\n Ingrese una opcion: ","\n\n La opcion ingresada es incorrecta! Debe elegir una opcion del 1 al 5. \n",1,1,1,1,5);

        switch(opcion)
        {
            case 1:
                agregarPelicula();
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
                listarPeliculas();
                break;
            case 5:
                printf("\n\n PROCESO TERMINADO. \n");
                break;
        }
    }

    return 0;
}
