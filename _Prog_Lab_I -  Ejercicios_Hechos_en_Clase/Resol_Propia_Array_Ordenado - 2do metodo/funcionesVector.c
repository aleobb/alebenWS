int calcIndiceV(int vector[], int sizeVector, int valorAordenar, int minMax) // El auxiliar minMax sirve para, segun el valor (-1 o 1), calcular el min o maximo
{                                          /// valorAordenar es el siguiente valor del vector que quiero acomodar
    int indice;
    int i = 0;
    int flag =0;
    for ( ; i<sizeVector; i++)
    {
        if ( (vector[i]*minMax) > (valorAordenar *minMax) )
        {
            indice = i;
            flag = 1;
        }
    }
    if (flag==1)
    {
      return indice;
    }
    else
    {
        return sizeVector;
    }

}


int expandirCompactarV(int vector[], int sizeVector, int indice, int compExp) // El auxiliar compExp sirve para, segun el valor (-1 o 1), compactar o expandir el vector
{
  //  printf("expComV\n");
    for (; (indice)*compExp > (sizeVector+compExp)*compExp; indice=(indice-compExp)) //chequear el 1 y multiplicar por compExp ??
    {
        if (compExp==1)
            { vector[indice+1] = vector[indice]; }
        else
            { vector[indice] = vector[indice+1]; }
    }
    return sizeVector;
}

void ordenarMetodoAlternativo(int vector[],int sizeVector, int menorMayor)
{
   // printf("ordenarV\n");
    int vectorRdo[100];
    int i;
    int indMinMax = menorMayor;
    int indice;
    int sizeOriginal = sizeVector; //
    int j;

    vectorRdo[0] = vector[0];
    printf("\nvRdo %d (0)",vectorRdo[0]);
    for ( i=1; i<sizeOriginal; i++) //arranco a ordenar desde la posicion 1
    {
        vectorRdo[i] = vector[i];
        indice = calcIndiceV(vectorRdo, i, vector[i], -menorMayor); /// aca con i (sola) le paso el tamaño del vector y con vector[i] paso el valor (de la posicion sigte) del vector que quiero agregar ordenadamente

        for (j=0; j<i; j++)
        {
            printf("\n elemento %d: %d",j,vectorRdo[j]);
        }

        printf("\n indice: %d ",indice);
        printf("\n indice compactado: %d ", expandirCompactarV(vectorRdo, indice, indMinMax, 1) ) ; /// no traigo el resultado de esta funcion porque el vector se tiene que ir expandiendo si o si de 1 en 1

        printf("\n");
        vectorRdo[i] = vector[i];
        printf("\nvRdo %d (%d)",vectorRdo[i],i);
    }
}





/*
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

    */
