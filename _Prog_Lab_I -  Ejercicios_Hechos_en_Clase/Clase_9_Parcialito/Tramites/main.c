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

valoresDePrueba()
{
    Tramites turnos[QTYTURNOS];
}

int main()
{
    Tramites turnos[QTYTURNOS];
    int opcion=0;
    int nroTurnoSigte=0;
    int proxTurnoUrgente;
    int proxTurnoRegular;


    while(opcion!=6)
    {
        printf("\n");
        printf(" 1- Tramite Urgente\n");
        printf(" 2- Tramite Regular\n");
        printf(" 3- Proximo Cliente\n");
        printf(" 4- Listar Clientes Pendientes de Ser Atendidos\n");
        printf(" 5- Listar Clientes ya Atendidos\n\n");
        printf(" 6- Salir \n\n");

        printf(" Ingrese una opcion: ");
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
                /*
                proxTurnoUrgente=maxMinArrayInt(turnos,0,nroTurnoSigte-1,-1,1,URGENTE);
                printf("\n ProxTurno urgente: %d",proxTurnoUrgente+1);

                proxTurnoRegular=maxMinArrayInt(turnos,0,nroTurnoSigte-1,-1,1,REGULAR);
                printf("\n ProxTurno urgente: %d",proxTurnoUrgente+1);

                listarTurnos(turnos, nroTurnoSigte);
                */

                if (proxTurnoUrgente+1>0 && nroTurnoSigte>0)
                {
                    printf("\n\n Turno a atender: %d - DNI %d \n",turnos[proxTurnoUrgente].nroTurno,turnos[proxTurnoUrgente].dni);
                   /// printf("%d - DNI %d",turnos[proxTurnoUrgente].nroTurno,turnos[proxTurnoUrgente].dni);
                    turnos[proxTurnoUrgente].tipoyEstadoTurno=-URGENTE;
                }
                else if (proxTurnoRegular+1>0 && nroTurnoSigte>0)
                {
                    printf("\n Turno a atender: %d - DNI %d \n",turnos[proxTurnoRegular].nroTurno,turnos[proxTurnoRegular].dni);
                    turnos[proxTurnoRegular].tipoyEstadoTurno=-REGULAR;
                }
                else
                    printf("\n NO HAY TURNOS PENDIENTES DE ATENDER \n");
                break;
            case 4:
                listarTurnos(turnos, nroTurnoSigte);
                break;
            case 5:
                bubleSort(turnos, nroTurnoSigte);
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
