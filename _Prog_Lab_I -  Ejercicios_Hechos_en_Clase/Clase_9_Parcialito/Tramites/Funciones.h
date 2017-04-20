struct
{
    int dni;
    int nroTurno;
    int tipoyEstadoTurno;

}typedef Tramites;

int getString(char mensajeIngreso[], char input[]);

int esCadenaSoloNumeros (char vector[], int cantPuntos, int admiteNegativos);

int otorgarTurno(Tramites turno[], int posicionArray, int tipoTramite, int nroTurno);

void listarTurnos(Tramites* turnos, int nroTurnoSigte);

