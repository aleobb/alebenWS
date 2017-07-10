/******************************************************************
* Programa: TP Semaforos
*
* Objetivo:
*   Mostrar los aspectos básicos de funcionamiento de un cruce con
*   Semaforos para autos y peatones
*
*
* Versión: 1.0 del 26 de Junio de 2017
* Autor: Alejandro Ben
*
* *******************************************************************/
#include "Semaforo.h"
#include "timer.h"
#include "lcd.h"


/** \brief  Se invoca una sola vez cuando el programa empieza.
 *          Se utiliza para inicializar los modos de trabajo
 *          de los pines, el puerto serie, etc...
 * \param void
 * \return void
 */
void setup(void)
{
    timer_setup(); // inicializo el reloj
    semaforo_setup();
    lcd_setup();
}


/** \brief  Contiene el programa que se ejecutará cíclicamente
 * \param void
 * \return void
 */
void loop(void)
{
    timer_loop();
    semaforo_loop();
    lcd_loop();
}
