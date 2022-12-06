#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED

typedef struct Pilha{
    int vetor[100];
    int topo;
}Pilha;

Pilha *cria_pilha();

void pushP(Pilha *p, int x);

int popP(Pilha *p);

int pilha_vazia(Pilha *p);

#endif
