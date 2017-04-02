#include <stdio.h>
#include <stdlib.h>

/*
* \brief solicitar al usuario un numero y validarlo dentro de un rango de enteros (en este caso una opcion del menu)
* \param mensaje: leyenda para pedir el dato
* \param mensjaeError: leyenda a mostrar si el dato no esta dentro del rango
* \param int y max: minimos y maximos validos
* \return devuelve el dato tomado y validado (en este caso la opcion del menu)
*/
int pedirIntVal(char mensaje[], char mensajeError[], int min, int max)
{
    int option;
    int i=5; // cantidad maxima de ingresos erronos
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&option);   // limpiar
    printf("\n");

    while( option < min || option > max )
    {
        printf("%s",mensajeError);
        printf("%s",mensaje);
        printf("(Cantidad de intentos maximos: %d)\n",i);
        fflush(stdin);
        scanf("%d",&option);
        printf("\n");
        i--;
        if (i==0)
            { option = 9; } //igualo a la opcion de salir del menu
    }
    return option;
}

/*
* \brief Informa al usuario limitaciones en las operaciones posibles a realizar.
* \param flagA y flagB verifican si el usuario ya ingreso los valores de A y B respectivamente (x e y en main.c)
* \param option es la opcion del menu elegida por el usuario
* \return no devuelve nada
*/
void infDatosIng(int flagA, int flagB, int option)
{
    if ( option>2 && (flagA + flagB)<2  )
    {
        printf("\n Atencion!! No se puede realizar una niguna operacion ");
        if (flagA == 1) // si solo se ingreso el dato A )(x en main.c)
        {
            printf("\n (salvo factorial) porque falta ingresar el valor del 2do operando. \n ");
            printf("Aclaracion: Solo se calculara el factorial de numeros enteros del 0 al 100 \n ");
            printf("(en caso de haber ingresado un numero negativo se calculara el factorial de la porcion entera) \n ");
        }
        else if (flagB == 1) // si solo se ingreso el dato B )(y en main.c)
            { printf("\n porque falta ingresar el valor del 1er operando. \n"); }
        else // si todavia no se ingreso ningun dato de A y B)(x e y en main.c)
            { printf("\n porque todavia no ha ingresado el valor de ningun operando. \n"); }
    }
}

/*
* \brief calcula la suma entre 2 numeros A y B
* \param A y B son los valores con los que se va a calcular la suma
* \return devuelve el resultado de la suma
*/
float suma(float A, float B)
{
    return (A+B);
}

/*
* \brief calcula la resta entre 2 numeros A y B
* \param A y B son los valores con los que se va a calcular la resta
* \return devuelve el resultado de la resta
*/
float resta(float A, float B)
{
    return (A-B);
}

/*
* \brief calcula la division de A por B
* \param A y B son los valores con los que se va a calcular la division
* \return devuelve el resultado de la division
*/
float division(float A, float B)
{
    if ( B == 0 ) //controla el error de dividir por 0
    {
        printf("\n El divisor es igual a 0 y por tanto no puede realizarse la division. Modifiquelo e intente nuevamente. \n\n");
        return 0;
    }
    else
        { return (A/B); }
}

/*
* \brief calcula la multiplicacion entre 2 numeros A y B
* \param A y B son los valores con los que se va a calcular la multiplicacion
* \return devuelve el resultado de la multiplicacion
*/
double multiplicacion(float A, float B)
{
    return (A*B);
}

/*
* \brief calcula el factorial del numero A
* \param A es el valor utilizado para realizar el calculo
* \return devuelve el resultado del factorial de A
*/
double factorial(int A)
{
    double factA=1; // el resultado a devolver de la funcion sera 1 cuando A sea cero
    double aux;

    if ( A < 0 ) // controla que el factorial pueda calcularse
    {
        printf("\n El valor factorial no puede calcularse debido a que el 1er operando no es un numero negativo.\nModifiquelo e intente nuevamente. \n\n");
        return 0;
    }
    else if (A>100)
    {
        printf("\n El valor factorial de %.0f no se calculara porque es mayor a 100 \n Modifiquelo e intente nuevamente. \n\n", A);
        return 0;
    }
    else
    {
        for (aux = A; aux > 1; aux--) // si A es mayor a 1 debe calcularse
            { factA = factA * aux; }
        return factA;
    }
}
