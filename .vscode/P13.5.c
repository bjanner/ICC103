//ALGORITMO//
//1-Definar las variables y funciones//
//2-Declarar variables necesarias//
//3-Leer los dos valores//
//4- Sumar los nuleros//
//5-Mostrar el resultados//


#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 40

void sumarNumerosGrandes(char* numero1, char* numero2, char* resultado) {
    int aux = 0;
    int longitud1 = strlen(numero1);
    int longitud2 = strlen(numero2);
    int longitudMaxima = (longitud1 > longitud2) ? longitud1 : longitud2;

    int i;
    for (i = 0; i < longitudMaxima; i++) {
        int digito1 = (i < longitud1) ? (numero1[longitud1 - i - 1] - '0') : 0;
        int digito2 = (i < longitud2) ? (numero2[longitud2 - i - 1] - '0') : 0;

        int suma = digito1 + digito2 + aux;
        aux = suma / 10;
        resultado[i] = (suma % 10) + '0';
    }

    if (aux > 0) {
        resultado[longitudMaxima] = aux + '0';
        resultado[longitudMaxima + 1] = '\0';
    } else {
        resultado[longitudMaxima] = '\0';
    }

    for (i = 0; i < longitudMaxima / 2; i++) {
        char temp = resultado[i];
        resultado[i] = resultado[longitudMaxima - i - 1];
        resultado[longitudMaxima - i - 1] = temp;
    }
}

int main() {
    char numero1[MAX_DIGITS + 1];
    char numero2[MAX_DIGITS + 1];
    char resultado[MAX_DIGITS + 2];

    printf("Ingrese el primer número: ");
    scanf("%s", numero1);

    printf("Ingrese el segundo número: ");
    scanf("%s", numero2);

    sumarNumerosGrandes(numero1, numero2, resultado);

    printf("La suma es: %s\n", resultado);

    return 0;
}
