#define SEMAFOROSQTY 2  /// Cantidad total de semaforos
#define LEDSQTY 5       /// Cantidad total de luces led por semaforo
#define STATUSQTY 5     /// Cantidad total de diferentes estados para cada semaforo
#define SECUENCEQTY 8   /// Cantidad total de secuencias por ciclo de estados
#define SECUENCEPARTS 2 /// Cantidad de partes de la secuencia

struct {
    int time;
    int state[SEMAFOROSQTY][LEDSQTY];
}typedef S_Secuencia;

/// Prototipos de las funciones del Semaforo a utilizar:
void initSemaforo();
void nextState();
void secNumberIncrease();
