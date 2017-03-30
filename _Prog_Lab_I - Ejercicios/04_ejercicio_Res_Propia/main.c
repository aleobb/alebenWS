#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num;
    printf("Intente adivinar un numero del 1 al 100 \n \n\
            (Ingrese un nro. negativo para terminar)");
    do
    {
        printf("Intento nro. %d: ",i);
        scanf("%d",&num);
        if (num<1)
        {
            return 0
        }
        else if (num = 0 || num > 100)
        {
        printf("El nro. ingresado es incorrecto.");
        printf("Reintente adivinar el nro. (%d): ",i);
        scanf("%d",&num);
        }
        i++

    }





    return 0;
}
