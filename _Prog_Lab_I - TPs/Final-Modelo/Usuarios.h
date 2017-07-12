/*struct
{
    int id;
    char nombre[50];
    char email[50];
    char sexo[50];
    char pais[50];
    char password[50];

}typedef Usuario;*/

struct
{
    int id;
    char nombre[50];
    char password[50];
    int contadorCalificaciones;
    int acumuladorCalificaciones;
    int flagRegistro;

}typedef Usuario;

Usuario* newUsuario(int id, char nombre[], char password[], int contadorCalificaciones, int acumuladorCalificaciones, int flagRegistro);

void printUsuario(Usuario* pUsuario, int flagRegistro);
void listarUsuarios(ArrayList* listaUsuarios, int flagRegistro);
void listarUsuariosOrdenadosPorParametro(ArrayList* listaUsuarios, int order, int (*pFunc)(void*,void*));
int filtrarUsuarioPorCantidadDeCalificaciones(void* pUsuario, void* cantidadDeCalificaciones);
void listarUsuariosFiltradosPorCalificacion(ArrayList* listaUsuarios);
void listarUsuariosFiltrados(ArrayList* listaUsuarios, int (*pFuncCompare)(void*,void*), int filter, void* pCompare);
int compararUsuarioPorCalificacion(void* pUsuarioA, void* pUsuarioB);



int altaUsuario(ArrayList* listaUsuarios);

void cargaNombreUsuario(char* nombre);

void cargaPasswordUsuario(char* password);

int calcularIdUsuario(ArrayList* listaUsuarios);

int tomarYcomprobarExistenciaUsuarioPorId(ArrayList* listaUsuarios, char* leyendaCancelar);

int bajaUsuario(ArrayList* listaUsuarios);

int modificarUsuarioPorId(ArrayList* listaUsuarios);

float calcularPromedioCalificaciones(void* pUsuario);

int borrarUsuarios(ArrayList* listaUsuarios);







int cargaInicialUsuarios (ArrayList* listaUsuarios);
