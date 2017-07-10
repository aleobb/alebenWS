#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>


/// Luces Semaforo Principal:
#define R1 10
#define A1 11
#define V1 12
/// Luces Semaforo Peatonal Principal:
#define RP1 8
#define VP1 9

/// Luces Semaforo Secundario:
#define R2 4
#define A2 5
#define V2 6
/// Luces Semaforo Peatonal Secundario:
#define RP2 2
#define VP2 3


#define SEMAFOROSQTY 2  /// Cantidad total de semaforos
#define LEDSQTY 5       /// Cantidad total de luces led por semaforo
#define STATUSQTY 5     /// Cantidad total de diferentes estados para cada semaforo
#define SECUENCEQTY 8   /// Cantidad total de secuencias por ciclo de estados
#define SECUENCEPARTS 2 /// Cantidad de partes de la secuencia

struct {
    int time;
    int state[SEMAFOROSQTY][LEDSQTY];
}typedef S_Secuencia;

/// Prototipos de funciones a utilizar:
void printSemaforo();
void printSemaforo2();

/// Se define arrayEstructura de uso global con los estados de los leds de los semaforos
int pinLedSemaforo[SEMAFOROSQTY][LEDSQTY] = { {R1,A1,V1,RP1,VP1} , {R2,A2,V2,RP2,VP2} };
S_Secuencia secuence[SECUENCEQTY];

int main()
{
    int i,j;
    /// Se inicializan los PINES correspondientes a todos los leds como salida digital:
    for (j = 0; j < SEMAFOROSQTY ; j++)
        for (i = 0; i < LEDSQTY ; i++)
            printf("\n Pin %d",pinLedSemaforo[j][i]);

    printf("\n\n ");
    printSemaforo();

    return 0;
}


void printSemaforo()
{
    int states[STATUSQTY][LEDSQTY] = { {0,0,1,1,0} , {0,0,0,1,0} , {0,1,0,1,0} , {1,0,0,0,1} , {1,0,0,0,0} };
    int stateTime[SECUENCEQTY] = {5,1,1,1,1,1,1,1};
    int stateIndex[SEMAFOROSQTY][SECUENCEQTY] = { {0,1,0,1,0,2,2,2} , {3,3,3,4,3,4,3,4} }; /// {1er secuencia de estados para el semaforo 1 (2da para el 2)} {2da secuencia de estados para el semaforo 1 (1era para el 2)}

    int i, j, k;
    printf("Sec Nro - Tiempo - Sem Nro - Leds States");
    for (k = 0; k < SECUENCEQTY ; k++)
    {
        (secuence+k)->time = stateTime[k];
        for (j = 0; j < SEMAFOROSQTY ; j++)
        {
            printf("\n   %d  \t    %d \t     %d \t\t",k,(secuence+k)->time,j);
            for (i = 0; i < LEDSQTY ; i++)
            {
                (secuence+k)->state[j][i] = states[ stateIndex[j][k] ][i];
                printf("%d ",(secuence+k)->state[j][i]);
            }
        }
    }
    printSemaforo2();
}

void printSemaforo2()
{
    int i, j, k, l;
    printf("\n\n Segunda Parte del Ciclo: ");
    for (k = 0; k < SECUENCEQTY ; k++)
    {
        //for (j = SEMAFOROSQTY-1; j >= 0 ; j--)
        for (j=0, l=SEMAFOROSQTY-1; j < SEMAFOROSQTY ; j++,l--)
        {
            printf("\n   %d  \t    %d \t     %d \t\t",k,(secuence+k)->time,j);
            for (i = 0; i < LEDSQTY ; i++)
                printf("%d ",(secuence+k)->state[l][i]);
        }
    }
}
