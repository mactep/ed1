#include <stdio.h>
#include <stdlib.h>

#include "professor.h"

struct professor {
    char* nome;
    int siape;
    float salario;
};

Professor* inicProfessor(int siape, char* nome, float salario) {
    Professor* novo = (Professor*) malloc(sizeof(Professor));

    novo->siape = siape;
    novo->nome = nome;
    novo->salario = salario;

    return novo;
}

void imprimeProfessor(Professor* prof) {
    printf("Siape: %d\n", prof->siape);
    printf("Nome: %s\n", prof->nome);
    printf("Salário: %.2f\n", prof->salario);
}

int getSiape(Professor* prof) {
    return prof->siape;
}

char* getNomeProfessor(Professor* prof) {
    return prof->nome;
}

float getSalario(Professor* prof) {
    return prof->salario;
}

void destroiProfessor(Professor* prof) {
    free(prof->nome);
    free(prof);
}
