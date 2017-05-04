struct
{
    int contador;
    int tiempo;
    float promedio;

}typedef EPromedioLlamada;


int listarAbonadoConMasMenosReclamos(EAbonado* arrayAbonados, int sizeArrayAbonados, int maxMin);

int cantidadLlamadasDeUnMotivoDeReclamo(ELlamada* arrayLlamadas, int sizeArrayLlamadas, int motivoReclamo);

int listarMotivoLlamadaMasRealizado(ELlamada* arrayLlamadas, int sizeArrayLlamadas);

int listarReclamoQueMasDemora(ELlamada* arrayLlamadas, int sizeArrayLlamadas);

