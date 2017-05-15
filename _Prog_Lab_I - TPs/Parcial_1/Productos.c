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
 * @brief Realiza la inicializacion del arrayProductos ingresando el valor EMPTY en el campo flagRegistro.
 * @param array el array se pasa como parametro.
 * @param sizeArrayProductos el tamaño del array se pasa como parametro.
 * @return devuelve 1 si se pudo inicializar el array (o 0 si no se pudo porque se paso un tamaño del array invalido o un puntero NULO)
 */
int initArrayProductos(EProducto* arrayProductos, int sizeArrayProductos)
{
    int i;
    int retorno=0;
    if ( arrayProductos==NULL || sizeArrayProductos<=0 )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
    {
        for (i=0; i<sizeArrayProductos; i++)
        {
            arrayProductos[i].flagRegistro=EMPTY;
            arrayProductos[i].id=0;
        }
        retorno=1;
    }
    return retorno;
}


/**
 * @brief Obtiene el primer indice libre del array.
 * @param arrayProductos el array se pasa como parametro.
 * @param sizeArrayProductos el tamaño del array se pasa como parametro.
 * @return devuelve el primer indice disponible (o -1 si no exite ninguno disponible o si el tamaño del array es invalido o un puntero NULO)
 */
int obtenerPosicionLibreArrayProductos(EProducto* arrayProductos, int sizeArrayProductos)
{
    int i;
    if ( arrayProductos==NULL || sizeArrayProductos<=0 )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
    {
        for (i=0; i<sizeArrayProductos; i++)
            if (arrayProductos[i].flagRegistro==EMPTY)
                return i;
        printf("\n No se puede agregar Producto porque se agoto el espacio disponible! \n");
    }
    return -1;
}


/**
 * @brief busca si se encuentra cargado un id de Producto.
 * @param arrayProductos el array se pasa como parametro.
 * @param sizeArrayProductos el tamaño del array se pasa como parametro.
 * @param idProducto se pasa como como parametro.
 * @return devuelve el indice en que esta guardado los datos de ese Producto (o -1 si no exite o si el tamaño del array es invalido o un puntero NULO)
 */
int buscarProductoPorId(EProducto* arrayProductos, int sizeArrayProductos, int idProducto)
{
    int i;
    if ( arrayProductos==NULL && sizeArrayProductos<=0 )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<sizeArrayProductos; i++)
            if (arrayProductos[i].flagRegistro==USED && arrayProductos[i].id==idProducto)
                return i;
    return -1;
}


/**
 * \brief Realiza el ingresdo de datos de una Producto
 * \param arrayProductos se le pasa como parametro el array-estructura donde se van a cargar los datos
 * \param sizeArrayProductos es el tamaño del array-estructura donde se van a guardar los datos
 * \param arrayUsuarios se le pasa como parametro el array-estructura de usuarios para validar su existencia
 * \param sizeArrayUsuarios es el tamaño del array-estructura usuarios
 * \return devuelve (0) si Tamaño invalido o puntero NULL pointer o sin espacio disponible - (1) si la carga se pudo realizar.
 */
