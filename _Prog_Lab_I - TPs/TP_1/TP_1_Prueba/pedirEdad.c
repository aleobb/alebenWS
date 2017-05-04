#include "biblioteca.AOB.h"

int pedirEdad ()
{
    int edad;
    edad = obtenerInt("Ingrese la edad: ","El dato ingresado es invalido!", 0, 120);
    printf("La edad validada es: %d", edad);
    return 0
}
