//1-Definar las 3 funciones//
//2-Declarar variables necesarias//
//3-Bucle para iterar el rango establecido//
//4- Evaluacion de funciones en el bucle//
//5-Mostrar los resultados//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x);
double g(double x);
double h(double x);


int main() {
    double x, increase =0.2, limit = 3.5;
    
    for (x = 0.0; x < limit; x += increase) {
        double (*funciones[])(double) = {f, g, h};
        int num_funciones = sizeof(funciones) / sizeof(funciones[0]);

        for (int i = 0; i < num_funciones; i++) {
            double resultado = funciones[i](x);
            printf("f%d(%.1f) = %.2f\t", i+1, x, resultado);
        }
     }


            
  return 0;
 }

double f(double x){
    return 3 * exp(x) - 2 * x;

}
double g(double x){
    return  -x * sin(x) + 1.5 ;

}

double h(double x){
    return x * x - 2 * x + 3;

}      