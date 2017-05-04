#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcValidacion.h"
#include "funcMatematicas.h"
#include "funcOrdenar.h"
#include "funcEstructuras.h"

#define BUFFER 4084
#define EL_DATO_ES_VALIDO 1
#define EL_DATO_NO_ES_VALIDO 0


/**
 * \brief Solicitar al usuario un numero y validarlo dentro de un rango de enteros.
 * \param numero: donde se va a guardar el numero ya validado.
 * \param mensajeIngreso: mensaje a mostrar para pedir el dato.
 * \param mensajeError: mensaje a mostrar si el dato no esta dentro del rango valido.
 * \param bucle: si el parametro es 1 el codigo se va a repetir hasta que se ingrese un tipo de dato valido.
 * \param conLimInf: si se recibe 1 como parametro valida el limite inferior, sino no.
 * \param minimo: valor minimo que el usuario puede ingresar como dato valido.
 * \param conLimSup: si se recibe 1 como parametro valida el limite superior, sino no.
 * \param maximo: valor maximo que el usuario puede ingresar como dato valido.
 * \return Si obtuvo un numero valido devuelve [1] sino devuelve [0].
 */
int getInt(int* numero, char mensajeIngreso[], char mensajeError[], int bucle, int conLimInf, int minimo, int conLimSup, int maximo);



/**
 * \brief Solicitar al usuario un numero y validarlo dentro de un rango de numeros decimales.
 * \param numero: donde se va a guardar el numero ya validado.
 * \param mensajeIngreso: mensaje a mostrar para pedir el dato.
 * \param mensajeError: mensaje a mostrar si el dato no esta dentro del rango valido.
 * \param bucle: si el parametro es 1 el codigo se va a repetir hasta que se ingrese un tipo de dato valido.
 * \param conLimInf: si se recibe 1 como parametro valida el limite inferior, sino no.
 * \param minimo: valor minimo que el usuario puede ingresar como dato valido.
 * \param conLimSup: si se recibe 1 como parametro valida el limite superior, sino no.
 * \param maximo: valor maximo que el usuario puede ingresar como dato valido.
 * \return Si obtuvo un numero valido devuelve [1] sino devuelve [0].
 */
int getFloat(float* numero, char mensajeIngreso[], char mensajeError[], int bucle, int conLimInf, float minimo, int conLimSup, float maximo);



/**
 * \brief Solicitar al usuario un numero y validarlo dentro de un rango de enteros largos.
 * \param numero: donde se va a guardar el numero ya validado.
 * \param mensajeIngreso: mensaje a mostrar para pedir el dato.
 * \param mensajeError: mensaje a mostrar si el dato no esta dentro del rango valido.
 * \param bucle: si el parametro es 1 el codigo se va a repetir hasta que se ingrese un tipo de dato valido.
 * \param conLimInf: si se recibe 1 como parametro valida el limite inferior, sino no.
 * \param minimo: valor minimo que el usuario puede ingresar como dato valido.
 * \param conLimSup: si se recibe 1 como parametro valida el limite superior, sino no.
 * \param maximo: valor maximo que el usuario puede ingresar como dato valido.
 * \return Si obtuvo un numero valido devuelve [1] sino devuelve [0].
 */
int getLongInt(long int* numero, char mensajeIngreso[], char mensajeError[], int bucle, int conLimInf, long int minimo, int conLimSup, long int maximo);



/**
 * \brief Solicitar al usuario una cadena de caracteres.
 * \param mensajeIngreso: es el mensaje a mostrar para pedir el ingreso.
 * \param mensajeError: mensaje a mostrar si el dato no esta dentro del rango valido.
 * \param bucle: el codigo se va a repetir hasta que se ingrese un tipo de dato valido.
 * \param type: tipo de ingreso que se quiere obtener como valido (1- cadena solo letras / 2-cadena alfanumerica / 3-cadena fecha / 4-cadena telefono / 5-cadena email)
 * \param arrayCharsAdmitidos es el array que contiene los caracteres que tambien van a resultar validos.
 * \param maxExtensionArray: indica la extension maxima (en cantidad de caracteres) para el array.
 * \param input: es el array donde se va a guardar la cadena.
 * \return Si obtuvo un ingreso valido devuelve [1] sino devuelve [0].
 */
