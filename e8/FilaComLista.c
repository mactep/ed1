#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "Fila.h"

struct fila {
    Lista* alunos;
};

Fila* inicFila() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->alunos = criaLista();

    return fila;
}

void insereFila(Fila* fila, Aluno* aluno) {
    insereElemento(fila->alunos, aluno);
}

Aluno* retiraFila(Fila* fila) {
    return retiraElemento(fila->alunos, 0)->aluno;
}

void imprimeFila(Fila* fila) {
    imprimeLista(fila->alunos);
}

void destroiFila(Fila* fila) {
    destroiLista(fila->alunos);

    free(fila);
}

