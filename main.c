#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaAdj.h"
#include "PilhaEstatica.h"
#include "FilaEstatica.h"
#define MAX 101
#define MIN 20

int niv_agua = 0;


/**/

/*
    --> Vizinhos de cada ilha será armazenado em uma LISTA DE ADJACENCIA
    --> Nivel incial da agua = 0;
    --> Laço de repetição para os comandos: agua H, arq, caminho A B, fim
    --> Busca de Profundidade para o arq (recursiva ou interativo - pilhaEstatica OU pilhaDinamica);
    --> Busca em Largura para o caminho A B (filaEstatuca OU filaDinamica);

*/

/*
    1 - Pegar um vertice inicial (Primeiro da lista de adjacencia)
    2 - Empilha ele e atribui o valor 1 ao vetor visitado;
    3 - Desempliha e analisa quais são seus vizinhos, os empilhando e repetindo o processo


*/

int *buscaProfundidade(grafo *Grafo, int *visitado, int ilha);

int *buscaLargura(grafo *Grafo, int *visitado, int origem, int destino);

void imprime_caminho(grafo *Grafo, int *pai, int origem, int destino);

int quant_Pontes(grafo *Grafo, int *conjunto);

grafo *cria_grafo(){
    grafo *novo = (grafo*)malloc(sizeof(grafo));
    novo->n_vertice = 0;
    novo->lista_Adj = (nodo**)malloc(MAX*sizeof(nodo*));
    return novo;
}

int main(){
    int visitado[MAX], aux_visitado[MAX];
    int *arquipelogo, *pai;
    int ilha, aux_ilha, altura, quant_ilha, quant_ponte, aux_nivel, verif, n_ilhas, n_pontes, n_arq, origem, destino;
    int i, j, k;
    char comando[MIN];

    grafo *Grafo = cria_grafo();
    nodo **lista_Adj = Grafo->lista_Adj;

    scanf("%d %d", &quant_ilha, &quant_ponte);

    for(i = 1; i < MAX; i++){
        visitado[i] = -1;
    }

    for(i = 0; i < quant_ponte; i++){
        scanf("%d %d %d", &ilha, &aux_ilha, &altura);
        if(visitado[ilha] == -1)
            lista_Adj[ilha] = NULL;
        lista_Adj[ilha] = insere_vizinho(lista_Adj[ilha], ilha, aux_ilha, altura);
        if(visitado[aux_ilha] == -1)
            lista_Adj[aux_ilha] = NULL;
        lista_Adj[aux_ilha] = insere_vizinho(lista_Adj[aux_ilha],aux_ilha, ilha, altura);
        if(visitado[ilha] == -1) visitado[ilha] = 0;
        if(visitado[aux_ilha] == -1) visitado[aux_ilha] = 0;
    }

    for(i = 1; i < MAX; i++){
        aux_visitado[i] = visitado[i];
    }

    printf("\n");
    scanf("%s", comando);
    while((verif = strcmp(comando, "fim")) != 0){
        n_arq = 0;
        i = 1;
        if(verif = strcmp(comando, "arq") == 0){
            while(1){
                Grafo->n_vertice = 0;
                while(aux_visitado[i] != 0 && i != MAX) i++;
                if(i == MAX){
                    printf("Total: %d arquipelogos", n_arq);
                    break;
                }
                printf("[");
                arquipelogo = buscaProfundidade(Grafo, aux_visitado, i);
                n_arq++;
                n_ilhas = 0;
                n_pontes = quant_Pontes(Grafo, arquipelogo);
                printf(" ] (%d ilhas, %d pontes)\n", Grafo->n_vertice, n_pontes);
                free(arquipelogo);
        }}
        else if(verif = strcmp(comando, "caminho") == 0){
            scanf("%d %d", &origem, &destino);
            pai = buscaLargura(Grafo, aux_visitado, origem, destino);
            imprime_caminho(Grafo, pai, origem, destino);
            free(pai);
        }
        else if(verif = strcmp(comando, "agua") == 0){
            scanf("%d", &aux_nivel);
            niv_agua = aux_nivel;
            printf("Nivel da agua: %d m", niv_agua);
        }
        printf("\n\n");
        for(i = 0; i < MAX; i++){
            aux_visitado[i] = visitado[i];
        }
        scanf("%s", comando);
    }

    return 0;

}


