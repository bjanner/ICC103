#include <stdio.h>
#include <stdlib.h>
//1-Declarar una matriz de caracteres//
//2-Captuarar el texto//
//3-Usar un blucle para recorrer el texto//
//4- Craer un contador de voacales//
//5-Mostar en pantalla la cantidad de vocales//

int main() {
    char linea[81];
    int i;
    printf("Ingrese 20 líneas de texto (máximo 80 caracteres cada una):\n");
    for (i =0; i <20; i++){
        fgets(linea, sizeof(linea), stdin);

        int cont= 0;
        char *p = linea;
        while (*p != '\0'){
            if (*p =='a' ||*p =='e' ||*p =='i' ||*p =='o' ||*p =='u' ||
            *p =='A' ||*p =='E' ||*p =='I' ||*p =='O' ||*p =='U' ){
                cont++;
            }
            p++;
        }
         printf("Linea %d : %d \n", i+1,cont);
    }

   


    return 0;
}