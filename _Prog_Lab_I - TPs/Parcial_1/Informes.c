#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcionesAuxiliares.h"
#include "Usuarios.h"
#include "Productos.h"
#include "Informes.h"


#define EMPTY 0
#define USED 1
#define DELETED 2

#define TRUE 1
#define FALSE 0



/**
 * @brief muetra por pantalla un listado con los usuarios.
 * @param arrayUsuarios el array se pasa como parametro.
 * @param sizeArrayUsuarios el tamaño del array se pasa como parametro.
 * @return no devuelve nada.
 */
void listarUsuariosConCalificaciones(EUsuario* arrayUsuarios, int sizeArrayUsuarios)
{
    int i;
    int flag=0;
    float promCalif;
    if ( existenUsuarios(arrayUsuarios, sizeArrayUsuarios)==0 )
        printf("\n No se pueden listar usuarios porque no hay ninguno cargado! \n");
    else
    {
        for (i=0; i<sizeArrayUsuarios; i++)
            if (arrayUsuarios[i].flagRegistro==USED && arrayUsuarios[i].contadorCalificaciones!=0)
            {
                promCalif=arrayUsuarios[i].acumuladorCalificaciones/arrayUsuarios[i].contadorCalificaciones;
                printf("\n Id %d - Nombre %s - Promedio Calificaciones %.2f \
                       ", arrayUsuarios[i].id, arrayUsuarios[i].nombre, promCalif);
                flag=1;
            }
        printf("\n");
        if (flag==0)
            printf(" No se pueden listar usuarios porque no hay ninguno con calificaciones! \n");
    }
}


/**
 * @brief muetra por pantalla un listado con los usuarios.
 * @param arrayUsuarios el array se pasa como parametro.
 * @param sizeArrayUsuarios el tamaño del array se pasa como parametro.
 * @return no devuelve nada.
 */
void listarUsuarios(EUsuario* arrayUsuarios, int sizeArrayUsuarios)
{
    int i;
    for (i=0; i<sizeArrayUsuarios; i++)
        if (arrayUsuarios[i].flagRegistro!=EMPTY)
            printf("\n indice %d - Id %d - Nombre %s - Password %s - ContCalif %d - AcumCalif %d - flaReg %d\
                   ",i, arrayUsuarios[i].id, arrayUsuarios[i].nombre, arrayUsuarios[i].password,
                   arrayUsuarios[i].contadorCalificaciones, arrayUsuarios[i].acumuladorCalificaciones, arrayUsuarios[i].flagRegistro);
    printf("\n");
}


/**
 * \brief Imprime por pantalla el listado de publicaciones activas de un usuario
 * \param arrayUsuarios se le pasa como parametro el array-estructura donde se van a modificar los datos
 * \param sizeArrayUsuarios es el tamaño del array-estructura donde se van a guardar los datos
 * \param arrayProductos se le pasa como parametro el array-estructura donde se van a modificar los datos
 * \param sizeArrayProductos es el tamaño del array-estructura donde se van a guardar los datos
 * \return no devuelve nada
 */
void listarPublicacionesUsuarioPorId(EUsuario* arrayUsuarios, int sizeArrayUsuarios, EProducto* arrayProductos, int sizeArrayProductos)
{
    int idUsuario;
    int indiceUsuario;
    if ( arrayProductos==NULL || sizeArrayProductos<=0 || arrayUsuarios==NULL || sizeArrayUsuarios<=0 )
        printf("\n La ejecucion se detendra! Tamaño de array invalido o puntero NULO \n");
    else if ( existenProductosPublicados(arrayProductos, sizeArrayProductos)==0 )
        printf("\n No se pueden listar publicaciones de usuarios porque no hay ninguna cargada! \n");
    else
    {
        indiceUsuario=tomarYcomprobarExistenciaUsuarioPorId(arrayUsuarios,sizeArrayUsuarios,&idUsuario,"\n El listado de publicaciones del usuario ha sido cancelada. \n");

        if(indiceUsuario>=0)
        {
            printf("\n Las publicaciones activas del usuario idUsuario %d - Nombre %s son: \n", idUsuario, arrayUsuarios[indiceUsuario].nombre);
            if( listarProductosUsuario(arrayProductos, sizeArrayProductos, idUsuario)==0 )
                printf("\n No existen publicaciones activas para ese usuario \n");
        }
        else
            printf("\n Usuario inexistente \n");
    }
}


/**
 * @brief muestra por pantalla un listado con los Productos publicados por un usuario.
 * @param arrayProductos el array se pasa como parametro.
 * @param idUsuario se pasa como parametro.
 * @param sizeArrayProductos el tamaño del array se pasa como parametro.
 * @return devuelve 1 si tiene algo que imprimir pantalla o 0 si no hay publicaciones de ese usuario.
 */
