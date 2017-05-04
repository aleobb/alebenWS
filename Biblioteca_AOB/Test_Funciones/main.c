#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "testBiblioteca.h"

#define BUFFER 4084
#define EL_DATO_ES_VALIDO 1
#define EL_DATO_NO_ES_VALIDO 0

void testEsUnFlotante();

float getFloat(float* numero, char mensajeIngreso[], char mensajeError[], int conLimInf, float minimo, int conLimSup, float maximo, int cantIntentos);

int getString(char mensajeIngreso[], char input[]);
int getInt(int* numero, char mensajeIngreso[], char mensajeError[], int conLimInf, int minimo, int conLimSup, int maximo, int cantIntentos);

int esCadenaSoloLetras (char vector[], char arrayCharsAdmitidos[]);

int esCadenaSoloNumeros (char vector[], int cantPuntos, int admiteNegativos);

int esCadenaAlfanumerica (char vector[], char arrayCharsAdmitidos[]);

void getStringg(char mensaje[],char input[]);

int getType(char mensajeIngreso[], char mensajeError[], int bucle, int type, char arrayCharsAdmitidos[], int maxExtensionArray, char* input);

void testIngresoString();

int esCadenaEmail (char vector[], char arrayCharsAdmitidos[]);

int esCadenaTelefono (char vector[]);

void testIngresoEmail();

int main()
{
 /*    char vector[10]="1212.";
    printf("%d",esCadenaSoloNumeros(vector,1));

    int num;
    getDato(&num);
    printf("%d",num);
*/
    //int cmin, min, cmax, max;

    testIngresoEmail();


    /*
    char arreglo[10];
    getStringg("igrese",arreglo);
    printf("%s",arreglo);
*/
 return 0;
}

void testIngresoEmail()
{
    int aux;
    char charsAdm [10]={"@."};
    char dato[100];
    aux=getType("\n Ingrese un dato: ", "\n El dato ingresado es invalido", 1, 5, charsAdm, 20, dato);
    if (aux)
        printf("\nEl dato valido ingresado es: %s",dato);
    else
        printf("\nEl dato no se pudo ingresar correctamente");
    return 0;
}

void testIngresoString()
{
    int aux;
    char charsAdm [10]={" .-"};
    char dato[100];
    aux=getType("\n Ingrese un dato: ", "\n El dato ingresado es invalido", 1, 3, charsAdm, 11, dato);
    if (aux)
        printf("\nEl dato valido ingresado es: %s",dato);
    else
        printf("\nEl dato no se pudo ingresar correctamente");
    return 0;
}

void testEsUnEntero()
{
    int dato;

    if (getInt(&dato, "\n Ingrese un entero: ", "\n El valor ingresado es invalido", 1, 0, 1, 200, 3)==1)
        printf("\n El dato ingresado es: %d",dato);
    else
        printf("\n El dato ingresado es invalido!");
}

void testEsUnFlotante()
{
    float dato;

    if (getFloat(&dato, "\n Ingrese un flotante: ", "\n El valor ingresado es invalido", 1, 0, 1, 200, 5)==1)
        printf("\n El dato ingresado es: %f",dato);
    else
        printf("\n El dato ingresado es invalido!");
}


/**
 * \brief Solicitar al usuario una cadena de caracteres.
 * \param mensajeIngreso: es el mensaje a mostrar para pedir el ingreso.
 * \param mensajeError: mensaje a mostrar si el dato no esta dentro del rango valido.
 * \param bucle: el codigo se va a repetir hasta que se ingrese un tipo de dato valido.
 * \param type: tipo de ingreso que se quiere obtener como valido.
 * \param arrayCharsAdmitidos es el array que contiene los caracteres que tambien van a resultar validos.
 * \param input: es el array donde se va a guardar la cadena.
 * \return Si obtuvo un ingreso valido devuelve [1] sino devuelve [0].
 */
int getType(char mensajeIngreso[], char mensajeError[], int bucle, int type, char arrayCharsAdmitidos[], int maxExtensionArray, char* input)
{
    int validacion;
    char buffer[BUFFER];
    do
    {
        getString(mensajeIngreso, buffer);
        switch (type)
        {
            case 1:
                validacion=esCadenaSoloLetras(buffer, arrayCharsAdmitidos);
                break;
            case 2:
                validacion=esCadenaAlfanumerica(buffer, arrayCharsAdmitidos);
                break;
            case 3:
                validacion=esCadenaFecha(buffer);
                break;
            case 4:
                validacion=esCadenaTelefono(buffer);
            case 5:
                validacion=esCadenaEmail(buffer, arrayCharsAdmitidos);
        }
        if(validacion==EL_DATO_NO_ES_VALIDO || strlen(buffer)>maxExtensionArray)
        {
            printf(mensajeError);
            validacion=EL_DATO_NO_ES_VALIDO;
        }
        else
            strcpy(input,buffer);
    }while( bucle==1 && validacion==EL_DATO_NO_ES_VALIDO );
    return validacion;
}


