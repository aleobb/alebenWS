
// funcion nro entero y validarlo

int obtenerInt(char mensaje[],char mensajeError[],int min, int max)
// La funcion se llamaria x ej de la siguiente manera: obtenerInt("Ingrese la edad","La edad ingresada es incorrecta", 0, 100);
{
    int buffer; //es lo que me ingresa el usuario
    printf("%s",mensaje);
    scanf("%d",&buffer);
    while( buffer < min || buffer > max )
    {
        printf("%s",mensajeError);
        printf("%s",mensaje);
        scanf("%d",&buffer);

        // se puede dar un limite de cantidad de intentos para igresar la un valor valido y si no terminar la funcion
    }

    return buffer;
}
