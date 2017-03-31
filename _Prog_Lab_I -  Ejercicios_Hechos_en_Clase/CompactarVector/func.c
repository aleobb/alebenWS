
int compactar(int array[], int indice, int size)
{

    for ( ; indice<size-1 ;indice++)
    {
        array [indice]=array[indice+1];
    }

    return size - 1 ;

}

int fMaxMin(int num[], int cantIng, int calcMax )  // para calcular el maximo hay que ingresar 1 en char calcMax y para el min -1
{

    int indice =1;
    int extremo = num[0]; // extremo lo uso para encontrar el extremo,(maximo o minimo)
    int indiceExtremo = 0;

    for( ; indice < cantIng ; indice++ )
    {
        if ( (num[indice]*calcMax) > (extremo*calcMax) ) // con calcMax invierto el signo y por tanto el comparador ">"3
        {
            extremo = num[indice] ;
            indiceExtremo = indice;
        }
    }

    return indiceExtremo;
}

void fOrdenarVector ();
{

}
