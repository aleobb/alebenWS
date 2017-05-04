// Pines utilizados
#define LEDVERDE1 2
#define LEDAMARILLO1 3
#define LEDROJO1 4
#define LEDVERDE2 5
#define LEDAMARILLO2 6
#define LEDROJO2 7
#define PULSADOR1 8
#define PULSADOR2 9
// Variables
bool activo1 = true; // Indica si el sem�foro 1 est� activo, de lo contrario ser� el sem�foro 2
int tiempoCambio = 1500; // Tiempo de espera entre transici�n de LEDs
int tiempoEspera = 5000; // Tiempo de espera hasta comenzar transici�n
void setup() {
// Iniciamos el monitor serie
Serial.begin(9600);
// Modo entrada/salida de los pines
pinMode(LEDVERDE1, OUTPUT);
pinMode(LEDAMARILLO1, OUTPUT);
pinMode(LEDROJO1, OUTPUT);
pinMode(LEDVERDE2, OUTPUT);
pinMode(LEDAMARILLO2, OUTPUT);
pinMode(LEDROJO2, OUTPUT);
pinMode(PULSADOR1, INPUT);
pinMode(PULSADOR2, INPUT);
// Apagamos todos los LEDs
digitalWrite(LEDVERDE1, LOW);
digitalWrite(LEDAMARILLO1, LOW);
digitalWrite(LEDROJO1, LOW);
digitalWrite(LEDVERDE2, LOW);
digitalWrite(LEDAMARILLO2, LOW);
digitalWrite(LEDROJO2, LOW);
// Estado inicial: sem�foro 1 abierto, sem�foro 2 cerrado
digitalWrite(LEDVERDE1, HIGH);
digitalWrite(LEDROJO2, HIGH);
}
void loop() {
// Dependiendo del sem�foro que tengamos activo
if (activo1)
{
// Est� encendido el sem�foro 1, comprobamos el pulsador 2
int valor2 = digitalRead(PULSADOR2);
// Si hay un coche esperando, pulsador pulsado
if (valor2 == HIGH)
{
// Encender sem�foro 2
ecenderSemaforo2();
// Sem�foro 2 activo
activo1 = false;
}
}
else
{
// Est� encendido el sem�foro 1, comprobamos el pulsador 1
int valor1 = digitalRead(PULSADOR1);
// Si hay un coche esperando, pulsador pulsado
if (valor1 == HIGH)
{
// Encender sem�foro 1
ecenderSemaforo1();
// Sem�foro 1 activo
activo1 = true;
}
}
}
void ecenderSemaforo2()
{
// Apagamos sem�foro 1
// Esperamos
delay(tiempoEspera);
// Pasamos a luz amarilla
digitalWrite(LEDVERDE1, LOW);
digitalWrite(LEDAMARILLO1, HIGH);
// Esperamos
delay(tiempoCambio);
// Pasamos a luz roja
digitalWrite(LEDAMARILLO1, LOW);
digitalWrite(LEDROJO1, HIGH);
// Encendemos sem�foro 2
// Esperamos
delay(tiempoCambio);
// Pasamos a luz amarilla
digitalWrite(LEDROJO2, LOW);
digitalWrite(LEDVERDE2, HIGH);
}
void ecenderSemaforo1()
{
// Apagamos sem�foro 2
// Esperamos
delay(tiempoEspera);
// Pasamos a luz amarilla
digitalWrite(LEDVERDE2, LOW);
digitalWrite(LEDAMARILLO2, HIGH);
// Esperamos
delay(tiempoCambio);
// Pasamos a luz roja
digitalWrite(LEDAMARILLO2, LOW);
digitalWrite(LEDROJO2, HIGH);
// Encendemos sem�foro 1
// Esperamos
delay(tiempoCambio);
// Pasamos a luz amarilla
digitalWrite(LEDROJO1, LOW);
digitalWrite(LEDVERDE1, HIGH);
}
