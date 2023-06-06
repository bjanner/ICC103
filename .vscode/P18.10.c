#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Algoritmo
Declarar la estructura Pasajero .
Crear una  función para crear Pasajero.
Crear una función insertar Pasajero
Crear una función mostrar Pasajeros.
Crear una la función para buscar Pasajero.
*/

Pasajero* crearPasajero(char nombre[], int edad, char destino[]);
void insertarPasajero(Pasajero** cabeza, Pasajero* nuevoPasajero);
void mostrarPasajeros(Pasajero* cabeza);
Pasajero* buscarPasajero(Pasajero* cabeza, char nombre[]);

int main() {
    Pasajero* cabeza = NULL;
    int opcion;
    do {
        printf("\nMENU\n");
        printf("1. Agregar pasajero\n");
        printf("2. Mostrar lista de pasajeros\n");
        printf("3. Buscar pasajero\n");
        printf("4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                char nombre[50];
                int edad;
                char destino[50];

                printf("\nIngrese el nombre del pasajero: ");
                scanf("%s", nombre);
                printf("Ingrese la edad del pasajero: ");
                scanf("%d", &edad);
                printf("Ingrese el destino del pasajero: ");
                scanf("%s", destino);

                Pasajero* nuevoPasajero = crearPasajero(nombre, edad, destino);
                insertarPasajero(&cabeza, nuevoPasajero);
                printf("Pasajero agregado exitosamente.\n");
                break;

            case 2:
                printf("\nLISTA DE PASAJEROS\n");
                mostrarPasajeros(cabeza);
                break;

            case 3:
                printf("\nIngrese el nombre del pasajero a buscar: ");
                scanf("%s", nombre);
                Pasajero* pasajeroEncontrado = buscarPasajero(cabeza, nombre);
                if (pasajeroEncontrado != NULL) {
                    printf("\nDATOS DEL PASAJERO\n");
                    printf("Nombre: %s\n", pasajeroEncontrado->nombre);
                    printf("Edad: %d\n", pasajeroEncontrado->edad);
                    printf("Destino: %s\n", pasajeroEncontrado->destino);
                } else {
                    printf("\nEl pasajero no se encuentra en la lista.\n");
                }
                break;

            case 4:
                printf("\nSaliendo del programa...\n");
                break;

            default:
                printf("\nOpcion invalida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 4);

    while (cabeza != NULL) {
        Pasajero* siguiente = cabeza->siguiente;
        free(cabeza);
        cabeza = siguiente;
    }

    return 0;
}

Pasajero* crearPasajero(char nombre[], int edad, char destino[]) {
    Pasajero* nuevoPasajero = (Pasajero*)malloc(sizeof(Pasajero));
    strcpy(nuevoPasajero->nombre, nombre);
    nuevoPasajero->
