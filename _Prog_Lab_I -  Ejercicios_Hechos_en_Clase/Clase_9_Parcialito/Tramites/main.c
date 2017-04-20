/***********************************************************************
* Programa: Calculadora de 5 funciones
*
* Objetivo:
* Organizar la atencion a clientes.
*
* Version: 1.0 - 19/04/2017
* Autor: Alejandro Ben
*
***********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"

#define QTYTURNOS 200
#define URGENTE 1
#define REGULAR 2
#define BUFFER 4084

int main()
{
    Tramites turnos[QTYTURNOS];
    int opcion=0;
    int nroTurnoSigte=0;

    while(opcion!=6)
    {
        printf("\n");
        printf("1- Tramite Urgente\n");
        printf("2- Tramite Regular\n");
        printf("3- Proximo Cliente\n");
        printf("4- Listar Clientes Pendientes de Ser Atendidos\n");
        printf("5- Listar Clientes ya Atendidos\n\n");
        printf("6- Salir\n");

        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                if (otorgarTurno(turnos,nroTurnoSigte,URGENTE,nroTurnoSigte+1)==1)
                    nroTurnoSigte++;
                break;
            case 2:
                if (otorgarTurno(turnos,nroTurnoSigte,REGULAR,nroTurnoSigte+1)==1)
                    nroTurnoSigte++;
                break;
            case 3:

                break;
            case 4:
                listarTurnos(turnos, nroTurnoSigte);
                break;
            case 5:

                break;
            case 6:
                break;
        }
    }

    printf("\n dni: %d",turnos[0].dni);
    printf("\n nro turno: %d",turnos[0].nroTurno);
    printf("\n Tipo tramite: %d",turnos[0].tipoyEstadoTurno);
    return 0;
}