void testCadenaSoloNumeros ()
{

    int i, aux;
    char array[100]={};

    printf("ingrese nros: ");
    scanf("%[^\n]s",array);
    printf("\n el nro es: ");
    for (i=0;array[i]!='\0';i++)
        printf("%c",array[i]);

    printf("\n");
    aux = esCadenaSoloNumeros(array, 1, 1);

    if ( aux )
        printf("\n Es solo nros");
    else
        printf("\n NO LO ES");


}


void testCadenaSoloLetras ()
{

    char array[10]={};
    char arrayChars[10];

    printf("ingrese texto: ");
    scanf("%[^\n]s",array);

    strcpy(arrayChars,".-,");
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



/**
 * \brief Verifica que una array esté compuesto solo por numeros.
 * \param vector: es el array a evaluar
 * \param cantPuntos: Valida que la cadena pueda incluir hasta la cantidad de puntos ('.') que recibe como parametro.
 * \param admiteNegativos: recibe 1 como parametro, acepta como valido una cadena que empieza con el signo '-', sino no.
 * \return Si el array esta compuesto solo por numeros devuelve [1] sino devuelve [0].
 */
int esCadenaSoloNumeros (char vector[], int cantPuntos, int admiteNegativos)
{
    int i=0;
    if (vector[0]=='-')
    {
        if (admiteNegativos==1)
            i++;
        else
            return 0;
    }
    for ( ; vector[i]!='\0'; i++)
    {
        if (vector[i]=='.' && cantPuntos>0)
            cantPuntos--;
        else if (vector[i]<'0' || vector[i]>'9')
            return 0;
    }
    return 1;
}



/**
 * \brief Verifica que una array esté compuesto solo por numeros, guiones y/o parentesis.
 * \param vector: es el array a evaluar
 * \return Si el array esta compuesto por una cadena telefono devuelve [1] sino devuelve [0].
 */
int esCadenaTelefono (char vector[])
{
    int i=0;
    int flagAbrirParentesis=0;
    int flagGuion=0;
    int cantCaracteresTel=6;
    if (vector[0]=='-' || vector[0]==')' || vector[0]=='\0')
        return EL_DATO_NO_ES_VALIDO;
    else if (vector[0]=='(' && vector[1]!='\0')
    {
        i++;
        flagAbrirParentesis++;
        cantCaracteresTel=cantCaracteresTel+3;
    }

    for ( ; vector[i]!='\0'; i++)
    {
        if (vector[i]==')' && flagAbrirParentesis==1 && vector[i+1]!='\0')
            continue;
        else if (vector[i]=='-' && vector[i-1]!='(' && vector[i-1]!=')' && vector[i+1]!='\0')
        {
            flagGuion++;
            continue;
        }
        else if (vector[i]<'0' || vector[i]>'9')
            return EL_DATO_NO_ES_VALIDO;
    }
    if (flagGuion==0 || flagGuion>2 || strlen(vector)<cantCaracteresTel)
        return EL_DATO_NO_ES_VALIDO;
    return EL_DATO_ES_VALIDO;
}


int esCadenaEmail (char vector[], char arrayCharsAdmitidos[])
{
    int i;
    int flagArroba=0;
    int flagPunto=0;
    int cantCaracteres=6;
    if (vector[0]=='@' || vector[0]=='.' || vector[0]=='\0' || esCadenaAlfanumerica(vector, arrayCharsAdmitidos)==0 || strlen(vector)<cantCaracteres)
    {
        printf("\n llego aca \n");
        return EL_DATO_NO_ES_VALIDO;
    }
    for (i=1 ; vector[i]!='\0'; i++)
    {
        if (vector[i]=='@')
        {
            flagArroba++;
            if (flagArroba>1 || flagPunto>0 || vector[i+1]=='\0' || vector[i+1]=='.')
            {
                printf("\n llego aca2 \n");
                return EL_DATO_NO_ES_VALIDO;
            }
            continue;
        }
        else if (vector[i]=='.')
        {
            flagPunto++;
            if (flagArroba==0 || flagPunto>1 || vector[i+1]=='\0')
            {
                printf("\n llego aca3 \n");
                return EL_DATO_NO_ES_VALIDO;
            }
            continue;
        }
    }
    if (flagArroba==0 || flagPunto==0)
        return EL_DATO_NO_ES_VALIDO;
    return EL_DATO_ES_VALIDO;
}


/**
 * \brief Verifica que una array esté compuesto solo por letras (mayusculas y/o minusculas) y/o una serie de caracteres definidos.
 * \param vector es el array a evaluar
 * \param arrayCharsAdmitidos es el array que contiene los caracteres que tambien van a resultar validos.
 * \return Si el array esta compuesto solo por letras y/o los caracteres especificados devuelve [1] sino devuelve [0].
 */
int esCadenaSoloLetras (char vector[], char arrayCharsAdmitidos[])
{
   ///  int size=strlen(arrayCharsAdmitidos);
    int i;
    int j;
    int flag=0;
    for (i=0 ; vector[i]!='\0'; i++)
    {
        if ( (vector[i]<'a' || vector[i]>'z') && (vector[i]<'A' || vector[i]>'Z') )
        {
            for(j=0 ; arrayCharsAdmitidos[j]!='\0' && flag==0 ; j++)
            {
                if (vector[i]==arrayCharsAdmitidos[j])
                    flag=1;
            }
            if (flag!=1)
                return 0;
        }
    }
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
    return 0;
}

int getString(char mensajeIngreso[], char input[])
{
    char buffer[BUFFER];
    printf("%s",mensajeIngreso);
    fflush(stdin);
    scanf("%[^\n]s",buffer);
    if ( strlen(buffer)==0 || buffer[0]=='\0' )
        return 0;
    strcpy(input,buffer);
    return 1;
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
            return EL_DATO_NO_ES_VALIDO;
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
        if ( esCadenaSoloNumeros(input,0,1) == EL_DATO_NO_ES_VALIDO )
            continue;
        aux = atoi(input);

        if(conLimInf==0)
            minimo=aux;
        if(conLimSup==0)
            maximo=aux;
    } while ( aux < minimo || aux > maximo );

    *numero = aux;
    return EL_DATO_ES_VALIDO;
}


