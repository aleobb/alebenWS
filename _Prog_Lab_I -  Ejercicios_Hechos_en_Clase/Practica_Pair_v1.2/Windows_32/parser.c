#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Employee.h"

FILE* fileOpenReadOnly(char* fileDirAndName)
{
    FILE* pFile = fopen("data.csv","r"); ///  Abrirlo como solo lectura

    if (pFile==NULL)
        printf("El archivo no se pudo abrir! \n");
    return pFile;
}


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    //Employee auxEmployee=NULL;
    char id[6];
    char isEmpty[10];

    if (pFile!=NULL)
    {
         while( !feof(pFile) )
         {
            Employee* auxEmployee = (Employee*)malloc(sizeof(Employee));
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]", id, auxEmployee->name, auxEmployee->lastName, isEmpty);
            /// Falta validar!!!
            auxEmployee->id=atoi(id);
            auxEmployee->isEmpty=0;
            if(strcmp(isEmpty,"true")==0)
                auxEmployee->isEmpty=1;

            //employee_print(auxEmployee);

            al_add(pArrayListEmployee,(void*)auxEmployee);
         }
    }
    else
        printf("El archivo no se pudo abrir! \n");
    return 0;
}


int compareEmployee(void* empOne , void* EmpTwo )
{
    return strcmp( ( (Employee*)empOne )->name , ( (Employee*)EmpTwo )->name );
}


int addEmployee(ArrayList* pArrayListEmployee)
{
    Employee* auxEmployee = (Employee*)malloc(sizeof(Employee));

    al_add(pArrayListEmployee,auxEmployee);
}

int idNextEmployee(ArrayList* pArrayListEmployee)
{
    int i;
    int size=al_len(pArrayListEmployee)

    for (i=0;i<size;i++)

}
