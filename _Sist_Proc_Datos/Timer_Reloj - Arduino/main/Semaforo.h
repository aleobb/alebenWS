#define LEDSQTY 10

struct {
    int time;
    int ledState[LEDSQTY];
}typedef S_SemaforoState;//Status;


/*
    struct {
        int ledPin[LEDSQTY];
        int ledState[LEDSQTY];
    }typedef S_Leds;


    struct {
        int time;
        int semaforosStatusNumber;
        int nextStatusNumber;
    }typedef Secuencia;

    struct {
        int time;
        //int semaforosStatusNumber;
        int nextStatusNumber;
    }typedef SemaforoStatus;


    typedef struct
    {
        PinStruct pin[5];
        int rojo;
        int amarillo;
        int verde;
        int rojoPeatonal;
        int verdePeatonal;

    }SemaforoStruct;

    typedef struct
    {
        int pin
        int state
    }S_Pin;

*/
