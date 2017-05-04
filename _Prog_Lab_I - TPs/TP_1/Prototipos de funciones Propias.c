

float getFloat

/*brief Pedir y validar un  dato flotante
**
**
**
*/

float fPedirYValidarDato(char leyendaPedirDato[], char leyendaDatoInvalido[], char vValidaciones[], float min, float max, float distinto, float igual)
{
    printf("%c",leyendaPedirDato);
    scanf("%f",&dato);

    if ( vValidaciones[0] == 0 )  // En caso de que no se valide límite inferior
        { min = dato; }
    if ( vValidaciones[1] == 0 )  // En caso de que no se valide límite inferior
        { max = dato; }
    if ( vValidaciones[2] == 0 )  // En caso de que no se valide que no sea un valor determinado
        { distinto = dato+1; }
    if ( vValidaciones[3] == 0 )  // En caso de que no se valide que sea un valor determinado
        { igual = dato; }

    while ( dato < min || dato > max || dato == distinto || dato != igual )
    {
        printf("%c",leyendaDatoInvalido);
        printf("%c",leyendaPedirDato);
        scanf("%f",&dato);
    }

    return dato
}
