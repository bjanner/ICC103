/*Escribir una funcion con un argumento tipo puntero a double y otro
argumeno de tipo int. El primer arguemnto se debe corresponder con un
array y el segundo con el numero de elementos del array. La funcion debe
ser de tipo puntero a double para devolver la direccion del elemnto menor.*/
#include <stdio.h>
#include <stdlib.h>
double *encontrarMenor(double *array, int longitud) {
    double *menor = array; 
    for (int i = 1; i < longitud; i++) {
        if (array[i] < *menor) {
            menor = &array[i]; 
        }
    }
    return menor;
}

int main() {
    double array[] = {4.2, 2.5, 6.1, 1.8, 3.9};
    int longitud = sizeof(array) / sizeof(double);

    double* direccionMenor = encontrarMenor(array, longitud);

    printf("El elemento menor es %.2f y su dirección es %p\n", *direccionMenor, (void*)direccionMenor);

    return 0;
}