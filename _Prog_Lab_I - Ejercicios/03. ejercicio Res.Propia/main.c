#include <stdio.h>
#include <stdlib.h>

float ingresarNum ();
float calcularAreaCirculo (float radio);

int main()
{

    float numeroIngresado, areaCirculoCalculado;
    numeroIngresado = ingresarNum ();
    //printf("\n El numero es: %f", numeroingresado);
    areaCirculoCalculado = calcularAreaCirculo (numeroIngresado);
    printf("\n El area del circulo es: %.4f", areaCirculoCalculado);
    return 0;
}

float ingresarNum ()
{
    float num;
    printf("\n Ingrese un numero : \n");
    scanf("%f",&num);
    return num ;
}

float calcularAreaCirculo (float radio)
{
    float areaCirculo ;
    areaCirculo = 3.14159 * radio * radio ;
    return areaCirculo ;
}
