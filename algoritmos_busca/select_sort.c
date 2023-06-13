    #include <stdio.h>
    #include <stdlib.h>

    void selection(int array[], int n) {
        int i, j, idx_menor;

        // percorre toda a lista
        for (i = 0; i < n-1; i++) {
            // encontra o menor elemento a partir da posição atual, n ta mudando nd na lista so achando o menor idx baseado em cada i
            idx_menor = i;
            for (j = i+1; j < n; j++) {
                if (array[j] < array[idx_menor]) {
                    idx_menor = j;
                }
            }

            // troca o menor elemento com o primeiro elemento da lista não ordenada, começa a trocar usando as mudanças de i, dps de sair do for c j p cada posição
            int aux = array[idx_menor];
            array[idx_menor] = array[i];
            array[i] = aux;
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

        selection(array,10);


    }

    //VERSAO MELHORADA
    //verificar se o menor elemento encontrado é diferente do elemento atual antes de fazer a troca. Isso evita trocas desnecessárias. 
    void selection(int array[], int n) {
        int i, j, idx_menor;

        // percorre toda a lista
        for (i = 0; i < n-1; i++) {
            // encontra o menor elemento a partir da posição atual, n ta mudando nd na lista so achando o menor idx baseado em cada i
            idx_menor = i;
            for (j = i+1; j < n; j++) {
                if (array[j] < array[idx_menor]) {
                    idx_menor = j;
                }
            }

            // troca o menor elemento com o primeiro elemento da lista não ordenada, começa a trocar usando as mudanças de i, dps de sair do for c j p cada posição
        if (idx_menor != i) {
        int aux = array[idx_menor];
        array[idx_menor] = array[i];
        array[i] = aux;
    }
        }
    printf("\nsaiu assim:\n");
        for(int i= 0; i < 10; i++){printf("%d ", array[i]);}
    }
