#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Algoritmo
1- Definir una estructura llamada "Complejo" con campos "real" e "imaginario".
2- Declarar los prototipos de las funciones para realizar las operaciones de suma, resta, multiplicación y división de complejos.
3- En el programa principal, solicitar al usuario ingresar dos números complejos.
4- Llamar a las funciones correspondientes para realizar las operaciones y almacenar los resultados en una variable.
5- Mostrar los resultados de las operaciones al usuario

 */

typedef struct {
    float real;
    float imaginario;
} Complejo;

Complejo sumarComplejos(Complejo num1, Complejo num2);
Complejo restarComplejos(Complejo num1, Complejo num2);
Complejo multiplicarComplejos(Complejo num1, Complejo num2);
Complejo dividirComplejos(Complejo num1, Complejo num2);
void imprimirComplejo(Complejo num);

int main();

Complejo sumarComplejos(Complejo num1, Complejo num2) {
    Complejo resultado;
    resultado.real = num1.real + num2.real;
    resultado.imaginario = num1.imaginario + num2.imaginario;
    return resultado;
}

Complejo restarComplejos(Complejo num1, Complejo num2) {
    Complejo resultado;
    resultado.real = num1.real - num2.real;
    resultado.imaginario = num1.imaginario - num2.imaginario;
    return resultado;
}

Complejo multiplicarComplejos(Complejo num1, Complejo num2) {
    Complejo resultado;
    resultado.real = (num1.real * num2.real) - (num1.imaginario * num2.imaginario);
    resultado.imaginario = (num1.real * num2.imaginario) + (num1.imaginario * num2.real);
    return resultado;
}

Complejo dividirComplejos(Complejo num1, Complejo num2) {
    Complejo resultado;
    float divisor = (num2.real * num2.real) + (num2.imaginario * num2.imaginario);
    resultado.real = ((num1.real * num2.real) + (num1.imaginario * num2.imaginario)) / divisor;
    resultado.imaginario = ((num1.imaginario * num2.real) - (num1.real * num2.imaginario)) / divisor;
    return resultado;
}

void imprimirComplejo(Complejo num) {
    printf("%.2f + %.2fi\n", num.real, num.imaginario);
}

int main() {
    Complejo num1, num2, resultado;

    printf("Ingrese el primer número complejo (parte real y parte imaginaria): ");
    scanf("%f %f", &num1.real, &num1.imaginario);

    printf("Ingrese el segundo número complejo (parte real y parte imaginaria): ");
    scanf("%f %f", &num2.real, &num2.imaginario);

    resultado = sumarComplejos(num1, num2);
    printf("Suma: ");
    imprimirComplejo(resultado);

    resultado = restarComplejos(num1, num2);
    printf("Resta: ");
    imprimirComplejo(resultado);

    resultado = multiplicarComplejos(num1, num2);
    printf("Multiplicación: ");
    imprimirComplejo(resultado);

    resultado = dividirComplejos(num1, num2);
    printf("División: ");
    imprimirComplejo(resultado);

    return 0;
}
