#include <stdio.h>
#include <stdlib.h>
/*
Algoritmo
1- Verificar si la lista está vacía o solo tiene un nodo.
2- Inicializar dos punteros.
3- Recorrer la lista hasta que se llegue al final.
4- Si el sexo del nodo actual es masculino y el sexo del siguiente nodo es femenino, insertar un nuevo nodo femenino entre ambos.
5- Actualizar los punteros para avanzar en la lista y repetir el proceso hasta alcanzar el final.

*/

void intercalarAlumnos(Alumno* cabeza);
void imprimirLista(Alumno* cabeza);

typedef struct Alumno {
    char nombre[50];
    int edad;
    char sexo;
    struct Alumno* siguiente;
} Alumno;


int main() {

    Alumno* cabeza = (Alumno*)malloc(sizeof(Alumno));
    cabeza->sexo = 'M';

    Alumno* segundo = (Alumno*)malloc(sizeof(Alumno));
    segundo->sexo = 'F';

    Alumno* tercero = (Alumno*)malloc(sizeof(Alumno));
    tercero->sexo = 'M';

    Alumno* cuarto = (Alumno*)malloc(sizeof(Alumno));
    cuarto->sexo = 'F';

    cabeza->siguiente = segundo;
    segundo->siguiente = tercero;
    tercero->siguiente = cuarto;
    cuarto->siguiente = NULL;


    printf("Lista original:\n");
    imprimirLista(cabeza);


    intercalarAlumnos(cabeza);


    printf("Lista transformada:\n");
    imprimirLista(cabeza);


    Alumno* actual = cabeza;
    while (actual != NULL) {
        Alumno* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }

    return 0;
}

void intercalarAlumnos(Alumno* cabeza) {
    if (cabeza == NULL || cabeza->siguiente == NULL) {
        return;
    }

    Alumno* actual = cabeza;
    Alumno* siguiente = cabeza->siguiente;

    while (siguiente != NULL) {
        if (actual->sexo == 'M' && siguiente->sexo == 'F') {
            Alumno* nuevoNodo = (Alumno*)malloc(sizeof(Alumno));
            nuevoNodo->sexo = 'F';
            nuevoNodo->siguiente = siguiente;
            actual->siguiente = nuevoNodo;
        }

        actual = siguiente;
        siguiente = siguiente->siguiente;
    }
}

void imprimirLista(Alumno* cabeza) {
    Alumno* actual = cabeza;

    while (actual != NULL) {
        printf("Nombre: %s, Edad: %d, Sexo: %c\n", actual->nombre, actual->edad, actual->sexo);
        actual = actual->siguiente;
    }

    printf("\n");
}
