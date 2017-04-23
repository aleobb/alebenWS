#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "funcionesAuxiliares.h"

#define EL_DATO_ES_VALIDO 1
#define EL_DATO_NO_ES_VALIDO 0
#define QTYPERSONA 20


int main()
{
    EPersona arrayPersonas[QTYPERSONA];
    int contadorPersonas=0;
    int indice;
    long int dni;

    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        printf("\nIngrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                indice=obtenerEspacioLibre(arrayPersonas,QTYPERSONA);
                if (indice<0)
                    printf("\n No se puede agregar persona porque se agoto el espacio disponible!");
                else
                {
                    ingresoPersona(arrayPersonas,indice);
                    contadorPersonas++;
                }
                break;
            case 2:
                if (contadorPersonas==0)
                    printf("\n No se puede eliminar persona porque no hay datos de personas cargadas! \n");
                else
                    indice=buscarPorDni(arrayPersonas,QTYPERSONA,dni);
                    if (indice<0)
                         printf("\n No se puede eliminar persona porque ese nro. de DNI no se encuentra cargado! \n");
                    else
                        arrayPersonas[indice].estado=-1;
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