int listarProductosUsuario(EProducto* arrayProductos, int sizeArrayProductos, int idUsuario)
{
    int i;
    int retorno=0;
    for (i=0; i<sizeArrayProductos; i++)
        if (arrayProductos[i].flagRegistro==USED && arrayProductos[i].isPublished==TRUE && arrayProductos[i].idUsuario==idUsuario)
        {
            printf("\n idProducto %d - Nombre %s - Precio %.2f - Cantidad Vendida %d - Stock %d\
                   ", arrayProductos[i].id, arrayProductos[i].nombre, arrayProductos[i].precio, arrayProductos[i].cantidadVendida, arrayProductos[i].stock);
            retorno=1;
        }
    printf("\n");
    return retorno;
}


/**
 * @brief muestra por pantalla un listado con los Productos.
 * @param arrayProductos el array se pasa como parametro.
 * @param sizeArrayProductos el tamaño del array se pasa como parametro.
 * @return no devuelve nada.
 */
void listarProductos(EProducto* arrayProductos, int sizeArrayProductos)
{
    int i;
    for (i=0; i<sizeArrayProductos; i++)
        if (arrayProductos[i].flagRegistro!=EMPTY)
            printf("\n Indice %d - Id %d - Nombre %s - idUsuario %d - Precio %.2f - Stock %d - CantVendida %d (isPub %d - FlagReg %d)\
                   ",i, arrayProductos[i].id, arrayProductos[i].nombre, arrayProductos[i].idUsuario, arrayProductos[i].precio,
                   arrayProductos[i].stock, arrayProductos[i].cantidadVendida, arrayProductos[i].isPublished, arrayProductos[i].flagRegistro);
    printf("\n");
}


/**
 * @brief muestra por pantalla un listado con los Productos.
 * @param arrayProductos el array se pasa como parametro.
 * @param sizeArrayProductos el tamaño del array se pasa como parametro.
 * @param arrayUsuarios se le pasa como parametro
 * @param sizeArrayUsuarios es el tamaño del arrayUsuarios
 * @return no devuelve nada.
 */
void listarProductosConNombreUsuario(EProducto* arrayProductos, int sizeArrayProductos, EUsuario* arrayUsuarios, int sizeArrayUsuarios)
{
    int i;
    int flag=0;

    if ( arrayProductos==NULL || sizeArrayProductos<=0 || arrayUsuarios==NULL || sizeArrayUsuarios<=0 )
        printf("\n La ejecucion se detendra! Tamaño de array invalido o puntero NULO \n");
    else if ( existenProductosPublicados(arrayProductos, sizeArrayProductos)==0 )
        printf("\n No se pueden listar publicaciones de usuarios porque no hay ninguna cargada! \n");
    else
    {
        printf("\n Los Productos publicados son: ");
        for (i=0; i<sizeArrayProductos; i++)
            if (arrayProductos[i].flagRegistro==USED)
            {
                printf("\n idProducto %d - Nombre %s - Precio %.2f - Stock %d - CantVendida %d - Nombre Usuario %s\
                       ", arrayProductos[i].id, arrayProductos[i].nombre, arrayProductos[i].precio, arrayProductos[i].stock, arrayProductos[i].cantidadVendida,
                       arrayUsuarios[buscarUsuarioPorId(arrayUsuarios, sizeArrayUsuarios, arrayProductos[i].idUsuario)].nombre );
                flag=1;
            }

        if (flag==0)
            printf("\n No hay productos publicados! ");
    }
    printf("\n");
}


/*
void cargaAutomatica(EUsuario* arrayUsuarios, int sizeArrayUsuarios, EProducto* arrayProductos, int sizeArrayProductos)
{
    arrayUsuarios[0].id=1;
    strcpy(arrayUsuarios[0].nombre,"aaa");
    strcpy(arrayUsuarios[0].password,"a1");
    arrayUsuarios[0].contadorCalificaciones=0;
    arrayUsuarios[0].acumuladorCalificaciones=0;
    arrayUsuarios[0].flagRegistro=USED;

    arrayUsuarios[1].id=2;
    strcpy(arrayUsuarios[1].nombre,"bbb");
    strcpy(arrayUsuarios[1].password,"b1");
    arrayUsuarios[1].contadorCalificaciones=0;
    arrayUsuarios[1].acumuladorCalificaciones=0;
    arrayUsuarios[1].flagRegistro=USED;



    arrayProductos[0].id=1;
    strcpy(arrayProductos[0].nombre,"Prod-ddd");
    arrayProductos[0].precio=10.15;
    arrayProductos[0].idUsuario=1;
    arrayProductos[0].stock=50;
    arrayProductos[0].cantidadVendida=0;
    arrayProductos[0].isPublished=TRUE;
    arrayProductos[0].flagRegistro=USED;

    arrayProductos[1].id=2;
    strcpy(arrayProductos[1].nombre,"Prod-ccc");
    arrayProductos[1].precio=22.22;
    arrayProductos[1].idUsuario=1;
    arrayProductos[1].stock=30;
    arrayProductos[1].cantidadVendida=0;
    arrayProductos[1].isPublished=TRUE;
    arrayProductos[1].flagRegistro=USED;
}

*/

