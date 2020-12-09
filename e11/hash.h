#ifndef hash_h
#define hash_h

#include "palavra.h"

typedef struct hash Hash;

Hash* cria_hash(int tam);

Palavra* acessa(Hash* hash, char* string);

int conta_palavras(Hash* hash);

void imprime_hash(Hash* hash);

void destro_hash(Hash* hash);

#endif /* ifndef hash_h */
