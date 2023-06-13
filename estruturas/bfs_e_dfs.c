#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct lista_adj
{
    int vertice;
    struct lista_adj *prox;
} lista_adj;

typedef struct grafo {
    int tamanho;
    int *visitado;
    lista_adj **lista_adj;
} grafo;

typedef struct fila {
    int v;
    struct fila *prox;
} fila;

void enfileirar(int v, fila **f)
{
    fila *novo_no = (fila *) malloc(sizeof(fila));
    
    if (novo_no == NULL)
        exit(1);

    novo_no->v = v;
    novo_no->prox = NULL;

    if (*f == NULL)
    {
        *f = novo_no;
    }
    else
    {
        fila *aux = *f;

        while (aux->prox != NULL)
            aux = aux->prox;

        aux->prox = novo_no;
    }
}

int desenfileirar(fila **f)
{
    fila *aux = *f;

    int desenfileirado = aux->v;

    (*f) = (*f)->prox;

    aux->prox = NULL;
    free(aux);

    return desenfileirado;
}

lista_adj *adicionar_lista_adj(int v, lista_adj *cabeca)
{
    lista_adj *novo_no = (lista_adj *) malloc(sizeof(lista_adj));

    if (novo_no == NULL)
        exit(1);

    novo_no->vertice = v;
    novo_no->prox = NULL;

    if (cabeca == NULL)
    {
        return novo_no;
    }
    else
    {
        lista_adj *aux = cabeca;

        while (aux->prox != NULL)
            aux = aux->prox;

        aux->prox = novo_no;
        return cabeca;
    }

}

grafo *criar_grafo(int tamanho)
{
    grafo *g = (grafo *) malloc(sizeof(grafo));

    if (g == NULL)
        exit(1);

    g->tamanho = tamanho;
    g->visitado = malloc(tamanho * sizeof(int));
    g->lista_adj = (lista_adj **) malloc(tamanho * sizeof(lista_adj *));

    for (int i = 0; i < g->tamanho; i++) //inicializando grafo td como não visitado 
    {
        g->visitado[i] = 0;
        g->lista_adj[i] = NULL;
    }
    
    return g;
}

void adicionar_vertice(int x, int y, grafo *g)// não direcionado, adc x -> y e y -> x , nas suas respectivas listas de adjacencia 
{
    g->lista_adj[x] = adicionar_lista_adj(y, g->lista_adj[x]);
    g->lista_adj[y] = adicionar_lista_adj(x, g->lista_adj[y]);
}

void dfs(grafo *g, int v, int contador)
{   
    printf("%d ", v);

    contador += 1;
    g->visitado[v] = contador;

    lista_adj *aux = g->lista_adj[v];

    while (aux != NULL)
    {
        if (g->visitado[aux->vertice] == 0)
            dfs(g, aux->vertice, contador);
        
        aux = aux->prox;
    }   
}

void imprimir_fila(fila *q)
{
fila *aux = q;
while (aux != NULL)
{
    if (aux->prox == NULL)
    {
        printf("%d\n", aux->v);
    }
    else
    {
        printf("%d\n", aux->v);
    }

    aux = aux->prox;
}
}

void bfs (grafo *g, int v)
{

int contador = 0;

fila *q = NULL;
enfileirar(v, &q);

while (q != NULL)
{
    int desenfileirado = desenfileirar(&q);
    lista_adj *aux = g->lista_adj[desenfileirado];
    
    printf("%d ", contador);

    while (aux != NULL)
    {
        if (g->visitado[aux->vertice] == 0)
            enfileirar(aux->vertice, &q);
        
        aux = aux->prox;
    }

    //so diz q é visitado aqui no fim
    contador += 1;
    g->visitado[desenfileirado] = contador;
}
//imprimir_fila(q);
printf("\n");
}

void imprimir_grafo (int v, grafo *g)
{
for (int i = 0; i < g->tamanho; i++)
{
printf("v%d -> ", i);

    lista_adj *aux = g->lista_adj[i];

    while (aux != NULL)
    {
        if (aux->prox == NULL)
        {
            printf("v%d vizinhos\n", aux->vertice);
        }
        else
        {
            printf("v%d ", aux->vertice);
        }

        aux = aux->prox;
    }
    
}
}

int main ()
{

int tam, num_v;
scanf("%d %d", &tam, &num_v);

grafo *g = criar_grafo(tam); 

for (int i = 0; i < num_v; i++)
{
    int x, y;
    scanf("%d %d", &x, &y);
    adicionar_vertice(x, y, g);
}

imprimir_grafo(0, g);
dfs(g, 0, 0);
bfs(g, 0);
printf("\n");

return 0;
}