#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcUTN.h"

#define QTYPELICULA 1000
#define QTYDIRECTOR 500

#define BUFFER 4084

int main()
{
    Pelicula arrayPeliculas[QTYPELICULA];
    Director arrayDirectores[QTYDIRECTOR];
    int contadorGeneradorIdDirector=0;
    int contadorGeneradorIdPelicula=0;

    int indexAltaDirector;
    int indexAltaPelicula;
    int idPeliculaAbuscar;

    inicializarArrays(arrayDirectores, arrayPeliculas);

    int opcion=0;

    while(opcion!=8)
    {
        printf("\n");
        printf(" 1- ALTAS PELICULAS \n");
        printf(" 2- MODIFICAR DATOS DE UNA PELÍCULA \n");
        printf(" 3- BAJA DE PELICULA \n");
        printf(" 4- NUEVO DIRECTOR \n");
        printf(" 5- ELIMINAR DIRECTOR \n");
        printf(" 6- INFORMAR DIRECTOR CON MAS PELICULAS Y PELICULAS CON MAS DIRECTORES \n");
        printf(" 7- LISTAR PELICULAS \n\n");
        printf(" 8- SALIR \n\n");

        printf(" Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                indexAltaPelicula = buscarIndexVacioEnArrayPeliculas(arrayPeliculas, QTYPELICULA);
                if (indexAltaPelicula>=0)
                {
                    altaPelicula(arrayPeliculas,indexAltaPelicula,contadorGeneradorIdPelicula,arrayDirectores);
                    contadorGeneradorIdPelicula++;
                }
                break;
            case 2:

                if ( buscarPelicula(arrayPeliculas,QTYPELICULA,idPeliculaAbuscar) == -1)
                    printf("La pelicula no existe");
                else
                {
                    altaPelicula(arrayPeliculas,idPeliculaAbuscar, 'contadorGeneradorIdPelicula' ,arrayDirectores);
                }
                break;
            case 3:

                break;
            case 4:
                indexAltaDirector = buscarIndexVacioEnArrayDirectores(arrayDirectores, QTYDIRECTOR);
                if (indexAltaDirector>=0)
                {
                    altaDirector(arrayDirectores,indexAltaDirector,contadorGeneradorIdDirector);
                    contadorGeneradorIdDirector++;
                }
                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:
                break;
        }
    }

    return 0;
}
