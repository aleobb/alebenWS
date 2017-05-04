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

int fMaxMin(int num[], int cantIng, int calcMax )  // para calcular el maximo hay que ingresar 1 en char calcMax y para el min -1
{
    int i;
    int extremo = num[0]; // extremo lo uso para encontrar el extremo,(maximo o minimo)

    for( i=1 ; i < cantIng ; i++ )
    {
        if ( (num[i]*calcMax) > (extremo*calcMax) ) // con calcMax invierto el signo y por tanto el comparador ">"3
        {
            extremo = num[i] ;
        }
    }

    return extremo;

}

