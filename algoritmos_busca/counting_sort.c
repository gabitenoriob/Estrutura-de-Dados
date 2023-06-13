#include <stdio.h>

void counting(int array[], int n, int max) {
    // Cria um array de contagem com tamanho igual ao valor máximo mais um
    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Conta a ocorrência de cada elemento no array
    for (int i = 0; i < n; i++) {
        count[array[i]]++;
    }

    // Atualiza o array de contagem para refletir a posição correta de cada elemento na saída
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Constrói o array de saída
    int saida[n];
    // aqui ele vai de tras p frente , diminuindo cada contador de cada indice 
    for (int i = n - 1; i >= 0; i--) {
        saida[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copia o array de saída para o array original
    for (int i = 0; i < n; i++) {
        array[i] = saida[i];
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

    int max = array[0];
    for (int i = 1; i < 10; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    counting(array,10,max);



}

//VERSÃO MELHORADA
#include <stdio.h>

void countingSort(int array[], int n) {
    // Encontra o valor máximo no array
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    // Cria um array de contagem com tamanho igual ao valor máximo
    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Conta a ocorrência de cada elemento no array
    for (int i = 0; i < n; i++) {
        count[array[i]]++;
    }

    // Constrói a tabela de frequência acumulada
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Constrói o array de saída
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copia o array de saída para o array original
    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
}

int main() {
    int array[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
    }

    printf("Entrada:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    countingSort(array, 10);

    printf("\nSaída:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

