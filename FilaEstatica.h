#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED

typedef struct fila{
    int vetor[100];
    int inicio, fim;
}Fila;

Fila *cria_fila();

void pushF(Fila *f, int x);

int popF(Fila *f);

#endif
