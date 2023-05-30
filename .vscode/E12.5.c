//Acceder a los elementos de la matriz utilizando nomenclatura de punteros//
#include <stdio.h>
#include <stdlib.h>
#define N 4
#define M 5
int main (){
    int f=0,c=0;
    double mt [N][M];
    double *p = mt;

    for (f=0; f<N; f++){
         for (c=0; c<M; f++){
            printf("%lf", *p);
            p++;
         }
    }

   

    return 0;
}