float getFloat(float* numero, char mensajeIngreso[], char mensajeError[], int conLimInf, float minimo, int conLimSup, float maximo, int cantIntentos)
{
    float aux;
    char input[4096];
    int intentosDisponibles=cantIntentos;

    do
    {
        if (intentosDisponibles==0)
        {
            printf("\n Se ha superado la cantidad de intentos de ingreso de un dato valido! \n El ingreso se detendra. \n");
            return EL_DATO_NO_ES_VALIDO;
        }
        else if (intentosDisponibles!=cantIntentos)
            printf("%s",mensajeError);
        if(conLimInf!=0)
            printf("\n El valor a ingresar no puede ser inferior a %f ",minimo);
        if(conLimSup!=0)
            printf("\n El valor a ingresar no puede ser superior a %f ",maximo);

        printf("\n (Cantidad de intentos disponibles: %d)",intentosDisponibles);
        intentosDisponibles--;

        getString(mensajeIngreso,input);
        if ( esCadenaSoloNumeros(input,1,1) == EL_DATO_NO_ES_VALIDO )
            continue;
        aux = atof(input);

        if(conLimInf==0)
            minimo=aux;
        if(conLimSup==0)
            maximo=aux;
    } while ( aux < minimo || aux > maximo );

    *numero = aux;
    return EL_DATO_ES_VALIDO;
}


/**
 * \brief Verifica que una array esté compuesto solo por numeros y/o espacios y/o letras (mayusculas y/o minusculas).
 * \param vector es el array a evaluar
 * \return Si el array esta compuesto solo por numeros y/o letras y/o los caracteres especificados devuelve [1] sino devuelve [0].
 */
int esCadenaAlfanumerica (char vector[], char arrayCharsAdmitidos[])
{
    int i, j;
    int flag=0;
    for (i=0 ; vector[i]!='\0'; i++)
    {
        if ( (vector[i]<'a' || vector[i]>'z') && (vector[i]<'A' || vector[i]>'Z') && (vector[i]<'0' || vector[i]>'9') )
        {
            for(j=0 ; arrayCharsAdmitidos[j]!='\0' && flag==0 ; j++)
            {
                if (vector[i]==arrayCharsAdmitidos[j])
                    flag=1;
            }
            if (flag!=1)
                return EL_DATO_NO_ES_VALIDO;
        }
    }
    return EL_DATO_ES_VALIDO;
}
