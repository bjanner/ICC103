//1-Leer la cadena//
//2-Convertir la cadena a n�mero real//
//3-m�todo para convertir la cadena en un n�mero real.//
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
