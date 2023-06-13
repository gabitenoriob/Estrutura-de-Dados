#include <stdio.h>
void juntar_metades(int array[], int mais_a_esquerda, int meio, int mais_a_direita) {
    
    int i, j, k;
    int n1 = meio - mais_a_esquerda + 1;
    int n2 = mais_a_direita - meio;
    int lista1[n1], lista2[n2];
    for (i = 0; i < n1; i++) {
        lista1[i] = array[mais_a_esquerda + i];
    }
    for (j = 0; j < n2; j++) {
        lista2[j] = array[meio + 1 + j];
    }
    i = 0;
    j = 0;
    k = mais_a_esquerda;
    while (i < n1 && j < n2) { 
        if (lista1[i] <= lista2[j]) {
            array[k] = lista1[i];
            i++;
        } else {
            array[k] = lista2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        array[k] = lista1[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = lista2[j];
        j++;
        k++;
    }
}

void merge(int array[], int mais_a_esquerda, int mais_a_direita) {

    if (mais_a_esquerda < mais_a_direita) {
        int meio = mais_a_esquerda + (mais_a_direita - mais_a_esquerda) / 2;

        merge(array, mais_a_esquerda, meio);//lista 1
        merge(array, meio + 1, mais_a_direita);//lista 2
        juntar_metades(array, mais_a_esquerda, meio, mais_a_direita);
    }
}

int main()
{
    int array[10];
    for(int i= 0; i< 10; i++){scanf("%d", &array[i]);}

    printf("entrou assim:\n");
    for(int i= 0; i < 10; i++){printf("%d ", array[i]);}


    merge(array,0,9);

    printf("\nsaiu assim:\n");
    for(int i= 0; i < 10; i++){printf("%d ", array[i]);}


}

//VERSÃO MELHORADA 
#include <stdio.h>

void merge(int array[], int temp[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    while (i <= meio && j <= fim) {
        if (array[i] <= array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }

    while (i <= meio) {
        temp[k++] = array[i++];
    }

    while (j <= fim) {
        temp[k++] = array[j++];
    }

    for (i = inicio; i <= fim; i++) {
        array[i] = temp[i];
    }
}

void mergeSort(int array[], int temp[], int inicio, int fim) {
    if (fim - inicio <= 15) {
        // Limite de recursão atingido, usar algoritmo de ordenação mais simples
        // como o Insertion Sort
        // ... implementar Insertion Sort aqui ...
        return;
    }

    int meio2 = inicio + (fim - inicio) / 2;

    mergeSort(array, temp, inicio, meio2);
    mergeSort(array, temp, meio2 + 1, fim);

    // Verifica se as sublistas estão ordenadas antes de fazer a junção
    if (array[meio2] <= array[meio2 + 1]) {
        return;
    }

    merge(array, temp, inicio, meio2, fim);
}

void mergeSortWrapper(int array[], int n) {
    int temp[n];
    mergeSort(array, temp, 0, n - 1);
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

    mergeSortWrapper(array, 10);

    printf("\nsaiu assim:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

