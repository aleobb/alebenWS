#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main()
{
    char dato[100];
    if (getString("Ingrese dato", )==0)
        printf("\n El dato ingresado es: %s",dato);
    else
        printf("\n El dato ingresado es invalido!");
}

int getString(char mensajeIngreso[], char input[])
{
    char buffer[4084];
    printf("%s",mensajeIngreso);
    scanf("%s",buffer);
    if ( strlen(buffer) > 0 )
        strcpy(input,buffer);
        return 0;
    return -1;
}
