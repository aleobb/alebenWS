#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "funcAux.h"
#include "Archivos.h"
#include "Usuarios.h"
#include "Estadisticas.h"

#define ALL 0
#define ACTIVE 1
#define DELETED 2

#define SALIR 15

int main()
{
    //printf("Email: %s", getEmail());

   // fileToArray();

   // fileToArrayTemas();
/*

    ArrayList* uList = al_newArrayList();
    if ( uList != NULL)
        parserDataInFile("usuarios.dat", uList);

    ArrayList* tList = al_newArrayList();
    if ( tList != NULL)
        parseDataInFile("temas.dat", tList);

    tomarYcomprobarExistenciaUsuarioPorId(uList, "cancela?");
    */
    fileToArrayEstadisticas();



   FILE * fp;
   fp = fopen ("file.txt", "a");
//   fprintf(fp, "%s %s %s %d\n", "We", "are", "in", 2012);
   //fclose(fp);

   char str[80];
   sprintf(str, "Value of Pi = %f\n", 3.1416);
 //  puts(str);

   //fputs("This is c programming.", fp);
   fputs(str, fp);

    fclose(fp);




/*


    //printByName(uList);

    printByNacionalidadyNombre(uList);
/*
    int opcion=0;

    ArrayList* listaUsuarios = al_newArrayList();
    ArrayList* listaProductos = al_newArrayList();

    if ( listaUsuarios == NULL || listaProductos == NULL )
        opcion=SALIR;

  cargaInicialUsuarios(listaUsuarios);

    while(opcion!=SALIR)
    {
        listarUsuarios(listaUsuarios, ALL);

        printf("\n");
        printf(" 1-  \n");
        printf(" 2-  \n");
        printf(" 3-  \n");
        printf(" 4-  \n");
        printf(" 5-  \n");
        printf(" 6-  \n");
        printf(" 7-  \n");
        printf(" 8-  \n");
        printf(" 9-  \n");
        printf("10-  \n");
        printf("11-  \n");
        printf("12-  \n");
        printf("13-  \n");
        printf("14-  \n");
        printf("\n");
        printf("%d- Salir \n", SALIR);

        getInt(&opcion,"\n Ingrese una opcion: ","\n\n La opcion ingresada es incorrecta! Debe elegir una opcion del 1 al SALIR. \n",1,1,1,1,SALIR);

        switch(opcion)
        {
            case 1:
                printf("\n Funcion no terminada aun. \n");
                break;
            case 2:
                printf("\n Funcion no terminada aun. \n");
                break;
            case 3:
                printf("\n Funcion no terminada aun. \n");
                break;
            case 4:
                printf("\n Funcion no terminada aun. \n");
                break;
            case 5:
                printf("\n Funcion no terminada aun. \n");
                break;
            case 6:
                printf("\n Funcion no terminada aun. \n");
                break;
            case 7:
                printf("\n Funcion no terminada aun. \n");
                break;
            case 8:
                printf("\n Funcion no terminada aun. \n");
                break;
            case 9:
                printf("\n Funcion no terminada aun. \n");
                break;
            case 10:
                printf("\n Funcion no terminada aun. \n");
                break;
            case 11:
                printf("\n Funcion no terminada aun. \n");
                break;
            case 12:
                printf("\n Funcion no terminada aun. \n");
                break;
            case 13:
                printf("\n Funcion no terminada aun. \n");
                break;
            case 14:
                printf("\n Funcion no terminada aun. \n");
                break;
            case SALIR:
                printf("\n\n PROCESO TERMINADO. \n");
                break;
        }
    }
*/
    return 0;
}
