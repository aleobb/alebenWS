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
  //  printf("expComV\n");
    for (; (indice)*compExp > (sizeVector+compExp)*compExp; indice=(indice-compExp)) //chequear el 1 y multiplicar por compExp ??
    {
        vector[indice] = vector[indice-compExp]; //chequear el 1
    }
    return sizeVector+compExp;
}

void ordenarMetodoAlternativo(int vector[],int sizeVector, int vectorRdo[], int menorMayor)
{
   // printf("ordenarV\n");
    int i;
    int indMinMax;
    int sizeOriginal = sizeVector; //

    vectorRdo[0] = vector[0];
    for ( i=1; i<=sizeOriginal; i++) //arranco a ordenar desde la posicion 1
    {
        vectorRdo[i] = vector[i];
        indMinMax = calcIndiceV(vectorRdo, i+1, menorMayor);
        vectorRdo[i-1] = vector[indMinMax];
        sizeVector++; ///= expandirCompactarV(vectorRdo, sizeVector, indMinMax, menorMayor);
    }
}






/// ordenar original
/// ordenar original
/// ordenar original
/// ordenar original

void ordenarV(int vector[],int sizeVector, int vectorRdo[], int menorMayor)
{
   // printf("ordenarV\n");
    int i;
    int indMinMax;
    int sizeOriginal = sizeVector; //
    for ( i=0; i<sizeOriginal; i++)
    {
        indMinMax = calcIndiceV(vector, sizeVector, menorMayor);
        vectorRdo[i] = vector[indMinMax];
        sizeVector = expandirCompactarV(vector, sizeVector, indMinMax, menorMayor);
    }
}
