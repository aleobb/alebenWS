#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}


const int button = 2;
const int led = 3;
const int led2 = 4;

//int status;
int arrayLed[2]={3,4};
int arrayStatus[2]={1,1};
//int outputStatus = 0;
unsigned int intervalo = 500;
unsigned long marcaTiempo = 0;
int flag = 0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(arrayLed[0], arrayStatus[0]);
  digitalWrite(arrayLed[1], arrayStatus[1]);
}


void loop()
{

  	if ( digitalRead(button) == 0 )
    {
		marcaTiempo=millis()+500; /// Al detectar que se presiono el boton esta linea agrega 2 segundos (+ el tiempo del intervalo) al inicio de la secuencia de cambios de luces del semaforo.
        if ( (millis()-marcaTiempo) > intervalo && flag < 6 )
        {
         	if (flag < 4)
            	marcaTiempo = parpadeo(0);
          	if (flag > 2)
            	marcaTiempo = parpadeo(1);
          	flag++;
        }
      	if (flag == 6)
          	flag=0;
    }
}

unsigned long parpadeo (int led)
{
    if (arrayStatus[led]==0)
    	arrayStatus[led]=1;
    else
      	arrayStatus[led]=0;
  	digitalWrite(arrayLed[led], arrayStatus[led]);
  	return millis();
}

/*
        delay(3000);
        digitalWrite(V,0);
        delay(1000);
        digitalWrite(V,1);
        delay(10000);
        digitalWrite(V,0);
        digitalWrite(V_P_DOS,0);
        delay(1000);
        digitalWrite(V,1);
        digitalWrite(V_P_DOS,1);
        delay(1000);
        digitalWrite(V,0);
        digitalWrite(V_P_DOS,0);
        digitalWrite(A,1);
        delay(1000);
        digitalWrite(V_P_DOS,1);
        delay(1000);
        digitalWrite(V_P_DOS,0);
        delay(1000);
        digitalWrite(A,0);
        setStatus(1);
        delay(12000);

        */
