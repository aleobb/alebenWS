#include <stdio.h>
#include <stdlib.h>

void infDatosIng(int flagA, int flagB, int option)
{
    if (option>2 && (flagA + flagB)<2  )
    {
        printf("\n Atencion!! No se puede realizar una niguna operacion ");
        if (flagA == 1)
            { printf("\n (salvo factorial) porque falta ingresar el valor del 2do operando. \n "); }
        else if (flagB == 1)
            { printf("\n porque falta ingresar el valor del 1er operando. \n"); }
        else
            { printf("\n porque todavia no ha ingresado el valor de ningun operando. \n"); }
    }
}


int suma(int A, int B)
{
    return (A+B);
}

int resta(int A, int B)
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

long multiplicacion(int A, int B)
{
    return (A*B);
}

double factorial(double A)
{
    double factA=1;
    double aux;
    for (aux = A; aux > 1; aux--)
        { factA = factA * aux; }
    return factA;
}
