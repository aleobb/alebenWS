#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"

#define QTYTURNOS 200
#define URGENTE 1
#define REGULAR 2
#define BUFFER 4084


/**
 * \brief Solicitar al usuario una cadena de caracteres.
 * \param mensajeIngreso: es el mensaje a mostrar para pedir el ingreso.
 * \param input es el array donde se va a guardar la cadena.
 * \return Si obtuvo un ingreso no nulo devuelve [1] sino devuelve [0].
 */
int getString(char mensajeIngreso[], char input[])
{
    char buffer[BUFFER];
    printf("%s",mensajeIngreso);
    fflush(stdin);
    scanf("%[^\n]s",buffer);
    if ( strlen(buffer)==0 || buffer[0]=='\0' )
        return 0;
    strcpy(input,buffer);
    return 1;
}

/**
 * \brief Verifica que una array esté compuesto solo por numeros.
 * \param vector: es el array a evaluar
 * \param admitePunto: si se recibe 1 como parametro, valida que la cadena pueda incluir hasta 1 punto ('.'), sino no.
  * \param admitePunto: si se recibe 1 como parametro, acepta como valido una cadena que empieza con el signo '-', sino no.
 * \return Si el array esta compuesto solo por numeros devuelve [1] sino devuelve [0].
 */
int esCadenaSoloNumeros (char vector[], int cantPuntos, int admiteNegativos)
{
    int i=0;
    int contadorPuntos=cantPuntos;
    while (vector[i]!='\0')
    {
        if (vector[i]<'0' || vector[i]>'9')
        {
            if (vector[0]=='-' && admiteNegativos!=1)
                return 0;
            if (vector[i]=='.')
                contadorPuntos--;
            if ( cantPuntos==0 || contadorPuntos<0 )
                return 0;
        }
        i++;
    }
    return 1;
}

int otorgarTurno(Tramites turno[], int posicionArray, int tipoTramite, int nroTurno)
{
    int dni;
    char arrayAux[BUFFER];
    if ( getString("\n Ingrese su DNI: ",arrayAux) == 1 )
    {
        dni = esCadenaSoloNumeros(arrayAux,0,0);
        if ( dni == 1 && arrayAux>0 && arrayAux < 99999999) /// Rango de valores validos para un DNI
        {
            turno[posicionArray].dni=atoi(arrayAux);
            turno[posicionArray].tipoyEstadoTurno=tipoTramite;
            turno[posicionArray].nroTurno=nroTurno;
            return 1;
        }
    }
    printf ("\n El dato ingresado es Invalido! Debe ingresar un nro. de DNI (sin puntos) \n\n");
    return 0;
}


void listarTurnos(Tramites* turnos, int nroTurnoSigte)
{
    int i;
    printf("\n Tramites urgentes: ");
    for (i=0;i<nroTurnoSigte;i++)
        if (turnos[i].tipoyEstadoTurno==URGENTE)
            printf("\n Nro.turno: %d DNI %d",turnos[i].nroTurno,turnos[i].dni);

    printf("\n Tramites regulares: ");
    for (i=0;i<nroTurnoSigte;i++)
        if (turnos[i].tipoyEstadoTurno==REGULAR)
            printf("\n Nro.turno: %d DNI %d",turnos[i].nroTurno,turnos[i].dni);
    return 0;
}


/**
 * \brief halla el valor maximo o minimo de un vector de enteros
 * \param array es el vector que contiene los valores a analizar.
 * \param posInicio es la posicion del vector desde la que se va a analizar.
 * \param posFin es la posicion del vector hasta la que se va a analizar (inclusive).
 * \param maxMin parametro que indica si se van a hallar el maximo (1) o el minimo (-1).
 * \param posValor si es 1 devuelve la posicion en el vector, de lo contrario devuelve el valor.
 * \param valorCampo: se consideraran como maximo o minimo validos aquellos valores del array cuyo campo coincida con el valorCampo.
 * \return devuelve -1 si no se encotró ningun valor.
 */
int maxMinArrayInt(Tramites array[], int posInicio, int posFin, int maxMin, int posValor, int valorCampo)
{
    int i;
    int flag=0;
    int extremo;
    int posicion;
    if ( posInicio <= posFin )
    {
        for ( i = posInicio ; i <= posFin ; i++ )
        {
            if (array[i].tipoyEstadoTurno==valorCampo)
            {
                printf("\n nro turno: %d", array[i].nroTurno);
                printf("\n extremo: %d", extremo);
                if( (array[i].nroTurno*maxMin) > (extremo*maxMin) || flag==0  )
                {
                    extremo=array[i].nroTurno;
                    posicion = i;
                    flag=1;
                }
            }
        }
        if (flag==0)
            return -1;
        if (posValor==1)
            return posicion;
        return extremo;
    }
}


void bubleSort(Tramites array[], int size)
{
    int i;
    int flagSwap = 1;
    Tramites aux;
    while(flagSwap)
    {
        flagSwap = 0;
        for(i = 0; i<size-1 ; i++)
        {
            if( array[i].dni > array[i+1].dni )
            {
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                flagSwap = 1;
            }
        }
    }
}
