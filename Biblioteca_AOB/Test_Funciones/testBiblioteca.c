#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 4084
#define EL_DATO_ES_VALIDO 1
#define EL_DATO_NO_ES_VALIDO 0


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




int esNumFecha(char vector[], int posicionInicio, int posicionFin, char* numFecha)
{
    int flag=0;
    int i=posicionInicio;
    int j=posicionFin;
    while(vector[i]!='\0' && vector[i]!='-' && vector[i]!='/' && j>=i)
    {
        printf("\nllego a i: %d",i);
        if( isdigit(vector[i]) )
        {
            numFecha[flag]=vector[i];
            printf("\nllego a aca numfecha: %c",numFecha[flag]);
            flag++;
        }
        i++;
    }
    numFecha[flag]='\0';
    printf("\n numfecha: %s",numFecha);
    if (flag==0)
        return EL_DATO_NO_ES_VALIDO;
    return i;
}

int esCadeFecha (char* vector)
{
    if(strlen(vector)>11)
        return EL_DATO_NO_ES_VALIDO;
    char day[3];
    char month[3];
    char year[5];
    int flag=0;
    int j=1;
    int i=0;
    while(vector[i]!='\0' && vector[i]!='-' && vector[i]!='/' && j>=0)
    {
        printf("llego aca");
        if( isdigit(vector[i]) )
        {
            flag++;
            day[i]=vector[i];
        }
        else
            return EL_DATO_NO_ES_VALIDO;
        i++;
        j--;
    }
    day[flag]='\0';
    printf("\nflag: %d",flag);
    printf("\nllego aca dia: %s", day);
    if(flag==0 || vector[i]!='\0')
        return EL_DATO_NO_ES_VALIDO;
    i++;
    flag=0;
    j=1;
    while( vector[i]!='-' && vector[i]!='/' && j>=0 )
    {
        if( isdigit(vector[i]) )
        {
            flag++;
            month[i]=vector[i];
        }
        else
            return EL_DATO_NO_ES_VALIDO;
        i++;
        j--;
    }
    month[flag]='\0';

    printf("\nllego aca mes: %s", month);
    if(flag==0 || vector[i]!='\0')
        return EL_DATO_NO_ES_VALIDO;

    i++;
    flag=0;
    j=3;
    while(vector[i]!='\0' && vector[i]!='-' && vector[i]!='/' && j>=0 )
    {
        if( isdigit(vector[i]) )
        {
            flag++;
            year[j]=vector[i];
        }
        else
            return EL_DATO_NO_ES_VALIDO;
        i++;
        j--;
    }
    year[flag]='\0';
    printf("\nllego aca anio: %s", year);
    if(flag==0)
        return EL_DATO_NO_ES_VALIDO;

    vector[i]='\0';
    return EL_DATO_ES_VALIDO;

}

int testFecha()
{
 /*    char vector[10]="1212.";
    printf("%d",esCadenaSoloNumeros(vector,1));

    int num;
    getDato(&num);
    printf("%d",num);
*/
    //int cmin, min, cmax, max;

    int i=0;
    char numFecha[4];
    int aux;
    char dato[11];
    int r=0;
    while(r==0)
    {

    getString("\n Ingrese fecha: ",dato);
    printf("\n largo: %d",strlen(dato)); /// tiene que ser mayor a 5
    aux=esNumeroFecha(dato, i, i+1,numFecha);
    printf("\n aux: %d - i: %d", aux, i);
    if (aux>0)
        printf("\nEl dato valido ingresado es: %s", numFecha);
    else
        printf("\nEl dato no se pudo ingresar correctamente");

    i=aux+1;
    printf("\n aux: %d - i: %d", aux, i);
    aux=esNumeroFecha(dato, i, i+1, numFecha);
    if (aux>0)
        printf("\nEl dato valido ingresado es: %s",numFecha);
    else
        printf("\nEl dato no se pudo ingresar correctamente");

    printf("\n\n aux: %d - i: %d\n\n", aux, i);
    i=aux+1;
    printf("\n aux: %d - i: %d", aux, i);
    aux=esNumeroFecha(dato, i, i+3, numFecha);
    printf("\n aux: %d - i: %d", aux, i);
    if (aux>0 && dato[aux]=='\0')
        printf("\nEl dato valido ingresado es: %s",numFecha);
    else
        printf("\nEl dato no se pudo ingresar correctamente");


    i=0;
    aux=0;
    };


    /*
    char arreglo[10];
    getStringg("igrese",arreglo);
    printf("%s",arreglo);
*/
 return 0;
}

