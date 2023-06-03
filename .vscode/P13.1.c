/*ALGORITMO
1- Leer el n�mero de cadenas a ingresar.
2- Leer cada cadena y almacenarla en una matriz de caracteres.
3-Para cada cadena, eliminar los espacios en blanco manteniendo el tama�o ajustado.
4 -Mostrar las cadenas transformadas*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 99

void eliminarEspacios(char* cadena);
int main() {
    char cadenas[MAX][MAX];
    int numCadenas;

    printf("Ingrese el n�mero de cadenas: ");
    scanf("%d", &numCadenas);


    printf("Ingrese las cadenas:\n");
    for (int i = 0; i < numCadenas; i++) {
        scanf("%s", cadenas[i]);
        eliminarEspacios(cadenas[i]);
    }

    printf("\nCadenas transformadas:\n");
    for (int i = 0; i < numCadenas; i++) {
        printf("%s\n", cadenas[i]);
    }

    return 0;
}

void eliminarEspacios(char* cadena) {
    int j = 0;
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] != ' ') {
            cadena[j] = cadena[i];
            j++;
        }
    }
    cadena[j] = '\0';
}
