#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getString(char mensajeIngreso[], char input[]);
int getInt(int* numero, char mensajeIngreso[], char mensajeError[], int conLimInf, int minimo, int conLimSup, int maximo, int cantIntentos);

int esCadenaSoloNumeros (char vector[], int admitePunto)
{
    int i=0;
    int contadorPunto=0;
    while (vector[i]!='\0')
    {
        if (vector[i]<'0' || vector[i]>'9')
        {
            if (vector[i]=='.')
                contadorPunto++;
            if (admitePunto!=1 || contadorPunto>1)
                return -1;
        }
        i++;
    }
    return 0;
}

int main()
{
 /*    char vector[10]="1212.";
    printf("%d",esCadenaSoloNumeros(vector,1));

    int num;
    getDato(&num);
    printf("%d",num);
*/
    //int cmin, min, cmax, max;
    int dato;

    if (getInt(&dato, "\n Ingrese un entero: ", "\n El valor ingresado es invalido", 1, 0, 1, 200, 3)==0)
        printf("\n El dato ingresado es: %d",dato);
    else
        printf("\n El dato ingresado es invalido!");

}
int getDato (int* valor)
{
    int auxiliar;
    fflush(stdin);
    scanf("%d",&auxiliar);
    scanf("%d",&auxiliar);
    *valor=88;
}

int getString(char mensajeIngreso[], char input[])
{
    char buffer[4084];
    printf("%s",mensajeIngreso);
    fflush(stdin);
    scanf("%s",buffer);
    fflush(stdin);
    if ( strlen(buffer)==0 || buffer[0]=='\n' || buffer[0]=='\0' )
        return -1;
    strcpy(input,buffer);
    return 0;
}

int getInt(int* numero, char mensajeIngreso[], char mensajeError[], int conLimInf, int minimo, int conLimSup, int maximo, int cantIntentos)
{
    int aux;
    char input[4096];
    int intentosDisponibles=cantIntentos;

    do
    {
        if (intentosDisponibles==0)
        {
            printf("\n Se ha superado la cantidad de intentos de ingreso de un dato valido! \n El ingreso se detendra. \n");
            return -1;
        }
        else if (intentosDisponibles!=cantIntentos)
            printf("%s",mensajeError);
        if(conLimInf!=0)
            printf("\n El valor a ingresar no puede ser inferior a %d ",minimo);
        if(conLimSup!=0)
            printf("\n El valor a ingresar no puede ser superior a %d ",maximo);

        printf("\n (Cantidad de intentos disponibles: %d)",intentosDisponibles);
        intentosDisponibles--;

        getString(mensajeIngreso,input);
        if ( esCadenaSoloNumeros(input,1) != 0 )
            continue;
        aux = atoi(input);

        if(conLimInf==0)
            minimo=aux;
        if(conLimSup==0)
            maximo=aux;
    } while ( aux < minimo || aux > maximo );

    *numero = aux;
    return 0;
}
