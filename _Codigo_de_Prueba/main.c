#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int main()
{
   /*     int  num1 = 1000000000;
    long num2 = 1000000000;
    long long num3;
    scanf("%llu",&num3);
    //num3 = 100000000000;
    long long num4 = ~0;

    printf("%u %u %u", sizeof(num1), sizeof(num2), sizeof(num3));
    printf("%d %ld %lld %llu", num1, num2, num3, num4);
    return 0;

    */

    int salir = 1;
    double x;
    do
    {

    printf("Ingrese el valor del primer operando (con hasta 6 decimales): \n ");
    fflush(stdin);
    scanf("%f",&x);
    fflush(stdin);
    printf("\n %f",x);
    printf("\n salir? (1) \n");
    scanf("%d",&salir);
    }while (salir != 1);
    return 0;

}
