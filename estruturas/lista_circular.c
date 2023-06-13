#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int valor;
    struct no *prox;
    struct no* ante;
}No;

typedef struct {
    No *fim;
    No *inicio;
    int tam;
}Lista;

void inserir_inicio(Lista *lista, int elemento){ //endereço da lista
    No *novo = malloc(sizeof(No));

    if(novo != NULL){

        novo ->valor = elemento;
        novo->prox = lista->inicio;
        lista->inicio = novo;
       
        if(lista->fim == NULL)
        {
            lista->fim = novo;
        }
        lista->fim->prox = lista->inicio;
        
    }
    else
    {
        //erro de mem
    }
}

void inserir_final( Lista *lista, int elemento)
{
    No *aux,*novo = malloc(sizeof(No));

    if(novo != NULL)
    {
        novo->valor = elemento;
        novo->prox = NULL;
        // é o primeiro?
        if(lista->inicio == NULL)
        {
            lista->inicio = novo;
            lista->fim = novo;
            lista->fim->prox = lista->inicio;
        }
        else
        {
           lista->fim->prox = novo;
           lista->fim = novo;
           lista->fim->prox = lista->inicio;
           // ou novo->prox = lista->inicio
            
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
            novo->ante = NULL;
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
            aux->prox->ante = novo;
            novo->ante = aux;
            aux->prox = novo;

        
        }
    }
}
void inserir_ordenado(  Lista *lista, int elemento){
    No *aux,*novo = malloc(sizeof(No));
    novo->valor = elemento;
    if(novo != NULL){


       if(lista->inicio == NULL)
       {
        inserir_inicio(lista,elemento);
       }
       else if(novo->valor < lista->inicio)//vai ter q inserir na cabeça
       {
            inserir_inicio(lista,elemento);
       }
       else
       {
            aux = lista->inicio;
            while (aux->prox != lista->inicio && (novo->valor > aux->prox->valor))
            {
                aux = aux->prox;
            }

            novo->prox = aux->prox;
            if(aux->prox == lista->inicio)
            {
            inserir_final(lista,elemento);
            }
            else
            {
                
            novo->prox = aux->prox;
            aux->prox= novo;
            }
            
       }
    }
    else
    {
        //erro de mem
    }
    
}

No *remover(Lista *lista, int valor)
{
    No*aux,*remover = NULL;

    if(lista->inicio != NULL)
    {
        if(lista->inicio == lista->fim && lista->inicio->valor == valor){
            remover = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;


        }
        else if(lista->inicio->valor == valor)
        {
            remover = lista->inicio;
            lista->inicio = remover->prox;
            lista->fim->prox = lista->inicio;
        }
        else
        {
            aux = lista->inicio;
            while (aux->prox != lista->inicio && aux->prox->valor != valor)
            {
               aux = aux->prox;
            }
            if(aux->prox->valor == valor)
            {
                if(lista->fim == aux->prox)
                {
                    remover = aux->prox;
                    aux->prox = remover->prox;
                    lista->fim = aux;
                }
                else
                {
                    remover = aux->prox;
                    aux->prox = remover->prox;
                }
            }
            
        }
    }

    return remover;
}
No* buscar(Lista *lista, int chave)
{
    No *aux = lista->inicio;
    if(aux)
    {
        do{
            if(aux->valor = chave)
            {
                return aux;
            }
            aux = aux->prox;
        }while(aux != lista->inicio);
    }
    return NULL;
    
}
void imprimir(Lista *lista)
{
    No *no = lista->inicio;

    printf("LISTA:\n\n");
    if(no)
    {
        do{
            printf("%d ", no->valor);
            no = no->prox;
        }while(no != lista->inicio);
    }


       
}

int main()
{
    Lista *lista;
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;

    int op;
    int num;

    do{
        printf("0-sair\n1-inI\n2-inF\n3-insM\n4-imprimir\n5-ordenado\n6-remover\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            inserir_inicio(lista,2);
            break;
        case 2:
            inserir_final(lista,4);
            break;
        case 3:
            inserir_meio(lista,3,2);
            break;
        case 4:
            imprimir(lista);
            break;
        case 5:
        scanf("%d", &num);
            inserir_ordenado(lista,num);
        case 6:
        
            remover(lista,3);
            

            break;
        default:
            break;
        }
    }while(op != 0);
}


