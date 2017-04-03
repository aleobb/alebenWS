#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.AOB.h"

float suma(float x, float y);

int main()
{


    float num1, num2;
    float totSuma;
    int opcion;



    printf("Ingrese 1er. operando: \n");
    scanf("%f",&num1);
    printf("\n Ingrese 2do. operando: \n");
    scanf("%f",&num2);


    printf("Elija una opcion: \n\
            1. Calcular la suma (A+B) \n\
            2. Calcular la resta (A-B) \n\
            3. Calcular la division (A/B) \n\
            4. Calcular la multiplicacion (A*B) \n\
            5. Calcular el factorial (A!) \n\
            6. Calcular todas las operaciones \n \n\
            Cualquier otro valor para Salir \n \n");

    scanf("%d",&opcion);
    // printf("opcion elegida es: %d",opcion);

    switch (opcion)
    {
        case 1:
            totSuma = suma(num1,num2);
            printf("El resultado de la suma es: %f", totSuma);
            break;
        case 2:

            break;
    }
/*

    float num1, num2;
    printf("Ingrese 1er. operando: \n");
    scanf("%f",&num1);
    printf("Ingrese 2do. operando: \n");
    scanf("%f",&num2); \n
suma(num1,num2)


    printf("\n La \nresta es: \n %f",num1-num2);

    if (num2==0)
    {
        printf("\n La division no se puede hacer! \n");
    }
    else
    {
        printf("\n La dprintf("\n La suma es: \n %f",num1+num2);ivision es: %f",num1/num2);
    }

    printf("\n La multiplicacion es: %f",num1 \n*num2);
int obtenerInt(char mensaje[],char mensajeError[],int min, int max)
    printf("\n El factorial del 1er nro es: %f",num1);

    printf("\n El factorial del 2do nro es: %f",num2);
*/
    return 0;
}

float suma(float x, float y)
{
    return (x+y);
}

