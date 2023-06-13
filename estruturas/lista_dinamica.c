#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}No;

void inserir_inicio(No **lista, int elemento){ //endereço da lista
    No *novo = malloc(sizeof(No));

    if(novo != NULL){

        novo ->valor = elemento;
        novo->prox = *lista;//conteudo da lista
        *lista = novo;
    }
    else
    {
        //erro de mem
    }
}

void inserir_final( No **lista, int elemento)
{
    No *aux,*novo = malloc(sizeof(No));

    if(novo != NULL)
    {
        novo->valor = elemento;
        novo->prox = NULL;
        // é o primeiro?
        if(*lista == NULL)
        {
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->prox != NULL)
            {
                aux = aux->prox;
            }

            aux->prox = novo;
            
        }
    }
    else
    {
        //erro mem
    }
}

void inserir_meio(No **lista, int elemento, int anterior){

     No *aux,*novo = malloc(sizeof(No));

    if(novo != NULL){
        novo->valor = elemento;
        if(*lista == NULL)//lista vazia
        {
            novo->prox= NULL;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->valor != anterior && aux->prox != NULL)
            {
                aux = aux->prox;
            }
            //vai inserir entre aux e esse aux-.prox pq saiu do while qnd encontrou o anterior
            novo->prox = aux->prox;
            aux->prox = novo;

        
        }
    }
}
void inserir_ordenado(No **lista, int elemento){
    No *aux,*novo = malloc(sizeof(No));

    if(novo != NULL){

       if(*lista == NULL)
       {
        novo->prox = NULL;
        *lista = novo;
       }
       else if(novo->valor < (*lista)->valor)//vai ter q inserir na cabeça
       {
            novo->prox = *lista;
            *lista = novo;
       }
       else
       {
            aux = *lista;
            while (aux->prox && novo->valor > aux->prox->valor)
            {
                aux = aux->prox;
            }

            novo->prox = aux->prox;
            aux->prox= novo;
            
       }
    }
    else
    {
        //erro de mem
    }
}
No* buscar(No **lista, int chave)
{
    No *aux,*no = NULL;
    aux = *lista;
    while (aux && aux->valor != chave)
    {
        aux = aux->prox; 
    }
    if(aux != NULL)
    {
        no = aux;
    }
    

    return no;
}
void imprimir(No *lista)
    {
        printf("LISTA:\n\n");
        while (lista != NULL)
        {
           printf("%d ", lista->valor);
           lista = lista->prox;
        }
        printf("\n");
    }

int main()
{
    No *lista = NULL;
    int op;
    int num;
    int chave;
    No *sim = NULL;

    do{
        printf("0-sair\n1-inI\n2-inF\n3-insM\n4-imprimir\n5-ordenado\n6-buscar");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            inserir_inicio(&lista,2);
            break;
        case 2:
            inserir_final(&lista,4);
            break;
        case 3:
            inserir_meio(&lista,3,2);
            break;
        case 4:
            imprimir(lista);
            break;
        case 5:
        scanf("%d", &num);
            inserir_ordenado(&lista,num);
        
        case 6:
        scanf("%d", &chave);
            sim = buscar(&lista,chave);
            if(sim)
            {
                printf("achou %d\n", sim->valor );
            }
            

            break;
        default:
            break;
        }
    }while(op != 0);
}


