#include <stdio.h>
#include <stdlib.h>

#include "func.h"

#define SIZE 5
#define SIZEVO 4

int main()
{
        int array[SIZE] = {22,11,55,44,66};
        int vOrdenado[SIZEVO];
        int indice;
        int i;
        int min;

        printf("\nIngrese la posicion a eliminar: ");
        scanf("%d", &indice);
        while( indice<1 || indice>SIZE )
        {
            printf("\nLa posicion indicada supera el maximo! (1-5) ");
            printf("\nIngrese la posicion a eliminar: ");
            scanf("%d", &indice);
        }


    compactar(array, indice-1, SIZE );

    for (i=0;i<SIZEVO;i++)
      {
         printf("\nLos valores del array son: %d", array[i] );
      }

      printf("indice %d", fMaxMin(array, SIZEVO-i , -1) );

/*    for(i=0;i<SIZEVO;i++)
    {
        //int extremo = 1;
        compactar(array, SIZEVO, SIZEVO-1 );
        vOrdenado[i] = fMaxMin(array, SIZEVO-i , -1);
    }

    for (i=0;i<SIZEVO;i++)
      {
         printf("\nLos valores del array son: %d", vOrdenado[i] );
      }

*/
    return 0;
}
