/*Algoritmo
1 - Define un arreglo de entrada con 20 elementos enteros.
2 - Crea una matriz dinámica vacía.
3- Recorre el arreglo de entrada y verifica si cada elemento ya existe en la matriz.
4- Si el elemento no está repetido, agrégalo como una nueva fila a la matriz.
5- Muestra en pantalla las filas de la matriz que contienen los elementos no repetidos.
*/
#include <stdio.h>
#include <stdlib.h>

int** generarMatriz(int* entrada);
void mostrarMatriz(int** matriz);
void liberarMatriz(int** matriz);

int main() {
    int entrada[20] = {1, 2, 3, 4, 5, 6, 2, 4, 6, 8, 10, 12, 1, 3, 5, 7, 9, 11, 13, 15};

    int** resultado = generarMatriz(entrada);

    mostrarMatriz(resultado);

    liberarMatriz(resultado);

    return 0;
}

int** generarMatriz(int* entrada) {
    int** resultado = (int**)malloc(20 * sizeof(int*));
    int numFilas = 0;

    for (int i = 0; i < 20; i++) {
        int repetido = 0;

        for (int j = 0; j < numFilas; j++) {
            if (entrada[i] == resultado[j][0]) {
                repetido = 1;
                break;
            }
        }

        if (!repetido) {
            resultado[numFilas] = (int*)malloc(sizeof(int));
            resultado[numFilas][0] = entrada[i];
            numFilas++;
        }
    }

    return resultado;
}

void mostrarMatriz(int** matriz) {
    for (int i = 0; i < 20; i++) {
        if (matriz[i] != NULL) {
            printf("Fila %d: %d\n", i, matriz[i][0]);
        }
    }
}

void liberarMatriz(int** matriz) {
    for (int i = 0; i < 20; i++) {
        if (matriz[i] != NULL) {
            free(matriz[i]);
        }
    }
    free(matriz);
}
