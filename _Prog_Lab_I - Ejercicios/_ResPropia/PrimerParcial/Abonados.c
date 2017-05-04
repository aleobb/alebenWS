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


/**
 * @brief Realiza la inicializacion del arrayAbonados ingresando el valor EMPTY en el campo flagRegistro.
 * @param arrayPersonas el array se pasa como parametro.
 * @param sizeArray el tamaño del array se pasa como parametro.
 * @return devuelve 1 si se pudo inicializar el array (o 0 si no se pudo porque se paso un tamaño del array invalido o un puntero NULO)
 */
int initArrayAbonados(EAbonado* arrayAbonados, int sizeArrayAbonados)
{
    int i;
    int retorno=0;
    if ( arrayAbonados==NULL && sizeArrayAbonados<=0 )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
    {
        for (i=0; i<sizeArrayAbonados; i++)
        {
            arrayAbonados[i].flagRegistro=EMPTY;
            arrayAbonados[i].id=0;
        }
        retorno=1;
    }
    return retorno;
}


/**
 * @brief Obtiene el primer indice libre del array.
 * @param arrayAbonados el array se pasa como parametro.
 * @param sizeArrayAbonados el tamaño del array se pasa como parametro.
 * @return devuelve el primer indice disponible (o -1 si no exite ninguno disponible o si el tamaño del array es invalido o un puntero NULO)
 */
int obtenerPosicionLibreArrayAbonados(EAbonado* arrayAbonados, int sizeArrayAbonados)
{
    int i;
    if ( arrayAbonados==NULL && sizeArrayAbonados<=0 )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
    {
        for (i=0; i<sizeArrayAbonados; i++)
            if (arrayAbonados[i].flagRegistro==EMPTY)
                return i;
        printf("\n No se puede agregar abonado porque se agoto el espacio disponible! \n");
    }
    return -1;
}


/**
 * @brief busca si se encuentra cargado un id de Abonado.
 * @param arrayAbonados el array se pasa como parametro.
 * @param sizeArrayAbonados el tamaño del array se pasa como parametro.
 * @param idAbonado se pasa como como parametro.
 * @return devuelve el indice en que esta guardado los datos de ese abonado (o -1 si no exite o si el tamaño del array es invalido o un puntero NULO)
 */
int buscarAbonadoPorId(EAbonado* arrayAbonados, int sizeArrayAbonados, int idAbonado)
{
    int i;
    if ( arrayAbonados==NULL && sizeArrayAbonados<=0 )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<sizeArrayAbonados; i++)
            if (arrayAbonados[i].flagRegistro==USED && arrayAbonados[i].id==idAbonado)
                return i;
    return -1;
}


/**
 * @brief busca si se encuentra cargado un numero de Abonado.
 * @param arrayAbonados el array se pasa como parametro.
 * @param sizeArrayAbonados el tamaño del array se pasa como parametro.
 * @param numeroAbonado se pasa como como parametro.
 * @return devuelve el indice en que esta guardado los datos de ese abonado (o -1 si no exite o si el tamaño del array es invalido o un puntero NULO)
 */
int buscarAbonadoPorNumero(EAbonado* arrayAbonados, int sizeArrayAbonados, int numeroAbonado)
{
    int i;
    if ( arrayAbonados==NULL && sizeArrayAbonados<=0 )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<sizeArrayAbonados; i++)
            if (arrayAbonados[i].flagRegistro==USED && arrayAbonados[i].numero==numeroAbonado)
                return i;
    return -1;
}


/**
 * \brief Realiza el ingresdo de datos de un abonado
 * \param arrayAbonados se le pasa como parametro el array-estructura donde se van a cargar los datos
 * \param sizeArrayAbonados es el tamaño del array-estructura donde se van a guardar los datos
 * \return devuelve (0) si Tamaño invalido o puntero NULL pointer o sin espacio disponible - (1) si la carga se pudo realizar.
 */
