#ifndef LISTAMAT_H_
#define LISTAMAT_H_

#include "matriz.h"

typedef struct cel Cel;
struct cel {
    Matriz* mat;
    Cel* prox;
    Cel* ant;
};


Cel* criaLista();

Cel* insereElemento(Cel* lista, Matriz* mat);

Cel* retiraElemento(Cel* lista, int pos);

void imprimeLista(Cel* lista);

void destroiLista(Cel* lista);

#endif
