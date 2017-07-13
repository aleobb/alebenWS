#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcAux.h"

#define BUFFER 4084
#define EL_DATO_ES_VALIDO 1
#define EL_DATO_NO_ES_VALIDO 0

/**
 * \brief Solicitar al usuario una cadena de caracteres.
 * \param mensajeIngreso: es el mensaje a mostrar para pedir el ingreso.
 * \param mensajeError: mensaje a mostrar si el dato no esta dentro del rango valido.
 * \param bucle: el codigo se va a repetir hasta que se ingrese un tipo de dato valido.
 * \param type: tipo de ingreso que se quiere obtener como valido (1- cadena solo letras / 2-cadena alfanumerica)
 * \param arrayCharsAdmitidos es el array que contiene los caracteres que tambien van a resultar validos.
 * \param maxExtensionArray: indica la extension maxima (en cantidad de caracteres) para el array.
 * \param input: es el array donde se va a guardar la cadena.
 * \return Si obtuvo un ingreso valido devuelve [1] sino devuelve [0].
 */
int getType(char mensajeIngreso[], char mensajeError[], int bucle, int type, char arrayCharsAdmitidos[], int maxExtensionArray, char* input)
{
    int validacion;
    char buffer[BUFFER];
    do
    {
        getString(mensajeIngreso, buffer);
        switch (type)
        {
            case 1:
                validacion=esCadenaSoloLetras(buffer, arrayCharsAdmitidos);
                break;
            case 2:
                validacion=esCadenaAlfanumerica(buffer, arrayCharsAdmitidos);
                break;
            case 3:
                validacion=esEmail(buffer, arrayCharsAdmitidos);
                break;
        }
        if(validacion==EL_DATO_NO_ES_VALIDO || strlen(buffer)>maxExtensionArray)
        {
            printf(mensajeError);
            validacion=EL_DATO_NO_ES_VALIDO;
        }
        else
            strcpy(input,buffer);
    }while( bucle==1 && validacion==EL_DATO_NO_ES_VALIDO );
    return validacion;
}


/**
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
    gets(buffer);
    if ( strlen(buffer)==0 || buffer[0]=='\0' )
        return EL_DATO_NO_ES_VALIDO;
    strcpy(input,buffer);
    return EL_DATO_ES_VALIDO;
}


/**
 * \brief Solicitar al usuario un numero y validarlo dentro de un rango de enteros.
 * \param numero: donde se va a guardar el numero ya validado.
 * \param mensajeIngreso: mensaje a mostrar para pedir el dato.
 * \param mensajeError: mensaje a mostrar si el dato no esta dentro del rango valido.
 * \param bucle: si el parametro es 1 el codigo se va a repetir hasta que se ingrese un tipo de dato valido.
 * \param conLimInf: si se recibe 1 como parametro valida el limite inferior, sino no.
 * \param minimo: valor minimo que el usuario puede ingresar como dato valido.
 * \param conLimSup: si se recibe 1 como parametro valida el limite superior, sino no.
 * \param maximo: valor maximo que el usuario puede ingresar como dato valido.
 * \return Si obtuvo un numero valido devuelve [1] sino devuelve [0].
 */
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


/**
 * \brief Solicitar al usuario un numero y validarlo dentro de un rango de numeros decimales.
 * \param numero: donde se va a guardar el numero ya validado.
 * \param mensajeIngreso: mensaje a mostrar para pedir el dato.
 * \param mensajeError: mensaje a mostrar si el dato no esta dentro del rango valido.
 * \param bucle: si el parametro es 1 el codigo se va a repetir hasta que se ingrese un tipo de dato valido.
 * \param conLimInf: si se recibe 1 como parametro valida el limite inferior, sino no.
 * \param minimo: valor minimo que el usuario puede ingresar como dato valido.
 * \param conLimSup: si se recibe 1 como parametro valida el limite superior, sino no.
 * \param maximo: valor maximo que el usuario puede ingresar como dato valido.
 * \return Si obtuvo un numero valido devuelve [1] sino devuelve [0].
 */
