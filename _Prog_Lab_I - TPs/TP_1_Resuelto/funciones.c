
float ingresarDato(char leyendaPedirDato[100], char leyendaDatoInvalido[100], int cLimInf , int cLimSup, float min, float max, float distinto )
{

    printf("%s",leyendaPedirDato);
    scanf("%f",&dato);

    if ( cLimInf == 0 )  // con esto se saltea el siguiente while en caso de no pedir dato con limite minimo
    {
        min = dato;
    }
    if ( cLimSup == 0 )  // con esto se saltea el siguiente while en caso de no pedir dato con limite maximo
    {
        max = dato;
    }

    while ( dato <= min || dato >= max || dato == distinto)
    {
        printf("%s",leyendaDatoInvalido);
        printf("%s",leyendaPedirDato);
        scanf("%f",&dato);
    }


    return dato
}