int *buscaProfundidade(grafo *Grafo, int *visitado, int ilha){
    int tam, verif, desemp, *conjunto, aux;
    int aux_visitado[MAX] = {0};
    int i;
    nodo *aux_lista;

    Pilha *p = cria_pilha();
    conjunto = (int*)malloc(MAX*sizeof(int));

    for(i = 1; i < MAX; i++){
        conjunto[i] = 0;
    }

    i = 1;
    pushP(p, ilha);
    while((verif = pilha_vazia(p) != 1)){
        desemp = popP(p);
        if(visitado[desemp] == 0) {
            aux_visitado[i] = desemp;
            Grafo->n_vertice++;
        }
        visitado[desemp] = conjunto[desemp] = 1;
        aux_lista = Grafo->lista_Adj[desemp];
        i++;
        while(aux_lista != NULL){
            if(aux_lista->altura > niv_agua && visitado[aux_lista->vizinho] != 1){
                pushP(p, aux_lista->vizinho);
            }
            aux_lista = aux_lista->prox;
        }
    }
    for(i = 1; i < MAX; i++){
        if(aux_visitado[i] != 0)
            printf(" %d", aux_visitado[i]);
    }
    free(p);
    return conjunto;
}

int *buscaLargura(grafo *Grafo, int *visitado, int origem, int destino){
    int tam, verif, desemf, aux;
    int *conjunto, *pai;
    int i;
    nodo *aux_lista;

    Pilha *f = cria_fila();
    pai = (int*)malloc(MAX*sizeof(int));

    for(i = 1; i < MAX; i++){
        pai[i] = 0;
    }

    i = 1;
    pushF(f, origem);
    while((verif = fila_vazia(f) != 1)){
        desemf = popF(f);
        visitado[desemf] = 1;
        aux_lista = Grafo->lista_Adj[desemf];
        i++;
        while(aux_lista != NULL){
            if(aux_lista->altura > niv_agua && visitado[aux_lista->vizinho] != 1){
                if(pai[aux_lista->vizinho] == 0)
                    pai[aux_lista->vizinho] = desemf;
                pushF(f, aux_lista->vizinho);
            }
            aux_lista = aux_lista->prox;
        }
    }

    free(f);
    return pai;
}

void imprime_caminho(grafo *Grafo, int *pai, int origem, int destino){
    int aux_impressao[MAX] = {0};
    int aux_origem = origem, aux_destino = destino, num_pontes = 0;
    int i = 1;

    while(1){
        aux_impressao[i] = aux_destino;
        if(origem == aux_destino) break;
        if(pai[aux_destino] == 0){
            printf("sem caminho entre %d e %d", origem, destino);
            return;
        }
        aux_destino = pai[aux_destino];
        i++;
    }

    printf("%d ->", aux_impressao[i]);
    i--;
    num_pontes++;
    for(; i > 1; i--){
        printf(" %d ->", aux_impressao[i]);
        num_pontes++;
    }
    printf(" %d (%d pontes)", aux_impressao[1], num_pontes);


}

int quant_Pontes(grafo *Grafo, int *conjunto){
    int pontes = 0, j, i = 0;
    nodo *aux_lista;

    i = 1;
    while(1){
        while(conjunto[i] != 1 && i < MAX) i++;
        if(i == MAX) break;
        aux_lista = Grafo->lista_Adj[i];
        while((conjunto[i] == 1) && (aux_lista != NULL)){
            if(aux_lista->altura > niv_agua)
                pontes++;
            aux_lista = aux_lista->prox;
            if(aux_lista == NULL) i++;
        }
    }
    pontes = pontes/2;

    return pontes;
}
