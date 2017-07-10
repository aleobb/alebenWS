#include <Arduino.h>
//#include <LiquidCrystal.h>
//#include "reloj.h"
#include "timer.h"

#define TIMER_SECUENCIA 0
#define MILLIS_SECUENCIA 200
#define TIMER_BOTON2 1
#define MILLIS_BOTON2 200
#define FALSE 0
#define TRUE 1


/// Aclaraciones respecto de los define de las luces leds:
/// Las letras R, A, V representan los Leds Rojo, Amarillo y Verde respectivamente.
/// El agregado P indican que esos leds corresponden al semaforo peatonal
/// El agregado del numero indican que corresponden a los leds del semaforo principal(1) o secundario(2) (tanto vehicular como peatonal)

/// Luces Semaforo Principal:
#define R1 10
#define A1 11
#define V1 12
/// Luces Semaforo Peatonal Principal:
#define RP1 8
#define VP1 9

/// Luces Semaforo Secundario:
#define R2 4
#define A2 5
#define V2 6
/// Luces Semaforo Peatonal Secundario:
#define RP2 2
#define VP2 3

/// Boton de demanda de cruce peatonal:
#define BOTON1 7   /// Semaforo Principal
#define BOTON2 1   /// Semaforo Secundario
/// Sensor de vehiculo en calle secundaria:
#define SENSOR 0

#define SEMAFOROSQTY 2  /// Cantidad total de semaforos
#define LEDSQTY 5       /// Cantidad total de luces led por semaforo
#define STATUSQTY 5     /// Cantidad total de diferentes estados para cada semaforo
#define SECUENCEQTY 8   /// Cantidad total de secuencias por ciclo de estados
#define SECUENCEPARTS 2 /// Cantidad de partes de la secuencia


/// Se define arrayEstructura de uso global con los estados de los leds de los semaforos
int pinLedSemaforo[SEMAFOROSQTY][LEDSQTY] = { {R1,A1,V1,RP1,VP1} , {R2,A2,V2,RP2,VP2} };
S_Secuencia secuence[SECUENCEQTY];

int completandoCiclo = FALSE;
int secNumber = -1; /// El ciclo del semaforo comenzara en el estado 0 de la secuencia que es el estado por defecto, es por ello que necesita arrancar con valor -1 ya que ni bien se inicia pasa al siguiente estado


void semaforo_setup()
{
    int i, j;
    /// Se inicializan los PINES correspondientes a todos los leds como salida digital:
    for (j = 0; j < SEMAFOROSQTY ; j++)
        for (i = 0; i < LEDSQTY ; i++)
            pinMode(pinLedSemaforo[j][i], OUTPUT);

    initSemaforo(); /// Cargo los datos del ciclo de estados de los semaforos y los seteo a su estado por defecto

    /// Se inicializan los PINES correspondientes a los botones y sensor como entrada digital:
    pinMode(BOTON1, INPUT);
    pinMode(BOTON2, INPUT);
    pinMode(SENSOR, INPUT);
}

void semaforo_loop()
{
    if ( completandoCiclo == TRUE ) /// Si se esta completando el Ciclo de Cambio del semaforo tiene que entrar if ( y asi evitar que siga evaluando si se apreto el boton en el siguiente else if)
        if ( timer_waitMs(TIMER_SECUENCIA, MILLIS_SECUENCIA) ) /// y si el timer de la secuencia llegó a cero entra a este if y pasa al siguiente estado
            nextState();
    else if ( digitalRead(BOTON2) == 0 && timer_avoidRebound(TIMER_BOTON2) )/// || digitalRead(SENSOR) == 0  ) /// Si no se esta completando el ciclo evalua si se se pulso el boton del semaforo 2 o un vehiculo se acerco al cruce
    {                                                                                                          /// Con avoidRebound se evita el error de que se hagan muchas lecturas del boton al pulsarlo
        nextState();
        timer_waitMs(TIMER_BOTON2, MILLIS_BOTON2);/// cargo el reloj del Boton2
    }
}


void initSemaforo()
{
    int states[STATUSQTY][LEDSQTY] = { {0,0,1,1,0} , {0,0,0,1,0} , {0,1,0,1,0} , {1,0,0,0,1} , {1,0,0,0,0} };
    int stateTime[SECUENCEQTY] = {5,1,1,1,1,1,1,1};
    int stateIndex[SEMAFOROSQTY][SECUENCEQTY] = { {0,1,0,1,0,2,2,2} , {3,3,3,4,3,4,3,4} }; /// {1er secuencia de estados para el semaforo 1 (2da para el 2)} {2da secuencia de estados para el semaforo 1 (1era para el 2)}

    int i, j, k;
    for (k = 0; k < SECUENCEQTY ; k++)
    {
        (secuence+k)->time = stateTime[k];
        for (j = 0; j < SEMAFOROSQTY ; j++)
            for (i = 0; i < LEDSQTY ; i++)
                (secuence+k)->state[j][i] = states[ stateIndex[j][k] ][i];
    }
    nextState(); /// Establezco el estado de los leds de los semaforos a su estado por defecto
}


void nextState()
{
    int i, j, k;
    secNumberIncrease();
    for (j=0, k=SEMAFOROSQTY-1; j < SEMAFOROSQTY ; j++,k--)
    {
        for (i = 0; i < LEDSQTY ; i++)
        {
            if ( secNumber < SECUENCEQTY )
                digitalWrite( pinLedSemaforo[j][i] , (secuence+secNumber)->state[j][i] );
            else
                digitalWrite( pinLedSemaforo[j][i] , (secuence+secNumber-SECUENCEQTY)->state[k][i] );
        }/// ¿¿ digitalWrite( (semaforo+j)->ledPin[i], (semaforo+j)->*(ledState+stateSecuence)->Number[j][i])[i] ); ????
    }
    timer_waitMs(TIMER_SECUENCIA, MILLIS_SECUENCIA); /// Cargado el nuevo estado de los leds reinicio el timer de la secuencia
    if ( secNumber == 0 ) /// Si el semaforo pasa a su estado por defecto (nro secuencia 0) paro el timer de la secuencia
        timer_resetWait(TIMER_SECUENCIA);
}


void secNumberIncrease()
{
    if ( secNumber == 0 ) /// Si se llamó a esta funcion es para incrementar el nro de la secuencia, si se estaba en el cero se acaba de iniciar el ciclo, en consecuencia levanto el flag completandoCiclo a TRUE
        completandoCiclo = TRUE;
    secNumber++;
    if ( secNumber == SECUENCEQTY*SECUENCEPARTS ) /// Si ya se cumplió un ciclo entero reinicio el contador de secuencia y el estado de completandoCiclo a FALSE
    {
          secNumber = 0;
          completandoCiclo = FALSE;
    }
}
