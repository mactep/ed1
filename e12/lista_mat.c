#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"
#include "arquivo.h"

Cel* criaListaMat() {
    return criaLista();
}

Cel* insereMatriz(Cel* lista, Matriz* mat) {
    if (get_cont(lista) == NULL) {
        set_cont(lista, mat);
        return lista;
    } else {
        Cel* cel = criaLista();
        set_cont(cel, mat);
        set_prox(cel, lista);
        set_ant(cel, NULL);
        set_ant(lista, cel);

        return cel;
    }
}

Cel* retiraMatriz(Cel* lista, int pos) {
    return retiraElemento(lista, pos);
}

int imprime(void* cont) {
    imprimeMatriz(cont);
    return 1;
}

void imprimeListaMat(Cel* lista) {
    percorreLista(lista, imprime);
}

void destroiListaMat(Cel* lista) {
    destroiLista(lista);
}
