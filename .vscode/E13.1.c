
#include <stdio.h>
#include <stdlib.h>

int main() {
   int n, *p;
   char ** dob = "cadena de los punteros"; // Error: dob se declara como un puntero a puntero a char, pero se le asigna una cadena de caracteres directamente

   p = n * malloc(sizeof(int)); // Error: Operaci�n incorrecta en la asignaci�n de p

   return 0;
}

