#include <stdio.h>

// Função para ajustar o heap máximo
void max_heapify(int array[], int n, int i) {
    int maior = i;         // Inicializa o maior como raiz
    int filhoEsquerdo = 2 * i + 1;
    int filhoDireito = 2 * i + 2;

    // Verifica se o filho esquerdo é maior que a raiz
    if (filhoEsquerdo < n && array[filhoEsquerdo] > array[maior]) {
        maior = filhoEsquerdo;
    }

    // Verifica se o filho direito é maior que a raiz
    if (filhoDireito < n && array[filhoDireito] > array[maior]) {
        maior = filhoDireito;
    }

    // Se o maior não for a raiz, troca os elementos e ajusta o heap recursivamente
    if (maior != i) {
        int temp = array[i];
        array[i] = array[maior];
        array[maior] = temp;
        max_heapify(array, n, maior);
    }
}

// Função principal do Heap Sort
void heap(int array[], int n) {
    // Constrói o heap máximo
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(array, n, i);
    }

    // Extrai os elementos do heap um por um e os coloca na parte ordenada do array
    for (int i = n - 1; i >= 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        max_heapify(array, i, 0);
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

    heap(array,10);



}

//VERSÃO MELHORADA
#include <stdio.h>
#include <string.h>

// Função para ajustar o heap máximo
void max_heapify(int array[], int n, int i) {
    int maior = i;         // Inicializa o maior como raiz
    int filhoEsquerdo = 2 * i + 1;
    int filhoDireito = 2 * i + 2;

    // Verifica se o filho esquerdo é maior que a raiz
    if (filhoEsquerdo < n && array[filhoEsquerdo] > array[maior]) {
        maior = filhoEsquerdo;
    }

    // Verifica se o filho direito é maior que a raiz
    if (filhoDireito < n && array[filhoDireito] > array[maior]) {
        maior = filhoDireito;
    }

    // Se o maior não for a raiz, troca os elementos e ajusta o heap recursivamente
    if (maior != i) {
        int temp = array[i];
        array[i] = array[maior];
        array[maior] = temp;
        max_heapify(array, n, maior);
    }
}

// Função principal do Heap Sort
void heap(int array[], int n) {
    // Constrói o heap máximo usando versão bottom-up
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(array, n, i);
    }

    // Extrai os elementos do heap um por um e os coloca na parte ordenada do array
    for (int i = n - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        max_heapify(array, i, 0);
    }
  
    printf("\nsaiu assim:\n");
    for(int i= 0; i < n; i++){printf("%d ", array[i]);}
}

int main()
{
    int array[10];
    for(int i= 0; i< 10; i++){scanf("%d", &array[i]);}

    printf("entrou assim:\n");
    for(int i= 0; i < 10; i++){printf("%d ", array[i]);}

    heap(array, 10);

    return 0;
}