int nuevaPublicacion(EProducto* arrayProductos, int sizeArrayProductos, EUsuario* arrayUsuarios, int sizeArrayUsuarios)
{
    EProducto arrayAuxiliarProducto[1]; /// es el array-estructura donde se van a guardar provisoriamente los datos
    int retorno=0;
    int indiceProducto = obtenerPosicionLibreArrayProductos(arrayProductos,sizeArrayProductos);
    int indiceUsuario;

    if ( existenUsuarios(arrayUsuarios, sizeArrayUsuarios)==0 )
        printf("\n No se puede hacer una Publicacion porque no existe ningun usuario cargado! \n");
    else if (indiceProducto!=-1)
    {
        arrayAuxiliarProducto[0].id=calcularIdProducto(arrayProductos,sizeArrayProductos);
        printf("\n El nro de id para el Producto a cargar es: %d \n",arrayAuxiliarProducto[0].id);
        indiceUsuario=tomarYcomprobarExistenciaUsuarioPorId(arrayUsuarios,sizeArrayUsuarios,&arrayAuxiliarProducto[0].idUsuario,"\n El alta de la publicacion ha sido cancelada. \n");
        if(indiceUsuario>=0)
        {
            cargaNombreProducto(arrayAuxiliarProducto);
            arrayAuxiliarProducto[0].precio=ingresoPrecioProducto();
            arrayAuxiliarProducto[0].stock=ingresoStockProducto();
            arrayAuxiliarProducto[0].cantidadVendida=0;
            arrayAuxiliarProducto[0].isPublished=TRUE;
            arrayAuxiliarProducto[0].flagRegistro=USED;

            arrayProductos[indiceProducto]=arrayAuxiliarProducto[0];
            retorno=1;
            printf("\n EL producto se ha publicado correctamente. \n");
        }
    }
    return retorno;
}


/**
 * \brief Realiza la modificacion de datos de una Publicaion
 * \param arrayProductos se le pasa como parametro el array-estructura donde se van a modificar los datos
 * \param sizeArrayProductos es el tamaño del array-estructura donde se van a guardar los datos
 * \return devuelve (0) si Tamaño invalido o puntero NULL pointer o si no se encuentra el Producto - (1) si la modificacion se pudo realizar.
 */
int modificarPublicacionPorIdUsuario(EProducto* arrayProductos, int sizeArrayProductos, EUsuario* arrayUsuarios, int sizeArrayUsuarios)
{
    EProducto arrayAuxiliarProducto[1];  /// es el array-estructura donde se van a guardar provisoriamente los datos
    int retorno=0;
    int indiceProducto;
    int indiceUsuario;
    int controlIdProducto=0;
    int controlIdUsuario=0;

    if ( existenProductosPublicados(arrayProductos, sizeArrayProductos)==0 )
        printf("\n No se pueden modificar publicaciones porque no hay ninguna cargada! \n");
    else
    {

        indiceUsuario=tomarYcomprobarExistenciaUsuarioPorId(arrayUsuarios,sizeArrayUsuarios,&arrayAuxiliarProducto[0].idUsuario,"\n La modificacion de la publicacion ha sido cancelada. \n");
        if(indiceUsuario>=0)
        {
            controlIdUsuario=listarProductosUsuario(arrayProductos,sizeArrayProductos,arrayAuxiliarProducto[0].idUsuario);
            if (controlIdUsuario==0)
            {
                printf("\n No se pueden modificar publicaciones porque ese usuario no tiene ninguna realizada! \n");
                return retorno;
            }
            while(controlIdProducto==0)
            {
                indiceProducto=tomarYcomprobarExistenciaProductoPorId(arrayProductos, sizeArrayProductos, &arrayAuxiliarProducto[0].id,"\n La modificacion de la publicacion ha sido cancelada. \n");
                if(arrayProductos[indiceProducto].idUsuario==arrayAuxiliarProducto[0].idUsuario || arrayAuxiliarProducto[0].id==0)
                    controlIdProducto=1;
                else
                    printf("\n El id del producto ingresado no corresponde a ese usuario! Reingrese. \n");
            }
            if(indiceProducto>=0)
            {
                arrayAuxiliarProducto[0].precio=ingresoPrecioProducto();
                arrayAuxiliarProducto[0].stock=ingresoStockProducto();
                arrayProductos[indiceProducto].precio=arrayAuxiliarProducto[0].precio;
                arrayProductos[indiceProducto].stock=arrayAuxiliarProducto[0].stock;
                retorno=1;
                printf("\n La publicacion ha sido modificada correctamente. \n");
            }
        }
    }
    return retorno;
}


