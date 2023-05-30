/*Un array unidimecional se puede indexar con arritmetica de punteros.
Que tipo de puntero habria que definir para indexar un array unidimecional?
- Se tendria que declarar un puntero a entero (*int).*/
#include <stdio.h>
#include <stdlib.h>
int main (){
    int array[]={1,2,3,4?};
    int *pointer = array;
    printf("%d\n", *(pointer + 2)); //Imprime tercer elemento//

    return 0;
}