#include <stdio.h>
#include <stdlib.h>

void infDatosIng(float flagA, float flagB, int option)
{
    if( (flagA + flagB) == 0 && option > 2 )
        { printf("\n\n Atencion!! No se puede realizar una operacion porque todavia no ha ingresado el valor de ningun operando \n\n"); }
    else if ( (flagA + flagB) < 2 && option > 2 )
            { printf("\n\n(Atencion!! No se podra realizar ninguna operacion todavia porque falta ingresar el valor del otro operando -salvo factorial-) \n\n"); }
}


float suma(float A, float B)
{
    return (A+B);
}

float resta(float A, float B)
{
    return (A-B);
}

float division(float A, float B)
{
    if ( B == 0 )
    {
        printf("\n El divisor es igual a 0 y por tanto no puede realizarse la division. Modifiquelo e intente nuevamente. \n'n");
        return 0;
    }
    else
        { return (A/B); }
}

float multiplicacion(float A, float B)
{
    return (A*B);
}
float factorial(float A, float B)
{
    if ( A==0 )
        { return 1; }
    else
        { return !A; }
}
