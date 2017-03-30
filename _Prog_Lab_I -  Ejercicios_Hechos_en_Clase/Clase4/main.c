#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define MAX 100

float promedio(int numero[], int cont);

int main()
{
    int numero[MAX];
    int cont=1;
    char respuesta;
    float promedioR;

    do
    {
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    promedioR=promedio(numero,cont);
    cont++;
    fflush(stdin);
    printf("Si desea continuar precione 'S': ");
    scanf("%c",&respuesta);
    fflush(stdin);
    }while(respuesta=='s'||respuesta=='S');

    printf("%f",promedioR);



    return 0;
}
