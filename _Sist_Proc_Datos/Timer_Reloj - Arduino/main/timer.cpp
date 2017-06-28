#include <Arduino.h>
#include "timer.h"
#define TIMERS_QTY 1


static S_timerData timersArray[TIMERS_QTY];
static unsigned long anterior = 0;
static unsigned long actual;


/** \brief  Inicializa el array de timers
 * \param void
 * \return void
 */
void timer_setup()
{
    int i;
    for(i=0; i<TIMERS_QTY; i++) // inicializo array de timers
        timersArray[i].running = 0;
}


/** \brief  Si el timer no esta corriendo setea el contador del timer caso contrario evalua si finalizo
 * \param void
 * \return Retorna 1 si finalizo la cuenta
 */
int timer_loop()
{
    actual = millis();
    if( anterior != actual )
    {
        anterior = actual;
        timer_tick();
    }
}


/** \brief  Decrementa los contadores de los timers
 * \param void
 * \return void
 */
void timer_tick()
{
    int i;
    for( i=0 ; i<TIMERS_QTY ; i++ )
        if(timersArray[i].running && timersArray[i].delayValue > 0)
            timersArray[i].delayValue--;
}



/** \brief  Si el timer no esta corriendo setea el contador del timer caso contrario evalua si finalizo
 * \param void
 * \return Retorna 1 si finalizo la cuenta
 */
int timer_waitMs(int delayNumber,int delayMs) /// delayNumber es la posicion (Timer Nro.) del array de relojes
{
    int retorno = 0;
    if ( timersArray[delayNumber].running == 0 ) /// Aca entra si el reloj no está corriendo
    {
        timersArray[delayNumber].delayValue = delayMs; /// Recargo el contador
        timersArray[delayNumber].running = 1; /// Lo vuelvo a declarar como corriendo
    }
    else if ( timersArray[delayNumber].delayValue == 0 ) /// Aca entra cuando el contador tiempo del reloj llegó a cero
    {
        timersArray[delayNumber].running = 0; /// Al llegar a cero el reloj deja de correr y se informa esto por retorno
        retorno = 1;
    }
    return retorno;
}


/** \brief  Baja el flag running
 * \param void
 * \return void
 */
void timer_resetWait(int delayNumber)
{
    timersArray[delayNumber].running = 0;
}




