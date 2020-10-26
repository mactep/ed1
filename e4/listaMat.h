#ifndef LISTAMAT_H_
#define LISTAMAT_H_

#include "matriz.h"

typedef struct cel Cel;
typedef struct lista Lista;

Lista* criaLista();

void insereLista(Lista* lista, Matriz* mat);

Cel* retiraLista(Lista* lista, int pos);

void imprimeLista(Lista* lista);

void destroiLista(Lista* lista);

#endif
