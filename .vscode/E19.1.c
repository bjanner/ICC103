#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef PILA_H
#define PILA_H

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

typedef struct Pila {
    Nodo* tope;
} Pila;

Pila* crearPila();
int estaVacia(Pila* pila);
int obtenerTope(Pila* pila);
void apilar(Pila* pila, int dato);
int desapilar(Pila* pila);
void vaciarPila(Pila* pila);
void liberarPila(Pila* pila);

#endif // PILA_H
