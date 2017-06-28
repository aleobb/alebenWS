/******************************************************************
  Programa: Ejemplo de uso del receptor IR

  Objetivo:
    Mostrar los aspectos básicos del receptor IR

  Aspectos a destacar:
    -Lectura y Decodificación


  Versión: 0.1 del 6 de marzo de 2017
  Autor: Mauricio Dávila
  Revisión: -

* *******************************************************************/

#include <math.h>

#include "IRremote.h"

#include <LiquidCrystal.h>


LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // Pines utilizados

const int RECV_PIN = A3;

long ctrolRem;


IRrecv irrecv(RECV_PIN);

decode_results results;
int milisegundos = 0;
int decimas = 0;
int segundos = 0;
int minutos = 0;
int horas = 0;


/** \brief  Se invoca una sola vez cuando el programa empieza.
            Se utiliza para inicializar los modos de trabajo
            de los pines, el puerto serie, etc...
   \param void
   \return void
*/
void setup()
{
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  irrecv.enableIRIn(); // Comienzo a recibir por IR
  irrecv.blink13(true);

  lcd.begin(16, 2); // inicializo la biblioteca indicando 16 caracteres por 2 lineas

  lcd.setCursor(0, 0);
  /// lcd.print("HH:MM:SS:D");
  lcd.setCursor(0, 1);
  /// lcd.print("00:00:00:0");

}

double Thermister(int RawADC) {  //Function to perform the fancy math of the Steinhart-Hart equation
  double Temp;
  Temp = log(((10240000 / RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp )) * Temp );
  Temp = Temp - 273.15;              // Convert Kelvin to Celsius
  /// Temp = (Temp * 9.0) / 5.0 + 32.0; // Celsius to Fahrenheit - comment out this line if you need Celsius
  return Temp;


}


void loop()
{


  milisegundos = millis();
  if (milisegundos % 100 == 0) {
    decimas++;
    if (decimas == 10) {
      decimas = 0;
      segundos++;

    }
    if (segundos == 60) {
      segundos = 0;
      minutos++;
    }


    if (minutos == 60) {
      minutos = 0;
      horas++;
    }
    //Print Time
    lcd.setCursor(0, 0);
    if (horas < 10) {
      lcd.print("0");
    }
    lcd.print(horas);
    lcd.print(":");
    lcd.setCursor(3, 0);
    if (minutos < 10) {
      lcd.print("0");
    }
    lcd.print(minutos);
    lcd.print(":");
    lcd.setCursor(6, 0);
    if (segundos < 10) {
      lcd.print("0");
    }
    lcd.print(segundos);
    lcd.print(":");
    lcd.setCursor(9, 0);
    lcd.print(decimas);
  }

  if (irrecv.decode(&results)) {
    if (results.decode_type == NEC) {
      Serial.print("NEC: ");
      Serial.println(results.value);

      switch (results.value)
      {

        case 16718055:
          lcd.setCursor(6, 1);
          lcd.print("Arriba");
          break;
        case 16730805:
          lcd.print("Abajo");
          break;
        case 16716015:
          lcd.print("Izquierda");
          break;
        case 16734885:
          lcd.print("Derecha");
          break;
        case 16726215:
          lcd.print("Ok");
          break;
        case 16753245:
          lcd.setCursor(6, 1);
          lcd.print("Uno    ");
          break;
        case 16736925:
          lcd.setCursor(6, 1);
          lcd.print("Dos    ");
          break;
        case 16769565:
          lcd.setCursor(6, 1);
          lcd.print("Tres    ");
          break;
        case 16720605:
          lcd.setCursor(6, 1);
          lcd.print("Cuatro    ");
          break;
        case 16712445:
          lcd.setCursor(6, 1);
          lcd.print("Cinco    ");
          break;
        case 16761405:
          lcd.setCursor(6, 1);
          lcd.print("Seis    ");
          break;
        case 16769055:
          lcd.setCursor(6, 1);
          lcd.print("Siete    ");
          break;
        case 16754775:
          lcd.setCursor(6, 1);
          lcd.print("Ocho    ");
          break;
        case 16748655:
          lcd.setCursor(6, 1);
          lcd.print("Nueve    ");
          break;
        case 16750695:
          lcd.setCursor(6, 1);
          lcd.print("Cero    ");
          break;
        case 16738455:
          lcd.setCursor(0, 0);
          lcd.print("00:00:00:0");
          lcd.setCursor(6, 1);
          milisegundos = 0;
          decimas = 0;
          segundos = 0;
          minutos = 0;
          horas = 0;
          lcd.print("Asterisco    ");
          break;
        case 16756815:
          lcd.setCursor(6, 1);
          lcd.print("Numeral    ");
          break;
      }

      irrecv.resume(); // Habilito a recibir el proximo dato



    }

  }

}



