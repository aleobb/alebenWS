/********************************************************************************************
 *
 * Programa: Base de datos de Personas
 *
 * Objetivo:
 * Crear una base de datos de personas y poder listarla ordenadamente y graficarla.
 *
 * Version: 1.0 22 de Abril de 2017.
 * Autor: Ben Alejandro
 *
 ********************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcionesAuxiliares.h"
#include "Abonados.h"
#include "Llamadas.h"


#define EL_DATO_ES_VALIDO 1
#define EL_DATO_NO_ES_VALIDO 0
#define QTYABONADO 20
#define QTYLLAMADA 50


int main()
{
    EAbonado arrayAbonados[QTYABONADO];
    ELlamada arrayLlamadas[QTYLLAMADA];

    char seguir='s';
    int opcion=0;

    //printf("\n init abon: %d", initArrayAbonados(arrayAbonados,QTYABONADO) );
    //printf("\n init llamadas: %d", initArrayLlamadas(arrayLlamadas,QTYLLAMADA) );

    if ( initArrayAbonados(arrayAbonados,QTYABONADO)==0 || initArrayLlamadas(arrayLlamadas,QTYLLAMADA)==0 )
        seguir='n';

///    cargaAutomatica(arrayAbonados,QTYABONADO);


    while(seguir=='s')
    {
        listarAbonados(arrayAbonados,QTYABONADO);
        listarLlamadas(arrayLlamadas,QTYLLAMADA);

        printf("\n");
        printf("1- Alta del Abonado\n");
        printf("2- Modificar datos del Abonado\n");
        printf("3- Baja del Abonado\n");
        printf("4- Nueva llamada\n");
        printf("5- Fin llamada\n");
        printf("6- Informar nombre y apellido del abonado con mas reclamos\n");
        printf("7- Informar reclamo mas realizado\n");
        printf("8- Informar reclamo que en promedio mas demora en ser resuelto\n");
        printf("\n");
        printf("9- Salir\n");

        printf("\nIngrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                altaAbonado(arrayAbonados,QTYABONADO);
                break;
            case 2:
                modificarAbonadoPorId(arrayAbonados,QTYABONADO);
                break;
            case 3:
                bajaAbonadoPorId(arrayAbonados,QTYABONADO,arrayLlamadas,QTYLLAMADA);
                break;
            case 4:
                nuevaLlamada(arrayLlamadas,QTYLLAMADA,arrayAbonados,QTYABONADO);
                break;
            case 5:
                modificarLlamadaPorId(arrayLlamadas,QTYLLAMADA);
                break;


            case 9:
                seguir = 'n';
                break;
            default:
                printf("\n La opcion ingresada es invalida! Intente nuevamente. \n");
                break;
        }
    }

    return 0;
}