/**
 * \brief Realiza la baja logica de una publicacion
 * \param arrayProductos se le pasa como parametro el array-estructura donde se van a modificar los datos
 * \param sizeArrayProductos es el tamaño del array-estructura donde se van a guardar los datos
 * \return devuelve (0) si Tamaño invalido o puntero NULL pointer o si no se encuentra el Producto - (1) si la baja se pudo realizar.
 */
int cancelarPublicacionPorIdUsuario(EProducto* arrayProductos, int sizeArrayProductos, EUsuario* arrayUsuarios, int sizeArrayUsuarios)
{
    EProducto arrayAuxiliarProducto[1];  /// es el array-estructura donde se van a guardar provisoriamente los datos
    int retorno=0;
    int indiceProducto;
    int indiceUsuario;
    int controlIdProducto=0;
    int controlIdUsuario=0;

    if ( existenProductosPublicados(arrayProductos, sizeArrayProductos)==0 )
        printf("\n No se pueden eliminar publicaciones porque no hay ninguna cargada! \n");
    else
    {

        indiceUsuario=tomarYcomprobarExistenciaUsuarioPorId(arrayUsuarios,sizeArrayUsuarios,&arrayAuxiliarProducto[0].idUsuario,"\n La modificacion de la publicacion ha sido cancelada. \n");
        if(indiceUsuario>=0)
        {
            controlIdUsuario=listarProductosUsuario(arrayProductos,sizeArrayProductos,arrayAuxiliarProducto[0].idUsuario);
            if (controlIdUsuario==0)
            {
                printf("\n No se pueden eliminar publicaciones porque ese usuario no tiene ninguna realizada! \n");
                return retorno;
            }
            while(controlIdProducto==0)
            {
                indiceProducto=tomarYcomprobarExistenciaProductoPorId(arrayProductos, sizeArrayProductos, &arrayAuxiliarProducto[0].id,"\n La modificacion de la publicacion ha sido cancelada. \n");
                if(arrayProductos[indiceProducto].idUsuario==arrayAuxiliarProducto[0].idUsuario || arrayAuxiliarProducto[0].id==0)
                    controlIdProducto=1;
                else
                    printf("\n El id del producto ingresado no corresponde a ese usuario! Reingrese. \n");
            }
            if(indiceProducto>=0)
            {
                arrayProductos[indiceProducto].isPublished=FALSE;
                arrayProductos[indiceProducto].flagRegistro=DELETED;
                retorno=1;
                printf("\n La publicacion ha sido dada de baja correctamente. \n");
            }
        }
    }
    return retorno;
}


/**
 * @brief pide al usuario el id del producto y comprueba que exista.
 * @param arrayProductos el array se pasa como parametro.
 * @param sizeArrayProductos el tamaño del array se pasa como parametro.
 * @param idProducto variable donde se va a guardar el idProducto tomado.
 * @param leyendaCancelar Se le pasa la leyenda a mostrar en caso de desistir del ingreso
 * @return devuelve -1 si se desistio de la carga, -2 si el tamaño del array es invalido o un puntero NULO, de lo contrario devuelve el indice del idProducto en arrayProductos.
 */
int tomarYcomprobarExistenciaProductoPorId(EProducto* arrayProductos, int sizeArrayProductos,int* idProducto, char* leyendaCancelar)
{
    int retorno=-2;
    int indiceProducto;

    if ( arrayProductos==NULL || sizeArrayProductos<=0 )
        printf("\n La ejecucion se detendra! Tamaño de array invalido o puntero NULO \n");
    else
        while(retorno<-1)
        {
            getInt(idProducto, "\n Ingrese el id del producto (0 para cancelar): ", "\n El dato ingresado es invalido!\
                \n El id debe ser un numero positvo entre 0 y 31999",1,1,0,1,31999);
            if (*idProducto==0)
            {
                printf("%s",leyendaCancelar);
                retorno=-1;
            }
            else
            {
                indiceProducto=buscarProductoPorId(arrayProductos, sizeArrayProductos, *idProducto);
                if ( indiceProducto == -1)
                    printf("\n El nro. de id del producto NO se encuentra ingresado! Reingrese \n");
                else
                    retorno=indiceProducto;
            }
        }
    return retorno;
}


