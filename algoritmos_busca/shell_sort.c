#include <stdio.h>

void shell(int array[], int n) {
    // Define o intervalo inicial (gap)
    int gap = n / 2;

    // Loop através dos intervalos (gaps) até que o gap seja 1
    while (gap > 0) {
        // Aplica o algoritmo de inserção para cada sublista com o gap atual
        for (int i = gap; i < n; i++) {
            int chave = array[i];
            int j = i;

            // Move os elementos maiores que a chave para a frente
            while (j >= gap && array[j - gap] > chave) {
                array[j] = array[j - gap];
                j -= gap;
            }

            // Insere a chave na posição correta
            array[j] = chave;
        }

        // Reduz o gap pela metade
        gap /= 2;
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

    shell(array,10);



}
