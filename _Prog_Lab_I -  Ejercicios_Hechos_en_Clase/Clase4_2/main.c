#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define MAX 5

int main()
{
    int vNum[MAX] = {22,11,33,55,66};
    int buffer;


    buffer = fOrdenar(int vNum[], MAX)


    printf("\nEl promedio de las edades ingresadas es %d", buffer);

    return 0;
}

    /*for(i=0; i<MAX;i++){

        printf("\nIngrese la edad de la persona %d: ", i);
        scanf("%d", &edad[i]);

        printf("\n\nDesea seguir ingresando? [s/n]");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta!='s'&&respuesta!='S'){
            break;
        }

        system("cls");
    }*/
