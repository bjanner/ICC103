#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Nodo {
    char dato;
    struct Nodo* siguiente;
};


void push(struct Nodo** pila, char dato);
char pop(struct Nodo** pila);
void procesarExpresion(char* expresion);

int main() {
    char expresion[100];

    printf("Ingrese una expresion: ");
    fgets(expresion, sizeof(expresion), stdin);


    procesarExpresion(expresion);

    return 0;
}

void push(struct Nodo** pila, char dato) {
    struct Nodo* nuevoNodo = malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
}

char pop(struct Nodo** pila) {
    if (*pila == NULL) {
        printf("La pila esta vacia.\n");
        return '\0';
    }
    struct Nodo* temp = *pila;
    char dato = temp->dato;
    *pila = temp->siguiente;
    free(temp);
    return dato;
}

void procesarExpresion(char* expresion) {
    struct Nodo* pila = NULL;
    int i = 0;


    while (expresion[i] != '\0') {
        char caracter = expresion[i];

        if (caracter == '(' || caracter == '[' || caracter == '{') {
            push(&pila, caracter);
        } else if (caracter == ')' || caracter == ']' || caracter == '}') {
            char ultimoCaracter = pop(&pila);
            if ((caracter == ')' && ultimoCaracter != '(') ||
                (caracter == ']' && ultimoCaracter != '[') ||
                (caracter == '}' && ultimoCaracter != '{')) {
                printf("La expresion no esta balanceada.\n");
                return;
            }
        }

        i++;
    }

    if (pila == NULL) {
        printf("La expresion esta balanceada.\n");
    } else {
        printf("La expresion no esta balanceada.\n");
    }
}
