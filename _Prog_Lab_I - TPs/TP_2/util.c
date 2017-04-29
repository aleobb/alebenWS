
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "util.h"
#include "funciones.h"





int validarString(char buffer[],int min,int max)
{
    int aux=0;
    int j;
    j=strlen(buffer);

    if(j >= min && j <= max)
    {
        aux=1;
    }

    return aux;

}
/**
* \brief Funcion para verificar el tamaño del ingreso del usuario.
* \param Entrada el usuario
* \param Tamaño minimo.
* \param Tamaño maximo.
* \return Devuelve 1 si el String es correcto o devuelve 0 si es incorrecto.
*
*/

int validarChar(char buffer[])
{
    int aux=0;
    int j;
    j=strlen(buffer);

    if(j==1)
    {
        aux=1;
    }

    return aux;


}
/**
* \brief Funcion para verificar si el usuario ingreso un char
* \param Recibe la entrada por teclado del usuario
* \return Devuelve 1 si es un char y devuelve 0 si no lo es.
*
*/

int validarInt(char buffer[],int min,int max)
{
    int aux=1; // RETURN
    int j; // AUXILIAR
    int i=0; // AUXILIARCONTADOR
    int numero;

    j=strlen(buffer); // CARGA EN AUX LA CANTIDAD DE ELEMENTOS DEL ARRAY

	while( i<j && aux == 1)
    {
	  if(isdigit(buffer[i])!=0) // isdigit devuelve 1 si es numero o 0 sino lo es.
      {
	      i++;
      }
	  else
      {
	      aux=0;
      }
	}
	if(aux==1)
	{
        numero=cadena_entero(buffer);

        if(numero < min || numero > max)
        {
            aux=0;
        }

	}

    return aux;
}

/**
* \brief Valida si el usuario ingreso un entero positivo
* \param Recibe como parametro una cadena de caracteres
* \return Devuelve 0 si la cadena posee letras o signos y no esta en el rango correcto. Devuelve 1 si la cadena posee numeros y esta dentro del rango.
*
*/



int cadena_entero(char numero[])
{
    int num=0; //RETURN
    int aux=strlen(numero); // CARGA EN AUX LA CANTIDAD DE ELEMENTOS DEL ARRAY
    int i; // AUX CONTADOR
    int digito; // AUXILIAR PARA OBTENER LOS DIGITOS

    for(i=aux;i>0;i--)
    {
        digito=numero[i-1]-48; // TRANSFORMA EL ELEMENTO A UN DIGITO ENTERO
        num=num+(digito*pow(10,aux-i)); // ARMA EL NUMERO FINAL digito*10^n

    }

    return num;
}

/**
* \brief Trasnforma una cadena de numeros a un entero(int).
* \param Recibe la cadena de numeros.
* \return Devuelve la cadena transformado a un entero.
*
*/

int menu(char texto[],int rangoOpcionMin,int rangoOpcionMax)
{
  int opcion=0;
  char buffer[4000];

  printf("%s",texto);
  printf("Opcion: ");
  gets(buffer);

  if(validarInt(buffer,rangoOpcionMin,rangoOpcionMax)==1)
  {
    opcion=cadena_entero(buffer);

  }
  else
  {
    opcion=-1;

    printf("Opcion incorrecta.\n");
  }



  return opcion;


}

/**
* \brief Funcion para crear un menu de opciones
* \param Recibe una cadena de caracteres para mostrar los indices del menu
* \param Recibe un int para definir la primer opcion
* \param Recibe un int para definir la ultima opcion
* \return Devuelve la opcion elegida por el usuario o devuelve -1 si la opcion es incorrecta.
*/


void flush_in()
{
  int ch;

  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

/**
* \brief Funcion para limpiar el buffer en cualquier SO.
*/

 Desktop version
