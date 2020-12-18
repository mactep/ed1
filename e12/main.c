#include <stdlib.h>
#include <stdio.h>

#include "lista_mat.h"
#include "matriz.h"

#define NLINHAS 3
#define NCOLUNAS 3

int main()
{
    printf("Criando matrizes\n");
    Matriz* um = inicializaMatriz(NLINHAS, NCOLUNAS);
    for (int i = 0; (i < NLINHAS || i < NCOLUNAS); i++) {
        modificaElemento(um, i, i,1);
    }

    Matriz* dois = inicializaMatriz(NLINHAS, NCOLUNAS);
    for (int i = 0; (i < NLINHAS || i < NCOLUNAS); i++) {
        modificaElemento(dois, i, i, 2);
    }

    Matriz* tres = inicializaMatriz(NLINHAS, NCOLUNAS);
    for (int i = 0; (i < NLINHAS || i < NCOLUNAS); i++) {
        modificaElemento(tres, i, i, 3);
    }

    printf("Criado lista\n");
    Cel* matrizes = criaListaMat();

    printf("Inserindo matrizes na lista\n");
    matrizes = insereMatriz(matrizes, um);
    matrizes = insereMatriz(matrizes, dois);
    matrizes = insereMatriz(matrizes, tres);

    imprimeListaMat(matrizes);

    printf("removendo matrizes\n");
    matrizes = retiraElemento(matrizes, 0);
    imprimeListaMat(matrizes);
    printf("----------------------\n");

    matrizes = retiraElemento(matrizes, 1);
    imprimeListaMat(matrizes);
    printf("----------------------\n");

    printf("Inserindo matrizes de volta\n");
    matrizes = insereElemento(matrizes, um);
    matrizes = insereElemento(matrizes, tres);

    imprimeListaMat(matrizes);

    destroiMatriz(um);
    destroiMatriz(dois);
    destroiMatriz(tres);


    printf("Destruindo listas\n");
    destroiLista(matrizes);
}

