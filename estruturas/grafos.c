//mapeamento de cada a uma lista de nos ao qual ele esta conectado
// no ------ conectado a (quais nos ele ta ligado)

// formas de fazer :
// grafo de n nos =  matriz[n][n] de 1 ou 0 (se tem ligação ou não) ou os proprios pesos
// arranjo de n listas ligadas,uma p cada vertice no grafo
// se for menos denso é melhor fazer a matriz, p busca mlr a lista pq cada no ja tem uma lista de proximos

#include <stdio.h>
#include <stdlib.h>


//LISTA DE ADJACENCIA -> prox
typedef struct adjacencia{
    int vertice; //onde chega
    int peso;
    struct adjacencia *prox;//prox da lista ligada
}adjacencia;

typedef struct vertices{
    
    adjacencia *cabeca; //um vertice possui um ponteiro p estrutura adjacencia apontando p vertice do topo
}vertice;

typedef struct grafos 
{
    int vertices;//num de
    int arestas;// num de
    vertice *adj; // arranjo de vertices

}grafo;

grafo *criarGrafo(int v)
{
    grafo *g = (grafo *)malloc(sizeof(grafo));

    g->vertices = v; //num fixo de vertices q entra 
    g -> arestas = 0;
    g -> adj = (vertice *)malloc(v * sizeof(vertice));
    // aloco e boto null em todas as adjacencias pq por enquanto n tem arestas
    for(int i = 0; i <v; i++)
    {
        g->adj[i].cabeca = NULL;
    }
    return (g);
}

adjacencia *criarAdj(int vf, int peso)// v = num de vertices = no final
{
    adjacencia *temp = (adjacencia *)malloc(sizeof(adjacencia));

    temp->vertice = vf;
    temp->peso = peso;
    temp->prox = NULL;
    return(temp);
}

//aresta dirigida de vi p vf
int criarAresta(grafo *gr, int vi, int vf, int peso)// vi = vertice inicial , vf = vertice final
{
    //tratamento de erros
    if(!gr) return 0;
    if((vf<0) || (vf >= gr->vertices)) return 0;
    if((vi<0) || (vi >= gr->vertices)) return 0;



    adjacencia *novo = criarAdj(vf,peso);
    novo->prox = gr->adj[vi].cabeca;
    // essa linha abaixo talvez de erro
    gr->adj[vi].cabeca = novo;
    gr->arestas++;
    return 1;

}

void imprimir(grafo *gr)
{
    printf("vertices = %d  arestas = %d \n\n", gr->vertices, gr->arestas);

    for(int i = 0; i <gr->vertices;i++)
    {
        printf("v%d:", i);
        adjacencia *ad = gr->adj[i].cabeca;
        while (ad)
        {
        printf("v%d(%d)" ,ad->vertice, ad->peso);
        ad = ad->prox;
        }

        printf("\n");
        
    }
}

int main()
{
    grafo *gr = criarGrafo(5); //criou grafo de 5 vertices
    criarAresta(gr,0,1,2);
    criarAresta(gr,1,2,4);  
    criarAresta(gr,2,0,12);
    criarAresta(gr,2,4,40);
    criarAresta(gr,3,1,3);
    criarAresta(gr,4,3,8);


    imprimir(gr);



  
}