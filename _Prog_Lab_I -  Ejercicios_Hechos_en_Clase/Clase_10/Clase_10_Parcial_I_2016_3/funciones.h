

struct
{
    int id;
    char titulo[50];
    int year;
    char nacionalidad[50];
    int idDirector;

}typedef Pelicula;

struct
{
    int id;
    char nombre[50];
    char fechaNacimiento[10];
    char paisOrigen[50];

}typedef Director;


int getString(char mensajeIngreso[], char input[]);

int esCadenaSoloNumeros (char vector[], int cantPuntos, int admiteNegativos);

void altaDirector(Director arrayDirectores[], int indexArrayDirectores, int idDirector);

void inicializarArrays(Director arrayDirectores[], Pelicula arrayPeliculas[]);

int buscarDirector(Director arrayDirectores[], int sizeArrayDirectores, int idDirector);

int buscarIndexVacioEnArrayDirectores(Director arrayDirectores[], int sizeArrayDirectores);
