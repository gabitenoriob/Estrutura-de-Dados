#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* prox;
} No;

typedef struct fila {
    No* primeiro;
    No* fim;
    int tamanho;
} Fila;

void criar_fila(Fila* fila) {
    fila->primeiro = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

void inserir(Fila* fila, int num) {
    No* aux, * novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = num;
        novo->prox = NULL;

        if (fila->primeiro == NULL) {
            fila->primeiro = novo;
            fila->fim = novo;
        }
        else {
            fila->fim->prox = novo;
            fila->fim = novo;
        }
        fila->tamanho++;
    }
    else {
        printf("erro de mem\n");
    }
}
void inserir_prioridades(Fila *fila, int idade)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->valor = idade;
        novo->prox = NULL;

        if (fila->primeiro == NULL)
        {
            fila->primeiro = novo;
            fila->fim = novo;
        }
        else
        {
            if (idade >= 60)
            {
                if (fila->primeiro->valor < 60)
                {
                    novo->prox = fila->primeiro;
                    fila->primeiro = novo;
                }
                else
                {
                    aux = fila->primeiro;
                    while (aux->prox && aux->prox->valor >= 60)
                    {
                        aux = aux->prox;
                    }
                    novo->prox = aux->prox;
                    aux->prox = novo;
                }
            }
            else
            {
                aux = fila->fim;
                aux->prox = novo;
                fila->fim = novo;
            }
        }
        fila->tamanho++;
    }
    else
    {
        printf("erro de mem");
        return;
    }
}


No* remover(Fila* fila) {
    No* remover = NULL;
    if (fila->primeiro != NULL) {
        remover = fila->primeiro;
        fila->primeiro = remover->prox;
        fila->tamanho--;
    }
    else {
        printf("fila vazia\n");
    }
    return remover;
}

void imprimir(Fila* fila) {
    No* aux = fila->primeiro;
    printf("\t----FILA----\n\t");
    while (aux) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n\t----FIM FILA----\n");
}

int main() {
    No* remov;
    Fila* fila = malloc(sizeof(Fila));
    criar_fila(fila);
    int op, valor;
    do {
        printf("0 = sair\n1 = inserir\n2 = remover = sair da fila\n3 = imprimir\n4 = inserir com prioridade\n\n");
        scanf("%d", &op);
        switch (op) {
        case 1:
            printf("digite o valor\n");
            scanf("%d", &valor);
            inserir(fila, valor);
            break;
        case 2:
            remov = remover(fila);
            free(remov);
            break;
        case 3:
            imprimir(fila);
            break;
             case 4:
        printf("digite o valor\n");
            scanf("%d", &valor);
            inserir_prioridades(fila,valor);
        break;
        default:
            if (op != 0) { printf("erro\n"); }
        }
    } while (op != 0);
    free(fila);
    return 0;
}
