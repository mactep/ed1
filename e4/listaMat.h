#ifndef LISTAMAT_H_
#define LISTAMAT_H_

#include "matriz.h"

typedef struct cel Cel;
struct cel {
    Matriz* mat;
    Cel* prox;
};

typedef struct lista Lista;
struct lista {
    Cel* prim;
    Cel* ult;
};


Lista* criaLista();

void insereElemento(Lista* lista, Matriz* mat);

Cel* retiraElemento(Lista* lista, int pos);

void imprimeLista(Lista* lista);

void destroiLista(Lista* lista);

#endif
