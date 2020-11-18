#ifndef fila_h
#define fila_h

#include "aluno.h"

typedef struct fila Fila;

Fila* inicFila();

void insereFila(Fila* fila, Aluno* aluno);

Aluno* retiraFila(Fila* fila);

void imprimeFila(Fila* fila);

void destroiFila(Fila* fila);

#endif
