#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcAux.h"
#include "utn.h"

#define ARCHIVO "BIN.DAT"

/**
 *  Cierra un archivo ya abierto
 *  @param pFile se le pasa el puntero al archivo como parametro
 *  @return retorna 0 si se pudo cerrar correctamente o -1 si no se pudo
 */
int cerrarArch(FILE* pFile)
{
    int retorno=-1;
    if( fclose(pFile) != -1 ) ///  Cerrar archivo
        retorno=0; /// printf("Archivo cerrado correctamente \n");
    else
        printf("\n El archivo no pudo ser cerrado! \n");
    return retorno;
}


/**
 * \brief Realiza el ingreso de datos de una persona
 * \param la cadena del campo name se le pasa como parametro
 * \return devuelve (0) si Tamaño invalido o puntero NULL pointer o sin espacio disponible - (1) si la carga se pudo realizar.
 */
EPersona ingresoDatosPersona()
{
    EPersona auxPersona; /// es la variable donde se van a guardar provisoriamente los datos
    char arrayCharsAdmitidos[20]=" ";

    getType("\n Ingrese el nombre: ", "\n El dato ingresado es invalido!\n Solo se adminten letras\
            espacios y que no exceda los 31 caracteres \n",1,1,arrayCharsAdmitidos,31,auxPersona.name);
    getType("\n Ingrese el apellido: ", "\n El dato ingresado es invalido!\n Solo se adminten letras\
            espacios y que no exceda los 31 caracteres \n",1,1,arrayCharsAdmitidos,31,auxPersona.surname);
    getInt(&auxPersona.age, "\n Ingrese la edad de la persona en anios: ", "\n El dato ingresado es invalido!\
           \n La edad debe ser un numero positvo entre 1 y 150",1,1,1,1,150);

    return auxPersona;
}


/**
 *  \brief Agrega una persona al archivo binario
 *  \param no recibe parametros
 *  \return retorna 0 si se pudo agregar correctamente o -2 si no se pudo grabar y -1 si se pudo grabar pero no cerrar el archivo
 */
int agregarPersona()
{
    FILE* pArchivo=NULL;
    int retorno=-2;


    EPersona persona = ingresoDatosPersona();
    listarDatosPersona(persona);
    pArchivo = fopen(ARCHIVO,"ab");
    if (pArchivo!=NULL)
    {
        // printf("pArchivo abierto correctamente \n");
        if ( fwrite(&persona,sizeof(EPersona),1,pArchivo) == 1 )
        {
            printf("\n La persona fue agregada en el archivo correctamente \n");
            retorno=cerrarArch(pArchivo);
        }
    }
    else
        printf("\n El archivo \"%s\" NO pudo ser abierto en modo escritura! La carga de la persona fue cancelada. \n", ARCHIVO);

    return retorno;
}


/**
 * \brief Lista por pantalla los datos de una persona
 * \param la variable que contiene los datos de la persona del tipo EPersona se le pasa como parametro
 * \return no devuelve nada.
 */
void listarDatosPersona(EPersona persona)
{
    printf("\n Nombre: \t %s",persona.name);
    printf("\n Apellido: \t %s",persona.surname);
    printf("\n Edad: \t %d",persona.age);
    printf("\n");
}



/**
 * \brief Carga los datos de las personas en un array
 * \param se le pasa la cantidad de personas que va a leer del archivo
 * \return EPersona* Retorna un puntero al array de personas (con todos sus datos) o NULL en caso de error
 */
EPersona* cargarPersonasEnArray(int* cantPersonas)
{
    FILE* pArchivo=NULL;
    EPersona* pPersonas=NULL;
    *cantPersonas=contarPersonasEnArchivo();

    if ( (*cantPersonas) > 0 )
    {
        pPersonas = (EPersona*)malloc(sizeof(EPersona)*(*cantPersonas)); /// Creo un array para la cantidad de personas guardadas en el archivo
        if( pPersonas == NULL )
            printf("\n La ejecucion se detendra! No se pudo asignar espacio en memoria para realizar esta operacion. \n");
        else
        {
            pArchivo = fopen(ARCHIVO,"rb"); ///  Abrirlo como solo lectura
            if ( pArchivo == NULL )
                printf("\n El archivo %s no pudo ser abierto! La ejecucion se detendra. \n", ARCHIVO);
            else
            {
                fread( pPersonas, sizeof(EPersona), (*cantPersonas), pArchivo );
                cerrarArch(pArchivo);
            }
        }
    }
    else
        printf("\n La opcion seleccionada no se puede ejecutar porque no hay personas guardadas en el archivo \n");
    return pPersonas;
}


