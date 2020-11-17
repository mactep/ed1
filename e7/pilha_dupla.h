#ifndef pilha_dupla_h
#define pilha_dupla_h

#define MaxTam 10

typedef int TipoItem;

typedef struct indicepilha IndicePilha;

typedef struct pilhadupla PilhaDupla;

PilhaDupla* inicPilha(void);

void push(PilhaDupla* p, int c, TipoItem* n);

TipoItem* pop(PilhaDupla* p, int c);

void imprime(PilhaDupla* p, int c);

void destroi(PilhaDupla* p);

#endif
