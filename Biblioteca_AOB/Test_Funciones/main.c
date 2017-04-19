#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getString(char mensajeIngreso[], char input[]);
int getInt(int* numero, char mensajeIngreso[], char mensajeError[], int conLimInf, int minimo, int conLimSup, int maximo, int cantIntentos);

int esCadenaSoloLetras (char vector[], char arrayCharsAdmitidos[]);

void getStringg(char mensaje[],char input[]);

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

    /*
    int dato;

    if (getInt(&dato, "\n Ingrese un entero: ", "\n El valor ingresado es invalido", 1, 0, 1, 200, 3)==0)
        printf("\n El dato ingresado es: %d",dato);
    else
        printf("\n El dato ingresado es invalido!");

    */

    /*
    char arreglo[10];
    getStringg("igrese",arreglo);
    printf("%s",arreglo);
*/

    char array[10]={};
    char arrayChars[10];

    printf("ingrese texto: ");
    scanf("%[^\n]s",array);

    strcpy(arrayChars," ");
    printf("\n %c",arrayChars[0]);
    printf("\n %c",arrayChars[1]);
    printf("\n %d \n",strlen(arrayChars));

    if ( array[0]==arrayChars[0] )
        printf("es igual");

    if ( esCadenaSoloLetras(array, arrayChars)  )
        printf("\n es solo letras");
    else
        printf("\n NO LO ES");
    ///print(array);


}

void getStringg(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%[^\n]s", input);
}

int esCadenaSoloLetras (char vector[], char arrayCharsAdmitidos[])
{
    int size=strlen(arrayCharsAdmitidos);
    int i;
    int j;
    int flag=0;
    for (i=0 ; vector[i]!='\0'; i++)
    {
        printf("\n entro 1");
        if ( (vector[i]<'a' || vector[i]>'z') && (vector[i]<'A' || vector[i]>'Z') )
        {
            printf("\n entro 2");
            for(j=0 ; arrayCharsAdmitidos[j]!='\0' && flag==0 ; j++)
            {
                printf("\n entro 3");
                printf("\ni %c",vector[i]);
                printf("\nj %c",arrayCharsAdmitidos[j]);
                if (vector[i]==arrayCharsAdmitidos[j])
                    flag=1;
                printf("\n entro 4");
            }
            if (flag!=1)
                return 0;
        }
    }
    printf("\n devuelve");
    return 1;
}


void print (char arrayCharsAdmitidos[])
{

   /// strcpy(array,"abcd");

    printf("\n%d",strlen(arrayCharsAdmitidos));

    printf("\n%s",arrayCharsAdmitidos);

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
