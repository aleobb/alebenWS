/********************************************************************************************
 *
 * Programa: Venta de Productos
 *
 * Version: 1.0 04 de Mayo de 2017.
 *
 * Autor: Ben Alejandro
 *
 ********************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcionesAuxiliares.h"
#include "Usuarios.h"
#include "Productos.h"
#include "Informes.h"


#define QTYUSUARIO 100
#define QTYPRODUCTO 1000

#define TRUE 1
#define FALSE 0


int main()
{
    EUsuario arrayUsuarios[QTYUSUARIO];  /// Declaro los arrays de las Identidades que necesito usar
    EProducto arrayProductos[QTYPRODUCTO];  /// Declaro los arrays de las Identidades que necesito usar

    int opcion=0;

    if ( initArrayUsuarios(arrayUsuarios,QTYUSUARIO)==0 || initArrayProductos(arrayProductos,QTYPRODUCTO)==0 )
        opcion=11;

    //cargaAutomatica(arrayUsuarios, QTYUSUARIO, arrayProductos, QTYPRODUCTO);

    while(opcion!=11)
    {
        // listarUsuarios(arrayUsuarios,QTYUSUARIO);
        // listarProductos(arrayProductos,QTYPRODUCTO);

        printf("\n");
        printf(" 1- Alta de Usuario \n");
        printf(" 2- Modificar datos del Usuario \n");
        printf(" 3- Baja del Usuario \n");
        printf(" 4- Publicar Producto \n");
        printf(" 5- Modificar Publicacion \n");
        printf(" 6- Cancelar Publicacion \n");
        printf(" 7- Comprar Producto \n");
        printf(" 8- Listar Publicaciones de Usuario \n");
        printf(" 9- Listar Publicaciones \n");
        printf("10- Listar Usuarios (con calificaciones)\n");
        printf("\n");
        printf("11- Salir \n");

        getInt(&opcion,"\n Ingrese una opcion: ","\n\n La opcion ingresada es incorrecta! Debe elegir una opcion del 1 al 11. \n",1,1,1,1,11);

        switch(opcion)
        {
            case 1:
                altaUsuario(arrayUsuarios,QTYUSUARIO);
                break;
            case 2:
                modificarUsuarioPorId(arrayUsuarios,QTYUSUARIO);
                break;
            case 3:
                bajaUsuarioPorId(arrayUsuarios,QTYUSUARIO,arrayProductos,QTYPRODUCTO);
                break;
            case 4:
                nuevaPublicacion(arrayProductos, QTYPRODUCTO,arrayUsuarios,QTYUSUARIO);
                break;
            case 5:
                modificarPublicacionPorIdUsuario(arrayProductos, QTYPRODUCTO, arrayUsuarios, QTYUSUARIO);
                break;
            case 6:
                cancelarPublicacionPorIdUsuario(arrayProductos, QTYPRODUCTO, arrayUsuarios, QTYUSUARIO);
                break;
            case 7:
                comprarProductoPorId(arrayProductos, QTYPRODUCTO, arrayUsuarios, QTYUSUARIO);
                break;
            case 8:
                listarPublicacionesUsuarioPorId(arrayUsuarios, QTYUSUARIO, arrayProductos, QTYPRODUCTO);
                break;
            case 9:
                listarProductosConNombreUsuario(arrayProductos, QTYPRODUCTO, arrayUsuarios, QTYUSUARIO);
                break;
            case 10:
                listarUsuariosConCalificaciones(arrayUsuarios, QTYUSUARIO);
                break;
            case 11:
                printf("\n\n PROCESO TERMINADO. \n");
                break;
        }
    }

    return 0;
}

