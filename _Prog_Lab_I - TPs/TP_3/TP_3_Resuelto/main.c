/********************************************************************************************
 * Programa: Trabajo Practico N� 3
 *
 * Realizar un programa que permita agregar, borrar y modificar peliculas en un archivo binario
 * mediante un men�:
 * 1. Agregar pel�cula
 * 2. Borrar pel�cula
 * 3. Modificar pel�cula
 * 4. Generar p�gina web
 * 5. Salir
 *
 * Version: 1.0 31 de Mayo de 2017.
 * Autor: Ben Alejandro
 *
 ********************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "funcionesAuxiliares.h"


int main()
{
    EMovie* arrayPeliculas;  /// Declaro el array de peliculas usando memoria dinamica

    if ( initArrayPeliculas(arrayPeliculas)==-1 )
        opcion=11;

    int opcion=0;

    while(opcion!=5)
    {
        printf("\n");
        printf(" 1- Agregar pelicula\n");
        printf(" 2- Borrar pelicula\n");
        printf(" 3- Modificar pelicula\n");
        printf(" 4- Generar pagina web\n");
        printf("\n");
        printf(" 5- Salir\n");

        getInt(&opcion,"\n Ingrese una opcion: ","\n\n La opcion ingresada es incorrecta! Debe elegir una opcion del 1 al 5. \n",1,1,1,1,11);

        switch(opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
                break;
            case 5:
                printf("\n\n PROCESO TERMINADO. \n");
                break;
        }
    }

    return 0;
}
