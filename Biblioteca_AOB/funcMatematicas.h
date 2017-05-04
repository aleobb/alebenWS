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
 * \brief calcula la division entre dos numeros (A dividido por B)
 * \param A y B son las variables con cuyos valores se va a calcular la division.
 * \return devuelve el resultado de la division (que va a ser un nro. flotante).
 */
float division(float A, float B);



/**
 * \brief calcula la cantidad de numeros positivos/negativos en un vector de enteros
 * \param array es el vector que contiene los valores a analizar.
 * \param posInicio es la posicion del vector desde la que se va a analizar.
 * \param posFin es la posicion del vector hasta la que se va a analizar (inclusive).
 * \param posNeg parametro que indica si se van a calcular la cantidad de positivos (1) o de negativos (-1).
 * \return devuelve la cantidad de valores positivos o negativos encontrados.
 */
int cantPosNegInt (int array[], int posInicio, int posFin, int posNeg);



/**
 * \brief calcula la cantidad de numeros positivos/negativos en un vector de flotantes.
 * \param array es el vector que contiene los valores a analizar.
 * \param posInicio es la posicion del vector desde la que se va a analizar.
 * \param posFin es la posicion del vector hasta la que se va a analizar (inclusive).
 * \param posNeg parametro que indica si se van a calcular la cantidad de positivos (1) o de negativos (-1).
 * \return devuelve la cantidad de valores positivos o negativos encontrados.
 */
int cantPosNegFloat (float array[], int posInicio, int posFin, int posNeg);



/**
 * \brief halla el valor maximo o minimo de un vector de enteros
 * \param array es el vector que contiene los valores a analizar.
 * \param posInicio es la posicion del vector desde la que se va a analizar.
 * \param posFin es la posicion del vector hasta la que se va a analizar (inclusive).
 * \param maxMin parametro que indica si se van a hallar el maximo (1) o el minimo (-1).
 * \return devuelve la posicion en el array del valor maximo o minimo encontrado y si no la econtró devuelve -1.
 */
int maxMinArrayInt (int array[], int posInicio, int posFin, int maxMin);



/**
 * \brief halla el valor maximo o minimo de un vector de flotantes
 * \param array es el vector que contiene los valores a analizar.
 * \param posInicio es la posicion del vector desde la que se va a analizar.
 * \param posFin es la posicion del vector hasta la que se va a analizar (inclusive).
 * \param maxMin parametro que indica si se van a hallar el maximo (1) o el minimo (-1).
 * \return devuelve la posicion en el array del valor maximo o minimo encontrado y si no la econtró devuelve -1.
 */
int maxMinArrayFloat (float array[], int posInicio, int posFin, int maxMin);



/**
 * \brief halla el promedio de un vector de enteros.
 * \param array es el vector que contiene los valores a analizar.
 * \param posInicio es la posicion del vector desde la que se va a analizar.
 * \param posFin es la posicion del vector hasta la que se va a analizar (inclusive).
 * \return devuelve el promedio calculado (siempre la cantidad posiciones a analizar sea mayor a cero, sino devuelve 0).
 */
float promedioArrayInt (int array[], int posInicio, int posFin);



/**
 * \brief halla el promedio de un vector de flotantes.
 * \param array es el vector que contiene los valores a analizar.
 * \param posInicio es la posicion del vector desde la que se va a analizar.
 * \param posFin es la posicion del vector hasta la que se va a analizar (inclusive).
 * \return devuelve el promedio calculado (siempre la cantidad posiciones a analizar sea mayor a cero, sino devuelve 0).
 */
float promedioArrayFloat (float array[], int posInicio, int posFin);



 /**
 * \brief calcula el factorial del numero A (entero positivo menor o igual a 100)
 * \param A es la variable donde se almacena el valor utilizado para realizar el calculo factorial
 * \return devuelve el resultado del factorial de A
 */
double factorial(int A);



/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar);

