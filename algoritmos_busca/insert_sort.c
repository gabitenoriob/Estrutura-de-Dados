    #include <stdio.h>
    #include <stdlib.h>

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

    printf("\nsaiu assim:\n");
        for(int i= 0; i < 10; i++){printf("%d ", array[i]);}
    }

    int main()
    {
        int array[10];
        for(int i= 0; i< 10; i++){scanf("%d", &array[i]);}

        printf("entrou assim:\n");
        for(int i= 0; i < 10; i++){printf("%d ", array[i]);}

        insertion(array,10);



    }

    
// VERSÃO MELHORADA
#include <stdio.h>

// Função para realizar a pesquisa binária em um array ordenado
int pesquisaBinaria(int array[], int inicio, int fim, int chave) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (array[meio] == chave)
            return meio;
        else if (array[meio] < chave)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return inicio;
}

// Função de Insertion Sort com pesquisa binária
void insertionBinary(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = array[i];
        int posicao = pesquisaBinaria(array, 0, i - 1, chave);

        // Desloca os elementos maiores para a direita da lista
        for (int j = i - 1; j >= posicao; j--) {
            array[j + 1] = array[j];
        }

        // Insere o elemento na posição correta
        array[posicao] = chave;
    }

    printf("\nsaiu assim:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
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

    insertionBinary(array, 10);

    return 0;
}

