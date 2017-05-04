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
 * @brief Realiza la inicializacion del arrayLlamadas ingresando el valor EMPTY en el campo flagRegistro.
 * @param array el array se pasa como parametro.
 * @param sizeArray el tamaño del array se pasa como parametro.
 * @return devuelve 1 si se pudo inicializar el array (o 0 si no se pudo porque se paso un tamaño del array invalido o un puntero NULO)
 */
int initArrayLlamadas(ELlamada* arrayLlamadas, int sizeArrayLlamadas)
{
    int i;
    int retorno=0;
    if ( arrayLlamadas==NULL && sizeArrayLlamadas<=0 )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
    {
        for (i=0; i<sizeArrayLlamadas; i++)
        {
            arrayLlamadas[i].flagRegistro=EMPTY;
            arrayLlamadas[i].id=0;
        }
        retorno=1;
    }
    return retorno;
}


/**
 * @brief Obtiene el primer indice libre del array.
 * @param arrayLlamadas el array se pasa como parametro.
 * @param sizeArrayLlamadas el tamaño del array se pasa como parametro.
 * @return devuelve el primer indice disponible (o -1 si no exite ninguno disponible o si el tamaño del array es invalido o un puntero NULO)
 */
int obtenerPosicionLibreArrayLlamadas(ELlamada* arrayLlamadas, int sizeArrayLlamadas)
{
    int i;
    if ( arrayLlamadas==NULL && sizeArrayLlamadas<=0 )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
    {
        for (i=0; i<sizeArrayLlamadas; i++)
            if (arrayLlamadas[i].flagRegistro==EMPTY)
                return i;
        printf("\n No se puede agregar Llamada porque se agoto el espacio disponible! \n");
    }
    return -1;
}


/**
 * @brief busca si se encuentra cargado un id de Llamada.
 * @param arrayLlamadas el array se pasa como parametro.
 * @param sizeArrayLlamadas el tamaño del array se pasa como parametro.
 * @param idLlamada se pasa como como parametro.
 * @return devuelve el indice en que esta guardado los datos de ese Llamada (o -1 si no exite o si el tamaño del array es invalido o un puntero NULO)
 */
int buscarLlamadaPorId(ELlamada* arrayLlamadas, int sizeArrayLlamadas, int idLlamada)
{
    int i;
    if ( arrayLlamadas==NULL && sizeArrayLlamadas<=0 )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<sizeArrayLlamadas; i++)
            if (arrayLlamadas[i].flagRegistro==USED && arrayLlamadas[i].id==idLlamada)
                return i;
    return -1;
}


/**
 * \brief Realiza el ingresdo de datos de una Llamada
 * \param arrayLlamadas se le pasa como parametro el array-estructura donde se van a cargar los datos
 * \param sizeArrayLlamadas es el tamaño del array-estructura donde se van a guardar los datos
 * \param arrayAbonados se le pasa como parametro el array-estructura de abonados para validar su existencia
 * \param sizeArrayAbonados es el tamaño del array-estructura abonados
 * \return devuelve (0) si Tamaño invalido o puntero NULL pointer o sin espacio disponible - (1) si la carga se pudo realizar.
 */
int nuevaLlamada(ELlamada* arrayLlamadas, int sizeArrayLlamadas, EAbonado* arrayAbonados, int sizeArrayAbonados)
{
    ELlamada arrayAuxiliarLlamada[1]; /// es el array-estructura donde se van a guardar provisoriamente los datos
    int retorno=0;
    int indice = obtenerPosicionLibreArrayLlamadas(arrayLlamadas,sizeArrayLlamadas);
    int existeAbonado=-1;

    if ( existenAbonados(arrayAbonados, sizeArrayAbonados)==0 )
        printf("\n No se pueden cargar llamadas porque no existe ningun abonado cargado! \n");
    else if (indice!=-1)
    {
        arrayAuxiliarLlamada[0].id=calcularIdLlamada(arrayLlamadas,sizeArrayLlamadas);
        printf("\n El nro de id para la Llamada a cargar es: %d \n",arrayAuxiliarLlamada[0].id);
        while(existeAbonado==-1)
        {
            arrayAuxiliarLlamada[0].idAbonado=ingresoIdAbonado();
            existeAbonado=buscarAbonadoPorId(arrayAbonados,sizeArrayAbonados,arrayAuxiliarLlamada[0].idAbonado);
            if (existeAbonado==-1)
                printf("\n El id de abonado ingresado no se encuentra cargado! \n ");
        }
        arrayAuxiliarLlamada[0].idAbonado=arrayAuxiliarLlamada[0].idAbonado;
        arrayAuxiliarLlamada[0].motivo=ingresoMotivoLlamada();
        arrayAuxiliarLlamada[0].estado=EN_CURSO;
        arrayAuxiliarLlamada[0].tiempo=0;
        arrayAuxiliarLlamada[0].flagRegistro=USED;

        arrayLlamadas[indice]=arrayAuxiliarLlamada[0];
        retorno=1;
        printf("\n El Llamada ha sido cargado correctamente. \n");
    }
    return retorno;
}


