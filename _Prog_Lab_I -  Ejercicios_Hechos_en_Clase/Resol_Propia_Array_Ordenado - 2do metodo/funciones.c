

int calcIndiceV(int vector[], int sizeVector, int minMax) // El auxiliar minMax sirve para, segun el valor (-1 o 1), calcular el min o maximo
{
    int i = 1; // i=indice
    int valorMinVector = vector[0];
    int indiceMin = 0;
    for ( ; i<sizeVector; i++)
    {
        if ( (vector[i]*minMax) > (valorMinVector*minMax) )
        {
            valorMinVector = vector[i];
            indiceMin = i;
        }
    }
    return indiceMin;
}


int expandirCompactarV(int vector[], int sizeVector, int indice, int compExp) // El auxiliar compExp sirve para, segun el valor (-1 o 1), compactar o expandir el vector
{
    for (;indice<sizeVector-1;indice++) //chequear el 1 y multiplicar por compExp ??
    {
        vector[indice] = vector[indice+1]; //chequear el 1
    }
    printf("%d",sizeVector);
    return sizeVector-1;
}

void ordenarV(int vector[],int sizeVector, int vectorRdo[], int menorMayor)
{
    int i;
    int indMinMax;
    int sizeOriginal = sizeVector; //
    for ( i=0; i<sizeOriginal; i++)
    {
        indMinMax = calcIndiceV(vector, sizeVector, menorMayor);
        vectorRdo[i] = vector[indMinMax];
        sizeVector = expandirCompactarV(vector, sizeVector, indMinMax, -1);
    }
}

*/
