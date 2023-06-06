#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Algoritmo
1 - Definir una estructura llamada "Punto" con campos "x" e "y" .
2- Declarar las funciones correspondientes.
3- En el programa principal, solicitar al usuario las coordenadas del primer y segundo punto, .
4- Calcular la distancia entre los puntos llamando a la función calcularDistancia y mostrar el resultado al usuario.
5- Obtener la ecuación de la recta que pasa por los puntos llamando a la función obtenerEcuacionRecta y mostrarla al usuario.

 */

typedef struct {
    float x;
    float y;
} Punto;

float calcularDistancia(Punto punto1, Punto punto2);
void obtenerEcuacionRecta(Punto punto1, Punto punto2);

int main() {
    Punto punto1, punto2;

    printf("Ingrese las coordenadas del primer punto (x y): ");
    scanf("%f %f", &punto1.x, &punto1.y);

    printf("Ingrese las coordenadas del segundo punto (x y): ");
    scanf("%f %f", &punto2.x, &punto2.y);

    float distancia = calcularDistancia(punto1, punto2);
    printf("La distancia entre los puntos es: %.2f\n", distancia);

    obtenerEcuacionRecta(punto1, punto2);

    return 0;
}

float calcularDistancia(Punto punto1, Punto punto2) {
    return sqrtf(powf(punto2.x - punto1.x, 2) + powf(punto2.y - punto1.y, 2));
}

void obtenerEcuacionRecta(Punto punto1, Punto punto2) {
    float pendiente = (punto2.y - punto1.y) / (punto2.x - punto1.x);
    float intercepto = punto1.y - pendiente * punto1.x;
    printf("La ecuación de la recta es: y = %.2fx + %.2f\n", pendiente, intercepto);
}
