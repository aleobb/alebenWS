
typedef struct
{
    unsigned long delayValue;
    char running;
}S_timerData;

/// Prototipos de las funciones del reloj a utilizar:
void timer_setup();
int timer_loop();
void timer_resetWait(int delayNumber);
void timer_tick();
int timer_waitMs(int delayNumber,int delayMs);
int timer_avoidRebound(int delayNumber);


