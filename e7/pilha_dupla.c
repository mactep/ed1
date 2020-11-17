#include <stdio.h>
#include <stdlib.h>

#include "pilha_dupla.h"

struct indicepilha {
    int topo;
    int base;
};

struct pilhadupla {
    TipoItem* Item[MaxTam];
    IndicePilha Pilha1;
    IndicePilha Pilha2;
};

PilhaDupla* inicPilha(void) {
    PilhaDupla* p = (PilhaDupla*)malloc(sizeof(PilhaDupla));
    p->Pilha1.base = 0;
    p->Pilha1.topo = -1;
    p->Pilha2.base = MaxTam - 1;
    p->Pilha2.topo = MaxTam;

    return p;
}

void push(PilhaDupla* p, int c, TipoItem* n) {
    if (!p || p->Pilha1.topo == p->Pilha2.topo - 1) {
        printf("pilha cheia\n");
        return;
    }
    if (c == 1) {
        p->Pilha1.topo++;
        p->Item[p->Pilha1.topo] = n;
    } else {
        p->Pilha2.topo--;
        p->Item[p->Pilha2.topo] = n;
    }
}

TipoItem* pop(PilhaDupla* p, int c) {
    TipoItem* ret;
    if (c == 1) {
        if (p->Pilha1.topo > -1) {
            ret = p->Item[p->Pilha1.topo];
            p->Pilha1.topo--;
        }
    } else {
        if (p->Pilha2.topo < MaxTam) {
            ret = p->Item[p->Pilha2.topo];
            p->Pilha2.topo++;
        }
    }
    return ret;
}

void imprime(PilhaDupla* p, int c) {
    if (!p) {
        return;
    }

    if (c == 1) {
        for (int i = 0; i <= p->Pilha1.topo; i++) {
            printf("%d\n", *p->Item[i]);
        }
    } else {
        for (int i = MaxTam - 1; i >= p->Pilha2.topo; i--) {
            printf("%d\n", *p->Item[i]);
        }
    }
}

void destroi(PilhaDupla* p) {
    if (!p) {
        return;
    }

    free(p);
}