int getFloat(float* numero, char mensajeIngreso[], char mensajeError[], int bucle, int conLimInf, float minimo, int conLimSup, float maximo)
{
    char input[BUFFER];
    int validacion;
    float valor=0;

    do
    {
        getString(mensajeIngreso,input);
        validacion=esCadenaSoloNumeros(input,1,1);
        if ( validacion )
            valor = atof(input);
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




/**
 * \brief Solicitar al usuario un numero y validarlo dentro de un rango de enteros largos.
 * \param numero: donde se va a guardar el numero ya validado.
 * \param mensajeIngreso: mensaje a mostrar para pedir el dato.
 * \param mensajeError: mensaje a mostrar si el dato no esta dentro del rango valido.
 * \param bucle: si el parametro es 1 el codigo se va a repetir hasta que se ingrese un tipo de dato valido.
 * \param conLimInf: si se recibe 1 como parametro valida el limite inferior, sino no.
 * \param minimo: valor minimo que el usuario puede ingresar como dato valido.
 * \param conLimSup: si se recibe 1 como parametro valida el limite superior, sino no.
 * \param maximo: valor maximo que el usuario puede ingresar como dato valido.
 * \return Si obtuvo un numero valido devuelve [1] sino devuelve [0].
 */
int getLongInt(long int* numero, char mensajeIngreso[], char mensajeError[], int bucle, int conLimInf, long int minimo, int conLimSup, long int maximo)
{
    char input[BUFFER];
    int validacion;
    long int valor=0;

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


/**
 * \brief Verifica que una array esté compuesto solo por letras (mayusculas y/o minusculas) y/o una serie de caracteres definidos.
 * \param vector es el array a evaluar
 * \param arrayCharsAdmitidos es el array que contiene los caracteres que tambien van a resultar validos.
 * \return Si el array esta compuesto solo por letras y/o los caracteres especificados devuelve [1] sino devuelve [0].
 */
int esCadenaSoloLetras (char vector[], char arrayCharsAdmitidos[])
{
    int i, j;
    int flag=0;
    for (i=0 ; vector[i]!='\0'; i++)
    {
        if ( (vector[i]<'a' || vector[i]>'z') && (vector[i]<'A' || vector[i]>'Z') )
        {
            for(j=0 ; arrayCharsAdmitidos[j]!='\0' && flag==0 ; j++)
            {
                if (vector[i]==arrayCharsAdmitidos[j])
                    flag=1;
            }
            if (flag!=1)
                return EL_DATO_NO_ES_VALIDO;
        }
    }
    return EL_DATO_ES_VALIDO;
}

/**
 * \brief Verifica que una array esté compuesto solo por numeros y/o espacios y/o letras (mayusculas y/o minusculas).
 * \param vector es el array a evaluar
 * \param arrayCharsAdmitidos es el array que contiene los caracteres que tambien van a resultar validos.
 * \return Si el array esta compuesto solo por numeros y/o letras y/o los caracteres especificados devuelve [1] sino devuelve [0].
 */
int esCadenaAlfanumerica (char vector[], char arrayCharsAdmitidos[])
{
    int i, j;
    int flag=0;
    for (i=0 ; vector[i]!='\0'; i++)
    {
        if ( (vector[i]<'a' || vector[i]>'z') && (vector[i]<'A' || vector[i]>'Z') && (vector[i]<'0' || vector[i]>'9') )
        {
            for(j=0 ; arrayCharsAdmitidos[j]!='\0' && flag==0 ; j++)
            {
                if (vector[i]==arrayCharsAdmitidos[j])
                    flag=1;
            }
            if (flag!=1)
                return EL_DATO_NO_ES_VALIDO;
        }
    }
    return EL_DATO_ES_VALIDO;
}



/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}


/**
 * \brief Verifica que una array esté compuesto es un email valido.
 * \param vector es el array a evaluar
 * \param arrayCharsAdmitidos es el array que contiene los caracteres que tambien van a resultar validos.
 * \return Si el array es un email valido devuelve [1] sino devuelve [0].
 */
int esEmail (char vector[], char arrayCharsAdmitidos[])
{
    int i, j;
    int flag=0;
    int arroba=0;
    int punto=0;

    for (i=0 ; vector[i]!='\0'; i++)
    {
        if ( (vector[i]<'a' || vector[i]>'z') && (vector[i]<'A' || vector[i]>'Z') && (vector[i]<'0' || vector[i]>'9') )
        {
            if (vector[i]=='@')
            {
                if (i>2 && arroba==0)
                    arroba++;
                else
                    return EL_DATO_NO_ES_VALIDO;
            }
            else if (vector[i]=='.')
            {
                if (i>6 && punto==0 && arroba==1 && vector[i-1]!='@' && strlen(vector)>i+2 )
                    punto++;
                else
                    return EL_DATO_NO_ES_VALIDO;
            }

            for(j=0 ; arrayCharsAdmitidos[j]!='\0' && flag==0 ; j++)
            {
                if (vector[i]==arrayCharsAdmitidos[j])
                    flag=1;
            }
            if (flag!=1)
                return EL_DATO_NO_ES_VALIDO;
        }
    }
    return EL_DATO_ES_VALIDO;
}



char* getEmail()
{
    char* email = (char*)malloc(sizeof(char*)*50);
    char* arrayCharsAdmitidos="@.-_";
    getType("\n Ingrese el email del usuario: ", "\n El mail ingresado es invalido!\
        \n Solo se adminten letras, numeros, el caracter '@._-' y que no exceda los 49 caracteres \n",1,3,arrayCharsAdmitidos,49,email);
    return email;
}