int altaAbonado(EAbonado* arrayAbonados, int sizeArrayAbonados)
{
    EAbonado arrayAuxiliarAbonado[1]; /// es el array-estructura donde se van a guardar provisoriamente los datos
    int retorno=0;
    int existeAbonado;
    char salir='n';
    int indice = obtenerPosicionLibreArrayAbonados(arrayAbonados,sizeArrayAbonados);

    while (salir!='s' && salir!='S' && indice!=-1)
    {
        arrayAuxiliarAbonado[0].id=calcularIdAbonado(arrayAbonados,sizeArrayAbonados);
        printf("\n El nro de id para el abonado a cargar es: %d \n",arrayAuxiliarAbonado[0].id);
        arrayAuxiliarAbonado[0].numero=ingresoNumeroAbonado();
        existeAbonado=buscarAbonadoPorNumero(arrayAbonados,sizeArrayAbonados,arrayAuxiliarAbonado[0].numero);
        if(existeAbonado<0)
        {
            cargaNombreYapellidoAbonado(arrayAuxiliarAbonado);
            arrayAuxiliarAbonado[0].flagRegistro=USED;
            arrayAuxiliarAbonado[0].contadorLlamadas=0;
            arrayAbonados[indice]=arrayAuxiliarAbonado[0];
            retorno=1;
            printf("\n El abonado ha sido cargado correctamente. \n");
            break;
        }
        else
            getString("\n El nro. de abonado ya se encuentra ingresado! \
                \n Ingrese 'S' para salir de la carga de datos o cualquier otra tecla para continuar: ",&salir);
    }
    return retorno;
}


/**
 * \brief Realiza la modificacion de datos de un abonado
 * \param arrayAbonados se le pasa como parametro el array-estructura donde se van a modificar los datos
 * \param sizeArrayAbonados es el tamaño del array-estructura donde se van a guardar los datos
 * \return devuelve (0) si Tamaño invalido o puntero NULL pointer o si no se encuentra el abonado - (1) si la modificacion se pudo realizar.
 */
int modificarAbonadoPorId(EAbonado* arrayAbonados, int sizeArrayAbonados)
{
    EAbonado arrayAuxiliarAbonado[1]; /// es el array-estructura donde se van a guardar provisoriamente los datos
    int retorno=0;
    int existeAbonado;
    char salir='n';

    if ( existenAbonados(arrayAbonados, sizeArrayAbonados)==0 )
    {
        printf("\n No se pueden modificar datos de abonados porque no hay ninguno cargado! \n");
        salir='s';
    }
    while (salir!='s' && salir!='S')
    {
        arrayAuxiliarAbonado[0].id=ingresoIdAbonado();
        existeAbonado=buscarAbonadoPorId(arrayAbonados,sizeArrayAbonados,arrayAuxiliarAbonado[0].id);
        if(existeAbonado>=0)
        {
            cargaNombreYapellidoAbonado(arrayAuxiliarAbonado);
            strcpy(arrayAbonados[existeAbonado].nombre,arrayAuxiliarAbonado[0].nombre);
            strcpy(arrayAbonados[existeAbonado].apellido,arrayAuxiliarAbonado[0].apellido);
            retorno=1;
            printf("\n Se han modificado los datos correctamente. \n");
            break;
        }
        else
            getString("\n El nro. de id del abonado NO se encuentra ingresado! \
                \n Ingrese 'S' para salir de la carga de datos o cualquier otra tecla para continuar: ",&salir);
    }
    return retorno;
}


/**
 * \brief  Realiza la baja logica del registro de datos de una persona.
 * \param arrayAbonados se le pasa como parametro el array-estructura donde se encuentra el abonado cuyos datos se quieren dar de baja.
 * \param sizeArrayAbonados es el tamaño del array-estructura donde se van a guardar los datos
 * \return devuelve (0) si Tamaño invalido o puntero NULL pointer o si no se encuentra el abonado - (1) si la baja se pudo realizar.
 */
int bajaAbonadoPorId(EAbonado* arrayAbonados, int sizeArrayAbonados, ELlamada* arrayLlamadas, int sizeArrayLlamadas)
{
    EAbonado arrayAuxiliarAbonado[1]; /// es el array-estructura donde se van a guardar provisoriamente los datos
    int retorno=0;
    int existeAbonado;
    char salir='n';

    if ( existenAbonados(arrayAbonados, sizeArrayAbonados)==0 )
    {
        printf("\n No se puede eliminar un abonado porque no hay ninguno cargado! \n");
        salir='s';
    }
    while (salir!='s' && salir!='S')
    {
        arrayAuxiliarAbonado[0].id=ingresoIdAbonado();
        existeAbonado=buscarAbonadoPorId(arrayAbonados,sizeArrayAbonados,arrayAuxiliarAbonado[0].id);
        if(existeAbonado>=0)
        {
            retorno=1;
            arrayAbonados[existeAbonado].flagRegistro=DELETED;
            eliminarLlamadasPorBajaAbonado(arrayLlamadas,sizeArrayLlamadas,arrayAbonados[existeAbonado].id);
            printf("\n El abonado id nro. %d  ha sido dado de baja correctamente. \n", arrayAuxiliarAbonado[0].id);
            break;
        }
        else
            getString("\n El nro. de id del abonado NO se encuentra ingresado! \
                \n Ingrese 'S' para salir de la carga de datos o cualquier otra tecla para continuar: ",&salir);
    }
    return retorno;
}


