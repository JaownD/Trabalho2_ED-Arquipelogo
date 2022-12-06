#include <stdio.h>
#include <stdlib.h>
#include "ListaAdj.h"

nodo *insere_vizinho(nodo *lista, int ilha, int aux_ilha, int h){
    nodo *aux_lista = lista;
    nodo *novo = (nodo*)malloc(sizeof(nodo));
    novo->atual = ilha;
    novo->vizinho = aux_ilha;
    novo->altura = h;
    novo->prox = lista;
    return novo;
}

/*
    nodo *aux_lista = lista;
    nodo *novo = (nodo*)malloc(sizeof(nodo));
    novo->atual = ilha;
    novo->vizinho = aux_ilha;
    novo->altura = h;
    novo->prox = NULL;

    if(aux_lista == NULL)
        return novo;
    while(aux_lista->prox != NULL) aux_lista = aux_lista = aux_lista->prox;
        aux_lista->prox = novo;
    return lista;
*/
