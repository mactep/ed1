#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palavra.h"

struct palavra {
    char* string;
    int ocorr;
    Palavra* prox;
};

Palavra* cria_palavra(char* string) {
    Palavra* palavra = (Palavra*) malloc(sizeof(Palavra));

    palavra->string = string;
    palavra->ocorr = 0;
    palavra->prox = NULL;

    return palavra;
}

char* get_string(Palavra* palavra) {
    return palavra->string;
}

void inc_ocorrencia(Palavra* palavra) {
    palavra->ocorr++;
}

int get_ocorrencia(Palavra* palavra) {
    return palavra->ocorr;
}

Palavra* busca_palavra(Palavra* palavra, char* string) {
    for (Palavra* pal = palavra; pal != NULL; pal = pal->prox) {
        if (strcmp(string, pal->string) == 0) {
            return pal;
        }
    }

    return NULL;
}

Palavra* insere_palavra_lista(Palavra* lista, Palavra* palavra) {
    for (Palavra* pal = palavra; pal != NULL; pal = pal->prox) {
        if (lista->prox == NULL) {
            pal->prox = palavra;
        }
    }

    return lista;
}

int conta_palavra_lista(Palavra* palavra) {
    int n = 0;

    for (Palavra* pal = palavra; pal != NULL; pal = pal->prox) {
        n++;
    }

    return n;
}

void imprime_lista(Palavra* palavra) {
    for (Palavra* pal = palavra; pal != NULL; pal = pal->prox) {
        printf("String: %s\n", pal->string);
        printf("Ocorrencias: %d\n", pal->ocorr);
    }
}

void destroi_palavra(Palavra* palavra) {
    Palavra* aux = palavra;
    Palavra* t;

    while (aux != NULL) {
        t = aux->prox;
        free(aux->string);
        free(aux);

        aux = t;
    }
}
