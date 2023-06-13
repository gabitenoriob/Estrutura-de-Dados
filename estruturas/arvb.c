
#include <stdio.h>
#include <stdlib.h>


typedef struct no
{
   int conteudo;
   struct no *esquerdo, * direita;
   
}No;

typedef struct arvore_binaria
{
    No *raiz;
}arvb;
No* criarNovoNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->conteudo = valor;
    novo->esquerdo = NULL;
    novo->direita = NULL;
    return novo;
}

void inserir(arvb* arvore_binaria, int valor) {
    if (arvore_binaria->raiz == NULL) {
        arvore_binaria->raiz = criarNovoNo(valor);
    } else {
        No* atual = arvore_binaria->raiz;
        No* pai;

        while (1) {
            pai = atual;

            if (valor < atual->conteudo) {
                atual = atual->esquerdo;
                if (atual == NULL) {
                    pai->esquerdo = criarNovoNo(valor);
                    return;
                }
            } else {
                atual = atual->direita;
                if (atual == NULL) {
                    pai->direita = criarNovoNo(valor);
                    return;
                }
            }
        }
    }
}

No* buscar(No* raiz, int chave) {
    if (raiz == NULL || raiz->conteudo == chave) {
        return raiz;
    }

    if (chave < raiz->conteudo) {
        return buscar(raiz->esquerdo, chave);
    } else {
        return buscar(raiz->direita, chave);
    }
}

No* encontrarNoPai(No* raiz, int chave) {
    if (raiz == NULL || (raiz->esquerdo && raiz->esquerdo->conteudo == chave) ||
        (raiz->direita && raiz->direita->conteudo == chave)) {
        return raiz;
    }

    if (chave < raiz->conteudo) {
        return encontrarNoPai(raiz->esquerdo, chave);
    } else {
        return encontrarNoPai(raiz->direita, chave);
    }
}

void remover(arvb* arvore_binaria, int chave) {
    No* noPai = encontrarNoPai(arvore_binaria->raiz, chave);
    No* noRemover;

    if (noPai == NULL) {
        noRemover = arvore_binaria->raiz;
    } else if (noPai->esquerdo && noPai->esquerdo->conteudo == chave) {
        noRemover = noPai->esquerdo;
    } else {
        noRemover = noPai->direita;
    }

    if (noRemover == NULL) {
        return; // Nó não encontrado na árvore
    }

    // Caso 1: Nó a ser removido é uma folha (não tem filhos)
    if (noRemover->esquerdo == NULL && noRemover->direita == NULL) {
        if (noPai == NULL) {
            arvore_binaria->raiz = NULL;
        } else if (noPai->esquerdo == noRemover) {
            noPai->esquerdo = NULL;
        } else {
            noPai->direita = NULL;
        }
        free(noRemover);
    }
    // Caso 2: Nó a ser removido possui apenas um filho
    else if (noRemover->esquerdo == NULL) {
        if (noPai == NULL) {
            arvore_binaria->raiz = noRemover->direita;
        } else if (noPai->esquerdo == noRemover) {
            noPai->esquerdo = noRemover->direita;
        } else {
            noPai->direita = noRemover->direita;
        }
        free(noRemover);
    } else if (noRemover->direita == NULL) {
        if (noPai == NULL) {
            arvore_binaria->raiz = noRemover->esquerdo;
        } else if (noPai->esquerdo == noRemover) {
            noPai->esquerdo = noRemover->esquerdo;
        } else {
            noPai->direita = noRemover->esquerdo;
        }
        free(noRemover);
    }
    // Caso 3: Nó a ser removido possui dois filhos
    else {
        No* sucessor = noRemover->direita;
        No* paiSucessor = noRemover;

        while (sucessor->esquerdo != NULL) {
            paiSucessor = sucessor;
            sucessor = sucessor->esquerdo;
        }

        noRemover->conteudo = sucessor->conteudo;

        if (paiSucessor->esquerdo == sucessor) {
            paiSucessor->esquerdo = sucessor->direita;
        } else {
            paiSucessor->direita = sucessor->direita;
        }

        free(sucessor);
    }
}

void imprimir(No* raiz) {
    if (raiz != NULL) {
        imprimir(raiz->esquerdo);
        printf("%d ", raiz->conteudo);
        imprimir(raiz->direita);
    }
}

int main()
{
    int  valor;
    arvb arvore;
    arvore.raiz = NULL;

    do{
        printf("insira o valor a inserir:\n 0 eh a condicao de parada\n");
        scanf("%d", &valor);
        if(valor !=0)
        {
        inserir(&arvore, valor);
        }
    }while (valor != 0);

    //imprimir(arvore.raiz);

    printf("qual chave deseja buscar?\n");
    int chave_de_busca;
    scanf("%d", &chave_de_busca);
    printf("resultado da busca %d", busca(arvore.raiz, chave_de_busca));
   
}