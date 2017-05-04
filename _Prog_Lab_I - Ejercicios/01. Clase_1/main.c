#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pos = 0;
    int neg = 0;
    int num, i;


    for ( i = 0 ; i < 5 ; i++ )
    {

        printf("Ingrese Numero: \n");
        scanf("%d",&num);
        if(num>0)
        {
            pos++;
        }
        else
        {
            neg++;
        }

    }


    printf("\nPositivos: %d",pos);
    printf("\nNegativos: %d",neg);

}

/*
    int pos = 0;
    int neg = 0;
    int num, i;


    for ( i = 0 ; i < 10 ; i++ )
    {

    printf("Ingrese Numero: \n");
    scanf("%d",&num);
        if(num>0)
            { pos++;     }
        else
            { neg++;    }

    }


    printf("\nPositivos: %d",pos);
    printf("\nNegativos: %d",neg);


*/

/*

    int num1;
    int num2;

    printf("num1? \n");
    scanf("%d",&num1);

    printf("num2? \n");
    scanf("%d",&num2);

    printf("\nResultado: %d",num1+num2);

*/



/*   char edad;
   printf("Edad? \n");
   scanf("%d",&edad);

   printf("La edad es : %d",edad);

   return 0; */
