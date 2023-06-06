#include <stdio.h>
#include <string.h>

#define MAX_MATERIAS 10

/*
Algoritmo
1- Definir las estructuras de datos para Estudiante, Docente y Persona.
2 - Crear funciones para ingresar los datos de Estudiante, Docente y Persona.
3- Crear funciones para mostrar los datos de Estudiante, Docente y Persona.
4- En el programa principal, llamar a las funciones de ingreso para cada tipo de entidad.
5- En el programa principal, llamar a las funciones de mostrar para cada tipo de entidad.
*/

struct Estudiante {
    char nombreCurso[50];
    int edad;
    char direccion[100];
    float calificaciones[MAX_MATERIAS];
};

struct Docente {
    char nombreMateria[50];
    char direccion[100];
};

struct Persona {
    char nombre[50];
    int edad;
    char direccion[100];
};

void ingresarEstudiante(struct Estudiante* estudiante);
void ingresarDocente(struct Docente* docente);
void ingresarPersona(struct Persona* persona);
void mostrarEstudiante(struct Estudiante estudiante);
void mostrarDocente(struct Docente docente);
void mostrarPersona(struct Persona persona);

int main() {
    struct Estudiante estudiante;
    struct Docente docente;
    struct Persona persona;

    ingresarEstudiante(&estudiante);
    ingresarDocente(&docente);
    ingresarPersona(&persona);

    mostrarEstudiante(estudiante);
    mostrarDocente(docente);
    mostrarPersona(persona);

    return 0;
}

void ingresarEstudiante(struct Estudiante* estudiante) {
    printf("Ingrese los datos del estudiante:\n");
    printf("Nombre del curso: ");
    scanf("%s", estudiante->nombreCurso);

    printf("Edad: ");
    scanf("%d", &(estudiante->edad));

    printf("Dirección: ");
    scanf("%s", estudiante->direccion);

    printf("Calificaciones de las materias:\n");
    for (int i = 0; i < MAX_MATERIAS; i++) {
        printf("Materia %d: ", i + 1);
        scanf("%f", &(estudiante->calificaciones[i]));
    }
}

void ingresarDocente(struct Docente* docente) {
    printf("\nIngrese los datos del docente:\n");
    printf("Nombre de la materia que imparte: ");
    scanf("%s", docente->nombreMateria);

    printf("Dirección: ");
    scanf("%s", docente->direccion);
}

void ingresarPersona(struct Persona* persona) {
    printf("\nIngrese los datos de un profesor o un alumno:\n");
    printf("Nombre: ");
    scanf("%s", persona->nombre);

    printf("Edad: ");
    scanf("%d", &(persona->edad));

    printf("Dirección: ");
    scanf("%s", persona->direccion);
}

void mostrarEstudiante(struct Estudiante estudiante) {
    printf("\n Datos del estudiante \n");
    printf("Nombre del curso: %s\n", estudiante.nombreCurso);
    printf("Edad: %d\n", estudiante.edad);
    printf("Dirección: %s\n", estudiante.direccion);
    printf("Calificaciones de las materias:\n");
    for (int i = 0; i < MAX_MATERIAS; i++) {
        printf("Materia %d: %.2f\n", i + 1, estudiante.calificaciones[i]);
    }
}

void mostrarDocente(struct Docente docente) {
    printf("\n Datos del docente \n");
    printf("Nombre de la materia que imparte: %s\n", docente.nombreMateria);
    printf("Dirección: %s\n", docente.direccion);
}

void mostrarPersona(struct Persona persona) {
    printf("\n Datos de la persona \n");
    printf("Nombre: %s\n", persona.nombre);
    printf("Edad: %d\n", persona.edad);
    printf("Dirección: %s\n", persona.direccion);
}

