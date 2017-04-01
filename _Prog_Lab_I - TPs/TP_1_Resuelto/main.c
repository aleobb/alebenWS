#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s'; // seguir cargando operandos o realizar calculos
    int opcion=0; // opcion elegida del menu
    float x, y; // variables de los operandos
    int flagX=0, flagY=0; // con esto verifico que se hayan ingresado los ooperandos
    int i; //auxiliar necesario para responder la opcion de calcular todas las operaciones

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        if ( flagX == 1 )
            { printf("El valor ingresado del 1er operando es: %f \n",x); }
        if ( flagY == 1 )
            { printf("El valor ingresado del 2do operando es: %f \n",y); }

        infDatosIng(flagX, flagY , opcion);

        printf("Elija una opcion: ");
        scanf("%d",&opcion);   // limpiar
        printf("\n\n");

        while ( (flagX + flagY) == 2 || opcion < 3 || opcion == 9 )
        {

            for ( i=1 ; i > 0 ; i--)
            {
                switch(opcion)
                {
                    case 1: // Ingresar 1er operando
                        printf("\n Ingrese el valor del primer operando: ");
                        scanf("%f",&x);
                        flagX = 1;
                        break;
                    case 2: // Ingresar 2do operando
                        printf("\n Ingrese el valor del segundo operando: ");
                        scanf("%f",&y);
                        flagY = 1;
                        break;
                    case 3: // Calcular la suma (A+B)
                        printf("\n El resultado de la suma es: %f", suma(x, y) );
                        break;
                    case 4: // Calcular la resta (A-B)
                        printf("\n El resultado de restar %f a %f es: %f", y, x, resta(x, y) );
                        break;
                    case 5: // Calcular la division (A/B)
                        printf("\n El resultado de dividir %f por %f es: %f", x, y, division(x, y) );
                        break;
                    case 6: // Calcular la multiplicacion (A*B)
                        printf("\n El resultado de la multiplicacion es: %f", multiplicacion(x, y) );
                        break;
                    case 7: // Calcular el factorial (A!)
                        printf("\n El factorial de %f es: %f", x, factorial(x, y) );
                        break;
                    case 8: // Calcular todas las operaciones\n
                        i = 5; // cantidad de operaciones a calcular
                        break;
                    case 9: // Salir
                        seguir = 'n';
                        break;

                }
                opcion--;
            }
        }
    }

    return 0;
}
