/*1- Lee dos números grandes como cadenas de caracteres.
2 - Inicializa dos estructuras para representar los números grandes, almacenando los dígitos en arreglos dinámicos.
3- Suma los dígitos de ambos números, teniendo en cuenta el acarreo.
4- Crea una nueva estructura para el resultado, con suficiente espacio para los dígitos obtenidos.
5- Imprime el resultado de la suma de los números grandes.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* digitos;
    int numDigitos;
} NumeroGrande;

NumeroGrande* inicializarNumeroGrande(char* numero) {
    int longitud = strlen(numero);

    NumeroGrande* numeroGrande = (NumeroGrande*)malloc(sizeof(NumeroGrande));
    numeroGrande->digitos = (int*)malloc(longitud * sizeof(int));
    numeroGrande->numDigitos = longitud;

    for (int i = 0; i < longitud; i++) {
        numeroGrande->digitos[i] = numero[i] - '0';
    }

    return numeroGrande;
}

NumeroGrande* sumarNumerosGrandes(NumeroGrande* num1, NumeroGrande* num2) {
    int maxDigitos = (num1->numDigitos > num2->numDigitos) ? num1->numDigitos : num2->numDigitos;
    int carry = 0;

    NumeroGrande* resultado = (NumeroGrande*)malloc(sizeof(NumeroGrande));
    resultado->digitos = (int*)malloc((maxDigitos + 1) * sizeof(int));
    resultado->numDigitos = maxDigitos;

    for (int i = 0; i < maxDigitos; i++) {
        int suma = carry;

        if (i < num1->numDigitos) {
            suma += num1->digitos[num1->numDigitos - 1 - i];
        }

        if (i < num2->numDigitos) {
            suma += num2->digitos[num2->numDigitos - 1 - i];
        }

        resultado->digitos[maxDigitos - 1 - i] = suma % 10;
        carry = suma / 10;
    }

    if (carry > 0) {
        resultado->numDigitos++;
        resultado->digitos = (int*)realloc(resultado->digitos, (maxDigitos + 1) * sizeof(int));
        resultado->digitos[0] = carry;
    }

    return resultado;
}

void liberarNumeroGrande(NumeroGrande* numeroGrande) {
    free(numeroGrande->digitos);
    free(numeroGrande);
}

int main() {
    char numero1[] = "234567890";
    char numero2[] = "989943210";

    NumeroGrande* num1 = inicializarNumeroGrande(numero1);
    NumeroGrande* num2 = inicializarNumeroGrande(numero2);

    NumeroGrande* suma = sumarNumerosGrandes(num1, num2);

    printf("La suma es: ");
    for (int i = 0; i < suma->numDigitos; i++) {
        printf("%d", suma->digitos[i]);
    }
    printf("\n");

    liberarNumeroGrande(num1);
    liberarNumeroGrande(num2);
    liberarNumeroGrande(suma);

    return 0;
}
