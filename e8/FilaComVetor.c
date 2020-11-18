#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"

#define TAM 10

struct fila {
    int ini;
    int len;
    Aluno* alunos[TAM];
};

Fila* inicFila() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->ini = 0;
    fila->len = 0;

    return fila;
}

void insereFila(Fila* fila, Aluno* aluno) {
    if (!fila || fila->len >= TAM) {
        printf("Fila cheia");
        return;
    }

    int pos = (fila->ini + fila->len) % TAM;
    fila->alunos[pos] = aluno;
    fila->len++;
}

Aluno* retiraFila(Fila* fila) {
    if (!fila || fila->len == 0) {
        printf("Fila vazia");
        return NULL;
    }

    Aluno* aluno = fila->alunos[fila->ini];
    fila->ini = (fila->ini + 1) % TAM;
    fila->len--;

    return aluno;
}

void imprimeFila(Fila* fila) {
    if (!fila) {
        return;
    }

    int pos;
    for (int i = 0; i < fila->len; i++) {
        pos = (fila->ini + i) % TAM;
        imprimeAluno(fila->alunos[pos]);
    }
}

void destroiFila(Fila* fila) {
    if (!fila) {
        return;
    }

    free(fila);
}
