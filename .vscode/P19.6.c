#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMEROS 100

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

void encolar(struct Nodo** cola, int dato);
int desencolar(struct Nodo** cola);

int main() {
    struct Nodo* cola = NULL;
    srand(time(NULL));

    for (int i = 0; i < MAX_NUMEROS; i++) {
        int numero = rand() % 51 - 25;
        encolar(&cola, numero);
    }

    printf("Números generados:\n");
    while (cola != NULL) {
        int numero = desencolar(&cola);
        printf("%d ", numero);
    }

    return 0;
}

void encolar(struct Nodo** cola, int dato) {
    struct Nodo* nuevoNodo = malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    if (*cola == NULL) {
        *cola = nuevoNodo;
    } else {
        struct Nodo* actual = *cola;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

int desencolar(struct Nodo** cola) {
    if (*cola == NULL) {
        printf("La cola está vacía.\n");
        return 0;
    }
    struct Nodo* temp = *cola;
    int dato = temp->dato;
    *cola = temp->siguiente;
    free(temp);
    return dato;
}

