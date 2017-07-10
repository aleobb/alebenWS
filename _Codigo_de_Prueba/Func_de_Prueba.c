#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

void prueba()
{
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

}
