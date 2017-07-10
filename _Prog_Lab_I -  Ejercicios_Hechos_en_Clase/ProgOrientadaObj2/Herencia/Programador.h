
struct S_Programador
{
    Object obj;  /// Siempre es el primer campo
    char nombre[20];
    char lenguaje[16]; // "C", "JAVA", "PYTHON"
};
typedef struct S_Programador Programador;

Programador* newProgamador(Object object, char nombre[], char lenguaje[]);
