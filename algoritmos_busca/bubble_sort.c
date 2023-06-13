#include <stdio.h>
#include <stdlib.h>
void bubble(int array[], int n) {

    int i, j, aux;

    for (i = 0; i < n-1; i++) {

        for (j = 0; j < n-i-1; j++) { //vai diminuindo o array 

            if (array[j] > array[j+1]) {
                // troca os elementos se estiverem na ordem errada
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }
        }
    }

    printf("\nsaiu assim:\n");
    for(int i= 0; i < 10; i++){printf("%d ", array[i]);}
}

int main()
{
    int array[10];
    for(int i= 0; i< 10; i++){scanf("%d", &array[i]);}

    printf("entrou assim:\n");
    for(int i= 0; i < 10; i++){printf("%d ", array[i]);}

    bubble(array,10);



}

// VERSAO MELHORADA
#include <stdio.h>
#include <stdlib.h>

void bubble(int array[], int n) {
    int i, j, aux;
    int trocas;

    for (i = 0; i < n - 1; i++) {
        trocas = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                trocas = 1;
            }
        }


        if (trocas == 0) {
            // Nenhuma troca ocorreu nesta iteração, o array está ordenado
            break;
        }



        
    }

    printf("\nsaiu assim:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}

