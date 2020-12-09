#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

struct hash {
    Palavra** lista;
    int tam;
};

Hash* cria_hash(int tam) {
    Hash* hash = (Hash*) malloc(sizeof(Hash));

    hash->tam = tam;
    hash->lista = (Palavra**) malloc(sizeof(Palavra*) * tam);

    for (int i = 0; i < tam; i++) {
        hash->lista[i] = NULL;
    }

    return hash;
}

int calc_hash(char* string, int tam) {
    int soma;

    for (int i = 0; string[i] != '\0'; i++) {
        soma += string[i];
    }

    return (soma % tam);
}

Palavra* acessa(Hash* hash, char* string) {
    Palavra* pal;
    int indice = calc_hash(string, hash->tam);

    pal = busca_palavra(hash->lista[indice], string);
    if (pal == NULL) {
        pal = cria_palavra(string);
        hash->lista[indice] = insere_palavra_lista(hash->lista[indice], pal);
    }

    return pal;
}

int conta_palavras(Hash* hash) {
    int soma;

    for (int i = 0; i < hash->tam; i++) {
        soma += conta_palavra_lista(hash->lista[i]);
    }

    return soma;
}

void imprime_hash(Hash* hash) {
    for (int i = 0; i < hash->tam; i++) {
        printf("Posição %d: ", i);
        imprime_lista(hash->lista[i]);
    }
}

void destroi_hash(Hash* hash) {
    for (int i = 0; i < hash->tam; i++) {
        destroi_palavra(hash->lista[i]);
    }

    free(hash->lista);
    free(hash);
}
