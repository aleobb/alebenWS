#include <stdio.h>
#include <stdlib.h>
#include "func.h"

#define MAX 100

int main()
{
    int vEdad[MAX];
    int i=0;
    int edad;
    char salir;
    //float promedio;

    for (i=0;i<MAX;i++)
    {
        printf("\n Ingrese la edad de la persona %d: \n",i+1);
        scanf("%d",&edad);
        while (edad < 0 || edad > 120 )
        {
            printf("\n El dato ingresado es incorrecto! ");
            printf("\n Ingrese la edad de la persona %d: ",i+1);
            scanf("%d",&edad);
        }
        vEdad[i]=edad;
        i++;
        if(i==MAX)
            { break; }
    }while(salir != 's' && salir != 'S')





        scanf("%c",&preg);

        if

    }

    printf("La mayor edad es: %d", fMaxMin(vEdad,i,1);
    printf("La menor edad es: %d", fMaxMin(vEdad,i,-1);
    return 0;
}
