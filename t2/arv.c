#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "arv.h"

struct arv {
    char* val;
    Arvore* esq;
    Arvore* dir;
};

Arvore* cria_node_arvore() {
    Arvore* arv = (Arvore*) malloc(sizeof(Arvore));
    arv->val = NULL;
    arv->esq = NULL;
    arv->dir = NULL;

    return arv;
}

void imprime_arvore(Arvore* arv) {
    if (arv != NULL) {
        printf("%s\n", arv->val);
        imprime_arvore(arv->esq);
        imprime_arvore(arv->dir);
    }
}

// percorre a arvore hierarquicamente realizando as operações e computando o valor da expressão
float calcula_arvore(Arvore* arv) {
    if (arv != NULL) {
        if (strcmp(arv->val, "+") == 0) {
            return calcula_arvore(arv->esq) + calcula_arvore(arv->dir);
        }
        else if (strcmp(arv->val, "-") == 0) {
            return calcula_arvore(arv->esq) - calcula_arvore(arv->dir);
        }
        else if (strcmp(arv->val, "*") == 0) {
            return calcula_arvore(arv->esq) * calcula_arvore(arv->dir);
        }
        else if (strcmp(arv->val, "/") == 0) {
            return calcula_arvore(arv->esq) / calcula_arvore(arv->dir);
        }
        // se for uma raiz, converte pra float e retorna
        else if (isdigit(arv->val[0])) {
            return atof(arv->val);
        }
    }
}

// percorre e libera a memória
void destroi_arvore(Arvore* arv) {
    if (arv != NULL) {
        destroi_arvore(arv->esq);
        destroi_arvore(arv->dir);
        free(arv);
    }
}

// função para selecionar os dígitos que compõem um número
void le_numero(FILE* entrada, char* string) {
    char car = fgetc(entrada);

    int len = 0;
    char num[256] = "";

    // enquanto estiver lendo um dígito, adiciona ele ao vetor
    while (isdigit(car)) {
        num[len] = car;
        len++;
        car = fgetc(entrada);
    }

    // adicionar terminação
    num[len + 1] = '\0';
    // retorna pra poder ler o próximo token
    fseek(entrada, -1, SEEK_CUR);
    strcpy(string, num);
}

Arvore* parse_entrada(FILE* entrada, Arvore* arv) {
    char car;

    // Lê, caractere a caractere, até o fim da linha
    while (car != '\n' && car != '\r') {
        car = fgetc(entrada);

        // retorna se estiver lendo no fim do arquivo
        if (car == EOF) {
            return NULL;
        }

        // Cria nó se abrir parenteses
        if (car == '(') {
            // Cria nó auxiliar
            Arvore* aux = cria_node_arvore();

            // se o nó pai for nulo, atribui o auxiliar
            if (arv == NULL) {
                arv = aux;
            // senão, atribui pra um dos lados
            } else if (arv->esq == NULL) {
                arv->esq = aux;
            } 
            else if (arv->dir == NULL) {
                arv->dir = aux;
            }
            aux = parse_entrada(entrada, aux);
        }

        // verifica se o caractere lido é um dígito
        else if (isdigit(car)) {
            // retorna uma posição pra poder ler o número por completo
            fseek(entrada, -1, SEEK_CUR);
            char* num = (char*) malloc(sizeof(char) * 256);
            le_numero(entrada, num);

            arv->val = num;
        }

        // verifica se o caractere lido é uma operação e atribui valor do nó
        else if (car == '+' || car == '-' || car == '*' || car == '/') {
            char *val = malloc(sizeof(char)*2);
            val[0] = car;
            val[1] = '\0';
            arv->val = val;
        }

        // retornar ao fechar os parenteses
        else if (car == ')') {
            return arv;
        }
    }

    return arv;
}
