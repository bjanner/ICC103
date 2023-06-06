#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 1- Crear un nuevo nodo con el dato dado y actualizar los punteros.
 2- Crear un nuevo nodo con el dato dado, actualizar el puntero siguiente del nodo anterior del extremo al nuevo nodo.*/


typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

typedef struct Bicola {
    Nodo* front;
    Nodo* end;
} Bicola;

Bicola* crearBicola() {
    Bicola* bicola = (Bicola*)malloc(sizeof(Bicola));
    bicola->front = NULL;
    bicola->end = NULL;
    return bicola;
}

void insertFront(Bicola* bicola, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    if (bicola->front == NULL) {
        bicola->front = nuevoNodo;
        bicola->end = nuevoNodo;
    } else {
        nuevoNodo->siguiente = bicola->front;
        bicola->front = nuevoNodo;
    }
}

void insertEnd(Bicola* bicola, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    if (bicola->front == NULL) {
        bicola->front = nuevoNodo;
        bicola->end = nuevoNodo;
    } else {
        bicola->end->siguiente = nuevoNodo;
        bicola->end = nuevoNodo;
    }
}

int main() {

    Bicola* bicola = crearBicola();

    insertFront(bicola, 10);
    insertFront(bicola, 20);
    insertEnd(bicola, 30);

    Nodo* nodoActual = bicola->front;
    while (nodoActual != NULL) {
        printf("%d ", nodoActual->dato);
        nodoActual = nodoActual->siguiente;
    }

    return 0;
}
