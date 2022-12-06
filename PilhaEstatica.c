#include <stdio.h>
#include "PilhaEstatica.h"

Pilha *cria_pilha(){
    Pilha *p=(Pilha*)malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

void pushP(Pilha *p, int x){
    p->topo++;
    p->vetor[p->topo] = x;
}

int popP(Pilha *p){
    int aux;
    aux = p->vetor[p->topo];
    p->topo--;
    return aux;
}

int pilha_vazia(Pilha *p){
    if(p->topo == 0) return 1;
    return 0;
}
