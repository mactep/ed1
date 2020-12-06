#include <stdlib.h>
#include <stdio.h>

#include "aluno.h"
#include "abb.h"

int main()
{
    printf("Criando alunos\n");
    Aluno* a1 = inicAluno(1, "a1", 8.5);
    Aluno* a2 = inicAluno(2, "a2", 6);
    Aluno* a3 = inicAluno(3, "a3", 9.9);
    Aluno* a4 = inicAluno(4, "a4", 2.3);
    Aluno* a5 = inicAluno(5, "a5", 5);
    Aluno* a6 = inicAluno(6, "a6", 10);

    printf("Criado arvore\n");
    Arvore* arv = cria_arvore();

    printf("Inserindo alunos\n");
    arv = insere_arvore(arv, a1);
    arv = insere_arvore(arv, a2);
    arv = insere_arvore(arv, a3);
    arv = insere_arvore(arv, a4);
    arv = insere_arvore(arv, a5);
    arv = insere_arvore(arv, a6);

    imprime_arvore(arv);

    printf("Buscando aluno 4\n");
    Arvore* arvere = busca_arvore(arv, 4);

    if (arvere != NULL) {
        printf("%s\n", get_aluno(arvere)->nome);
    }

    printf("Removendo aluno 4\n");
    retira_arvore(arv, 4);

    imprime_arvore(arv);

    printf("Destruindo arvore\n");
    destroi_arvore(arv);

    printf("Destruindo alunos\n");
    destroiAluno(a1);
    destroiAluno(a2);
    destroiAluno(a3);
    destroiAluno(a4);
    destroiAluno(a5);
    destroiAluno(a6);
}
