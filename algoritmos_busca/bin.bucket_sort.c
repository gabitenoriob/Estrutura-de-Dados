#include <stdio.h>
#include <stdlib.h>
struct balde{
    int qntd;
    int valores[5];
};
void insertion(int array[], int n) {
    int i, j, chave;
    for (i = 1; i < n; i++) {
        chave = array[i];
        j = i - 1;

        // move os elementos maiores para a direita da lista
        while (j >= 0 && array[j] > chave) {
            array[j+1] = array[j];
            j = j - 1;
        }

        // insere o elemento na posição correta
        array[j+1] = chave;
    }

}
void bucket(int array[],int n)
{
    int j , maior, menor, num_baldes, index;
    struct balde baldes[100];
    maior = menor = array[0];// so inicializando menor e maior
    // realmente dando VALOR a maior e menor 
    for (int i = 0; i < n; i++)
    {
        if(array[i] > maior){
            maior = array[i];
        }
        if(array[i] < menor)
        {
            menor = array[i];
        }
    }
    //inicialiazando os baldes
    num_baldes = (maior - menor) / 5 + 1;// tam + 1
    //inicializa todos os baldes c 0 
    for(int i = 0; i < num_baldes; i++)
    {
        baldes[i].qntd = 0;
    }
    // distribui os valores nos baldes
    for (int i = 0; i < n; i++)
    {
        index = (array[i] - menor) / 5; // / tam
        baldes[index].valores[baldes[index].qntd] = array[i];
        baldes[index].qntd ++;
    }
    // ordena cada balde e coloca no array
    index = 0;
    for (int j = 0; j < num_baldes; j++)
    {
        insertion(baldes[j].valores, baldes[j].qntd);
        for(int k = 0; k < baldes[j].qntd; k++)
        {
            array[index] = baldes[j].valores[k];
            index++;
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

    bucket(array,10);



}

// VERSÃO MELHORADA
#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}

void bucketSort(int array[], int n) {
    const int numBuckets = 10;
    int minVal = array[0];
    int maxVal = array[0];

    for (int i = 1; i < n; i++) {
        if (array[i] < minVal) {
            minVal = array[i];
        } else if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }

    double interval = (double)(maxVal - minVal + 1) / numBuckets;

    int buckets[numBuckets][n];
    int bucketSizes[numBuckets] = {0};

    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)((array[i] - minVal) / interval);
        buckets[bucketIndex][bucketSizes[bucketIndex]] = array[i];
        bucketSizes[bucketIndex]++;
    }

    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        mergeSort(buckets[i], 0, bucketSizes[i] - 1);
        for (int j = 0; j < bucketSizes[i]; j++) {
            array[index] = buckets[i][j];
            index++;
        }
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

    bucketSort(array, 10);

    printf("\nSaída:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
