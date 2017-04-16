#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcValidacion.h"
#include "funcMatematicas.h"
#include "funcOrdenar.h"

/**
 * \brief Solicitar al usuario una cadena de caracteres.
 * \param mensajeIngreso: es el mensaje a mostrar para pedir el ingreso.
 * \param input es el array donde se va a guardar la cadena.
 * \return Si obtuvo un ingreso no nulo devuelve [0] sino devuelve [-1].
 */
int getString(char mensajeIngreso[], char input[])
{
    char buffer[4084];
    printf("%s",mensajeIngreso);
    fflush(stdin);
    scanf("%s",buffer);
    if ( strlen(buffer)==0 || buffer[0]=='\n' || buffer[0]=='\0' )
        return -1;
    strcpy(input,buffer);
    return 0;
}


/**
 * \brief Solicitar al usuario un numero y validarlo dentro de un rango de enteros.
 * \param numero: donde se va a guardar el numero ya validado.
 * \param mensajeIngreso: mensaje a mostrar para pedir el dato.
 * \param mensajeError: mensaje a mostrar si el dato no esta dentro del rango valido.
 * \param conLimInf: si se recibe 1 como parametro valida el limite inferior, sino no.
 * \param minimo: valor minimo que el usuario puede ingresar como dato valido.
 * \param conLimSup: si se recibe 1 como parametro valida el limite superior, sino no.
 * \param maximo: valor maximo que el usuario puede ingresar como dato valido.
 * \param salir: variable donde se almacena el valor que la funcion que llamó a ésta pide devolver en caso de que se haya superado el limite maximo de ingresos.
 * \return Si obtuvo un numero valido devuelve [0] sino devuelve [-1].
 */
int getInt(int* numero, char mensajeIngreso[], char mensajeError[], int conLimInf, int minimo, int conLimSup, int maximo, int cantIntentos)
{
    int aux;
    char input[4096];
    int intentosDisponibles=cantIntentos;

    do
    {
        if (intentosDisponibles==0)
        {
            printf("\n Se ha superado la cantidad de intentos de ingreso de un dato valido! \n El ingreso se detendra. \n");
            return -1;
        }
        else if (intentosDisponibles!=cantIntentos)
            printf("%s",mensajeError);
        if(conLimInf!=0)
            printf("\n El valor a ingresar no puede ser inferior a %d ",minimo);
        if(conLimSup!=0)
            printf("\n El valor a ingresar no puede ser superior a %d ",maximo);

        printf("\n (Cantidad de intentos disponibles: %d)",intentosDisponibles);
        intentosDisponibles--;

        getString(mensajeIngreso,input);
        if ( esCadenaSoloNumeros(input,1) != 0 )
            continue;
        aux = atoi(input);

        if(conLimInf==0)
            minimo=aux;
        if(conLimSup==0)
            maximo=aux;
    } while ( aux < minimo || aux > maximo );

    *numero = aux;
    return 0;
}


/**
 * \brief Verifica que una array esté compuesto solo por numeros.
 * \param vector: es el array a evaluar
 * \param admitePunto: si se recibe 1 como parametro valida que la cadena pueda incluir hasta 1 punto ('.'), sino no.
 * \return Si el array esta compuesto solo por numeros devuelve [0] sino devuelve [-1].
 */
int esCadenaSoloNumeros (char vector[], int admitePunto)
{
    int i=0;
    int contadorPunto=0;
    while (vector[i]!='\0')
    {
        if (vector[i]<'0' || vector[i]>'9')
        {
            if (vector[i]=='.')
                contadorPunto++;
            if (admitePunto!=1 || contadorPunto>1)
                return -1;
        }
        i++;
    }
    return 0;
}


/**
 * \brief Verifica que una array esté compuesto solo por espacios y/o letras (mayusculas y/o minusculas).
 * \param vector es el array a evaluar
 * \return Si el array esta compuesto solo por espacios y/o letras devuelve [0] sino devuelve [-1].
 */
int esCadenaSoloLetras (char vector[])
{
    int i=0;
    while (vector[i]!='\0')
    {
        if ( vector[i]!=' ' && (vector[i]<'a' || vector[i]>'z') && (vector[i]<'A' || vector[i]>'Z') )
            return -1;
        i++;
    }
    return 0;
}

/**
 * \brief Verifica que una array esté compuesto solo por numeros y/o espacios y/o letras (mayusculas y/o minusculas).
 * \param vector es el array a evaluar
 * \return Si el array esta compuesto solo por numeros y/o espacios y/o letras devuelve [0] sino devuelve [-1].
 */
int esCadenaAlfanumerica (char vector[])
{
    int i=0;
    while (vector[i]!='\0')
    {
        if ( vector[i]!=' ' && (vector[i]<'a' || vector[i]>'z') && (vector[i]<'A' || vector[i]>'Z') && (vector[i]<'0' || vector[i]>'9') )
            return -1;
        i++;
    }
    return 0;
}



/**
 * \brief Informa al usuario limitaciones en las operaciones posibles a realizar.
 * \param flagA y flagB variables cuyo valor va a permitir verificar si el usuario ya ingresó los valores de A y B respectivamente (x e y en main.c)
 * \param option es la variable donde se va a guardar la opcion del menu elegida por el usuario
 * \param A es la variable donde se va a almacenar el valor del primer operando
 * \return no devuelve nada al proceso que llamo a la funcion
 */
void infDatosIng(int flagA, int flagB, int option, float A)
{
    if ( (option>2 && (flagA + flagB)<2) || option==0 )
    {
        printf("\n\n Atencion!! No se puede realizar niguna operacion ");
        if (flagA == 1) /// si solo se ingresó el dato A
        {
            if (A<0)
                printf("\n (ni siquiera factorial) porque el valor del primer operando es negativo y ");
            else
                printf("\n (salvo factorial) porque ");

            printf("falta ingresar el valor del 2do operando. \n\n ");
            printf("Aclaraciones: \n * Solo se calculara el factorial de numeros enteros del 0 al 100 \n ");
            printf("* En caso de haber ingresado un numero con decimales se calculara el factorial de la porcion entera. \n ");
        }
        else if (flagB == 1) /// si solo se ingreso el dato B
            { printf("\n porque falta ingresar el valor del 1er operando. \n"); }
        else /// si todavia no se ingreso ningun dato de A y B
            { printf("\n porque todavia no ha ingresado el valor de ningun operando. \n"); }
    }
    printf(" (La precision de la calculadora es con hasta 8 digitos para el valor de los operandos) \n");
    if ( (flagA + flagB)==2 && A<0 )
        { printf("\n No se podra calcular factorial porque el valor del primer operando es negativo. \n"); }
}









