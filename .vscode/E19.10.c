#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};


void empujar(struct Nodo** cima, int dato);
int desempujar(struct Nodo** cima);
void encolar(struct Nodo** frente, struct Nodo** final, int dato);

int main() {
    struct Nodo* pila = NULL;
    struct Nodo* colaFrente = NULL;
    struct Nodo* colaFinal = NULL;


    empujar(&pila, 1);
    empujar(&pila, 2);
    empujar(&pila, 3);
    empujar(&pila, 4);
    empujar(&pila, 5);


    while (pila != NULL) {
        int num = desempujar(&pila);
        if (num % 2 == 0) {
            encolar(&colaFrente, &colaFinal, num);
        }
    }


    printf("Elementos pares en la cola: ");
    while (colaFrente != NULL) {
        int num = desempujar(&colaFrente);
        printf("%d ", num);
    }

    return 0;
}


void empujar(struct Nodo** cima, int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = *cima;
    *cima = nuevoNodo;
}


int desempujar(struct Nodo** cima) {
    if (*cima == NULL) {
        printf("Pila vacía\n");
        return -1;
    }
    struct Nodo* temp = *cima;
    int dato = temp->dato;
    *cima = temp->siguiente;
    free(temp);
    return dato;
}

void encolar(struct Nodo** frente, struct Nodo** final, int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    if (*frente == NULL) {
        *frente = nuevoNodo;
    } else {
        (*final)->siguiente = nuevoNodo;
    }
    *final = nuevoNodo;
}
