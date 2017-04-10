#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getInt (char pedirDato[], char mensajeError[], int min, int max, int numIntentos)
{
    int datoIngresado;
    printf("%s",pedirDato);
    scanf("%d",&datoIngresado);
    while (datoIngresado<min || datoIngresado>max)
    {
        if (numIntentos==0)
        {
            printf("\n Se ha superado la cantidad de intentos de ingreso de un dato valido! \n El ingreso se detendra. \n");
            return 0;
        }
        printf("%s",mensajeError);
        printf("\n (Cantidad de intentos disponibles: %d)",numIntentos);
        printf("%s",pedirDato);
        scanf("%d",&datoIngresado);
        numIntentos--;
    }
    return datoIngresado;
}

int esCadenaSoloNumeros (char vector[])
{
    int i=0;
    while (vector[i]!='\0')
    {
        if (vector[i]<'0' || vector[i]>'9')
            return 0;
        i++;
    }
    return 1;
}

int esCadenaSoloLetras (char vector[])
{
    int i=0;
    while (vector[i]!='\0')
    {
        if ( vector[i]!=' ' && (vector[i]<'a' || vector[i]>'z') && (vector[i]<'A' || vector[i]>'Z') )
            return 0;
        i++;
    }
    return 1;
}

int esCadenaAlfanumerica (char vector[])
{
    int i=0;
    while (vector[i]!='\0')
    {
        if ( vector[i]!=' ' && (vector[i]<'a' || vector[i]>'z') && (vector[i]<'A' || vector[i]>'Z') && (vector[i]<'0' || vector[i]>'9') )
            return 0;
        i++;
    }
    return 1;
}

int getString (char pedirDato[], char vectorDato[], char tipoDato, char mensajeErrorTipoDato[])
{
    int esCadenaValida=0;
    char vectorAux[100];
    int largoCadenaIngresada=0;
    char seguir='n';

    do
    {
        printf("%s",pedirDato);
        fflush(stdin);
        scanf("%s",vectorAux);
        largoCadenaIngresada=strlen(vectorAux);

        if (largoCadenaIngresada>0)
        {
            switch (tipoDato)
            {
                case 'n':
                    esCadenaValida = esCadenaSoloNumeros(vectorAux);
                    break;
                case 'l':
                    esCadenaValida = esCadenaSoloLetras(vectorAux);
                    break;
                case 'a':
                    esCadenaValida = esCadenaAlfanumerica(vectorAux);
                    break;
            }
        }
        if( esCadenaValida == 1)
        {
            strcpy(vectorDato,vectorAux);
            return 1;
        }
        else
        {
            printf("%s",mensajeErrorTipoDato);
            printf("\n Desea ingresar el Dato nuevamente? (s/n) ");
            fflush(stdin);
            scanf("%c",&seguir);
        }
    }while (seguir=='s');
    return 0;
}


/**
 *\brief ordena un vector compuesto por enteros
 */
void ordenarVector(int vector[], int sizeVector, int menorMayor)
{
    int pivot, i, j;
    int aux;

    if (sizeVector<2)
        return;

    pivot=vector[sizeVector/2];

    for( i=0, j=sizeVector-1; ; i++, j--)
    {
        while ( (vector[i]*menorMayor) < (pivot*menorMayor ) )
            i++;

        while ( (vector[j]*menorMayor) > (pivot*menorMayor) )
            j--;

        if(i>=j)
            break;

        aux = vector[i];
        vector[i] = vector[j];
        vector[j] = aux;
    }

    ordenarVector(vector,i,menorMayor);
    ordenarVector(vector+i,sizeVector-i,menorMayor);
}
