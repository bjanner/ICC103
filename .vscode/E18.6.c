#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Algoritmo
1- Define una estructura para representar un nodo.
2- Implementar una función para insertar un nuevo nodo.
3- Crea una función para mostrar los valores de los nodos de la lista enlazada.
4- Implementar una función para crear una nueva lista ordenada.
 */

void insertarOrdenado(Nodo** cabeza, float dato);
void imprimirLista(Nodo* cabeza);
void ordenarLista(Nodo** cabeza);

typedef struct Nodo {
    float dato;
    struct Nodo* siguiente;
} Nodo;


int main() {
    Nodo* cabeza = NULL;

    insertarOrdenado(&cabeza, 7.5);
    insertarOrdenado(&cabeza, 3.2);
    insertarOrdenado(&cabeza, 9.8);
    insertarOrdenado(&cabeza, 1.6);

    printf("Lista original: ");
    imprimirLista(cabeza);

    ordenarLista(&cabeza);

    printf("Lista ordenada: ");
    imprimirLista(cabeza);

    return 0;
}


void insertarOrdenado(Nodo** cabeza, float dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else if (dato < (*cabeza)->dato) {
        nuevoNodo->siguiente = *cabeza;
        *cabeza = nuevoNodo;
    } else {
        Nodo* actual = *cabeza;

        while (actual->siguiente != NULL && dato > actual->siguiente->dato) {
            actual = actual->siguiente;
        }

        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
}

void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;

    while (actual != NULL) {
        printf("%.2f ", actual->dato);
        actual = actual->siguiente;
    }

    printf("\n");
}

void ordenarLista(Nodo** cabeza) {
    Nodo* listaOrdenada = NULL;
    Nodo* actual = *cabeza;

    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;
        insertarOrdenado(&listaOrdenada, actual->dato);
        actual = siguiente;
    }

    *cabeza = listaOrdenada;
}
