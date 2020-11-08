#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"
#include "professor.h"
#include "lista.h"

#define PROF 0
#define ALUNO 1

typedef struct cel Cel;

struct cel {
    Cel* prox;
    void* item;
    int tipo;
};

struct lista {
    Cel* prim;
    Cel* ult;
};

Lista* criaLista(void) {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereAluno(Lista* lista, Aluno* al) {
    Cel* cel = (Cel*) malloc(sizeof(Cel));
    cel->item = al;
    cel->tipo = ALUNO;
    cel->prox = NULL;

    if (lista->ult == NULL) {
        lista->prim = cel;
        lista->ult = cel;
    } else {
        lista->ult->prox = cel;
        lista->ult = cel;
    }
}

void insereProfessor(Lista* lista, Professor* prof) {
    Cel* cel = (Cel*) malloc(sizeof(Cel));
    cel->item = prof;
    cel->tipo = PROF;
    cel->prox = NULL;

    if (lista->ult == NULL) {
        lista->prim = cel;
        lista->ult = cel;
    } else {
        lista->ult->prox = cel;
        lista->ult = cel;
    }
}

void imprimeLista(Lista* lista) {
    for (Cel* cel = lista->prim; cel != NULL; cel = cel->prox) {
        if (cel->tipo == ALUNO) {
            imprimeAluno(cel->item);
        } else if (cel->tipo == PROF) {
            imprimeProfessor(cel->item);
        } else {
            printf("sei o que tá rolando aqui não\n");
        }
    }
}

float valorChurrasco(Lista* lista) {
    float valor = 0;

    for (Cel* cel = lista->prim; cel != NULL; cel = cel->prox) {
        if (cel->tipo == ALUNO) {
            valor += 30;
        } else if (cel->tipo == PROF) {
            valor += getSalario(cel->item) * 0.02;
        } else {
            printf("sei o que tá rolando aqui não\n");
        }
    }

    return valor;
}

void destroiLista(Lista* lista) {
    Cel* cel = lista->prim;
    Cel* aux;

    while (cel != NULL) {
        aux = cel->prox;
        free(cel);
        cel = aux;
    }

    free(lista);
}
