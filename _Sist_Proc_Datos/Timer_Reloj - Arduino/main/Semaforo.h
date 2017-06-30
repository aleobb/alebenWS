#define SEMAFOROSQTY 2  /// Cantidad total de semaforos
#define LEDSQTY 5       /// Cantidad total de luces led por semaforo
#define STATUSQTY 5     /// Cantidad total de diferentes estados para cada semaforo
#define SECUENCEQTY 8   /// Cantidad total de secuencias por ciclo de estados
#define SECUENCEPARTS 2 /// Cantidad de partes de la secuencia


struct {
    int ledPin[LEDSQTY];
    int ledState[STATUSQTY][LEDSQTY];
}typedef S_Semaforo;//Status;

struct {
    int time[SECUENCEQTY];
    int number[SEMAFOROSQTY][SECUENCEQTY]; /// {1er secuencia de estados para el semaforo 1 (2da para el 2)} {2da secuencia de estados para el semaforo 1 (1era para el 2)}
}typedef S_StateSecuence;



secuence[SECUENCEQTY]
    int time;
    int state[SEMAFOROSQTY][LEDSQTY]; /// {1er secuencia de estados para el semaforo 1 (2da para el 2)} {2da secuencia de estados para el semaforo 1 (1era para el 2)}


    secuence[i].state[j][k];
