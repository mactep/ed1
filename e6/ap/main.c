#include <stdlib.h>
#include <stdio.h> // definindo o NULL

#include "aluno.h"
#include "lista.h"
#include "professor.h"

int main()
{
    printf("Criando alunos\n");
    Aluno* a1 = inicAluno(1, "a1", 8.5);
    Aluno* a2 = inicAluno(2, "a2", 6);
    Aluno* a3 = inicAluno(3, "a3", 9.9);
    Aluno* a4 = inicAluno(4, "a4", 2.3);
    Aluno* a5 = inicAluno(5, "a5", 5);

    printf("Criando professores\n");
    Professor* p1 = inicProfessor(1, "p1", 8500.9);
    Professor* p2 = inicProfessor(2, "p2", 6000.5);


    printf("Criado listas\n");
    Lista* churrasco = criaLista();

    printf("Inserindo matrizes na lista\n");
    insereAluno(churrasco, a1);
    insereAluno(churrasco, a2);
    insereAluno(churrasco, a3);
    insereAluno(churrasco, a4);
    insereAluno(churrasco, a5);
    insereProfessor(churrasco, p1);
    insereProfessor(churrasco, p2);

    imprimeLista(churrasco);

    printf("Valor do churrasco: %.2f", valorChurrasco(churrasco));

    printf("Destruindo alunos\n");
    destroiAluno(a1);
    destroiAluno(a2);
    destroiAluno(a3);
    destroiAluno(a4);
    destroiAluno(a5);

    printf("Destruindo professores\n");
    destroiProfessor(p1);
    destroiProfessor(p2);

    printf("Destruindo lista\n");
    destroiLista(churrasco);
}
