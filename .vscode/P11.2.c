#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Algoritmo
1 -Definir la estructura de datos para representar un cliente.
2- Implementar función  para calcular el monto total de la factura de un cliente.
3- En el programa principal, ingresar el número de clientes.
4- Iterar para cada cliente, ingresar sus datos y llamar a la función.
5- Mostrar el monto de la factura para cada cliente. */

#include <stdio.h>

struct Cliente {
    char nombre[50];
    int unidades;
    float precio;
    char estado[10];
};

float calcularMontoFactura(struct Cliente cliente);

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

    printf("\nFacturación de Clientes:\n");

    for (int i = 0; i < numClientes; i++) {
        float montoFactura = calcularMontoFactura(clientes[i]);
        printf("Cliente: %s\n", clientes[i].nombre);
        printf("Monto de la Factura: %.2f\n", montoFactura);
        printf("\n");
    }

    return 0;
}

float calcularMontoFactura(struct Cliente cliente) {
    float montoFactura = cliente.unidades * cliente.precio;
    if (strcmp(cliente.estado, "moro") == 0) {
        montoFactura *= 1.1;
    }
    return montoFactura;
}
