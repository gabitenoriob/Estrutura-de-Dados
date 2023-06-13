#include <stdio.h>

void quick(int array[], int mais_a_esquerda, int mais_a_direita) {

    if (mais_a_esquerda < mais_a_direita) {
        // Escolhe o pivô como o primeiro elemento da lista
        int pivo = array[mais_a_esquerda];
        int i = mais_a_esquerda;
        int j = mais_a_direita;

        // Particiona a lista em duas sub-listas
        while (i < j) {
            // Encontra um elemento da sub-lista esquerda que é maior ou igual ao pivô
            while (array[i] < pivo) {
                i++;
            }
            // Encontra um elemento da sub-lista direita que é menor ou igual ao pivô
            while (array[j] > pivo) {
                j--;
            }
            // Troca os elementos encontrados de lugar
            if (i <= j) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        }
        // Recursivamente, repete o processo de particionamento nas sub-listas
        quick(array, mais_a_esquerda, j);
        quick(array, i, mais_a_direita);
    }

   

}
int main()
{
    int array[10];
    for(int i= 0; i< 10; i++){scanf("%d", &array[i]);}

    printf("entrou assim:\n");
    for(int i= 0; i < 10; i++){printf("%d ", array[i]);}


    quick(array,0,9);

    printf("\nsaiu assim:\n");
    for(int i= 0; i < 10; i++){printf("%d ", array[i]);}


}

//VERSÃO MELHORADA = escolha mais inteligente do pivo usando a MEDIANA = array[meio]
    #include <stdio.h>

    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int partition(int array[], int low, int high) {
        // Escolha do pivô como o elemento mediano entre o primeiro, o último e o elemento central
        int middle = low + (high - low) / 2;
        if (array[middle] < array[low]) {
            swap(&array[low], &array[middle]);
        }
        if (array[high] < array[low]) {
            swap(&array[low], &array[high]);
        }
        if (array[high] < array[middle]) {
            swap(&array[middle], &array[high]);
        }

        int pivot = array[middle];
        int i = low - 1;
        int j = high + 1;

        while (1) {
            do {
                i++;
            } while (array[i] < pivot);

            do {
                j--;
            } while (array[j] > pivot);

            if (i >= j) {
                return j;
            }

            swap(&array[i], &array[j]);
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

    void quickSort(int array[], int low, int high) {
        // Limite de recursão atingido, usar Insertion Sort
        if (high - low <= 15) {
            insertionSort(array, low, high);
            return;
        }

        if (low < high) {
            int partitionIndex = partition(array, low, high);
            quickSort(array, low, partitionIndex);
            quickSort(array, partitionIndex + 1, high);
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

        quickSort(array, 0, 9);

        printf("\nsaiu assim:\n");
        for (int i = 0; i < 10; i++) {
            printf("%d ", array[i]);
        }

        return 0;
    }

