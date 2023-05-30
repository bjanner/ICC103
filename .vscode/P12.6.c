//1-Leer la cadena//
//2-Convertir la cadena a número real//
//3-método para convertir la cadena en un número real.//
//4- mostar numero real//

#include <stdio.h>
#include <stdlib.h>

double convertir(char* cadena);
void mostrar(double numero);


int main() {
    char cadena[] = "25.56";
    double resultado = convertir(cadena);

    mostrar(resultado);

    return 0;
}

double convertir(char* cadena) {
    return atof(cadena);
}

void mostrar(double numero) {
    printf("El numero es: %f\n", numero);
}
