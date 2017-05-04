#include <stdio.h>
#include <stdlib.h>

int main()
{
float num, max, min;
float suma = 0;
int i;


for ( i = 1 ; i <= 5 ; i++ )
    {
    printf("ingrese el numero (%d): \n",i);
    scanf("%f",&num);

    suma = suma + num ;

    if ( num > max || i == 1 )
        { max = num ; }
    if ( num < min || i == 1 )
        { min = num ; }

    }

printf("\n El promedio es: %f \n", suma/(i-1) );
printf("\n El maximo es: %f \n", max );
printf("\n El minimo es: %f \n", min );

return 0;
}
