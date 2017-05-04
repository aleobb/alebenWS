
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#include "util.h"



void graficoEdades (EPersona miPersona [], int largo)
{
    int i; // aux
    int menoresDe18=0; //cuenta edades menores a 18
    int de19A35=0; // cuenta edades entre 19 y 35
    int mayores35=0; // cuenta mayores de 35
    int mayor; // define el mayor de los valores anteriores
    int flag=0;

    // recorre la estructura para contar los valores.
    for(i=0;i<largo;i++)
    {
        if(miPersona[i].estado==1)
        {
            if(miPersona[i].edad<18)
            {
                menoresDe18++;
            }
            else
            {
                if(miPersona[i].edad>18 && miPersona[i].edad < 36)
                {
                    de19A35++;
                }
                else
                {
                    mayores35++;
                }
            }
        }
    }

    // define el mayor de los 3 valores
    if(menoresDe18 >= de19A35 && menoresDe18 >= mayores35)
    {
        mayor=menoresDe18;
    }
    else
    {
        if(de19A35 >= menoresDe18 && de19A35 >= mayores35)
        {
            mayor=de19A35;
        }
        else
        {
            mayor=mayores35;
        }
    }
    printf("\n\n");

    // imprime el grafico.
    for(i=mayor;i>0;i--)
    {
        if(i<=menoresDe18)
        {
            printf("*");
        }
        if(i<=de19A35)
        {
            printf("\t\t*");
        }
        if(i<=mayores35)
        {
            printf("\t\t\t        *");
        }
        printf("\n");
    }

    // imprime el detalle del grafico
    printf("<18\t\t19-35\t\t>35\n");
}

/**
* \brief imprime un grafico contando las edades
* \param recibe la estructura completa
* \return recibe el largo para recorrer la estructura
*
*/

int borrarPersona(EPersona miPersona[],int largo)
{
    char buffer[5000];
    int i; // aux
    int codigo; //Indice a borrar
    int min; // Primer indice activo.
    int max; //  Ultimo indice activo.
    int aux=0; // Auxiliar para validar
    int retorno; // return
    char respuesta; // confirmacion para borrar


    // Asigna a min el primer valor activo(en 1)
    for(i=0;i<largo;i++)
    {
        if(miPersona[i].estado==1)
        {
            min=i;

            break;
        }
    }

    // Asigna a max el ultimo valor activo (en 1)
    for(i=largo-1;i>=0;i--)
    {
        if(miPersona[i].estado==1)
        {
            max=i;

            break;
        }
    }



    printf("Ingrese el codigo de la persona que desea borrar: ");
    gets(buffer);

    // valida el ingreso del usuario pasandole el ingreso y los valores min y max
    while(validarInt(buffer,min,max)!=1)
    {
        printf("Ingreso invalido. Ingrese un codigo valido: ");
        gets(buffer);
    }

    //asigna a int codigo el valor del buffer
    codigo=cadena_entero(buffer);

    // pregunta para confirmar la operacion
    printf("Usted esta por borrar a: %s,con dni %d de %d años.\n",miPersona[codigo].nombre,miPersona[codigo].dni,miPersona[codigo].edad);
    printf("¿Desea confirmar? s/n: ");
    gets(buffer);

    //valida la respuesta
    while(aux==0)
    {
        // valida si el usuario ingreso un char
        while(validarChar(buffer)!=1)
        {
            printf("Ingreso invalido. Ingrese (s o n)\n");
            printf("¿Desea confirmar? s/n: ");
            gets(buffer);
        }

        //guarda el char en la variable char respuesta
        respuesta=buffer[0];

        //cambia el valor a miniscula
        tolower(respuesta);

        // evalua si el char es valido
        if(respuesta=='s'|| respuesta=='n')
        {
            aux=1;

        }
        else
        {
            strcpy(buffer,"123");
        }

    }
    // si es s borra.
    if(respuesta=='s')
    {
        miPersona[codigo].estado=0;

        retorno=1;
    }
    else
    {
        retorno=0;
    }


    return retorno;


}

/**
* \brief Funcion para borrar una persona
* \param Recibe la estructura completa
* \param Recibe el largo del array de la estructura
* \return Devuelve 1 si el usuario confirmo la operacion o 0 y no la confirmo.
*
*/

int setArray(EPersona array_a_setear[],int largo,int valor)
{
    int i;
    // recorre y asigna
    for(i=0;i<largo;i++)
    {
        array_a_setear[i].estado=valor;
    }

    return 0;

}
/**
* \brief Funcion para setear a un determinado valor un array
* \param recibe el array de estructuras
* \param recibe el largo del array de estructuras
* \param recibe el valor a setear en el array de estructuras
* \return
*
*/


void ordenarListar(EPersona miPersona[],int largo)
{
    int i,j; // variables de para ordenar
    int aux2=0; //auxiliar para hacer swap
    int flag=0;
    char aux[100];

    for(i=0;i<largo;i++)
    {
        if(miPersona[i].estado==1)
        {
            flag=1;

            break;
        }
    }
    // si el flag esta arriba  hay valores cargados
    if(flag==1)
    {
        for(i=0;i<largo;i++)
        {
            for(j=i+1;j<largo;j++)
            {

                // condicion verifica que este cargado i y j y luego compara los nombres
                if(miPersona[i].estado==1 && miPersona[j].estado==1 && strcasecmp(miPersona[i].nombre,miPersona[j].nombre)>0)
                {
                    strcpy(aux,miPersona[i].nombre);
                    strcpy(miPersona[i].nombre,miPersona[j].nombre);
                    strcpy(miPersona[j].nombre,aux);

                    aux2=miPersona[i].dni;
                    miPersona[i].dni=miPersona[j].dni;
                    miPersona[j].dni=aux2;

                    aux2=miPersona[i].edad;
                    miPersona[i].edad=miPersona[j].edad;
                    miPersona[j].edad=aux2;

                    aux2=miPersona[i].estado;
                    miPersona[i].estado=miPersona[j].estado;
                    miPersona[j].estado=miPersona[j].estado;


                }
            }
        }
        // imprime un titulo de columnas y los items cargados
        printf("CODIGO\t\tNOMBRE\t\tDNI\t\tEDAD\n");
        for(i=0;i<largo;i++)
        {
            if(miPersona[i].estado==1)
            {
                printf("%d\t\t%s\t\t%d\t\t%d\n",i,miPersona[i].nombre,miPersona[i].dni,miPersona[i].edad);
            }
        }
    }
    else
    {
        printf("No hay campos para mostrar.\n");
    }
}