int getType(char mensajeIngreso[], char mensajeError[], int bucle, int type, char arrayCharsAdmitidos[], int maxExtensionArray, char* input);



/**
 * \brief Solicitar al usuario una cadena de caracteres.
 * \param mensajeIngreso: es el mensaje a mostrar para pedir el ingreso.
 * \param input es el array donde se va a guardar la cadena.
 * \return Si obtuvo un ingreso no nulo devuelve [1] sino devuelve [0].
 */
int getString(char mensajeIngreso[], char* input);



/**
 * \brief Verifica que una array est� compuesto solo por numeros.
 * \param vector: es el array a evaluar
 * \param cantPuntos: Valida que la cadena pueda incluir hasta la cantidad de puntos ('.') que recibe como parametro.
 * \param admiteNegativos: recibe 1 como parametro, acepta como valido una cadena que empieza con el signo '-', sino no.
 * \return Si el array esta compuesto solo por numeros devuelve [1] sino devuelve [0].
 */
int esCadenaSoloNumeros (char vector[], int cantPuntos, int admiteNegativos);



/**
 * \brief Verifica que una array est� compuesto solo por numeros, guiones y/o parentesis.
 * \param vector: es el array a evaluar
 * \return Si el array esta compuesto solo por numeros devuelve [1] sino devuelve [0].
 */
int esCadenaTelefono (char vector[]);



/**
 * \brief Verifica que una array est� compuesto solo por letras, numeros, y como minimo un '@' y un '.'.
 * \param vector: es el array a evaluar
 * \param arrayCharsAdmitidos es el array que contiene los caracteres que tambien van a resultar validos.
 * \return Si el array esta compuesto por una cadena email devuelve [1] sino devuelve [0].
 */
int esCadenaEmail(char vector[], char arrayCharsAdmitidos[]);



/**
 * \brief Verifica que una array est� compuesto solo por letras (mayusculas y/o minusculas) y/o una serie de caracteres definidos.
 * \param vector es el array a evaluar
 * \param arrayCharsAdmitidos es el array que contiene los caracteres que tambien van a resultar validos.
 * \return Si el array esta compuesto solo por letras y/o los caracteres especificados devuelve [1] sino devuelve [0].
 */
int esCadenaSoloLetras (char vector[], char arrayCharsAdmitidos[]);



/**
 * \brief Verifica que una array est� compuesto solo por numeros y/o espacios y/o letras (mayusculas y/o minusculas).
 * \param vector es el array a evaluar
 * \param arrayCharsAdmitidos es el array que contiene los caracteres que tambien van a resultar validos.
 * \return Si el array esta compuesto solo por numeros y/o letras y/o los caracteres especificados devuelve [1] sino devuelve [0].
 */
int esCadenaAlfanumerica (char vector[], char arrayCharsAdmitidos[]);



/**
 * \brief Verifica que una array tenga la estructura de una fecha.
 * \param vector: es el array a evaluar
 * \return Si el array es una fecha valida devuelve [1] sino devuelve [0].
 */
int esCadenaFecha (char vector[]);



/**
 * \brief Funcion complementaria a esCadenaFecha. Valida que el rango de un array a evaluar corresponda a un componente de fecha valido.
 * \param vector: es el array a evaluar
 * \param posicionInicio: es la posicion del array desde la que se va a evaluar el valor.
 * \param posicionFin: es la posicion del array hasta la que se va a evaluar el valor.
 * \param numFecha: es el array donde se va a guardar el numero componente de la fecha.
 * \return Si el rango del array corresponde a un componente fecha valida devuelve [1] sino devuelve [0].
 */
int esNumeroFecha(char vector[], int posicionInicio, int posicionFin, char* numFecha);

