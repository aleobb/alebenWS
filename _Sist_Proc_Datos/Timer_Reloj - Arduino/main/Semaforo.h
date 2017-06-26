
/// Cantidad total de luces led:
#define LEDSQTY 5
/// Cantidad total de estados de los semaforos:
#define STATUSQTY 5


struct {
    int ledPin[LEDSQTY];
    int ledStateArray[STATUSQTY][LEDSQTY];
}typedef S_Semaforo;//Status;