/**
 * \brief obtiene la cantidad de personas guardadas en el archivo
 * \param no recibe parametros
 * \return retorna la cantidad personas guardadas en el archivo o -1 en caso de error
 */
int contarPersonasEnArchivo()
{
    int retorno=-1;
    FILE* pArchivo=NULL;
    pArchivo = fopen(ARCHIVO,"rb"); ///  Abrirlo como solo lectura
    if ( pArchivo == NULL )
        printf("\n El archivo %s no pudo ser abierto! La ejecucion se detendra. \n", ARCHIVO);
    else
    {
        fseek(pArchivo, 0, SEEK_END);
        retorno= ( ftell(pArchivo)/sizeof(EPersona) );
        cerrarArch(pArchivo);
    }
    return retorno;
}


/**
 * \brief Lista por pantalla los datos de una persona
 * \param no se le pasan parametros
 * \return no devuelve nada.
 */
void listarPersonas()
{
    int i;
    int sizeArrayPersonas;
    EPersona* arrayPersonas=cargarPersonasEnArray(&sizeArrayPersonas);

    if ( sizeArrayPersonas==0 )
        printf("\n No hay ninguna persona cargada en el archivo! \n");
    if ( arrayPersonas==NULL || sizeArrayPersonas<0 )
        printf("\n La ejecucion se detendra! El archivo que contiene las personas NO se pudo abrir. \n");
    else
    {
        for (i=0; i<sizeArrayPersonas; i++)
            listarDatosPersona( arrayPersonas[i] );
        free(arrayPersonas);
    }
}


/**
 * \brief busca una persona por su surname en una array cargado en memoria con los datos del archivo donde se almacenan
 * \param no se le pasan parametros
 * \return retorna 0 o el indice del array si se pudo realizar la operacion, -2 si no se pudo abrir el archivo o -1 si no se lo encontró o no se pudo abrir el archivo.
 */
int buscarPersonaPorApellido()
{
    int retorno=-2;
    char seguir='s';
    int i;
    char arrayCharsAdmitidos[]=" ";
    char surname[32];
    int sizeArrayPersonas;
    EPersona* arrayPersonas=cargarPersonasEnArray(&sizeArrayPersonas);


    if ( sizeArrayPersonas==0 )  /// Si este valor es cero es porque el archivo que contiene las personas se pudo abrir y no hay ninguna cargada
        retorno++;
    else if ( arrayPersonas==NULL || sizeArrayPersonas<0 )  /// En cualquiera de estas opciones el archivo que contiene las personas NO se pudo abrir
        printf("\n La ejecucion se detendra! El archivo que contiene las personas NO se pudo abrir, y por tanto no se pudo verificar si existe alguna con ese apellido \n");
    else
    {
        while (seguir!='n' && seguir!='N')
        {
            getType("\n Ingrese el apellido: ", "\n El dato ingresado es invalido!\n Solo se adminten letras\
                    espacios y que no exceda los 31 caracteres \n",1,1,arrayCharsAdmitidos,31,surname);
            // printf("\n %s",surname);
            for (i=0; i<sizeArrayPersonas; i++)
            {
                if( strcmp(arrayPersonas[i].surname,surname)==0 )
                {
                    printf("\n Persona encontrada! Datos completos: \n");
                    listarDatosPersona(arrayPersonas[i]);
                    retorno=i;
                    break;
                }
            }
            if (retorno<0)
            {
                printf("\n El apellido ingresado no coincide con ninguno guardado en el archivo! Desea reintentar? (s/n): ");
                scanf("%c",&seguir);
            }
            else
            {
                printf("\n Desea buscar otra persona? (s/n): ");
                scanf("%c",&seguir);
            }

        }
        free(arrayPersonas);
    }
    return retorno;
}
