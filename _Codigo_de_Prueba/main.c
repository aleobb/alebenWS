#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int main()
{
    int i;
    int array[4]={1,2,3,4};

    for (i=0; i<4; i++)
        printf("\n Valor array 0: %d ",array[i] );

    printf("\n ");

    //array[]={5,6,7,8};


    const int TABLA_SECUENCIA[2][3]= { {1,2,3}, {4,5,6} };

    for (i=0; i<3; i++)
    {
         printf("\n Valor array 0: %d ",TABLA_SECUENCIA[0][i] );
         printf("\n Valor array 1: %d ",TABLA_SECUENCIA[1][i] );
    }


    return 0;

}


/*

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
int arrayStatus[SIZE]={1,1,1,1,0,0,0,0,0,0}; /// Se define el estado de los leds a su valor inicial o por defecto.

/// Variables globales auxiliares:
unsigned int intervalo = 500;
unsigned long marcaTiempo = 0;
int flag = 0;

//Prototipo de funciones:
void writeStatus(int posicionInicio, int posicionFin, int status);
void parpadeo(int led);

void setup()
{
    /// Se inicializan los PINES correspondientes a todos los leds definidos en el array como salida digital.
	for (int i=0;i<SIZE;i++)
    {
		pinMode(arrayLeds[i], OUTPUT);
  		digitalWrite(arrayLeds[i],arrayStatus[i]);
    }

    /// Se inicializan los PINES correspondientes a boton y sensor como entrada digital.
	pinMode(BOTON, INPUT);
 	pinMode(SENSOR, INPUT);
}

void loop()
{
 	if ( digitalRead(BOTON) == 0 )
    {
		cambio(0);
      	/// marcaTiempo=millis();
        /// if ( (millis()-marcaTiempo) > 700 )
        delay(700);
      	cambio(1);
    }
}

void cambio(int estado)
{
 	int verde=0;
 	int verdePeaton=3;
    int amarillo=4;
  	int pivot=5;

	if (estado==1)
    {
      verde=6;
      verdePeaton=9;
      amarillo=5;
      pivot=3;
    }

    marcaTiempo=millis()+500; /// Al detectar que se presiono el boton esta linea agrega 2 segundos (+ el tiempo del intervalo) al inicio de la secuencia de cambios de luces del semaforo.
        while (flag<7)
        {
            if ( (millis()-marcaTiempo) > intervalo )
            {
              	marcaTiempo=millis();
                if (flag < 5)
                    parpadeo(verde);
                if (flag > 1)
                    parpadeo(verdePeaton);
                if (flag == 4)
                    parpadeo(amarillo);
                flag++;
            }
        }
        flag=0;
      	writeStatus(0,pivot,0+estado);
      	writeStatus(pivot+1,9,1-estado);

}

void writeStatus(int posicionInicio, int posicionFin, int status)
{
	for (int i=posicionInicio; i<=posicionFin; i++) // cambia el estado de los leds desde la posicion inicio hasta la posicion fin
		digitalWrite(arrayLeds[i], status); // cambia el estado de los leds (encendido/apagado) segun el valor indicado en el arrayStatus
}

void parpadeo(int led)
{
    if (arrayStatus[led]==0)
    	arrayStatus[led]=1;
    else
      	arrayStatus[led]=0;
  	digitalWrite(arrayLeds[led], arrayStatus[led]);
}

*/
