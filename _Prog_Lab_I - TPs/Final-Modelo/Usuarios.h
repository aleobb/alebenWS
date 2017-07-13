struct
{
    int id;
    char nombre[50];
    char email[50];
    char sexo[10];
    char pais[50];
    char password[50];
    char ip_address[50];

}typedef Usuario;

/*struct
{
    int id;
    char nombre[50];
    char password[50];
    int contadorCalificaciones;
    int acumuladorCalificaciones;
    int flagRegistro;

}typedef Usuario;*/

Usuario* newUsuario(int id, char nombre[], char email[], char sexo[], char pais[], char password[], char ip_address[]);

void printUsuario(Usuario* pUsuario);
