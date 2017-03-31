#include <stdio.h>
#include <stdlib.h>

int fOrdenar(int vNum[], int cantidad)
{
    int i, j, aux;
    for(i=0;i<cantidad;i++)
    {
        for(j=i+1;j<cantidad+1;j++)
        {
            if(vNum[i]>vNum[j])
            {
                aux=vNum[i];
                vNum[i]=vNum[j];
                vNum[j]=aux;
            }
        }
    }
}


