
struct S_Administrativo
{
    Object obj; /// Con esto digo que hereda de object y que ademas de ser Administrativo es Object
    char nombre[20];
    int area; // AREA_COMPRAS, AREA_VENTAS
};
typedef struct S_Administrativo Administrativo;

Administrativo* newAdministrativo(Object object, char* nombre, int area);
