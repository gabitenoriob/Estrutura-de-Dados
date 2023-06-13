#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int elemento;
   struct no  *proximo;

}No;

typedef struct pilha
{
    struct no *topo;
}pilha;


void empilhar(int dado, pilha *valor)
{
    No *novo = (No*)malloc(sizeof(No));
    if(novo != NULL)
    {
        novo -> elemento = dado;
        novo->proximo = valor->topo;
        valor-> topo = novo ;
    }
   
}

int desempilhar(pilha *valor)
{
    No* novo = valor -> topo;
    int elemento;
    if(novo != NULL)
    {
        valor-> topo = novo -> proximo;
        novo->proximo = NULL;
        elemento = novo -> elemento;
        free(novo);
        return elemento;

    }
}

void imprimir(pilha *valor)
{
    No* novo = valor -> topo;
    if(novo != NULL)
    {
        while (novo != NULL)
        {
            printf("%d ", novo->elemento);
            novo = novo->proximo;
        }
        
    }
}

int main()
{
    pilha *p;
    p = (pilha*)malloc(sizeof(pilha));
    p->topo = NULL;
    int valor;

    // menu abaixo
     do{
        printf("insira o valor a inserir:\n 0 eh a condicao de parada\n");
        scanf("%d", &valor);
        if(valor !=0)
        {
        empilhar(valor,p);
        }
    }while (valor != 0);
    imprimir(p);

   
    desempilhar(p);

    
   
}
/*#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 50

typedef struct no {
    int elemento;
    struct no* proximo;
} No;

typedef struct pilha {
    No* topo;
} Pilha;

void empilhar(int dado, Pilha* valor) {
    No* novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    novo->elemento = dado;
    novo->proximo = valor->topo;
    valor->topo = novo;
}

int desempilhar(Pilha* valor) {
    No* novo = valor->topo;
    int elemento;
    if (novo == NULL) {
        printf("Erro: pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    valor->topo = novo->proximo;
    elemento = novo->elemento;
    free(novo);
    return elemento;
}

void imprimir(Pilha* valor) {
    No* novo = valor->topo;
    while (novo != NULL) {
        printf("%d ", novo->elemento);
        novo = novo->proximo;
    }
}

int main() {
    Pilha* p = malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro: memoria insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    p->topo = NULL;

    int valor;
    char input[MAX_INPUT_SIZE];

    printf("Insira os valores a empilhar (separados por espacos): ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    char* token = strtok(input, " ");
    while (token != NULL) {
        valor = atoi(token);
        empilhar(valor, p);
        token = strtok(NULL, " ");
    }

    printf("Valores empilhados: ");
    imprimir(p);
    printf("\n");

    while (p->topo != NULL) {
        printf("Desempilhado: %d\n", desempilhar(p));
    }

    free(p);

    return 0;
}
*/


