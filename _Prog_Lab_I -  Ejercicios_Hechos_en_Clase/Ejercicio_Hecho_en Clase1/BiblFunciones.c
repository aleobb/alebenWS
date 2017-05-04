


float prom(int array[], int cantidad)
{
    float promedio, suma = 0;
    int i;

    for( i=0; i < cantidad ; i++ )
    {
        suma = suma + array[i] ;
    }
    promedio = suma/cantidad ;
    return promedio ;
}
