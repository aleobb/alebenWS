#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "funcAux.h"
#include "Usuarios.h"

#define ALL 0
#define ACTIVE 1
#define DELETED 2

#define BUFFER 1024


int fileToArray()
{
    ArrayList* uList = al_newArrayList();
    parserDataInFile("usuarios.dat", uList);
/*
    int i;
    for ( i = 0 ; i < uList->size ; i++ )
        printUsuario( uList->get(uList, i) );
*/
    return 0;
}


int parserDataInFile(char* nombreArchivo, ArrayList* uList)
{
    int id;
    char nombre[50];
    char email[50];
    char sexo[50];
    char pais[50];
    char password[50];
    char ip_address[50];

    char lineOfData[BUFFER];
    void* pAux;
    int elements = 0;


    FILE* pFile = fopen(nombreArchivo,"r");

    if ( pFile == NULL || uList == NULL )
        printf("El archivo no se pudo abrir o puntero a memoria de la lista es Null ! \n");
    else
    {
        fgets(lineOfData,sizeof(lineOfData)-1,pFile); /// Con esto leo la primer linea y la descarto
        while( fgets(lineOfData,sizeof(lineOfData)-1,pFile) != NULL )
        {
            sscanf(lineOfData,"%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",&id, nombre, email, sexo, pais, password, ip_address);
            //printf("Id: %d \t Object: %d \t Nombre: %s \t\t Data: %s \r\n", id, object.type, name, data);

            pAux = (void*)newUsuario(id, nombre, email, sexo, pais, password, ip_address);

            if ( pAux != NULL )
            {
                uList->add(uList, pAux);
                elements++;
            //  imprimirObject((Object*)pAux);
            }
        }
    }
    printf("\n Cantidad de elementos cargados en la lista: %d \n", elements);
    return elements;
}



/** \brief carga un nuevo usuario
 * \param se le pasan todos los datos de ese usuario
 * \return int Return (NULL) si no se pudo cargar el usuario - Puntero al usuario si se pudo cargar correctamente.
 */
Usuario* newUsuario(int id, char nombre[], char email[], char sexo[], char pais[], char password[], char ip_address[])
{

    Usuario* pUsuario = malloc( sizeof(Usuario) );

    if(pUsuario != NULL)
    {
        pUsuario->id = id;
        strcpy(pUsuario->nombre,nombre);
        strcpy(pUsuario->email,email);
        strcpy(pUsuario->sexo,sexo);
        strcpy(pUsuario->pais,pais);
        strcpy(pUsuario->password,password);
        strcpy(pUsuario->ip_address,ip_address);
    }
    return pUsuario;
}


/**
 * @brief muetra por pantalla los datos de un usuario.
 * @param pUsuario el puntero al usuario se pasa por parametro.
 * @param flagRegistro recibe como parametro el estado del usuario.
 * @return no devuelve nada.
 */
void printUsuario(Usuario* pUsuario)
{
    if(pUsuario != NULL)
    {
        printf("\n Id: %d ",pUsuario->id);
        printf("\n Nombre: %s ",pUsuario->nombre);
        printf("\n email: %s ",pUsuario->email);
        printf("\n sexo: %s ",pUsuario->sexo);
        printf("\n pais: %s ",pUsuario->pais);
        printf("\n password: %s ",pUsuario->password);
        printf("\n ip_address: %s ",pUsuario->ip_address);
        printf("\n ---------------------------------------------------");

    }
}


int compararUsuarioPorNombre(Usuario* pUsuarioA, Usuario* pUsuarioB)
{
    int retorno = 0;

    if ( pUsuarioA != NULL && pUsuarioB != NULL )
        retorno =  strcmp(pUsuarioA->nombre,pUsuarioB->nombre);
    return retorno;
}


int printByName(ArrayList* uList)
{
    ArrayList* uListClone = uList->clone(uList);
    uListClone->sort(uListClone,compararUsuarioPorNombre, 1);
    int i;
    for ( i = 0 ; i < uListClone->size ; i++ )
    {
        printf("\n i: %d", i);
        printUsuario( uListClone->get(uListClone, i) );
        if (i%100 == 0)
            getch();
    }
    free(uListClone);
    return 0;
}



int compararUsuarioPorNacionalidadYNombre(Usuario* pUsuarioA, Usuario* pUsuarioB)
{
    int retorno = 0;

    if ( pUsuarioA != NULL && pUsuarioB != NULL )
    {
        retorno =  strcmp(pUsuarioA->nombre,pUsuarioB->nombre);
        if ( retorno == 0 )
            retorno = strcmp(pUsuarioA->pais,pUsuarioB->pais);
    }

    return retorno;
}


int printByNacionalidadyNombre(ArrayList* uList)
{
    ArrayList* uListClone = uList->clone(uList);
    uListClone->sort(uListClone,compararUsuarioPorNacionalidadYNombre, 1);
    int i;
    for ( i = 0 ; i < uListClone->size ; i++ )
    {
        printf("\n i: %d", i);
        printUsuario( uListClone->get(uListClone, i) );
        if (i%100 == 0)
            getch();
    }
    free(uListClone);
    return 0;
}




/**
 * @brief busca si se encuentra cargado un id de usuario.
 * @param uList se pasa como parametro.
 * @param idUsuario se pasa como como parametro.
 * @return devuelve el puntero a la ubicacion de memoria donde estan guardados los datos de ese usuario (o NULL si no exite o si el tamaño del array es invalido o un puntero NULO)
 */
Usuario* buscarUsuarioPorId(ArrayList* uList, int idUsuario)
{
    Usuario* pUsuario = malloc(sizeof(Usuario));
    int i;

    if ( uList == NULL || pUsuario == NULL )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
        for (i=0; i<uList->size; i++)
        {
            pUsuario=uList->get(uList, i);
            if ( pUsuario->id == idUsuario )
                break;
        }
    return pUsuario;
}



/**
 * @brief pide al operador el id del usuario y comprueba que exista.
 * @param uList el array se pasa como parametro.
 * @param leyendaCancelar Se le pasa la leyenda a mostrar en caso de desistir del ingreso
 * @return devuelve -1 si se desistio de la carga, -2 si el tamaño del array es invalido o un puntero NULO, de lo contrario devuelve el indice del idUsuario en uList.
 */
int tomarYcomprobarExistenciaUsuarioPorId(ArrayList* uList, char* leyendaCancelar)
{
    int retorno=-2;
    int idUsuario=0;
    int i;
    Usuario* pUsuario = malloc(sizeof(Usuario));

    if ( uList == NULL || pUsuario == NULL )
        printf("\n La ejecucion se detendrá! Tamaño de array invalido o puntero NULO \n");
    else
    {
//        listarUsuarios(uList, ALL);
        while(retorno<-1)
        {
            getInt(&idUsuario, "\n Ingrese el id del usuario (0 para cancelar): ", "\n El dato ingresado es invalido!\
                \n El id debe ser un numero positvo entre 0 y 31999",1,1,0,1,31999);
            if (idUsuario==0)
            {
                printf("%s",leyendaCancelar);
                retorno=-1;
            }
            else
            {
                for (i=0; i<uList->size; i++)
                {
                    pUsuario = uList->get(uList, i);
                    if ( pUsuario != NULL && pUsuario->id == idUsuario )
                    {
                        retorno = i;
                        break;
                    }
                }
                if ( retorno < 0 )
                    printf("\n El nro. de id del usuario NO se encuentra ingresado! Reingrese \n");
            }
        }
    }
    return retorno;
}