/**
* \brief Ordena y imprime el array de estructuras
* \param recibe la estructura completa
* \param recibe el largo del array de estructura
*/


int agregarPersona(EPersona miPersona[],int valor)
{
    int auxEdad,auxDni; // Auxiliar para almacenar temporalmente la edad
    char bufferEdad[500]; // buffer para validar los datos que ingresa el usuario
    char bufferNombre[500]; // auxialiar para almacenar temporalmente el nombre
    char bufferDni[500]; // auxiliar para almacenar temporalmente el dni
    char bufferRespuesta[500]; // auxiliar para guardar temporalmente la respuesta
    char respuesta; // variable para guardar la respuesta de confirmacion
    int aux=0; //  variable para validar el ingreso de la respuesta (doble validacion)
    int retorno;

    printf("Ingrese el NOMBRE: "); // pide el nombre y lo guarda en el auxiliar
    gets(bufferNombre);

    while(validarString(bufferNombre,3,30)!=1) // verifica que sea un string entre 3 y 30 caracteres
    {
        printf("Ingreso invalido. Escriba el nombre (3 a 30 caracteres)\n");
        printf("Ingrese el NOMBRE: ");
        gets(bufferNombre);

    }


    printf("Ingrese el DNI: "); // pide el dni
    gets(bufferDni);

    while(validarInt(bufferDni,10000,999999999)!= 1) // verifica que el usuario ingreso un entero en el rango especifico
    {
        printf("Ingreso invalido. Escriba el DNI (5 a 9 caracteres)\n");
        printf("Ingrese el DNI: ");
        gets(bufferDni);
    }
    auxDni=cadena_entero(bufferDni);

    printf("Ingrese la EDAD: "); // ingresa la edad
    gets(bufferEdad);

    while(validarInt(bufferEdad,1,90)!= 1) // verifica que el usuario ingreso un entero
    {
        printf("Ingreso invalido. Escriba la EDAD (Entre 1 y 90)\n");
        printf("Ingrese la edad: ");
        gets(bufferEdad);
    }

    auxEdad=cadena_entero(bufferEdad); //guarda los numeros del string en una variable tipo int


    printf("Usted esta por ingresar a: %s, con DNI nº %d y su edad es %d años.\n",bufferNombre,auxDni,auxEdad);
    printf("¿Desea confirmar la operacion? s/n: ");
    gets(bufferRespuesta);


    while(aux == 0) // Empieza la doble validacion de la respuesta.
    {
        while(validarChar(bufferRespuesta)!=1) // valida que la entrada sea de un solo caracter
        {
            printf("Ingreso Invalido. (Escriba S o N)\n");
            printf("¿Desea confirmar la operacion? s/n: ");
            gets(bufferRespuesta);
        }

        respuesta=bufferRespuesta[0]; //guarda la respuesta en una variable char

        tolower(respuesta); // cambia el formato a minusculas

        if(respuesta == 's' || respuesta == 'n') // evalua si la respuesta es correcta
        {
            aux=1; // pasa la doble validacion.
        }
        else
        {
            strcpy(bufferRespuesta,"123"); // cambia el valor del buffer pasa ser evualuado nuevamente
        }
    }


    if(respuesta == 's') // confirma la operacion . guarda los datos en los campos definitivos
    {
        strcpy(miPersona[valor].nombre,bufferNombre);
        miPersona[valor].dni=auxDni;
        miPersona[valor].edad=auxEdad;
        miPersona[valor].estado=1;

        retorno=1;

    }
    else
    {
        retorno=0;
    }

    return retorno;


} // FIN agregarPErsona

/**
* \brief Funcion para agregar una persona con todos sus datos
* \param Recibe la estructura completa
* \param Recibe el valor para dar de alta
* \return Devuele 1 si el usuario confirmo la operacion o 0 sino la confirmo.
*
*/

int obtenerEspacioLibre(EPersona lista[],int largo)
{
    int i;
    int indice=-1;

    for(i=0;i<largo;i++)
    {
        if(lista[i].estado==0)
        {
            indice=i;

            break;
        }
    }
    return indice;
}

/**
* \brief Obtieve el primer espacio libre
* \param recibe la estructura completa
* \param recibe el largo de la estructura
* \return devuele el indice libre, sino encontro libres devuelve -1
*
*/

int chequearActivos(EPersona lista[],int largo)
{
    int i;
    int activos=0;

    for(i=0;i<largo;i++)
    {
        if(lista[i].estado==1)
        {
            activos=1;

            break;
        }
    }

    return activos;
}
/**
* \brief Verifica que exista un lugar activo
* \param recibe la estructura completa
* \param recibe el largo de la estructura
* \return devuelve 1 si hay lugares activos y 0 si no los hay
*
*/

 Desktop version
