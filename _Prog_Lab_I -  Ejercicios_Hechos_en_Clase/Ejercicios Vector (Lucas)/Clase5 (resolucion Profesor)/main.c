#include <stdio.h>
#include <stdlib.h>
#include "func.h"

#define MAX 100


int main(){
    int i=5;
//    char respuesta;
//    int buffer;

    int edad[MAX] = {22,11,55,33,66}; //el array original sin achicar ni ordenar
    int sizeEdad = 5; // tamaño de componentes actuales del vector

    int edadOrdenada[MAX]; // declaro el array donde van a quedar los datos compactados y ordenados

    for(i = 0 ; i < sizeEdad ; i++)  // para mostrar los valores sin ordenar
        printf("%d\n",edad[i]);

    // void nadiaSort(int array[], int size,int arrayOrdenado[])

    nadiaSort(edad,sizeEdad,edadOrdenada); //todo el proceso se hace aca llamando a esa funcion que a su vez llama al resto
    // ^^ a la funcion le paso el vector original, el tamaño del vector y el vector nuevo donde va a guardar los datos ordenados

    for(i = 0 ; i < sizeEdad ; i++)  // para mostrar los valores ordenados
        printf("\n%d",edadOrdenada[i]);




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

    printf("\nEl promedio de las edades ingresadas es %.2f", promedio(edad, i+1));

    return 0;
}
