int comparar (Empleado empleadoA, Empleado empleadoB)
{
    int retorno = 0;
    if(strcmp(empleadoA.nombre,empleadoB.nombre) > 0)
        retorno = 1;
    else if(strcmp(empleadoA.nombre,empleadoB.nombre) < 0)
        retorno = -1;
    else
    {
        if(strcmp(empleadoA.apellido,empleadoB.apellido) > 0)
            retorno = 1;
        else if(strcmp(empleadoA.apellido,empleadoB.apellido) < 0)
            retorno = -1;
        else
        {
            if(strcmp(empleadoA.legajo,empleadoB.legajo) > 0)
                retorno = 1;
            else if(strcmp(empleadoA.legajo,empleadoB.legajo) < 0)
                retorno = -1;
            else
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}




void imprimir(EPersona* arrayPunterosPersonas[], int sizeArray)
{
    int i;
    for (i = 0; i < sizeArray; i++)
        printf("indiceArray  %d \t Nombre  %s \t Edad  %d \t dirMemoria  0x%x \n", i, arrayPunterosPersonas[i]->nombre, arrayPunterosPersonas[i]->edad, arrayPunterosPersonas[i] );
}



/**
 * \brief Lista por pantalla los datos de una pelicula
 * \param no se le pasan parametros
 * \return no devuelve nada.
 */
void listarPeliculas()
{
    int i;
    int sizeArrayPeliculas;
    EMovie* arrayPeliculas=cargarPeliculasEnArray(&sizeArrayPeliculas);

    if ( sizeArrayPeliculas==0 )
        printf("\n No hay ninguna pelicula cargada en el archivo! \n");
    else if ( arrayPeliculas==NULL || sizeArrayPeliculas<0 )
        printf("\n El archivo que contiene las peliculas a listar NO se pudo abrir. \n");
    else
    {
        for (i=0; i<sizeArrayPeliculas; i++)
            listarDatosPelicula( arrayPeliculas[i] );
        free(arrayPeliculas);
    }
}




int fMaxMin(int num[], int cantIng, int calcMax )  // para calcular el maximo hay que ingresar 1 en char calcMax y para el min -1
{

    int indice =1;
    int extremo = num[0]; // extremo lo uso para encontrar el extremo,(maximo o minimo)
    int indiceExtremo = 0;

    for( ; indice < cantIng ; indice++ )
    {
        if ( (num[indice]*calcMax) > (extremo*calcMax) ) // con calcMax invierto el signo y por tanto el comparador ">"3
        {
            extremo = num[indice] ;
            indiceExtremo = indice;
        }
    }

    return indiceExtremo;
}



calcularIndiceMinimo




void graficoEdades(EPersona arrayPersonas[], int sizeArray)
{
    int i; /// variable auxiliar
    int edadMenorA19=0; /// contador de edades menores a 19
    int edadDesde19a35=0; /// contador de edades entre 19 y 35 (ambas inclusive)
    int edadMayorA35=0; /// contador edades mayores a 35
    int cantGrupoMasGrande; /// Con esta variable obtengo la altura maxima del grafico de barras

    /// defino variables de reemplazo para graficar cada grupo:
    char grupoMenorA19=' ';
    char grupo19a35=' ';
    char grupoMayorA35=' ';

    /// se recorre el array para obtener la cantidad de personas de cada grupo de edades:
    for(i=0;i<sizeArray;i++)
    {
        if(arrayPersonas[i].estado==1)
        {
            if(arrayPersonas[i].edad<19)
                edadMenorA19++;
            else if(arrayPersonas[i].edad>35)
                edadMayorA35++;
            else
                edadDesde19a35++;
        }
    }

    /// calculo cual es el grupo con mas personas:
    if(edadMenorA19 >= edadDesde19a35 && edadMenorA19 >= edadMayorA35)
        cantGrupoMasGrande=edadMenorA19;
    else if(edadDesde19a35 >= edadMenorA19 && edadDesde19a35 >= edadMayorA35)
        cantGrupoMasGrande=edadDesde19a35;
    else
        cantGrupoMasGrande=edadMayorA35;
    printf("\n\n");

    /// Con el codigo a continuacion genero el grafico con una cantidad de renglones maxima
    /// igual a la cantidad de personas del grupo de mayor cantidad de personas:
    /// (por ello se empieza a recorrer desde cantGrupoMasGrande hasta 1)
    for(i=cantGrupoMasGrande;i>0;i--)
    {
        if(i<=edadMenorA19 )
            grupoMenorA19='*';
        if(i<=edadDesde19a35)
            grupo19a35='*';
        if(i<=edadMayorA35)
            grupoMayorA35='*';
        printf("   %02d \t  %c \t  %c\t %c \t\n",i,grupoMenorA19,grupo19a35,grupoMayorA35);
    }
    printf("\n Grupo:\t <18\t19-35\t>35\n");
}
