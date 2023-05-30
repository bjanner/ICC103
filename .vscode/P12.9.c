/*Algortimo
1-Declarar las funciones para calcular el área de cada figura geométrica.
2- Declarar un array de punteros a funciones utilizando el tipo definido FuncionArea.
3- Solicitar al usuario la opción de la figura geométrica y las dimensiones necesarias.
4- Utilizar el puntero a la función correspondiente según la opción ingresada para calcular el área.
5- Imprimir el área de la figura seleccionada.*/


#include <stdio.h>
#include <stdlib.h>

float areaTri(float base, float altura);
float areaRec(float base, float altura);
float areaTriIso(float base, float altura);
float areaCua(float lado);
float areaTrap(float baseMayor, float baseMenor, float altura);
float areaCirc(float radio);

typedef float (*FuncionArea)(float, float);

int main() {
    float base, altura, lado, baseMayor, baseMenor, radio;
    FuncionArea funcionesArea[] = {
        areaTri,
        areaRec,
        areaTriIso,
        areaCua,
        areaTrap,
        areaCirc
    };

    int opcion;
    printf("Ingrese la opción de la figura geometrica (1-6): ");
    scanf("%d", &opcion);

    if (opcion < 1 || opcion > 6) {
        printf("Opción inválida.\n");
        return 1;
    }

    switch (opcion) {
        case 1:
            printf("Ingrese la base y la altura del triangulo: ");
            scanf("%f %f", &base, &altura);
            break;
        case 2:
            printf("Ingrese la base y la altura del rectangulo: ");
            scanf("%f %f", &base, &altura);
            break;
        case 3:
            printf("Ingrese la base y la altura del triangulo isósceles: ");
            scanf("%f %f", &base, &altura);
            break;
        case 4:
            printf("Ingrese el lado del cuadrado: ");
            scanf("%f", &lado);
            break;
        case 5:
            printf("Ingrese la base mayor, la base menor y la altura del trapecio: ");
            scanf("%f %f %f", &baseMayor, &baseMenor, &altura);
            break;
        case 6:
            printf("Ingrese el radio del circulo: ");
            scanf("%f", &radio);
            break;
    }

    float area = funcionesArea[opcion - 1](base, altura);
    printf("El área de la figura seleccionada es: %.2f\n", area);

    return 0;
}

float areaTri(float base, float altura) {
    return (base * altura) / 2;
}

float areaRec(float base, float altura) {
    return base * altura;
}

float areaTriIso(float base, float altura) {
    return (base * altura) / 2;
}

float areaCua(float lado) {
    return lado * lado;
}

float areaTrap(float baseMayor, float baseMenor, float altura) {
    return ((baseMayor + baseMenor) * altura) / 2;
}

float areaCirc(float radio) {
    return 3.14 * radio * radio;
}
