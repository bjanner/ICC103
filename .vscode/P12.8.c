/*ALGORITMO
1-Declarar una estructura Paciente con campos para el nombre, dirección, fecha de nacimiento, sexo, día de visita y problema.
2- Declarar una variable de tipo Paciente para almacenar la información del paciente.
3- Solicitar al usuario que ingrese los datos del paciente
4- Mostrar la información del paciente ingresado.*/


#include <stdio.h>
#include <stdlib.h>

struct Paciente {
    char nombre[50];
    char direccion[100];
    char fecha[20];
    char sexo;
    int dia;
    char problema[100];
};

int main() {
    struct Paciente p;

    printf("Nombre: ");
    fgets(p.nombre, sizeof(p.nombre), stdin);

    printf("Direccion: ");
    fgets(p.direccion, sizeof(p.direccion), stdin);

    printf("Fecha Nacimiento: ");
    fgets(p.fecha, sizeof(p.fecha), stdin);

    printf("Sexo (M/F): ");
    scanf("%c", &p.sexo);

    printf("Dia de la visita: ");
    scanf("%d", &p.dia);

    printf("Problema: ");
    getchar();
    fgets(p.problema, sizeof(p.problema), stdin);

    printf("\nInformacion del paciente:\n");
    printf("Nombre: %s", p.nombre);
    printf("Direccion: %s", p.direccion);
    printf("Fecha Nacimiento: %s", p.fecha);
    printf("Sexo: %c\n", p.sexo);
    printf("Dia de la visita: %d\n", p.dia);
    printf("Problema: %s", p.problema);

    return 0;
}
