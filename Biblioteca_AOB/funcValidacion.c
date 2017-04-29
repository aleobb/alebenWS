#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcValidacion.h"
#include "funcMatematicas.h"
#include "funcOrdenar.h"

#define BUFFER 4084
#define EL_DATO_ES_VALIDO 1
#define EL_DATO_NO_ES_VALIDO 0



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
        validacion=esCadenaSoloNumeros(input,0,1);
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
 * \brief Solicitar al usuario una cadena de caracteres.
 * \param mensajeIngreso: es el mensaje a mostrar para pedir el ingreso.
 * \param mensajeError: mensaje a mostrar si el dato no esta dentro del rango valido.
 * \param bucle: el codigo se va a repetir hasta que se ingrese un tipo de dato valido.
 * \param type: tipo de ingreso que se quiere obtener como valido (1- cadena solo letras / 2-cadena alfanumerica / 3-cadena fecha / 4-cadena telefono / 5-cadena email)
 * \param arrayCharsAdmitidos es el array que contiene los caracteres que tambien van a resultar validos.
 * \param maxExtensionArray: indica la extension maxima (en cantidad de caracteres) para el array.
 * \param input: es el array donde se va a guardar la cadena.
 * \return Si obtuvo un ingreso valido devuelve [1] sino devuelve [0].
 */
int getType(char mensajeIngreso[], char mensajeError[], int bucle, int type, char arrayCharsAdmitidos[], int maxExtensionArray, char* input)
{
    int validacion=EL_DATO_NO_ES_VALIDO;
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
                validacion=esCadenaFecha(buffer);
                break;
            case 4:
                validacion=esCadenaTelefono(buffer);
            case 5:
                validacion=esCadenaEmail(buffer, arrayCharsAdmitidos);
        }
        if(validacion==EL_DATO_NO_ES_VALIDO || strlen(buffer)>maxExtensionArray)
            printf(mensajeError);
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
    else if (vector[0]=='\0')
        return EL_DATO_NO_ES_VALIDO;
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
 * \brief Verifica que una array esté compuesto solo por numeros, guiones y/o parentesis.
 * \param vector: es el array a evaluar
 * \return Si el array esta compuesto solo por numeros devuelve [1] sino devuelve [0].
 */
int esCadenaTelefono (char vector[])
{
    int i=0;
    int flagAbrirParentesis=0;
    int flagGuion=0;
    int cantCaracteresTel=6;
    if (vector[0]=='-' || vector[0]==')' || vector[0]=='\0')
        return EL_DATO_NO_ES_VALIDO;
    else if (vector[0]=='(' && vector[1]!='\0')
    {
        i++;
        flagAbrirParentesis++;
        cantCaracteresTel=cantCaracteresTel+3;
    }

    for ( ; vector[i]!='\0'; i++)
    {
        if (vector[i]==')' && flagAbrirParentesis==1 && vector[i+1]!='\0')
            continue;
        else if (vector[i]=='-' && vector[i-1]!='(' && vector[i-1]!=')' && vector[i+1]!='\0')
        {
            flagGuion++;
            continue;
        }
        else if (vector[i]<'0' || vector[i]>'9')
            return EL_DATO_NO_ES_VALIDO;
    }
    if (flagGuion==0 || flagGuion>2 || strlen(vector)<cantCaracteresTel)
        return EL_DATO_NO_ES_VALIDO;
    return EL_DATO_ES_VALIDO;
}


/**
 * \brief Verifica que una array esté compuesto solo por letras, numeros, y como minimo un '@' y un '.'.
 * \param vector: es el array a evaluar
 * \param arrayCharsAdmitidos es el array que contiene los caracteres que tambien van a resultar validos.
 * \return Si el array esta compuesto por una cadena email devuelve [1] sino devuelve [0].
 */
int esCadenaEmail(char vector[], char arrayCharsAdmitidos[])
{
    int i;
    int flagArroba=0;
    int flagPunto=0;
    int cantCaracteres=6;
    if (vector[0]=='@' || vector[0]=='.' || vector[0]=='\0' || esCadenaAlfanumerica(vector, arrayCharsAdmitidos)==0 || strlen(vector)<cantCaracteres)
        return EL_DATO_NO_ES_VALIDO;
    for (i=1 ; vector[i]!='\0'; i++)
    {
        if (vector[i]=='@')
        {
            flagArroba++;
            if (flagArroba>1 || flagPunto>0 || vector[i+1]=='\0' || vector[i+1]=='.')
                return EL_DATO_NO_ES_VALIDO;
            continue;
        }
        else if (vector[i]=='.')
        {
            flagPunto++;
            if (flagArroba==0 || flagPunto>1 || vector[i+1]=='\0')
                return EL_DATO_NO_ES_VALIDO;
            continue;
        }
    }
    if (flagArroba==0 || flagPunto==0)
        return EL_DATO_NO_ES_VALIDO;
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
 * \brief Verifica que una array tenga la estructura de una fecha.
 * \param vector: es el array a evaluar
 * \return Si el array es una fecha valida devuelve [1] sino devuelve [0].
 */
int esCadenaFecha (char vector[])
{
    int i=0;
    char numFecha[4];
    int day;
    int month;
    int year;
    int aux;

    if(strlen(vector)<6)
        return EL_DATO_NO_ES_VALIDO;

    aux=esNumeroFecha(vector, i, i+1, numFecha);
    if ( aux==0 )
        return EL_DATO_NO_ES_VALIDO;
    day=atoi(numFecha);
    if ( day<1 || day>31 )
        return EL_DATO_NO_ES_VALIDO;

    i=aux+1;
    aux=esNumeroFecha(vector, i, i+1, numFecha);
    if ( aux==0 )
        return EL_DATO_NO_ES_VALIDO;
    month=atoi(numFecha);
    if ( month<1 || month>12 )
        return EL_DATO_NO_ES_VALIDO;
    if ( ( month==4 || month==6 || month==9 || month==11  ) && day>30 )
        return EL_DATO_NO_ES_VALIDO;
    if ( month==2  && day>28 )
        return EL_DATO_NO_ES_VALIDO;

    i=aux+1;
    aux=esNumeroFecha(vector, i, i+3, numFecha);
    if (aux==0 || vector[aux]!='\0')
        return EL_DATO_NO_ES_VALIDO;
    year=atoi(numFecha);
    if ( year<1 || year>9999 )
        return EL_DATO_NO_ES_VALIDO;


    return EL_DATO_ES_VALIDO;
}


/**
 * \brief Funcion complementaria a esCadenaFecha. Valida que el rango de un array a evaluar corresponda a un componente de fecha valido.
 * \param vector: es el array a evaluar
 * \param posicionInicio: es la posicion del array desde la que se va a evaluar el valor.
 * \param posicionFin: es la posicion del array hasta la que se va a evaluar el valor.
 * \param numFecha: es el array donde se va a guardar el numero componente de la fecha.
 * \return Si el rango del array corresponde a un componente fecha valida devuelve [1] sino devuelve [0].
 */
int esNumeroFecha(char vector[], int posicionInicio, int posicionFin, char* numFecha)
{
    int flag=0;
    int i=posicionInicio;
    int j=posicionFin;
    while(vector[i]!='\0' && vector[i]!='-' && vector[i]!='/' && j>=i)
    {
        if( isdigit(vector[i]) )
        {
            numFecha[flag]=vector[i];
            flag++;
        }
        i++;
    }
    numFecha[flag]='\0';
    if (flag==0)
        return EL_DATO_NO_ES_VALIDO;
    return i;
}










