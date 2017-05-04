#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcionesAuxiliares.h"
#include "Abonados.h"
#include "Llamadas.h"
#include "Informes.h"


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
 * @return devuelve 1 si lo encontró (o 0 si no pudo encontrarlo o si el tamaño del array es invalido o un puntero NULO)
 */
int listarAbonadoConMasMenosReclamos(EAbonado* arrayAbonados, int sizeArrayAbonados, int maxMin)
{
    int i;
    int retorno=0;
    int cantReclamosAbonadoConMasMenosReclamos=0;
    if ( arrayAbonados==NULL || sizeArrayAbonados<=0 )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
    {
        for (i=0; i<sizeArrayAbonados; i++)
            if (arrayAbonados[i].flagRegistro==USED && (arrayAbonados[i].contadorLlamadas*maxMin) >= (cantReclamosAbonadoConMasMenosReclamos*maxMin) )
            {
                cantReclamosAbonadoConMasMenosReclamos=arrayAbonados[i].contadorLlamadas;
                printf("\n mas reclamo: %d \n",cantReclamosAbonadoConMasMenosReclamos);
                retorno=1;
            }
        if (retorno!=0) /// con esto imprimo por pantalla
        {
            printf("\n El/los abonados con mas reclamos es/son: \n");
            for (i=0; i<sizeArrayAbonados; i++)
                if (arrayAbonados[i].flagRegistro==USED && arrayAbonados[i].contadorLlamadas==cantReclamosAbonadoConMasMenosReclamos )
                    printf("\n Id %d - Nro %d - Nombre: %s - Apellido: %s - Cantidad Llamadas: %d - FlagRegistro %d\
                            ", arrayAbonados[i].id, arrayAbonados[i].numero, arrayAbonados[i].nombre, arrayAbonados[i].apellido, arrayAbonados[i].contadorLlamadas, arrayAbonados[i].flagRegistro);
            printf("\n ");
        }
        else
            printf("\n No se puede informar porque no hay abonados cargados! \n");
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
    if ( arrayLlamadas==NULL || sizeArrayLlamadas<=0 )
        printf("\n La ejecucion se detendra! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<sizeArrayLlamadas; i++)
            if ( arrayLlamadas[i].flagRegistro==USED && arrayLlamadas[i].motivo==motivoReclamo )
                retorno++;
    return retorno;
}


/**
 * @brief lista por pantalla cual fue el reclamo mas realizado
 * @param arrayLlamadas el array se pasa como parametro.
 * @param sizeArrayLlamadas el tamaño del array se pasa como parametro.
 * @return devuelve 0 si no exite ninguna llamada o si el tamaño del array es invalido o un puntero NULO, de lo contrario devuelve 1.
 */
int listarMotivoLlamadaMasRealizado(ELlamada* arrayLlamadas, int sizeArrayLlamadas)
{
    int i;
    int retorno=0;
    int motivoReclamo[4]={0,0,0,0};
    int cantidadLlamadasMotivoMasReclamado=0;
    if ( arrayLlamadas==NULL || sizeArrayLlamadas<=0 )
        printf("\n La ejecucion se detendra! Tamaño de array invalido o puntero NULO \n");
    else
    {
        for (i=0; i<sizeArrayLlamadas; i++) /// con esto calculo la cantidad de llamadas por cada motivo y lo guardo en el array auxiliar
            if ( arrayLlamadas[i].flagRegistro==USED )
            {
                motivoReclamo[ arrayLlamadas[i].motivo ]++;
                retorno=1;
            }

        for (i=1; i<4; i++) /// con esto calculo la cantidad maxima de llamadas por un o mas motivos
            if (motivoReclamo[i]>=cantidadLlamadasMotivoMasReclamado)
                cantidadLlamadasMotivoMasReclamado=motivoReclamo[i];

        if (retorno!=0) /// con esto imprimo por pantalla
        {
            printf("\n El/los motivo/s de reclamos mas realizado es/son: \n");
            for (i=1; i<4; i++)
            {
                if ( motivoReclamo[i] >= cantidadLlamadasMotivoMasReclamado )
                    switch(i)
                    {
                        case FALLA_3G:
                            printf("- FALLA 3G \n");
                            break;
                        case FALLA_LTE:
                            printf("- FALLA LTE \n");
                            break;
                        case FALLA_EQUIPO:
                            printf("- FALLA EQUIPO \n");
                            break;
                    }
            }
        }
        else
            printf("\n No se puede informar porque no hay llamadas cargadas! \n");
    }
    return retorno;
}



/**
 * @brief lista por pantalla el motivo de la llamada que mas demoró en ser resuelto
 * @param arrayLlamadas el array se pasa como parametro.
 * @param sizeArrayLlamadas el tamaño del array se pasa como parametro.
 * @return devuelve 0 si no exite ninguna llamada o si el tamaño del array es invalido o un puntero NULO, de lo contrario devuelve la cantidad de llamadas por ese motivo.
 */
int listarReclamoQueMasDemora(ELlamada* arrayLlamadas, int sizeArrayLlamadas)
{
    int i;
    int retorno=0;
    int indice;
    EPromedioLlamada arrayPromedioLlamadas[4];
    int llamadaMayorPromedioTiempo=0;

    if ( arrayLlamadas==NULL || sizeArrayLlamadas<=0 )
        printf("\n La ejecucion se detendra! Tamaño de array invalido o puntero NULO \n");
    else
    {
        for (i=0; i<4; i++)
        {
            arrayPromedioLlamadas[i].contador=0;
            arrayPromedioLlamadas[i].tiempo=0;
            arrayPromedioLlamadas[i].promedio=0;
        }

        for (i=0; i<sizeArrayLlamadas; i++)
            if ( arrayLlamadas[i].flagRegistro==USED && arrayLlamadas[i].estado!=EN_CURSO )
            {
                retorno=1;
                indice=arrayLlamadas[i].motivo;
                arrayPromedioLlamadas[indice].contador++;
                arrayPromedioLlamadas[indice].tiempo=arrayPromedioLlamadas[indice].tiempo+arrayLlamadas[i].tiempo;
                arrayPromedioLlamadas[indice].promedio=arrayPromedioLlamadas[indice].tiempo/arrayPromedioLlamadas[indice].contador;
            }

        for (i=0; i<4; i++)
            if (arrayPromedioLlamadas[i].promedio>llamadaMayorPromedioTiempo)
                llamadaMayorPromedioTiempo=arrayPromedioLlamadas[i].promedio;

        if (retorno!=0) /// con esto imprimo por pantalla
        {
            printf("\n El/los reclamo/s que en promedio mas demora/n en ser resuelto/s es/son: \n");
            for (i=1; i<4; i++)
            {
                if ( arrayPromedioLlamadas[i].promedio >= llamadaMayorPromedioTiempo )
                    switch(i)
                    {
                        case FALLA_3G:
                            printf("- FALLA 3G \n");
                            break;
                        case FALLA_LTE:
                            printf("- FALLA LTE \n");
                            break;
                        case FALLA_EQUIPO:
                            printf("- FALLA EQUIPO \n");
                            break;
                    }
            }
        }
        else
            printf("\n No se puede informar porque no hay llamadas cargadas! \n");

    }
    return retorno;
}


