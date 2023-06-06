#include <stdio.h>
#include <stdlib.h>
/*
Algoritmo

Definir la estructura del nodo con el dato y siguiente nodo.
1- Crear función para crear nuevo nodo.
2- Crear función para insertar nodo al final de la lista.
3- Crear función para recorrer y mostrar elementos de la lista.
4- Crear función para eliminar nodos mayores a un valor dado en la lista.

*/

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void insertarNodo(Nodo** cabeza, int dato);
void mostrarLista(Nodo* cabeza);
void eliminarNodosMayores(Nodo** cabeza, int valor);


int main() {
    Nodo* cabeza = NULL;

    int i;
    for (i = 0; i < 10; i++) {
        int num = rand() % 100 + 1;
        insertarNodo(&cabeza, num);
    }


    printf("Lista original: ");
    mostrarLista(cabeza);

    int valor = 50;
    eliminarNodosMayores(&cabeza, valor);

    printf("Lista después de eliminar nodos mayores que %d: ", valor);
    mostrarLista(cabeza);

    Nodo* actual = cabeza;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }

    return 0;
}

void insertarNodo(Nodo** cabeza, int dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        Nodo* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void mostrarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

void eliminarNodosMayores(Nodo** cabeza, int valor) {
    Nodo* actual = *cabeza;
    Nodo* anterior = NULL;
    while (actual != NULL) {
        if (actual->dato > valor) {
            if (anterior == NULL) {
                *cabeza = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            actual = anterior == NULL ? *cabeza : anterior->siguiente;
        } else {
            anterior = actual;
            actual = actual->siguiente;
        }
    }
}
