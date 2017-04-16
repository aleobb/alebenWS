/*


// Aclaraciones respecto de los define de las luces leds:
// Las letras R, A, V representan los Leds Rojo, Amarillo y Verde respectivamente.
// El agregado _P indican que esos leds corresponden al semaforo peatonal
// El agregado _DOS indican que corresponden a los leds del semaforo secundario (tanto vehicular como peatonal)
//
// Luces Semaforo Peatonal Principal:
#define R_P 8
#define V_P 9
// Luces Semaforo Principal:
#define R 10
#define A 11
#define V 12
int prueba (int array[], int size)
{
// Luces Semaforo Peatonal Secundario:
#define R_P_DOS 2
#define V_P_DOS 3
// Luces Semaforo Secundario:
#define R_DOS 4
#define A_DOS 5
#define V_DOS 6

// Boton de demanda de cruce peatonal:
#define BOTON 0
// Sensor de vehiculo en calle secundaria:
#define SENSOR 1

// Tamaño de vector correspondiente a la cantidad total de luces led:
#define SIZE 10


void setStatus(int status);
void putStatus(int arrayLeds[], int arrayStatus[], int posicionInicio, int posicionFin);
void prueba(int opcion);

 	// Creo un array con los leds ordenados por grupos (Posic 0-3, 4-5 y 6-9)
 	int arrayLeds[SIZE]={V,R_P,R_DOS,V_P_DOS,A,A_DOS,V_DOS,R_P_DOS,R,V_P};
 	///int arrayStatus[SIZE];

void setup()
{
    // Se inicializan los PINES correspondientes a todos los leds definidos en el array como salida digital.
	for (int i=0;i<SIZE;i++)
		pinMode(arrayLeds[i], OUTPUT);

	pinMode(BOTON, INPUT);
 	pinMode(SENSOR, INPUT);

  	// setStatus(1); // Se define el estado de los leds, en este caso a su valor inicial o por defecto.

}

// the loop routine runs over and over again forever:
void loop()
{

 	int arrayStatus[SIZE]={1,1,1,1,0,0,0,0,0,0};
    putStatus(arrayLeds, arrayStatus, 0, SIZE); // Se inicializan los leds definidos en arrayLeds al estado indicado en el indicado en arrayStatus.

	//int arrayLeds[SIZE];
  	//int arrayStatus[SIZE];

  	int i;
 	if ( digitalRead(BOTON) == 0 )
    {
      	prueba(2);
      	// digitalWrite(arrayLeds[0],~arrayStatus[0]); //
      	// digitalWrite(LED_AMARILLO,1);
      	// digitalWrite(LED_AMARILLODOS,1);
		delay(2000);
    	for (i=0;i<SIZE;i++)
			arrayStatus[i]=~arrayStatus[i];
        //arrayStatus={0,0,0,0,0,0,1,1,1,1};
      	putStatus(arrayLeds, arrayStatus, 0, SIZE);

      	delay(2000);
      	for (i=0;i<SIZE;i++)
			arrayStatus[i]=~arrayStatus[i];
      	putStatus(arrayLeds, arrayStatus, 0, SIZE);
	}


}

void prueba(int opcion)
{
  switch(opcion)
  {
    case 1:
  		int arrayStatus[SIZE]={1,1,1,1,0,0,0,0,0,0};
  		break;
  	case 2:
  		int arrayStatus[SIZE]={0,0,0,0,0,0,1,1,1,1};
  		break;
  }
}

void setStatus(int status)
{
	switch (status)
    {
		case 1:
      		//int i;
      		//for (i=0;i<4;i++)
			//	arrayStatus[i]=1;
            //for (;i<SIZE-4;i++)
			//	arrayStatus[i]=0;
			//arrayStatus[10]={1,1,1,1,0,0,0,0,0,0}; //estado por defecto de los leds: encendido para los 4 primeros y apagado para el resto
  			break;
  		case 2:
  			break;
    }
}

/**
* \brief Inicializa los leds de los semaforos a su estado normal o por defecto.
* \param cantOn: posicion hasta del vector cuyos leds se van a encender
* \param size: tamaño del vector
* \return No devuelve nada.

void putStatus(int arrayLeds[], int arrayStatus[], int posicionInicio, int posicionFin)
{
   	for (int i=posicionInicio; i<posicionFin; i++) // cambia el estado de los leds desde la posicion inicio hasta la posicion fin
		digitalWrite(arrayLeds[i],arrayStatus[i]); // cambia el estado de los leds (encendido/apagado) segun el valor indicado en el arrayStatus
}


*/
