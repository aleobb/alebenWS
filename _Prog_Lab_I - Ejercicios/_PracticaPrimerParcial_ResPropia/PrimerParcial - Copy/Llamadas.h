
struct
{
    int id;
    int idAbonado;
    int motivo;
    int estado;
    int tiempo;
    int flagRegistro;

}typedef ELlamada;


int initArrayLlamadas(ELlamada* arrayLlamadas, int sizeArrayLlamadas);

int obtenerPosicionLibreArrayLlamadas(ELlamada* arrayLlamadas, int sizeArrayLlamadas);

int buscarLlamadaPorId(ELlamada* arrayLlamadas, int sizeArrayLlamadas, int idLlamada);

int nuevaLlamada(ELlamada* arrayLlamadas, int sizeArrayLlamadas, EAbonado* arrayAbonados, int sizeArrayAbonados);

int modificarLlamadaPorId(ELlamada* arrayLlamadas, int sizeArrayLlamadas);

int ingresoIdLlamada();

int ingresoMotivoLlamada();

int ingresoEstadoLlamada();

int calcularIdLlamada(ELlamada* arrayLlamadas, int sizeArrayLlamadas);

int existenLlamadas(EAbonado* arrayLlamadas, int sizeArrayLlamadas);

int eliminarLlamadasPorBajaAbonado(ELlamada* arrayLlamadas, int sizeArrayLlamadas, int idAbonado);

void listarLlamadas(ELlamada* arrayLlamadas, int sizeArrayLlamadas);
