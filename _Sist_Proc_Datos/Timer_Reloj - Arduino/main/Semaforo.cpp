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
/// Cantidad total de secuencias por ciclo:
#define SECUENCEQTY 8


/// Prototipos de funciones a utilizar:
void cargarEstados(int sNumber);
void cargarArray(int sNumber, int stateNumber, int rojo, int amarillo, int verde, int rojoPeat, int verdePeat);
void cargarCicloEstados();
void cargarSecNumber (int secNumber, int semaforo1StateNumber, int semaforo2StateNumber);
void setStatus(int secNumber);


/// Se define arrayEstructura de uso global con los estados de los leds de los semaforos
static S_Semaforo semaforo[SEMAFOROSQTY];
static int secuencia[CICLESECUENCEQTY][SEMAFOROSQTY];
static S_StateSecuence stateSecuence;


int iniciarSecuencia = FALSE;
int secuenceNumber = TRUE;


void semaforo_setup()
{
    int i,j,k;
    /// Creo un array provisorio con los numeros de pines de los leds
    int pinesLeds[LEDSQTY*SEMAFOROSQTY] = {R1,A1,V1,RP1,VP1,R2,A2,V2,RP2,VP2};
    int pinLedSemaforo[SEMAFOROSQTY][LEDSQTY] = { {R1,A1,V1,RP1,VP1} , {R2,A2,V2,RP2,VP2} };

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
        if ( secuenceNumber == SECUENCEQTY*SECUENCEPARTS )
        //if ( secuenceNumber == CICLESECUENCEQTY )  /// si ya se cumplió un ciclo entero reinicio el contador de secuencia y el estado a iniciarSecuencia=FALSE
        {
            secuenceNumber = 0;
            iniciarSecuencia = FALSE;
        }
        else if ( timer_waitMs(TIMER, MILLIS) ) /// Si el reloj llegó a cero entra, incrementa el contador de secuencia y reinicia el reloj
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


     setearEstados
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
    int stateTime[SECUENCEQTY] =                   {5,1,1,1,1,1,1,1};
    int stateNumber[SEMAFOROSQTY][SECUENCEQTY] = { {0,1,0,1,0,2,2,2} , {3,3,3,4,3,4,3,4} }; /// {1er secuencia de estados para el semaforo 1 (2da para el 2)} {2da secuencia de estados para el semaforo 1 (1era para el 2)}

/// Podría no cargar nada de los siguiente y manejarme directamente con los arrays declarados globalmente:
    int i, j;
    for (i = 0; i < SECUENCEQTY ; i++)
        stateSecuence.time[i] = stateTime[i];
    for (j = 0; j < SEMAFOROSQTY ; j++)
        for (i = 0; i < SECUENCEQTY ; i++)
            stateSecuence.number[j][i] = stateNumber[j][i];

}

void secuencias()
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
}




   /*       cargarLedStateSecuence(i, secTime[i], secNumber[j][i])

    int i=-1;
    cargarSecNumber (i++, 5, 0, 3);
    cargarSecNumber (i++, 1, 1, 3);
    cargarSecNumber (i++, 1, 0, 3);
    cargarSecNumber (i++, 1, 1, 4);
    cargarSecNumber (i++, 1, 0, 3);
    cargarSecNumber (i++, 1, 2, 4);
    cargarSecNumber (i++, 1, 2, 3);
    cargarSecNumber (i++, 1, 2, 4);
    cargarSecNumber (i++, 5, 3, 0);
    cargarSecNumber (i++, 1, 3, 1);
    cargarSecNumber (i++, 1, 3, 0);
    cargarSecNumber (i++, 1, 4, 1);
    cargarSecNumber (i++, 1, 3, 0);
    cargarSecNumber (i++, 1, 4, 2);
    cargarSecNumber (i++, 1, 3, 2);
    cargarSecNumber (i++, 1, 4, 2);*/


/* void setSecuence (int secNumber, int secTime, int semaforo1StateNumber, int semaforo2StateNumber)
{
    int i;
    int semStates[SEMAFOROSQTY] = {semaforo1StateNumber, semaforo2StateNumber};

    (secuencia+secNumber)->time = secTime;
    for (i=0; i < SEMAFOROSQTY ; i++)
        (secuencia+secNumber)->semaforoState[i] = semStates[i];


    secuencia[secNumber][0] = semaforo1StateNumber;
    secuencia[secNumber][1] = semaforo2StateNumber;
}*/



void setStatus(int secNumber) /// Debería controlar que no pase de
{
    int i, j, k;
    for (j=0, k=SEMAFOROSQTY-1; j < SEMAFOROSQTY ; j++,k--)
    {
        for (i = 0; i < LEDSQTY ; i++)
        {
            if ( secNumber < SECUENCEQTY )
                digitalWrite( pinLedSemaforo[j][i] , (secuence+secNumber)->state[j][i] );
            else
                digitalWrite( pinLedSemaforo[j][i] , (secuence+secNumber-SECUENCEQTY)->state[k][i] );
        }
    }
        /// ¿¿¿ digitalWrite( (semaforo+j)->ledPin[i], (semaforo+j)->*(ledState+stateSecuence)->Number[j][i])[i] ); ???
}
    /*
    int i, j, state;
    for (j = 0; j < SEMAFOROSQTY ; j++)
    {
        state = stateSecuence.number[j][secNumber];
        for (i = 0; i < LEDSQTY ; i++)
            digitalWrite( (semaforo+j)->ledPin[i], (semaforo+j)->ledState[state][i] ) ;
    }
    */


