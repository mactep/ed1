#ifndef lista_h
#define lista_h

#include "aluno.h"
#include "professor.h"

typedef struct lista Lista;

Lista* criaLista(void);

void insereAluno(Lista* lista, Aluno* al);

void insereProfessor(Lista* lista, Professor* prof);

void imprimeLista(Lista* lista);

float valorChurrasco(Lista* lista);

void destroiLista(Lista* lista);

#endif
