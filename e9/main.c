#include <stdlib.h>
#include <stdio.h>

#include "aluno.h"
#include "arvore.h"

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
    Arvore* arv = cria_arvore(a1,
            cria_arvore(a2, cria_arvore_vazia(), cria_arvore_vazia()),
            cria_arvore(a3,
                cria_arvore(a4, cria_arvore_vazia(), cria_arvore_vazia()),
                cria_arvore(a5, cria_arvore_vazia(), cria_arvore_vazia())
            )
    );

    imprime_arvore(arv);

    printf("Verificando se a1 pertence a arvore\n");
    printf("%d\n", pertence_arvore(arv, a1));

    printf("Verificando se a6 pertence a arvore\n");
    printf("%d\n", pertence_arvore(arv, a6));

    printf("Altura da arvore: %d\n", altura(arv));
    printf("Folhas da arvore: %d\n", folhas(arv));
    printf("Ocorrencias de a1 na arvore: %d\n", ocorrencias(arv, a1));

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
