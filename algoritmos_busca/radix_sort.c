#include <stdio.h>

// Função para encontrar o maior número no array
int encontrar_maior(int array[], int n) {
    int maior = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    return maior;
}

// Função para realizar o counting sort de acordo com o dígito específico
void counting(int array[], int n, int exp) {
    int saida[n]; // Array de saída
    int count[10] = {0}; // Array de contagem dos dígitos

    // Contagem da ocorrência de cada dígito
    for (int i = 0; i < n; i++) {
        count[(array[i] / exp) % 10]++;
    }

    // Atualiza o array de contagem para refletir a posição correta de cada dígito na saída
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Constrói o array de saída
    for (int i = n - 1; i >= 0; i--) {
        saida[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // Copia o array de saída para o array original
    for (int i = 0; i < n; i++) {
        array[i] = saida[i];
    }
}

// Função principal do Radix Sort
void radix(int array[], int n) {
    // Encontra o maior número do array para determinar o número de dígitos
    int maior = encontrar_maior(array, n);

    // Realiza o counting sort para cada dígito, começando pelo dígito menos significativo
    for (int exp = 1; maior / exp > 0; exp *= 10) {
        counting(array, n, exp);
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

   radix(array,10);



}
// VERSÃO MELHORADA
#include <stdio.h>

int encontrar_maior(int array[], int n) {
    int maior = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    return maior;
}

void counting(int array[], int n, int exp) {
    int saida[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(array[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        saida[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        array[i] = saida[i];
    }
}

void insertionSort(int array[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= low && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void radixSort(int array[], int n) {
    int maior = encontrar_maior(array, n);

    const int limite_insertion_sort = 15;

    if (maior <= limite_insertion_sort) {
        insertionSort(array, 0, n - 1);
        return;
    }

    int saida[n];
    int exp = 1;

    while (maior / exp > 0) {
        counting(array, n, exp);
        exp *= 10;
    }
}

int main() {
    int array[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
    }

    printf("entrou assim:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    radixSort(array, 10);

    printf("\nsaiu assim:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
