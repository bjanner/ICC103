#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Algoritmo
1- Definir la estructura del nodo con el dato y siguiente nodo.
2- Crear función para crear nuevo nodo.
3- Crear función para insertar nodo al final de la lista.
4- Crear función para recorrer y mostrar elementos de la lista.
5- Crear función para eliminar nodos mayores a un valor dado en la lista.
*/

typedef struct Nodo {
    char caracter;
    struct Nodo* siguiente;
} Nodo;

void insertarNodo(Nodo** cabeza, char caracter);
void mostrarLista(Nodo* cabeza);

int main() {
    char cadena[100];
    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin);

    Nodo* cabeza = NULL;
    for (int i = 0; i < strlen(cadena); i++) {
        insertarNodo(&cabeza, cadena[i]);
    }


    printf("Lista original: ");
    mostrarLista(cabeza);


    Nodo* actual = cabeza;
    while (actual != NULL) {
        Nodo* minimo = actual;
        Nodo* siguiente = actual->siguiente;

        while (siguiente != NULL) {
            if (siguiente->caracter < minimo->caracter) {
                minimo = siguiente;
            }
            siguiente = siguiente->siguiente;
        }

        if (minimo != actual) {
            char temp = actual->caracter;
            actual->caracter = minimo->caracter;
            minimo->caracter = temp;
        }

        actual = actual->siguiente;
    }


    printf("Lista ordenada: ");
    mostrarLista(cabeza);


    while (cabeza != NULL) {
        Nodo* siguiente = cabeza->siguiente;
        free(cabeza);
        cabeza = siguiente;
    }

    return 0;
}

void insertarNodo(Nodo** cabeza, char caracter) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->caracter = caracter;
    nuevoNodo->siguiente = NULL;

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
        printf("%c ", actual->caracter);
        actual = actual->siguiente;
    }
    printf("\n");
}
