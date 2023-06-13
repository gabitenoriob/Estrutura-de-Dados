#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no* primFilho;
    struct no* proxIrmao;

}No;


No* buscaChave(int valor, No* raiz)
{
    if(raiz == NULL) return NULL;
    if ( raiz->chave == valor) return raiz;
    No* p = raiz -> primFilho; //subarvore
    while (p)
    {
        No* resp = buscaChave(valor,p);
        if(resp) return (resp);
        p = p->proxIrmao;
    }
    return (NULL);
    
}
No* criarNovoNo (int valor)
{
    No* novo = (No*)malloc(sizeof(No));
    novo -> primFilho = NULL;
    novo -> proxIrmao = NULL;
    novo -> chave = valor;
    return (novo);

}
int insere(No* raiz, int novaChave, int chavePai)
{
    No* pai = buscaChave(chavePai,raiz); // ve se tem pai
    if(!pai) return 0;

    No* filho = criarNovoNo(novaChave); // cria o filho 
    No* p = pai -> primFilho; // se é o 1 filho
    if(!p) pai -> primFilho = filho; // se nao tiver primogenito, esse filho sera o primeiro caso nao
    else// ja tem filho ent vira um dos prox irmaos, na ultima posição
    {
        while (p ->proxIrmao)
        {
            p = p-> proxIrmao;
            p -> proxIrmao = filho;
        }
        return 1;
        
    }
}

No* inicializa (int valor)
{
    return criarNovoNo(valor);
}
void imprimir( No* raiz)
{
    if (raiz == NULL) return;
    printf("%d(", raiz->chave);
    No* p = raiz -> primFilho;
    while (p)
    {
        imprimir(p);
        p = p-> proxIrmao;
    }

    printf(")");
    
}
#include <stdio.h>
#include <stdlib.h>

// definições das funções

int main() {

    No* arvore;

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Inserir novo no.\n");
        printf("2. Buscar no na arvore.\n");
        printf("3. Criar novo no.\n");
        printf("4. Inicializar arvore.\n");
        printf("5. Imprimir arvore em ordem.\n");
        printf("0. Sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int novaChave, chavePai;
                printf("Digite a chave do novo no: ");
                scanf("%d", &novaChave);
                printf("Digite a chave do no pai: ");
                scanf("%d", &chavePai);
                if (insere(arvore, novaChave, chavePai)) {
                    printf("Novo no inserido com sucesso.\n");
                } else {
                    printf("Nao foi possivel inserir o novo no.\n");
                }
                break;
            }
            case 2: {
                int valor;
                printf("Digite a chave do no a ser buscado: ");
                scanf("%d", &valor);
                No* noEncontrado = buscaChave(valor, arvore);
                if (noEncontrado) {
                    printf("No encontrado com sucesso.\n");
                } else {
                    printf("No nao encontrado.\n");
                }
                break;
            }
            case 3: {
                int novaChave;
                printf("Digite a chave do novo no: ");
                scanf("%d", &novaChave);
                No* novoNo = criarNovoNo(novaChave);
                printf("Novo no criado com sucesso.\n");
                break;
            }
            case 4: {
                int raizNova;
                printf("Digite a chave da nova raiz: ");
                scanf("%d", &raizNova);
                arvore = inicializa(raizNova);
                printf("Arvore inicializada com sucesso.\n");
                break;
            }
            case 5: {
                printf("Arvore em ordem: ");
                imprimir(arvore);
                printf("\n");
                break;
            }
            case 0: {
                printf("Saindo...\n");
                break;
            }
            default: {
                printf("Opcao invalida. Tente novamente.\n");
                break;
            }
        }
    } while (opcao != 0);

    return 0;
}