/**
 * @brief pide al usuario los datos de nombre del producto y los carga (validados) en un array auxiliar recibido como parametro.
 * @param arrayAuxiliar el array se pasa como parametro.
 * @return no devuelve nada.
 */
void cargaNombreProducto(EProducto* arrayAuxiliarProducto)
{
    char arrayCharsAdmitidos[1]=" ";
    getType("\n Ingrese el nombre del producto: ", "\n El dato ingresado es invalido!\
        \n Solo se adminten letras, numeros, espacios y que no exceda los 49 caracteres \n",1,2,arrayCharsAdmitidos,49,arrayAuxiliarProducto[0].nombre);

}


/**
 * @brief pide al usuario el id de el Producto y lo devuelve validado dentro de un rango de enteros.
 * @param no recibe parametros.
 * @return el id validado como int.
 */
int ingresoIdProducto()
{
    int idProducto;
    getInt(&idProducto, "\n Ingrese el id de el Producto: ", "\n El dato ingresado es invalido!\
        \n El numero de Producto debe ser un numero positvo entre 1 y 31999",1,1,1,1,31999);
    return idProducto;
}


/**
 * @brief pide al usuario el precio de el Producto y lo devuelve validado dentro de un rango de flotantes.
 * @param no recibe parametros.
 * @return el id validado como float.
 */
float ingresoPrecioProducto()
{
    float precio;
    getFloat(&precio, "\n Ingrese el precio del Producto: ", "\n El dato ingresado es invalido!\
        \n El precio de Producto debe ser un numero positvo entre 0.01 y 31999.99",1,1,0.01,1,31999.99);
    return precio;
}


/**
 * @brief pide al usuario el stock del Producto y lo devuelve validado dentro de un rango de enteros.
 * @param no recibe parametros.
 * @return el id validado como int.
 */
int ingresoStockProducto()
{
    int stock;
    getInt(&stock, "\n Ingrese el stock del Producto: ", "\n El dato ingresado es invalido!\
        \n El stock de Producto debe ser un numero positvo entre 1 y 31999",1,1,1,1,31999);
    return stock;
}


/**
 * @brief pide al usuario la cantidad vendida del Producto y lo devuelve validado dentro de un rango de enteros.
 * @param stock se le pasa como parametro.
 * @return candidad vendida valida.
 */
int ingresoCantidadVendidaProducto(int stock)
{
    int cantidadVendida=0;
    do
    {
        getInt(&cantidadVendida, "\n Ingrese la cantidad vendida del Producto: ", "\n El dato ingresado es invalido!\
            \n El precio de Producto debe ser un numero positvo entre 1 y 31999",1,1,1,1,31999);
        if (cantidadVendida>stock)
            printf("\n La cantidad ingresada es invalida! No puede superar la cantidad en stock (%d) \n", stock);
    }while(cantidadVendida<=stock);
    return cantidadVendida;
}


/**
 * @brief cacula el proximo numero de id de Producto en una secuencia autoincrementable.
 * @param arrayProductos el array se pasa como parametro.
 * @param sizeArrayProductos el tamaño del array se pasa como parametro.
 * @return devuelve el proximo id (o -1 si no exite ninguno disponible o si el tamaño del array es invalido o un puntero NULO)
 */
int calcularIdProducto(EProducto* arrayProductos, int sizeArrayProductos)
{
    int nextIdProducto=0;
    int i;
    if ( arrayProductos==NULL || sizeArrayProductos<=0 )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<sizeArrayProductos; i++)
            if ( i==0 || ( arrayProductos[i].flagRegistro!=EMPTY && arrayProductos[i].id>=nextIdProducto ) )
                nextIdProducto=arrayProductos[i].id+1;
    return nextIdProducto;
}