/**
 * \brief Realiza la modificacion de datos de un Llamada
 * \param arrayLlamadas se le pasa como parametro el array-estructura donde se van a modificar los datos
 * \param sizeArrayLlamadas es el tamaño del array-estructura donde se van a guardar los datos
 * \return devuelve (0) si Tamaño invalido o puntero NULL pointer o si no se encuentra el Llamada - (1) si la modificacion se pudo realizar.
 */
int modificarLlamadaPorId(ELlamada* arrayLlamadas, int sizeArrayLlamadas)
{
    ELlamada arrayAuxiliarLlamada[1];  /// es el array-estructura donde se van a guardar provisoriamente los datos
    int retorno=0;
    int existeLlamada;
    char salir='n';

    if ( existenLlamadas(arrayLlamadas, sizeArrayLlamadas)==0 )
    {
        printf("\n No se pueden modificar datos de Llamadas porque no hay ninguna cargada! \n");
        salir='s';
    }
    while (salir!='s' && salir!='S')
    {
        arrayAuxiliarLlamada[0].id=ingresoIdLlamada();
        existeLlamada=buscarLlamadaPorId(arrayLlamadas,sizeArrayLlamadas,arrayAuxiliarLlamada[0].id);
        if(existeLlamada>=0)
        {
            getInt(&arrayLlamadas[existeLlamada].tiempo, "\n Igrese el tiempo insumido en la llamada (en minutos): ", "\
                   \n El dato ingresado es invalido! \n El tiempo maximo a ingresar en minutos es 32999",1,1,1,1,32999);
            arrayLlamadas[existeLlamada].estado=ingresoEstadoLlamada();
            retorno=1;
            printf("\n Se han modificado los datos correctamente. \n");
            break;
        }
        else
            getString("\n El nro. de id del Llamada NO se encuentra ingresado! \
                \n Ingrese 'S' para salir de la carga de datos o cualquier otra tecla para continuar: ",&salir);
    }
    return retorno;
}


/**
 * @brief pide al usuario el id de la Llamada y lo devuelve validado dentro de un rango de enteros.
 * @param no recibe parametros.
 * @return el id validado como int.
 */
int ingresoIdLlamada()
{
    int idLlamada;
    getInt(&idLlamada, "\n Ingrese el id de la Llamada: ", "\n El dato ingresado es invalido!\
        \n El numero de Llamada debe ser un numero positvo entre 1 y 31999",1,1,1,1,31999);
    return idLlamada;
}


/**
 * @brief pide al usuario el motivo de la Llamada y lo devuelve validado dentro de un rango de opciones.
 * @param no recibe parametros.
 * @return la opcion validada como int.
 */
int ingresoMotivoLlamada()
{
    int motivoLlamada;
   /// char opciones="\n 1- FALLA 3G \n 2– FALLA LTE \n 3– FALLA EQUIPO \n\n Ingrese el motivo del Llamada: ";
    getInt(&motivoLlamada, "\n\n Motivos de llamadas \n ------------------- \n 1- FALLA 3G \n 2- FALLA LTE \n 3- FALLA EQUIPO \n\n Ingrese el motivo de la Llamada: ", "\n El dato ingresado es invalido!\
        \n El motivo del a llamada debe ser una de las opciones",1,1,1,1,3);
    return motivoLlamada;
}


