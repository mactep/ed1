#ifndef LISTAMAT_H_
#define LISTAMAT_H_

#include "aluno.h"

typedef struct cel Cel;
struct cel {
    Aluno* aluno;
    Cel* prox;
};

typedef struct lista Lista;
struct lista {
    Cel* prim;
    Cel* ult;
};


Lista* criaLista();

void insereElemento(Lista* lista, Aluno* aluno);

Cel* retiraElemento(Lista* lista, int pos);

void imprimeLista(Lista* lista);

void destroiLista(Lista* lista);

#endif
