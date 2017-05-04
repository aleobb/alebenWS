#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define MAX 100

int main(){
    int i, edad[MAX];
    char respuesta;
    int buffer;

    for(i=0; i<MAX;i++){

        printf("\nIngrese la edad de la persona %d: ", i);
        scanf("%d", &edad[i]);

        printf("\n\nDesea seguir ingresando? [s/n]");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta!='s'&&respuesta!='S'){
            break;
        }

        system("cls");
    }

    printf("\nEl promedio de las edades ingresadas es %.2f", promedio(edad, i+1));

    return 0;
}