/**
 * @brief cacula si el array de Productos no está vacio
 * @param arrayProductos el array se pasa como parametro.
 * @param sizeArrayProductos el tamaño del array se pasa como parametro.
 * @return devuelve 0 si no exite ninguna Producto cargada o si el tamaño del array es invalido o un puntero NULO), de lo contrario devuelve 1.
 */
int existenProductosPublicados(EProducto* arrayProductos, int sizeArrayProductos)
{
    int i;
    if ( arrayProductos==NULL || sizeArrayProductos<=0 )
        printf("\n La ejecucion se detendra! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<sizeArrayProductos; i++)
            if ( arrayProductos[i].flagRegistro==USED && arrayProductos[i].isPublished==TRUE )
                return 1;
    return 0;
}


/**
 * @brief realiza una baja logica de todas las Productos de un usuario que fue dado de baja.
 * @param arrayProductos el array se pasa como parametro.
 * @param sizeArrayProductos el tamaño del array se pasa como parametro.
 * @return devuelve 0 si no exite ninguna Producto para ese usuario o si el tamaño del array es invalido o un puntero NULO, de lo contrario devuelve 1.
 */
int eliminarProductosPorBajaUsuario(EProducto* arrayProductos, int sizeArrayProductos, int idUsuario)
{
    int retorno=0;
    int i;
    if ( arrayProductos==NULL || sizeArrayProductos<=0 )
        printf("\n La ejecucion se detendra! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<sizeArrayProductos; i++)
            if ( arrayProductos[i].idUsuario==idUsuario && arrayProductos[i].flagRegistro==USED )
            {
                arrayProductos[i].flagRegistro=DELETED;
                arrayProductos[i].isPublished=FALSE;
                retorno=1;
            }
    return retorno;
}



/**
 * @brief muetra por pantalla un listado con los Productos.
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
        if (arrayProductos[i].flagRegistro!=EMPTY && arrayProductos[i].isPublished==TRUE && arrayProductos[i].idUsuario==idUsuario)
        {
            printf("\n idProducto %d - Nombre %s - Precio %.2f - Cantidad Vendida %d - Stock %d\
                   ", arrayProductos[i].id, arrayProductos[i].nombre, arrayProductos[i].precio, arrayProductos[i].cantidadVendida, arrayProductos[i].stock);
            retorno=1;
        }
    printf("\n");
    return retorno;
}


/**
 * @brief muetra por pantalla un listado con los Productos.
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



/*

void cargaAutomaticaLlamadas(EProducto* arrayProductos, int sizeArrayProductos, EUsuario* arrayUsuarios)
{
    arrayProductos[0].id=1;
    arrayProductos[0].idUsuario=1;
    arrayUsuarios[0].contadorLlamadas++;
    arrayProductos[0].motivo=FALLA_3G;
    arrayProductos[0].estado=EN_CURSO;
    arrayProductos[0].tiempo=0;
    arrayProductos[0].flagRegistro=USED;

    arrayProductos[1].id=2;
    arrayProductos[1].idUsuario=2;
    arrayUsuarios[1].contadorLlamadas++;
    arrayProductos[1].motivo=FALLA_EQUIPO;
    arrayProductos[1].estado=EN_CURSO;
    arrayProductos[1].tiempo=0;
    arrayProductos[1].flagRegistro=USED;

    arrayProductos[2].id=3;
    arrayProductos[2].idUsuario=2;
    arrayUsuarios[1].contadorLlamadas++;
    arrayProductos[2].motivo=FALLA_EQUIPO;
    arrayProductos[2].estado=EN_CURSO;
    arrayProductos[2].tiempo=0;
    arrayProductos[2].flagRegistro=USED;

    arrayProductos[3].id=4;
    arrayProductos[3].idUsuario=3;
    arrayUsuarios[2].contadorLlamadas++;
    arrayProductos[3].motivo=FALLA_LTE;
    arrayProductos[3].estado=SOLUCIONADO;
    arrayProductos[3].tiempo=15;
    arrayProductos[3].flagRegistro=USED;

}

*/

