


struct
{
    int idUsuario;
    int idTema;

}typedef Estadistica;

Estadistica* newEstadistica(int idUsuario, int idTema);

int fileToArrayEstadisticas();

int estadisticaToFile(char* nombreArchivo, ArrayList* eList);
