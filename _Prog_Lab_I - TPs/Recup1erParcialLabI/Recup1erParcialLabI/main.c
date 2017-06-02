#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcAux.h"
#include "utn.h"

int main()
{
    int opcion=0;
    char seguir='s';

    while(opcion!=4)
    {
        printf("\n");
        printf(" 1- Agregar persona\n");
        printf(" 2- Buscar persona\n");
        printf(" 3- Listar personas\n");
        printf("\n");
        printf(" 4- Salir\n");

        getInt(&opcion,"\n Ingrese una opcion: ","\n\n La opcion ingresada es incorrecta! Debe elegir una opcion del 1 al 5. \n",1,1,1,1,5);

        switch(opcion)
        {
            case 1:
                while (seguir!='n' && seguir!='N')
                {
                    agregarPersona();
                    printf("\n Desea continuar cargando mas personas? (s/n): ");
                    scanf("%c",&seguir);
                }
                break;
            case 2:
                buscarPersonaPorApellido();
                break;
            case 3:
                listarPersonas();
                break;
            case 4:
                printf("\n\n PROCESO TERMINADO. \n");
                break;
        }
    }
    return 0;
}
