#include <stdio.h>
#include <stdlib.h>

int prueba (int array[], int size);

int main()
{
    /*
    int status=1;
    printf("\n%d",status);
    status=~status;
    printf("\n%d",status);
    printf("\n\n\n\n\n");

    int i;
    int arrayStatus[10]={1,1,1,1,0,0,0,0,0,0};


    for (i=0;i<10;i++)
        printf("\n%d",arrayStatus[i]);
///    arrayStatus={0,0,0,1,0,0,0,0,0,1};
    for (i=0;i<10;i++)
        arrayStatus[i]=~arrayStatus[i];
        printf("\n%d",arrayStatus[i]);
*/
    int vector[4]={2,4,8,6};
    prueba(vector, 4);

    return 0;
}

int prueba (int array[], int size)
{
    int i;
    for (i=0;i<size;i++)
        printf("\n%d",array[i]);
}


/// Aclaraciones respecto de los define de las luces leds:
/// Las letras R, A, V representan los Leds Rojo, Amarillo y Verde respectivamente.
/// El agregado _P indican que esos leds corresponden al semaforo peatonal
/// El agregado _DOS indican que corresponden a los leds del semaforo secundario (tanto vehicular como peatonal)
///
/// Luces Semaforo Peatonal Principal:
#define R_P 8
#define V_P 9
/// Luces Semaforo Principal:
#define R 10
#define A 11
#define V 12

/// Luces Semaforo Peatonal Secundario:
#define R_P_DOS 2
#define V_P_DOS 3
/// Luces Semaforo Secundario:
#define R_DOS 4
#define A_DOS 5
#define V_DOS 6

/// Boton de demanda de cruce peatonal:
#define BOTON 0
/// Sensor de vehiculo en calle secundaria:
#define SENSOR 1

/// Tamaño de vector correspondiente a la cantidad total de luces led:
#define SIZE 10

/// Prototipos de funciones a utilizar:
void setStatus(int status);

/// Se define array de uso global con los leds ordenados por grupos (Posic 0-3, 4-5 y 6-9)
int arrayLeds[SIZE]={V,R_P,R_DOS,V_P_DOS,A,A_DOS,V_DOS,R_P_DOS,R,V_P};

void setup()
{
    /// Se inicializan los PINES correspondientes a todos los leds definidos en el array como salida digital.
	for (int i=0;i<SIZE;i++)
		pinMode(arrayLeds[i], OUTPUT);

    /// Se inicializan los PINES correspondientes a boton y sensor como entrada digital.
	pinMode(BOTON, INPUT);
 	pinMode(SENSOR, INPUT);
}

void loop()
{

    /// setStatus(0); /// Se define el estado de los leds a su valor inicial o por defecto.
    putStatus(0,3,1); /// Se define el estado de los leds a su valor inicial o por defecto.
    putStatus(4,9,0); /// Se define el estado de los leds a su valor inicial o por defecto.

 	if ( digitalRead(BOTON) == 0 )
    {
        delay(300);
        digitalWrite(V,0);
        delay(100);
        digitalWrite(V,1);
        delay(100);
        digitalWrite(V,0);
        digitalWrite(V_P_DOS,0);
        delay(100);
        digitalWrite(V,1);
        digitalWrite(V_P_DOS,1);
        delay(100);
        digitalWrite(V,0);
        digitalWrite(V_P_DOS,0);
        digitalWrite(A,1);
        delay(100);
        digitalWrite(V_P_DOS,1);
        delay(100);
        digitalWrite(V_P_DOS,0);
        delay(100);
        digitalWrite(A,0);
        setStatus(1);
        delay(1200);
	}
}


void setStatus(int status)
{
    int i;
	switch (status)
    {
		case 0:
            for (i=0;i<4;i++)
                digitalWrite(arrayLeds[i],1); /// enciende los leds desde la posicion 0 hasta la 3 del array de leds.
      		for (;i<SIZE-4;i++)
                digitalWrite(arrayLeds[i],0); /// apaga los leds desde la posicion 4 hasta la 9 del array de leds.
  			break;
  		case 1:
            for (i=0;i<6;i++)
                digitalWrite(arrayLeds[i],1); /// enciende los leds desde la posicion 0 hasta la 3 del array de leds.
      		for (;i<SIZE-6;i++)
                digitalWrite(arrayLeds[i],0); /// apaga los leds desde la posicion 4 hasta la 9 del array de leds.
  			break;
    }
}


void putStatus(int posicionInicio, int posicionFin, int status)
{
   	for (int i=posicionInicio; i<=posicionFin; i++) // cambia el estado de los leds desde la posicion inicio hasta la posicion fin
		digitalWrite(arrayLeds[i], status); // cambia el estado de los leds (encendido/apagado) segun el valor indicado en el arrayStatus
}

void parpadeo(int led, int cantParpadeos, unsigned int intervalo )
{

}




