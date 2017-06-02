#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

#include "funcAux.h"
#include "parser.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/

void codigoExtra();

int main()
{
    int opcion=0;

    ArrayList* pArrayListEmployee=al_newArrayList();
    FILE* pFile=NULL;

    int sizeLista;
    int i;

    while(opcion!=7)
    {

        printf("\n");
        printf(" 1- Parsear archivo \n");
        printf(" 2- Listar Empleados \n");
        printf(" 3- Ordenar por nombre \n");
        printf(" 4- Agregar un elemento \n");
        printf(" 5- Eliminar un elemento \n");
        printf(" 6- Listar Empleados (Desde-Hasta) \n");
        printf(" 7- Salir \n");

        getInt(&opcion,"\n Ingrese una opcion: ","\n\n La opcion ingresada es incorrecta! Debe elegir una opcion del 1 al 11. \n",1,1,1,1,11);

        switch(opcion)
        {
            case 1:
                pFile = fopen("data.csv","r"); //  Abrirlo como solo lectura
                if (pFile!=NULL)
                {
                    parserEmployee(pFile, pArrayListEmployee);
                    fclose(pFile);
                }
                else
                    printf("El archivo no se pudo abrir! \n");
                break;
            case 2:
                sizeLista=al_len(pArrayListEmployee);
                printf("\n size lista: %d",sizeLista);
                for (i=0;i<sizeLista;i++)
                    employee_print( (Employee*)al_get(pArrayListEmployee,i) );
                break;
            case 3:
                al_sort(pArrayListEmployee, compareEmployee, 1);
                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:
                printf("\n\n PROCESO TERMINADO. \n");
                break;
        }
    }
    return 0;
}

void codigoExtra()
{
    ArrayList* lista; /// es el equivalente a un struct empleado* lista[100]
    char seguir='s';

    lista = al_newArrayList();
    //int len = al_len(lista);

    while (seguir!='n' && seguir!='N')
    {
        Employee* aux = (Employee*)malloc(sizeof(Employee));
        printf("\n Nombre?: ");
        scanf("%s",aux->name);
        al_add(lista,(void*)aux);
        printf("\n El size de la lista es: %d\r\n",al_len(lista));
        printf("\n Continua?: (s/n) ");
        scanf("%s",&seguir);
    }
}
