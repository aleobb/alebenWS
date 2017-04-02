#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s'; // seguir cargando operandos o realizar calculos
    int opcion=0; // opcion elegida del menu
    int x, y; // variables de los operandos
    int flagX=0, flagY=0; // con esto verifico que se hayan ingresado los ooperandos
    int i=0; //auxiliar necesario para responder la opcion de calcular todas las operaciones

    while(seguir=='s')
    {
        infDatosIng(flagX, flagY , opcion);

        if ( flagX == 1 )
            { printf("\n(El valor ingresado del 1er operando es: %d) \n",x); }
        if ( flagY == 1 )
            { printf("\n(El valor ingresado del 2do operando es: %d) \n",y); }
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

        printf("\nElija una opcion: ");
        scanf("%d",&opcion);   // limpiar
        printf("\n");

        if ( (flagX + flagY) == 2 || opcion < 3 || opcion == 9 || (opcion == 7 && flagX ==1) )
        {
            do
            {
                switch(opcion)
                {
                    case 1: // Ingresar 1er operando
                        printf("Ingrese el valor del primer operando: ");
                        scanf("%d",&x);
                        flagX = 1;
                        break;
                    case 2: // Ingresar 2do operando
                        printf("Ingrese el valor del segundo operando: ");
                        scanf("%d",&y);
                        flagY = 1;
                        break;
                    case 3: // Calcular la suma (A+B)
                        printf("\n El resultado de la suma es: %d \n", suma(x, y) );
                        break;
                    case 4: // Calcular la resta (A-B)
                        printf("\n El resultado de restar %d a %d es: %d \n", y, x, resta(x, y) );
                        break;
                    case 5: // Calcular la division (A/B)
                        printf("\n El resultado de dividir %d por %d es: %f \n", x, y, division(x, y) );
                        break;
                    case 6: // Calcular la multiplicacion (A*B)
                        printf("\n El resultado de la multiplicacion es: %d \n", multiplicacion(x, y) );
                        break;
                    case 7: // Calcular el factorial (A!)
                        printf("\n El factorial de %d es: %.0f \n", x, factorial(x) );
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
