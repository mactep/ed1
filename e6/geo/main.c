// main pra testar o código
// Gerar algumas matrizes para teste (umas 3 ou 4 matrizes já seria suficiente);
// Inicializar uma lista encadeada;
// Inserir as matrizes na lista;
// Inicializar outra lista encadeada;
// Inserir as matrizes transpostas na segunda lista encadeada;
// Imprima as listas e veja se estão corretas!!!
// Retire algumas matrizes para verificar se o retira está funcionando (retire
// da primeira posição, última posição e caso comum);
// Insira as matrizes novamente para verificar se o retira não “quebrou” a lista;
// Libere as listas!
// Libere as matrizes!
// Passe o valgrind para verificar se não há erros e/ou vazamento de memória.

#include <stdlib.h>
#include <stdio.h> // definindo o NULL

#include "listaMat.h"
#include "matriz.h"

//definindo constantes para o número de linhas e colunas da matriz
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
    Lista* matrizes = criaLista();

    printf("Inserindo matrizes na lista\n");
    insereElemento(matrizes, um);
    insereElemento(matrizes, dois);
    insereElemento(matrizes, tres);

    imprimeLista(matrizes);

    printf("Criado lista\n");
    Lista* transpostas = criaLista();

    printf("Inserindo matrizes na lista\n");
    insereElemento(transpostas, transposta(um));
    insereElemento(transpostas, transposta(dois));
    insereElemento(transpostas, transposta(tres));

    imprimeLista(transpostas);

    printf("removendo matrizes\n");
    Cel* cel;
    cel = retiraElemento(matrizes, 0);
    if (cel != NULL) {
        imprimeMatriz(cel->mat);
        free(cel);
        printf("\n");
    }

    cel = retiraElemento(matrizes, 1);
    if (cel != NULL) {
        imprimeMatriz(cel->mat);
        free(cel);
        printf("\n");
    }

    cel = retiraElemento(transpostas, 1);
    if (cel != NULL) {
        imprimeMatriz(cel->mat);
        free(cel);
        printf("\n");
    }

    printf("Inserindo matrizes de volta\n");
    insereElemento(matrizes, um);
    insereElemento(matrizes, tres);

    imprimeLista(matrizes);

    printf("Destruindo matrizes\n");
    for (Cel* cel = matrizes->prim; cel != NULL; cel = cel->prox) {
        destroiMatriz(cel->mat);
    }

    for (Cel* cel = transpostas->prim; cel != NULL; cel = cel->prox) {
        destroiMatriz(cel->mat);
    }

    printf("Destruindo listas\n");
    destroiLista(matrizes);
    destroiLista(transpostas);
}

