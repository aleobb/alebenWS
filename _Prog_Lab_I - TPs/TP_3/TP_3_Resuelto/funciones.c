

int agregarPelicula(EMovie movie)

int borrarPelicula(EMovie movie)

void generarPagina(EMovie* lista[], char nombre[])



static void initialize(EMovie* movie, int age, int something);

/** \brief  Reseva espacio en memoria para una nueva pelicula y la inicializa
 *  \param int age Edad de la pelicula
 *  \param int something Otros datos
 *  \return EMovie* Retorna un puntero a la pelicula o NULL en caso de error
 */
EMovie* EMovie_new (int age, int something)
{
    EMovie* movie = (Emovie*)malloc(sizeof(EMovie));
    if(movie != NULL)
        initialize(movie,age,something);
    else
        printf("\n La ejecucion se detendra! No se pudo asignar espacio en memoria. \n");

    return movie;
}

/** \brief  Inicializa a una pelicula recibida como parametro
 * \param EMovie* movie Puntero a la pelicula
 * \param int age Edad de la pelicula
 * \param int something Otros datos
 * \return void
 */
static void initialize(EMovie* movie, int age, int something)
{
    movie->age = age;
    movie->something = something;
}
