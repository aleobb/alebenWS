#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s'; // seguir cargando operandos o realizar calculos
    int opcion=0; // opcion elegida del menu
    float x, y; // variables de los operandos
    int flagX=0, flagY=0; // con esto verifico que se hayan ingresado los ooperandos
    int i=0; //auxiliar necesario para responder la opcion de calcular todas las operaciones

    while(seguir=='s')
    {
        infDatosIng(flagX, flagY , opcion);

        if ( flagX == 1 )
            { printf("\n(El valor ingresado del 1er operando es: %f) \n",x); }
        if ( flagY == 1 )
            { printf("\n(El valor ingresado del 2do operando es: %f) \n",y); }
        printf("\n");

        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        opcion = pedirIntVal("\nElija una opcion: ", "La opcion ingresada es invalida! (debe estar entre el 1 y 9)", 1, 9); // Pido opcion y la valido

        if ( (flagX + flagY) == 2 || opcion < 3 || opcion == 9 || (opcion == 7 && flagX ==1) ) // controlo que se puedan hacer las operaciones solo si previamente se cargaron los valores correspondientes
        {
            do
            {
                switch(opcion)
                {
                    case 1: // Ingresar 1er operando
                        printf("Ingrese el valor del primer operando (con hasta 6 decimales): \n ");
                        fflush(stdin);
                        scanf("%f",&x);
                        flagX = 1;
                        break;
                    case 2: // Ingresar 2do operando
                        printf("Ingrese el valor del segundo operando (con hasta 6 decimales): \n ");
                        fflush(stdin);
                        scanf("%f",&y);
                        flagY = 1;
                        break;
                    case 3: // Calcular la suma (A+B)
                        printf("\n El resultado de la suma es: %f \n", suma(x, y) );
                        break;
                    case 4: // Calcular la resta (A-B)
                        printf("\n El resultado de restar %f a %f es: %f \n", y, x, resta(x, y) );
                        break;
                    case 5: // Calcular la division (A/B)
                        printf("\n El resultado de dividir %f por %f es: %f \n", x, y, division(x, y) );
                        break;
                    case 6: // Calcular la multiplicacion (A*B)
                        printf("\n El resultado de la multiplicacion es: %f \n", multiplicacion(x, y) );
                        break;
                    case 7: // Calcular el factorial (A!)
                        if (x>=0 && x<=100)
                            { printf("\n El factorial de %.0f es: %.0f \n", x, factorial(x) ); }
                        break;
                    case 8: // Calcular todas las operaciones\n
                        i = 6; // cantidad de operaciones a calcular (menos 1 que se va a restar en la linea i--
                        break;
                    case 9: // Salir
                        seguir = 'n';
                        printf("Proceso terminado.");
                        break;
                }

                opcion = 9 - i; // operacion a calcular y mostrar
                i--;
            } while (i>0);
        }
        printf("\n");
    }

    return 0;
}
