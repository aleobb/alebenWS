#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

/// Cantidad total de semaforos:
#define SEMAFOROSQTY 2
/// Cantidad total de luces led por semaforo:
#define LEDSQTY 5
/// Cantidad total de diferentes estados para cada semaforo:
#define STATUSQTY 5
/// Cantidad total de secuencias por ciclo de estados:
#define SECUENCEQTY 8

struct {
    int time;
    int state[SEMAFOROSQTY][LEDSQTY];
}typedef S_Secuencia;

int main()
{
    printSemaforo();
    /*
    int i;
    int array[4]={1,2,3,4};

    for (i=0; i<4; i++)
        printf("\n Valor array 0: %d ",array[i] );

    printf("\n ");

    //array[]={5,6,7,8};


    const int TABLA_SECUENCIA[2][3]= { {1,2,3}, {4,5,6} };

    for (i=0; i<3; i++)
    {
         printf("\n Valor array 0: %d ",TABLA_SECUENCIA[0][i] );
         printf("\n Valor array 1: %d ",TABLA_SECUENCIA[1][i] );
    }


    return 0;
*/
}

    S_Secuencia secuence[SECUENCEQTY];
    int states[STATUSQTY][LEDSQTY] = { {0,0,1,1,0} , {0,0,0,1,0} , {0,1,0,1,0} , {1,0,0,0,1} , {1,0,0,0,0} };
    int stateTime[SECUENCEQTY] = {5,1,1,1,1,1,1,1};
    int stateIndex[SEMAFOROSQTY][SECUENCEQTY] = { {0,1,0,1,0,2,2,2} , {3,3,3,4,3,4,3,4} }; /// {1er secuencia de estados para el semaforo 1 (2da para el 2)} {2da secuencia de estados para el semaforo 1 (1era para el 2)}

void printSemaforo()
{

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
    int i, j, k;
    int l = SEMAFOROSQTY;
    printf("\n\n Segunda Parte del Ciclo: ");
    for (k = 0; k < SECUENCEQTY ; k++)
    {
        //for (j = SEMAFOROSQTY-1; j >= 0 ; j--)
        for (j = 0; j < SEMAFOROSQTY ; j++)
        {
            l--;
            printf("\n   %d  \t    %d \t     %d \t\t",k,(secuence+k)->time,j);
            for (i = 0; i < LEDSQTY ; i++)
                printf("%d ",(secuence+k)->state[l][i]);
        }
    }

}
