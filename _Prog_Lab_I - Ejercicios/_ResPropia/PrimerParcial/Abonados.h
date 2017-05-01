
struct
{
    int id;
    int numero;
    char nombre[50];
    char apellido[50];
    int contadorLlamadas;
    int flagRegistro;

}typedef EAbonado;

int initArrayAbonados(EAbonado* arrayAbonados, int sizeArrayAbonados);

int obtenerPosicionLibreArrayAbonados(EAbonado* arrayAbonados, int sizeArrayAbonados);

int buscarAbonadoPorId(EAbonado* arrayAbonados, int sizeArrayAbonados, int idAbonado);

int buscarAbonadoPorNumero(EAbonado* arrayAbonados, int sizeArrayAbonados, int numeroAbonado);

int altaAbonado(EAbonado* arrayAbonados, int sizeArrayAbonados);

int modificarAbonadoPorId(EAbonado* arrayAbonados, int sizeArrayAbonados);

int ingresoNumeroAbonado();

int ingresoIdAbonado();

int calcularIdAbonado(EAbonado* arrayAbonados, int sizeArrayAbonados);

int existenAbonados(EAbonado* arrayAbonados, int sizeArrayAbonados);

void cargaNombreYapellidoAbonado(EAbonado* arrayAuxiliarAbonado);

void listarAbonados(EAbonado* arrayAbonados, int sizeArrayAbonados);

