#include <stdio.h>
#include <stdlib.h>
int main (){
    float mt[5][5]; // Matriz cuadrada //
    float *m[5]; // Arreglo de punteros //

    // Se pueden hacer estas asignciones ?//

    m = mt; 
    m[1] = m[1]; // Esta asignacion no tiene ningun efecto, ya que ambas son las mismas direciones
    m[2] = &mt[2][0];

    return 0;
}