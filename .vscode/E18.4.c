#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Algoritmo
1- Verificar si la lista está vacía.
2- Si la posición i es 0, actualizar la cabeza de la lista al siguiente nodo y liberar la memoria del nodo eliminado.
3- De lo contrario, recorrer la lista hasta llegar al nodo en la posición i.
4- Actualizar el enlace del nodo anterior para saltar el nodo a eliminar.
5- Liberar la memoria del nodo eliminado.
 */

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

void eliminarNodo(Nodo** cabeza, int i);

int main() {
    Nodo* cabeza = NULL;

    Nodo* nodo1 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* nodo2 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* nodo3 = (Nodo*)malloc(sizeof(Nodo));

    cabeza = nodo1;
    nodo1->dato = 1;
    nodo1->siguiente = nodo2;
    nodo2->dato = 2;
    nodo2->siguiente = nodo3;
    nodo3->dato = 3;
    nodo3->siguiente = NULL;

    eliminarNodo(&cabeza, 1);

    return 0;
}

void eliminarNodo(Nodo** cabeza, int i) {
    if (*cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    Nodo* nodoEliminar = *cabeza;

    if (i == 0) {
        *cabeza = nodoEliminar->siguiente;
    } else {
        Nodo* nodoAnterior = NULL;
        int posicion = 0;

        while (nodoEliminar != NULL && posicion < i) {
            nodoAnterior = nodoEliminar;
            nodoEliminar = nodoEliminar->siguiente;
            posicion++;
        }

        if (nodoEliminar == NULL) {
            printf("La posición %d está fuera de rango.\n", i);
            return;
        }

        nodoAnterior->siguiente = nodoEliminar->siguiente;
    }

    free(nodoEliminar);
    printf("Nodo eliminado en la posición %d.\n", i);
}
