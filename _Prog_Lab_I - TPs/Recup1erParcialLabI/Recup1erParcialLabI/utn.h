typedef struct{
    char name[32];
    char surname[32];
    int age;
}EPersona;


int cerrarArch(FILE* pFile);

EPersona ingresoDatosPersona();

int agregarPersona();

void listarDatosPersona(EPersona persona);

EPersona* cargarPersonasEnArray(int* cantPersonas);

int contarPersonasEnArchivo();

void listarPersonas();


