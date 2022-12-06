#ifndef LISTAADJ_H_INCLUDED
#define LISTAADJ_H_INCLUDED

typedef struct Nodo{
    int atual, vizinho, altura;
    struct Nodo *prox;
}nodo;

typedef struct Grafo{
    nodo **lista_Adj;
    int n_vertice;

}grafo;

nodo *insere_vizinho(nodo *l, int ilha, int aux_ilha, int h);

#endif
