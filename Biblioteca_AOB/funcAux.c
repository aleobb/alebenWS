#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 4084
#define EL_DATO_ES_VALIDO 1
#define EL_DATO_NO_ES_VALIDO 0

int compactArray(int array[], int size, int indice);
int expandArray(int array[], int size, int indice);

int esCadenaSoloNumeros (char vector[], int cantPuntos, int admiteNegativos);
int getInt(int* numero, char mensajeIngreso[], char mensajeError[], int bucle, int conLimInf, int minimo, int conLimSup, int maximo);

void main()
{
    /**
    int dato[100]={1,50,-52,0,330};
    int size=5;
    int i;
    for (i=0;i<size;i++)
        printf("\n el valor del array en %d es: %d",i,dato[i]);
    printf("\n");
    size=expandArray(dato,5,4);
    printf("\n");
    dato[4]=24;
    for (i=0;i<size;i++)
        printf("\n el valor del array en %d es: %d",i,dato[i]);
    */

    int edad;
    getInt(&edad, "\n Ingrese la edad de la persona: ", "\n El dato ingresado es invalido!.\
            \n La edad debe ser un numero positvo entre 0 y 150",1,1,0,1,150);

    printf("\n la edad es: %d",edad);
}

int getInt(int* numero, char mensajeIngreso[], char mensajeError[], int bucle, int conLimInf, int minimo, int conLimSup, int maximo)
{
    char input[BUFFER];
    int validacion;
    int valor=0;

    do
    {
        getString(mensajeIngreso,input);
        validacion=esCadenaSoloNumeros(input,0,1);
        if ( validacion )
            valor = atoi(input);
        if( validacion==EL_DATO_NO_ES_VALIDO || (conLimInf==1 && valor<minimo) || (conLimSup==1 && valor>maximo) )
        {
            validacion=EL_DATO_NO_ES_VALIDO;
            printf("%s",mensajeError);
        }
        else
            *numero = valor;
    } while (  bucle==1 && validacion==EL_DATO_NO_ES_VALIDO );
    return validacion;
}


/*
 * \brief Solicitar al usuario una cadena de caracteres.
 * \param mensajeIngreso: es el mensaje a mostrar para pedir el ingreso.
 * \param input es el array donde se va a guardar la cadena.
 * \return Si obtuvo un ingreso no nulo devuelve [1] sino devuelve [0].
 */
int getString(char mensajeIngreso[], char* input)
{
    char buffer[BUFFER];
    printf("%s",mensajeIngreso);
    fflush(stdin);
    scanf("%[^\n]s",buffer);
    if ( strlen(buffer)==0 || buffer[0]=='\0' )
        return EL_DATO_NO_ES_VALIDO;
    strcpy(input,buffer);
    return EL_DATO_ES_VALIDO;
}

/**
 * \brief Verifica que una array esté compuesto solo por numeros.
 * \param vector: es el array a evaluar
 * \param cantPuntos: Valida que la cadena pueda incluir hasta la cantidad de puntos ('.') que recibe como parametro.
 * \param admiteNegativos: recibe 1 como parametro, acepta como valido una cadena que empieza con el signo '-', sino no.
 * \return Si el array esta compuesto solo por numeros devuelve [1] sino devuelve [0].
 */
int esCadenaSoloNumeros (char vector[], int cantPuntos, int admiteNegativos)
{
    int i=0;
    if (vector[0]=='-')
    {
        if (admiteNegativos==1)
            i++;
        else
            return EL_DATO_NO_ES_VALIDO;
    }
    for ( ; vector[i]!='\0'; i++)
    {
        if (vector[i]=='.' && cantPuntos>0)
            cantPuntos--;
        else if (vector[i]<'0' || vector[i]>'9')
            return EL_DATO_NO_ES_VALIDO;
    }
    return EL_DATO_ES_VALIDO;
}





