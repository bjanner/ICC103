#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/* Algoritmo
1- Definir una estructura llamada para representar los elementos de la lista enlazada.
2- Implementar la funci�n que recibe como par�metro un puntero a la cabeza de la lista enlazada.
3- Verificar si el puntero de cabeza es igual a NULL.
4- Si el puntero de cabeza es NULL, retornar 0 para indicar que la lista est� vac�a.
 */

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

int estaVacia(Nodo* cabeza) {
    if (cabeza == NULL) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    Nodo* cabeza = NULL; // Lista vac�a

    if (estaVacia(cabeza) == 0) {
        printf("La lista est� vac�a.\n");
    } else {
        printf("La lista no est� vac�a.\n");
    }

    return 0;
}
