#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcionesAuxiliares.h"
#include "Abonados.h"
#include "Llamadas.h"


#define EL_DATO_ES_VALIDO 1
#define EL_DATO_NO_ES_VALIDO 0


#define EMPTY 0
#define USED 1
#define DELETED 2

#define FALLA_3G 1
#define FALLA_LTE 2
#define FALLA_EQUIPO 3

#define EN_CURSO 0
#define SOLUCIONADO 1
#define NO_SOLUCIONADO 2



/**
 * @brief busca el Abonado con mas/menos reclamos.
 * @param arrayAbonados el array se pasa como parametro.
 * @param sizeArrayAbonados el tamaño del array se pasa como parametro.
 * @param maxMin parametro que indica si se van a hallar el abonado con mas reclamos (1) o con menos reclamos (-1).
 * @param idAbonadoConMasMenosReclamos: donde se va a guardar el Id del Abonado con mas/menos reclamos.
 * @return devuelve 1 si lo encontró (o -1 si no pudo encontrarlo o si el tamaño del array es invalido o un puntero NULO)
 */
int calcularAbonadoConMasMenosReclamos(EAbonado* arrayAbonados, int sizeArrayAbonados, int maxMin, int* idAbonadoConMasMenosReclamos)
{
    int i;
    int retorno=-1;
    int cantReclamosAbonadoConMasMenosReclamos;
    if ( arrayAbonados==NULL && sizeArrayAbonados<=0 )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<sizeArrayAbonados; i++)
            if (arrayAbonados[i].flagRegistro==USED && ( i==0 || (arrayAbonados[i].contadorLlamadas*maxMin) > (cantReclamosAbonadoConMasMenosReclamos*maxMin) ) )
            {
                cantReclamosAbonadoConMasMenosReclamos=arrayAbonados[i].contadorLlamadas;
                idAbonadoConMasMenosReclamos=arrayAbonados[i].id;
                retorno=1;
            }
    return retorno;
}


/**
 * @brief cacula la cantidad de llamadas para un motivo de reclamo
 * @param arrayLlamadas el array se pasa como parametro.
 * @param sizeArrayLlamadas el tamaño del array se pasa como parametro.
 * @param motivoReclamo se pasa el motivo del reclamo por el que se quiere calcular la cantidad de llamadas.
 * @return devuelve 0 si no exite ninguna llamada con ese motivo de reclamo o si el tamaño del array es invalido o un puntero NULO), de lo contrario devuelve la cantidad de llamadas por ese motivo.
 */
int cantidadLlamadasDeUnMotivoDeReclamo(ELlamada* arrayLlamadas, int sizeArrayLlamadas, int motivoReclamo)
{
    int i;
    int retorno=0;
    if ( arrayLlamadas==NULL && sizeArrayLlamadas<=0 )
        printf("\n La ejecucion se detendra! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<sizeArrayLlamadas; i++)
            if ( arrayLlamadas[i].flagRegistro==USED && arrayLlamadas[i].motivo==motivoReclamo )
                retorno++;
    return retorno;
}


/**
 * @brief cacula la cantidad de llamadas para un motivo de reclamo
 * @param arrayLlamadas el array se pasa como parametro.
 * @param sizeArrayLlamadas el tamaño del array se pasa como parametro.
 * @return devuelve 0 si no exite ninguna llamada con ese motivo de reclamo o si el tamaño del array es invalido o un puntero NULO), de lo contrario devuelve la cantidad de llamadas por ese motivo.
 */
int cantidadLlamadasDeUnMotivoDeReclamo(ELlamada* arrayLlamadas, int sizeArrayLlamadas)
{
    int i;
    int retorno=0;
    int falla3G;
    int fallaLTE;
    int fallaEquipo:
    int motivoMayorReclamo;
    if ( arrayLlamadas==NULL && sizeArrayLlamadas<=0 )
        printf("\n La ejecucion se detendra! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<sizeArrayLlamadas; i++)
            if ( arrayLlamadas[i].flagRegistro==USED )
            {
                switch (arrayLlamadas[i].motivo)
                {
                    case FALLA_3G:
                        falla3G++;
                        break;

                    case FALLA_LTE:
                        fallaLTE++;
                        break;

                    case FALLA_EQUIPO:
                        fallaEquipo++;
                        break;
                }
            }
                retorno++;
    return retorno;
}
