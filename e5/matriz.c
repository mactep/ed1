#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

struct matriz {
    int linhas;
    int colunas;
    int* array;
};

Matriz* inicializaMatriz(int nlinhas, int ncolunas) {
    // nlinhas * ncolunas > 0

    Matriz* mat = (Matriz*) malloc(sizeof(Matriz));
    mat->linhas = nlinhas;
    mat->colunas = ncolunas;
    mat->array = (int*) malloc(sizeof(int) * nlinhas * ncolunas);

    return mat;
}

void modificaElemento(Matriz* mat, int linha, int coluna, int elem) {
    // mat existe

    if (linha < mat->linhas && coluna < mat->colunas) {
        mat->array[linha * mat->colunas + coluna] = elem;
    }
}

int recuperaElemento(Matriz* mat, int linha, int coluna) {
    // mat existe

    if (linha < mat->linhas && coluna < mat->colunas) {
        return mat->array[linha * mat->colunas + coluna];
    }

    return -1;
}

int recuperaNColunas(Matriz* mat) {
    // mat existe

    return mat->colunas;
}

int recuperaNLinhas(Matriz* mat) {
    // mat existe

    return mat->linhas;
}

Matriz* transposta(Matriz* mat) {
    // mat existe

    Matriz* transp;
    transp = inicializaMatriz(mat->colunas, mat->linhas);

    for (int i = 0; i < recuperaNLinhas(mat); i++) {
        for (int j = 0; j < recuperaNColunas(mat); j++) {
            modificaElemento(transp, j, i, recuperaElemento(mat, i, j));
        }
    }

    return transp;
}

Matriz* multiplicacao(Matriz* mat1, Matriz* mat2) {
    // mat existe

    int aux;
    Matriz* mult;
    mult = inicializaMatriz(mat1->linhas, mat2->colunas);

    if (mat1->colunas == mat2->linhas) {
        // mat2 = transposta(mat2);

        for (int i = 0; i < recuperaNLinhas(mat1); i++) {
            for (int j = 0; j < recuperaNColunas(mat2); j++) {
                aux = 0;
                for (int k = 0; k < recuperaNLinhas(mult); k++) {
                    aux += recuperaElemento(mat1, i, k) * recuperaElemento(mat2, k, j);
                }
                modificaElemento(mult, i, j, aux);
            }
        }
    }

    return mult;
}

void imprimeMatriz(Matriz* mat) {
    for (int i = 0; i < recuperaNLinhas(mat); i++) {
        for (int j = 0; j < recuperaNColunas(mat); j++) {
            printf("%d ", recuperaElemento(mat, i, j));
        }
        printf("\n");
    }
}

void destroiMatriz(Matriz* mat) {
    free(mat->array);
    free(mat);
}