/**
 * @brief pide al usuario el estado de la Llamada y lo devuelve validado dentro de un rango de opciones.
 * @param no recibe parametros.
 * @return la opcion validada como int.
 */
int ingresoEstadoLlamada()
{
    int estadoLlamada;
    ///char opciones="\n 1- SOLUCIONADO \n 2– NO SOLUCIONADO \n\n Ingrese el estado final de la Llamada: ";
    getInt(&estadoLlamada, "\n\n Estados para llamadas \n --------------------- \n 1- SOLUCIONADO \n 2- NO SOLUCIONADO \n\n Ingrese el estado final de la Llamada: ", "\n El dato ingresado es invalido!\
        \n El motivo del a llamada debe ser una de las opciones",1,1,1,1,2);
    return estadoLlamada;
}


/**
 * @brief cacula el proximo numero de id de Llamada en una secuencia autoincrementable.
 * @param arrayLlamadas el array se pasa como parametro.
 * @param sizeArrayLlamadas el tamaño del array se pasa como parametro.
 * @return devuelve el proximo id (o -1 si no exite ninguno disponible o si el tamaño del array es invalido o un puntero NULO)
 */
int calcularIdLlamada(ELlamada* arrayLlamadas, int sizeArrayLlamadas)
{
    int nextIdLlamada=0;
    int i;
    if ( arrayLlamadas==NULL && sizeArrayLlamadas<=0 )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<sizeArrayLlamadas; i++)
            if ( i==0 || ( arrayLlamadas[i].flagRegistro==USED && arrayLlamadas[i].id>=nextIdLlamada ) )
                nextIdLlamada=arrayLlamadas[i].id+1;
    return nextIdLlamada;
}


/**
 * @brief cacula si el array de llamadas no está vacio
 * @param arrayLlamadas el array se pasa como parametro.
 * @param sizeArrayLlamadas el tamaño del array se pasa como parametro.
 * @return devuelve 0 si no exite ninguna llamada cargada o si el tamaño del array es invalido o un puntero NULO), de lo contrario devuelve 1.
 */
int existenLlamadas(ELlamada* arrayLlamadas, int sizeArrayLlamadas)
{
    int i;
    if ( arrayLlamadas==NULL && sizeArrayLlamadas<=0 )
        printf("\n La ejecucion se detendra! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<sizeArrayLlamadas; i++)
            if ( arrayLlamadas[i].flagRegistro==USED )
                return 1;
    return 0;
}


/**
 * @brief realiza una baja logica de todas las llamadas de un abonado que fue dado de baja.
 * @param arrayLlamadas el array se pasa como parametro.
 * @param sizeArrayLlamadas el tamaño del array se pasa como parametro.
 * @return devuelve 0 si no exite ninguna llamada para ese abonado o si el tamaño del array es invalido o un puntero NULO, de lo contrario devuelve 1.
 */
int eliminarLlamadasPorBajaAbonado(ELlamada* arrayLlamadas, int sizeArrayLlamadas, int idAbonado)
{
    int i;
    if ( arrayLlamadas==NULL && sizeArrayLlamadas<=0 )
        printf("\n La ejecucion se detendra! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<sizeArrayLlamadas; i++)
            if ( arrayLlamadas[i].idAbonado==idAbonado && arrayLlamadas[i].flagRegistro==USED )
            {
                arrayLlamadas[i].flagRegistro=DELETED;
                return 1;
            }
    return 0;
}


/**
 * @brief muetra por pantalla un listado con los Llamadas.
 * @param arrayLlamadas el array se pasa como parametro.
 * @param sizeArrayLlamadas el tamaño del array se pasa como parametro.
 * @return no devuelve nada.
 */
void listarLlamadas(ELlamada* arrayLlamadas, int sizeArrayLlamadas)
{
    int i;
    for (i=0; i<sizeArrayLlamadas; i++)
        if (arrayLlamadas[i].flagRegistro!=EMPTY)
            printf("\n Id %d - idAbonado %d - Motivo: %d - Estado: %d - Tiempo: %d - FlagRegistro %d\
                   ", arrayLlamadas[i].id, arrayLlamadas[i].idAbonado, arrayLlamadas[i].motivo, arrayLlamadas[i].estado, arrayLlamadas[i].tiempo, arrayLlamadas[i].flagRegistro);
    printf("\n");
}

