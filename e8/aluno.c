#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"

struct aluno {
    char* nome;
    int matricula;
    float CR;
};

Aluno* inicAluno(int matricula, char* nome, float CR) {
    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));

    novo->matricula = matricula;
    novo->nome = nome;
    novo->CR = CR;

    return novo;
}

void imprimeAluno(Aluno* al) {
    printf("Matrícula: %d\n", al->matricula);
    printf("Nome: %s\n", al->nome);
    printf("CR: %.2f\n", al->CR);
}

int getMatricula(Aluno* al) {
    return al->matricula;
}

char* getNomeAluno(Aluno* al) {
    return al->nome;
}

float getCR(Aluno* al) {
    return al->CR;
}

void destroiAluno(Aluno* al) {
    // free(al->nome);
    free(al);
}
