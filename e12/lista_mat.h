#ifndef lista_mat_h
#define lista_mat_h

#include "arquivo.h"
#include "matriz.h"

Cel* criaListaMat();

Cel* insereMatriz(Cel* lista, Matriz* mat);

Cel* retiraMatriz(Cel* lista, int pos);

void imprimeListaMat(Cel* lista);

void destroiListaMat(Cel* lista);

#endif
