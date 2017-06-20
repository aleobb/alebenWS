#include <Arduino.h>
//#include <LiquidCrystal.h>
#include "reloj.h"
#include "timer.h"


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
#define BOTON 0
/// Sensor de vehiculo en calle secundaria:
#define SENSOR 1

/// Cantidad total de luces led:
#define LEDSQTY 10
/// Cantidad total de estados de los semaforos:
#define STATUSQTY 10

/// Prototipos de funciones a utilizar:


/// Se define arrayEstructura de uso global con los estados de los leds de los semaforos
static S_SemaforoState semaforos[STATUSQTY];
static int pinesLeds[LEDSQTY] = {R1,A1,V1,RP1,VP1,R2,A2,V2,RP2,VP2};
//static S_Leds leds;

void semaforo_setup()
{
    /// Se inicializan los PINES correspondientes a boton y sensor como entrada digital:
    pinMode(BOTON, INPUT);
    pinMode(SENSOR, INPUT);

    /// Se inicializan los PINES correspondientes a todos los leds definidos en el array de pinesLeds como salida digital:
    for (int i = 0; i < LEDSQTY; i++)
        pinMode(pinesLeds[i], OUTPUT);

}

void semaforo_loop()
{


    if ( digitalRead(BOTON) == 0)
    {

    }
}


void cargarEstados()
{
/// stateNumber,time,R1,A1,V1,RP1,VP1,R2,A2,V2,RP2,VP2
    cargarArray(0, 5, 0, 0, 1,  1,  0, 1, 0, 0,  0,  1);
    cargarArray(1, 1, 0, 0, 0,  1,  0, 1, 0, 0,  0,  1);
    cargarArray(2, 1, 0, 0, 0,  1,  0, 1, 0, 0,  0,  0);
    cargarArray(3, 1, 0, 1, 0,  1,  0, 1, 0, 0,  0,  0);
    cargarArray(4, 1, 0, 1, 0,  1,  0, 1, 0, 0,  0,  1);
    cargarArray(5, 5, 1, 0, 0,  0,  1, 0, 0, 1,  1,  0);
    cargarArray(6, 1, 1, 0, 0,  0,  1, 0, 0, 0,  1,  0);
    cargarArray(7, 1, 1, 0, 0,  0,  0, 0, 0, 0,  1,  0);
    cargarArray(8, 1, 1, 0, 0,  0,  0, 0, 1, 0,  1,  0);
    cargarArray(9, 1, 1, 0, 0,  0,  1, 0, 1, 0,  1,  0);
}

void cargarArray(int stateNumber, int time, int r1, int a1, int v1, int rP1, int vP1, int r2, int a2, int v2, int rP2, int vP2 )
{
    (semaforos+stateNumber)->time = time;

    (semaforos+stateNumber)->ledState[0] = r1;
    (semaforos+stateNumber)->ledState[1] = a1;
    (semaforos+stateNumber)->ledState[2] = v1;
    (semaforos+stateNumber)->ledState[3] = rP1;
    (semaforos+stateNumber)->ledState[4] = vP1;

    (semaforos+stateNumber)->ledState[5] = r2;
    (semaforos+stateNumber)->ledState[6] = a2;
    (semaforos+stateNumber)->ledState[7] = v2;
    (semaforos+stateNumber)->ledState[8] = rP2;
    (semaforos+stateNumber)->ledState[9] = vP2;
}


// int setStatus(int nextStatus,int newNextStatus)
void setStatus(int activeState,int nextState)
{
    secuenciaStatusSemaforo[]={0,1,0,2,0,3,4,3}///,5,6,5,7,5,8,9,8} /// Numero de secuencia del estado del semaforo

    for (int i = 0; i < LEDSQTY; i++)
        if ( (semaforos+activeState)->ledState[i] == (semaforos+nextState)->ledState[i] )
            digitalWrite( semaforos->ledPin[i], (semaforos+nextState)->ledState[i] );
    /*if ( nextStatus == STATUSQTY )
        nextStatus = 0;
    else
        nenextStatus++;
    return nextStatus*/

}



