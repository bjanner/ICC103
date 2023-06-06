#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Algoritmo
1- Definir la estructura de datos para representar una fecha.
2- Declarar los prototipos de las funciones.
3- En el programa principal, ingresar las dos fechas.
4- Llamar a la función contarDias pasando las fechas ingresadas.
5- Mostrar el resultado del cálculo de días entre las fechas. */

struct Fecha {
    int dia;
    int mes;
    int anio;
};

int esBisiesto(int anio);
int contarDias(struct Fecha fecha1, struct Fecha fecha2);


int main() {
    struct Fecha fecha1, fecha2;

    printf("Ingrese la primera fecha (DD MM AAAA): ");
    scanf("%d %d %d", &fecha1.dia, &fecha1.mes, &fecha1.anio);

    printf("Ingrese la segunda fecha (DD MM AAAA): ");
    scanf("%d %d %d", &fecha2.dia, &fecha2.mes, &fecha2.anio);

    int dias = contarDias(fecha1, fecha2);

    printf("El número de días entre las dos fechas es: %d\n", dias);

    return 0;
}

int esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}

int contarDias(struct Fecha fecha1, struct Fecha fecha2) {
    int totalDias = 0;

    while (fecha1.anio != fecha2.anio || fecha1.mes != fecha2.mes || fecha1.dia != fecha2.dia) {
        totalDias++;
        fecha1.dia++;

        if (fecha1.dia > 31 ||
            (fecha1.mes == 4 || fecha1.mes == 6 || fecha1.mes == 9 || fecha1.mes == 11) && fecha1.dia > 30 ||
            fecha1.mes == 2 && (fecha1.dia > 29 || (fecha1.dia > 28 && !esBisiesto(fecha1.anio)))) {
            fecha1.dia = 1;
            fecha1.mes++;

            if (fecha1.mes > 12) {
                fecha1.mes = 1;
                fecha1.anio++;
            }
        }
    }

    return totalDias;
}
