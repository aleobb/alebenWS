#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    return 0;
}


/**
 * \brief Lista por pantalla los datos de un empleado
 * \param un puntero a un empleado
 * \return no devuelve nada.
 */
void employee_print(Employee* this)
{
    if ( this==NULL )
        printf("\n Nada que listar! \n");
    else
    {
        printf("\n Id: %d",this->id);
        printf("\t Nombre: %s",this->name);
        printf("\t Apellido: %s",this->lastName);
        printf("\t (isEmpty %d)",this->isEmpty);
    }
    printf("\n");
}



Employee* employee_new(void)
{

    Employee* returnAux = NULL;

    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}


