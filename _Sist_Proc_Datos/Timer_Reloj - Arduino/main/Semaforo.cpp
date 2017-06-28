#include <Arduino.h>
//#include <LiquidCrystal.h>
//#include "reloj.h"
#include "timer.h"

#define TIMER 0
#define MILLIS 200

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
#define BOTON1 0   // Semaforo Secundario
#define BOTON2 13  // Semaforo Principal
/// Sensor de vehiculo en calle secundaria:
#define SENSOR 1

/// Cantidad total de semaforos:
#define SEMAFOROSQTY 2
/// Cantidad total de luces led:
#define LEDSQTY 5
/// Cantidad total de estados de los semaforos:
#define STATUSQTY 5
/// Cantidad de secuencias dentro de un Ciclo:
#define CICLESECUENCEQTY 24


/// Prototipos de funciones a utilizar:
void cargarEstados(int sNumber);
void cargarArray(int sNumber, int stateNumber, int rojo, int amarillo, int verde, int rojoPeat, int verdePeat);
void cargarCicloEstados();
void cargarSecNumber (int secNumber, int semaforo1StateNumber, int semaforo2StateNumber);
void setStatus(int secNumber);


/// Se define arrayEstructura de uso global con los estados de los leds de los semaforos
static S_Semaforo semaforo[SEMAFOROSQTY];
static int secuencia[CICLESECUENCEQTY][SEMAFOROSQTY];


int iniciarSecuencia = 0;
int secuenceNumber = 1;


void semaforo_setup()
{
    int i,j,k;
    /// Creo un array provisorio con los numeros de pines de los leds
    int pinesLeds[LEDSQTY*SEMAFOROSQTY] = {R1,A1,V1,RP1,VP1,R2,A2,V2,RP2,VP2};

    /// Se inicializan los PINES correspondientes a todos los leds definidos en el array de pinesLeds como salida digital:
    for (j=0,k=0; j < SEMAFOROSQTY; j++)
        for (i=0; i < LEDSQTY ; i++,k++)
            (semaforo+j)->ledPin[i] = pinesLeds[k]; /// Cargo los valores de los pines en el arrayEstrucutra de cada semaforo

    cargarEstados(0); /// Cargo los diferentes posibles estados del semaforo 1
    cargarEstados(1); /// Cargo los diferentes posibles estados del semaforo 2
    cargarCicloEstados(); /// Cargo los datos del ciclo de estados de los semaforos

    /// Se inicializan los PINES correspondientes a los botones y sensor como entrada digital:
    pinMode(BOTON1, INPUT);
    pinMode(BOTON2, INPUT);
    pinMode(SENSOR, INPUT);

    setStatus(0); /// Establezco el estado de los leds de los semaforos a su estado por defecto

}

void semaforo_loop()
{
    if ( iniciarSecuencia == TRUE )
    {
        if ( secuenceNumber == CICLESECUENCEQTY )  /// si ya se cumpli� un ciclo entero reinicio el contador de secuencia y el estado a iniciarSecuencia=FALSE
        {
            secuenceNumber = 0;
            iniciarSecuencia = FALSE;
        }
        else if ( timer_waitMs(TIMER, MILLIS) ) /// Si el reloj lleg� a cero entra, incrementa el contador de secuencia y reinicia el reloj
        {
            secuenceNumber++;
            timer_waitMs(TIMER, MILLIS);
        }
        setStatus(secuenceNumber);
    }
    else if ( digitalRead(BOTON2) == 0 || digitalRead(SENSOR) == 0  )
    {
        timer_waitMs(TIMER, MILLIS); /// Inicio el Timer
        iniciarSecuencia = TRUE; /// Inicio la secuencia
        secuenceNumber++; /// Incremento el nro de la secuencia de estados del Semaforo
    }
}



void cargarEstados(int sNumber) /// sNumber es el numero del semaforo
{
///   sNumber, stateNumber, R, A, V, RP, VP
    cargarArray(sNumber, 0, 0, 0, 1,  1,  0);  /// ledState[0]
    cargarArray(sNumber, 1, 0, 0, 0,  1,  0);  /// ledState[1]
    cargarArray(sNumber, 2, 0, 1, 0,  1,  0);  /// ledState[2]
    cargarArray(sNumber, 3, 1, 0, 0,  0,  1);  /// ledState[3]
    cargarArray(sNumber, 4, 1, 0, 0,  0,  0);  /// ledState[4]
}

void cargarArray(int sNumber, int stateNumber, int rojo, int amarillo, int verde, int rojoPeat, int verdePeat)
{
    (semaforo+sNumber)->ledStateArray[stateNumber][0] = rojo;
    (semaforo+sNumber)->ledStateArray[stateNumber][1] = amarillo;
    (semaforo+sNumber)->ledStateArray[stateNumber][2] = verde;
    (semaforo+sNumber)->ledStateArray[stateNumber][3] = rojoPeat;
    (semaforo+sNumber)->ledStateArray[stateNumber][4] = verdePeat;
}

void cargarCicloEstados()
{
    cargarSecNumber ( 0, 0, 3);
    cargarSecNumber ( 1, 0, 3);
    cargarSecNumber ( 2, 0, 3);
    cargarSecNumber ( 3, 0, 3);
    cargarSecNumber ( 4, 0, 3);
    cargarSecNumber ( 5, 1, 3);
    cargarSecNumber ( 6, 0, 3);
    cargarSecNumber ( 7, 1, 4);
    cargarSecNumber ( 8, 0, 3);
    cargarSecNumber ( 9, 2, 4);
    cargarSecNumber (10, 2, 3);
    cargarSecNumber (11, 2, 4);
    cargarSecNumber (12, 3, 0);
    cargarSecNumber (13, 3, 0);
    cargarSecNumber (14, 3, 0);
    cargarSecNumber (15, 3, 0);
    cargarSecNumber (16, 3, 0);
    cargarSecNumber (17, 3, 1);
    cargarSecNumber (18, 3, 0);
    cargarSecNumber (19, 4, 1);
    cargarSecNumber (20, 3, 0);
    cargarSecNumber (21, 4, 2);
    cargarSecNumber (22, 3, 2);
    cargarSecNumber (23, 4, 2);
}

void cargarSecNumber (int secNumber, int semaforo1StateNumber, int semaforo2StateNumber)
{
    secuencia[secNumber][0] = semaforo1StateNumber;
    secuencia[secNumber][1] = semaforo2StateNumber;
}



void setStatus(int secNumber)
{
    int i, j;
    for (j = 0; j < SEMAFOROSQTY ; j++)
        for (i = 0; i < LEDSQTY ; i++);
            digitalWrite( (semaforo+j)->ledPin[i], (semaforo+j)->ledStateArray[ secuencia[secNumber][j] ][i] ) ;
}


