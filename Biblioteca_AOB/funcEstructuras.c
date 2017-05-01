#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcValidacion.h"
#include "funcMatematicas.h"
#include "funcOrdenar.h"
#include "funcEstructuras.h"

#define BUFFER 4084
#define EL_DATO_ES_VALIDO 1
#define EL_DATO_NO_ES_VALIDO 0

#define TRUE 1
#define FALSE 0


/**
 *  \brief  To indicate that all position in the array are empty,
 *          this function put the flag (isEmpty) in TRUE in all
 *          position of the array
 * \param pEmployee employee* Pointer to array of employees
 * \param length int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(employee* pEmployee, int length)
{
    int i;
    int retorno=0;
    if ( pEmployee==NULL || length<=0 )
        retorno=-1;
    else
        for (i=0;i<length;i++)
            pEmployee[i].isEmpty=TRUE;
    return retorno;
}


/**
 * \brief add in a existing list of employees the values recived as parameters
 * \param pEmployee employee*
 * \param length int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addEmployee(employee* pEmployee, int length, int id, char name[],char lastName[],float salary,int sector)
{
    int i;
    int retorno=-1;
    if ( pEmployee!=NULL && length>0 )
        for (i=0 ; i<length;i++)
            if ( pEmployee[i].isEmpty==TRUE )
            {
                retorno=0;
             ///(pEmployee+i)->isEmpty=FALSE;
                pEmployee[i].isEmpty=FALSE;

                pEmployee[i].id=id;
                strcpy(pEmployee[i].name,name);
                strcpy(pEmployee[i].lastName,lastName);
                pEmployee[i].salary=salary;
                pEmployee[i].sector=sector;

                break;
            }
    return retorno;
}


/**
 * \brief find a Employee by Id
 * \param pEmployee employee*
 * \param length int
 * \param id int
 * \return employee* Return a (Employee pointer) if ok or (NULL pointer) if [Invalid length or NULL pointer recived or employeed not found]
 */
employee* findEmployeeById(employee* pEmployee, int length,int id)
{

    int i;
    employee* retorno=NULL;
    if ( pEmployee!=NULL && length>0 )
        for (i=0 ; i<length;i++)
            if ( pEmployee[i].isEmpty !=TRUE && pEmployee[i].id==id )
            {
                retorno=pEmployee+i;
                break;
            }
    return retorno;
}


/**
 * \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param pEmployee employee*
 * \param length int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 */
int removeEmployee(employee* pEmployee, int length, int id)
{
    int i;
    int retorno=-1;
    if ( pEmployee!=NULL && length>0 )
        for (i=0 ; i<length ; i++)
            if ( pEmployee[i].isEmpty!=TRUE && pEmployee[i].id==id )
            {
                pEmployee[i].isEmpty=TRUE;
                retorno=0;
                break;
            }
    return retorno;
}


/**
 * \brief Sort the elements in the array of employees by Name, the argument order indicate UP or DOWN order
 * \param pEmployee employee*
 * \param length int
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployeeByName(employee* pEmployee, int length, int order)
{
    int i;
    int flagSwap = 1;
    employee aux;

    int retorno=-1;
    if ( pEmployee!=NULL && length>0 )
    {
        retorno=0;
        while(flagSwap)
        {
            flagSwap = 0;
            for(i = 0; i<length-1 ; i++)
            {
                if( order==1 && strcmp(pEmployee[i].name,pEmployee[i+1].name) > 0 ) /// && pEmployee[i].isEmpty!=TRUE && pEmployee[i].isEmpty!=TRUE )
                {
                    aux = pEmployee[i+1];
                    pEmployee[i+1] = pEmployee[i];
                    pEmployee[i] = aux;
                    flagSwap = 1;
                }
                else if( order==1 &&  strcmp(pEmployee[i].name,pEmployee[i+1].name) < 0 ) /// && pEmployee[i].isEmpty!=TRUE && pEmployee[i].isEmpty!=TRUE )
                {
                    aux = pEmployee[i+1];
                    pEmployee[i+1] = pEmployee[i];
                    pEmployee[i] = aux;
                    flagSwap = 1;
                }
            }
        }
    }
    return retorno;
}



/**
 * \brief
 * \param pEmployee employee*
 * \param length int
 * \return int
 */
int printEmployees(employee* pEmployee, int length)
{
    int i;
    printf("\n  Id   -       Name       -     Last Name    - Salary  - Sector");
    for(i=0; i< length; i++)
    {
        if(!pEmployee[i].isEmpty)
            printf("\n%6i - %-16s - %-16s - %4.2f - %6d",pEmployee[i].id, pEmployee[i].name, pEmployee[i].lastName, pEmployee[i].salary, pEmployee[i].sector );
    }
    return 0;
}

