#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

void push(struct Nodo** pila, int dato);
int pop(struct Nodo** pila);
void copiarPila(struct Nodo** pilaOrigen, struct Nodo** pilaDestino);

int main() {
    struct Nodo* pilaOrigen = NULL;
    struct Nodo* pilaDestino = NULL;

    push(&pilaOrigen, 1);
    push(&pilaOrigen, 2);
    push(&pilaOrigen, 3);
    push(&pilaOrigen, 4);
    push(&pilaOrigen, 5);


    copiarPila(&pilaOrigen, &pilaDestino);

    printf("Contenido de la pila de destino: ");
    while (pilaDestino != NULL) {
        int dato = pop(&pilaDestino);
        printf("%d ", dato);
    }

    return 0;
}

void push(struct Nodo** pila, int dato) {
    struct Nodo* nuevoNodo = malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
}

int pop(struct Nodo** pila) {
    if (*pila == NULL) {
        printf("La pila está vacía.\n");
        return -1;
    }
    struct Nodo* temp = *pila;
    int dato = temp->dato;
    *pila = temp->siguiente;
    free(temp);
    return dato;
}

void copiarPila(struct Nodo** pilaOrigen, struct Nodo** pilaDestino) {
    while (*pilaOrigen != NULL) {
        int dato = pop(pilaOrigen);
        push(pilaDestino, dato);
    }
}
