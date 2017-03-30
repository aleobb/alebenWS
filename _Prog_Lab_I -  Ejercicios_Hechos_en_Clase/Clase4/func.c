float promedio(int numero[], int cont)
{
    float promedioR, suma = 0;
    int i;

    for( i=1; i < cont ; i++ )
    {
        suma = suma + numero[i] ;
    }
    promedioR = suma/cont ;
    return promedioR ;

}

int fMaxMin(int num[], int cantIngresos, char esMax )
{
    int i;
    int max, min;
    max = num[0];
    min = num[0];

    for( i=1 ; i < cantIngresos ; i++ )
    {
        max = num[i] ;
    }
    promedioR = suma/cont ;

    if (esMax=1)
        { return max; }
    else
        { return min; }

}

