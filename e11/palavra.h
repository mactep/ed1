#ifndef palavra_h
#define palavra_h

typedef struct palavra Palavra;

Palavra* cria_palavra(char* string);

char* get_string(Palavra* palavra);

void inc_ocorrencia(Palavra* palavra);

int get_ocorrencia(Palavra* palavra);

Palavra* busca_palavra(Palavra* palavra, char* string);

Palavra* insere_palavra_lista(Palavra* lista, Palavra* palavra);

int conta_palavra_lista(Palavra* palavra);

void imprime_lista(Palavra* palavra);

void destroi_palavra(Palavra* palavra);

#endif /* ifndef palavra_h */