/**
 * @brief pide al usuario el numero del abonado y lo devuelve validado dentro de un rango de enteros.
 * @param no recibe parametros.
 * @return el numero validado como int.
 */
int ingresoNumeroAbonado()
{
    int numeroAbonado;
    getInt(&numeroAbonado, "\n Ingrese el numero del abonado: ", "\n El dato ingresado es invalido!\
        \n El numero de abonado debe ser un numero positvo entre 1 y 31999",1,1,1,1,31999);
    return numeroAbonado;
}


/**
 * @brief pide al usuario el numero del abonado y lo devuelve validado dentro de un rango de enteros.
 * @param no recibe parametros.
 * @return el numero validado como int.
 */
int ingresoIdAbonado()
{
    int idAbonado;
    getInt(&idAbonado, "\n Ingrese el id del abonado: ", "\n El dato ingresado es invalido!\
        \n El id debe ser un numero positvo entre 1 y 31999",1,1,1,1,31999);
    return idAbonado;
}


/**
 * @brief cacula el proximo numero de id de abonado en una secuencia autoincrementable.
 * @param arrayAbonados el array se pasa como parametro.
 * @param sizeArrayAbonados el tamaño del array se pasa como parametro.
 * @return devuelve el proximo id (o -1 si no exite ninguno disponible o si el tamaño del array es invalido o un puntero NULO)
 */
int calcularIdAbonado(EAbonado* arrayAbonados, int sizeArrayAbonados)
{
    int nextIdAbonado=0;
    int i;
    if ( arrayAbonados==NULL && sizeArrayAbonados<=0 )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<sizeArrayAbonados; i++)
            if ( i==0 || ( arrayAbonados[i].flagRegistro==USED && arrayAbonados[i].id>=nextIdAbonado ) )
                nextIdAbonado=arrayAbonados[i].id+1;
    return nextIdAbonado;
}


/**
 * @brief cacula si el array de abonados no está vacio
 * @param arrayAbonados el array se pasa como parametro.
 * @param sizeArrayAbonados el tamaño del array se pasa como parametro.
 * @return devuelve 0 si no exite ningun abonado cargado o si el tamaño del array es invalido o un puntero NULO), de lo contrario devuelve 1.
 */
int existenAbonados(EAbonado* arrayAbonados, int sizeArrayAbonados)
{
    int i;
    if ( arrayAbonados==NULL && sizeArrayAbonados<=0 )
        printf("\n La ejecucion se detendra! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<sizeArrayAbonados; i++)
            if ( arrayAbonados[i].flagRegistro==USED )
                return 1;
    return 0;
}


/**
 * @brief pide al usuario los datos de nombre y apellido del abonado y los carga (validados) en un array auxiliar recibido como parametro.
 * @param arrayAuxiliar el array se pasa como parametro.
 * @return no devuelve nada.
 */
void cargaNombreYapellidoAbonado(EAbonado* arrayAuxiliarAbonado)
{
    char arrayCharsAdmitidos[1]=" ";
    getType("\n Ingrese el nombre del abonado: ", "\n El dato ingresado es invalido!\
        \n Solo se adminten letras y espacios y que no exceda los 49 caracteres \n",1,1,arrayCharsAdmitidos,49,arrayAuxiliarAbonado[0].nombre);
    getType("\n Ingrese el apellido del abonado: ", "\n El dato ingresado es invalido!\
        \n Solo se adminten letras y espacios y que no exceda los 49 caracteres \n",1,1,arrayCharsAdmitidos,49,arrayAuxiliarAbonado[0].apellido);
    /*
    getInt(&arrayAuxiliar[0].edad, "\n Ingrese la edad de la persona: ", "\n El dato ingresado es invalido!\
        \n La edad debe ser un numero positvo entre 0 y 150 \n",1,1,0,1,150);
    */
}


/**
 * @brief muetra por pantalla un listado con los abonados.
 * @param arrayAbonados el array se pasa como parametro.
 * @param sizeArrayAbonados el tamaño del array se pasa como parametro.
 * @return no devuelve nada.
 */
void listarAbonados(EAbonado* arrayAbonados, int sizeArrayAbonados)
{
    int i;
    for (i=0; i<sizeArrayAbonados; i++)
        if (arrayAbonados[i].flagRegistro!=EMPTY)
            printf("\n Id %d - Nro %d - Nombre: %s - Apellido: %s - Cantidad Llamadas: %d - FlagRegistro %d\
                   ", arrayAbonados[i].id, arrayAbonados[i].numero, arrayAbonados[i].nombre, arrayAbonados[i].apellido, arrayAbonados[i].contadorLlamadas, arrayAbonados[i].flagRegistro);
    printf("\n");
}

