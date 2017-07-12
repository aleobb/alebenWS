
struct
{
    char nombre[100];
    char email[100];

}typedef Destinatario;

FILE* abrirArchivo();

void listarDestinatarios(ArrayList* listaDestinatarios);

int parserDestinatario(FILE* pFile, ArrayList* listaDestinatarios);

void printUsuario(Destinatario* pDestinatario);

void printDestinatarios(ArrayList* listaDestinatarios);

void cargarDestinatariosEnArray(ArrayList* listaDestinatarios);

float compararDestinatario(char* pDestinatarioA, char* pDestinatarioB);

int compararDestinatarioPorMail( Destinatario* pDestinatarioA, Destinatario* pDestinatarioB );

void tomarNombreArchivo(char* nombreArchivo);

void listarDestinatariosFiltrados(ArrayList* listaDestinatarios, ArrayList* listaNegra, int (*pFuncCompare)(char*,char*), int comparisonType);

