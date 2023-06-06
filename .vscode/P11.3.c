#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Algoritmo
1- Definir la estructura de datos Cliente con los campos necesarios.
2- Declarar los prototipos las funciones que necesitare.
3- En el programa principal, solicitar al usuario el número de clientes.
4- Iterar para cada cliente e ingresar sus datos.
5- Llamar a las funciones.

 */

struct Cliente {
    char nombre[50];
    int unidades;
    float precio;
    char estado[10];
};

float calcularMontoFactura(struct Cliente cliente);
void listarClientesMorosos(struct Cliente clientes[], int numClientes);
void listarClientesPagadosMontoMayor(struct Cliente clientes[], int numClientes, float montoMinimo);

int main() {
    int numClientes;

    printf("Ingrese el número de clientes: ");
    scanf("%d", &numClientes);

    struct Cliente clientes[numClientes];

    for (int i = 0; i < numClientes; i++) {
        printf("Ingrese el nombre del cliente: ");
        scanf("%s", clientes[i].nombre);

        printf("Ingrese el número de unidades ordenadas: ");
        scanf("%d", &clientes[i].unidades);

        printf("Ingrese el precio de cada unidad: ");
        scanf("%f", &clientes[i].precio);

        printf("Ingrese el estado del cliente (moroso, pagado, mora): ");
        scanf("%s", clientes[i].estado);
    }

    listarClientesMorosos(clientes, numClientes);

    float montoMinimo;
    printf("\nIngrese un monto mínimo: ");
    scanf("%f", &montoMinimo);

    listarClientesPagadosMontoMayor(clientes, numClientes, montoMinimo);

    return 0;
}

float calcularMontoFactura(struct Cliente cliente) {
    return cliente.unidades * cliente.precio;
}

void listarClientesMorosos(struct Cliente clientes[], int numClientes) {
    printf("\nClientes en estado moroso:\n");

    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].estado, "moroso") == 0) {
            float montoFactura = calcularMontoFactura(clientes[i]);
            printf("Cliente: %s\n", clientes[i].nombre);
            printf("Monto de la Factura: %.2f\n", montoFactura);
            printf("\n");
        }
    }
}

void listarClientesPagadosMontoMayor(struct Cliente clientes[], int numClientes, float montoMinimo) {
    printf("\nClientes en estado pagado con factura mayor a %.2f:\n", montoMinimo);

    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].estado, "pagado") == 0) {
            float montoFactura = calcularMontoFactura(clientes[i]);
            if (montoFactura > montoMinimo) {
                printf("Cliente: %s\n", clientes[i].nombre);
                printf("Monto de la Factura: %.2f\n", montoFactura);
                printf("\n");
            }
        }
    }
}
