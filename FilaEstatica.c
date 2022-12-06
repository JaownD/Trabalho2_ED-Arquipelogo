#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

Fila *cria_fila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->fim = f->inicio = 0;
}

void pushF(Fila *f, int x){
    f->vetor[f->fim] = x;
    f->fim++;
}

int popF(Fila *f){
    int aux = f->vetor[f->inicio];
    f->inicio++;
    return aux;
}

int fila_vazia(Fila *f){
    if(f->fim == f->inicio) return 1;
    return 0;
}
