#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Algoritmo
1- Representar los nodos de la lista enlazada.
2- Implementar la función para contar nodos.
3- Inicializar un contador en 0 y un puntero actual apuntando a la cabeza de la lista.
4 -Mientras el puntero actual no sea NULL, incrementar el contador en 1 y avanzar al siguiente nodo.
5- Devolver el valor del contador.
 */

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

int contarNodos(Nodo* cabeza);

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

    int numeroNodos = contarNodos(cabeza);
    printf("El número de nodos de la lista es: %d\n", numeroNodos);

    return 0;
}

int contarNodos(Nodo* cabeza) {
    int contador = 0;

    while (cabeza != NULL) {
        contador++;
        cabeza = cabeza->siguiente;
    }

    return contador;
}
