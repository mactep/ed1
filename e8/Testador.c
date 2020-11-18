#include <stdlib.h>
#include <stdio.h> // definindo o NULL

#include "aluno.h"
#include "Fila.h"

int main()
{
    printf("Criando alunos\n");
    Aluno* a1 = inicAluno(1, "a1", 8.5);
    Aluno* a2 = inicAluno(2, "a2", 6);
    Aluno* a3 = inicAluno(3, "a3", 9.9);
    Aluno* a4 = inicAluno(4, "a4", 2.3);
    Aluno* a5 = inicAluno(5, "a5", 5);

    printf("Criando fila\n");
    Fila* fila = inicFila();

    printf("Inserindo na fila\n");
    insereFila(fila, a1);
    insereFila(fila, a2);
    insereFila(fila, a3);
    insereFila(fila, a4);
    insereFila(fila, a5);
    imprimeFila(fila);

    printf("Retirando da fila\n");
    imprimeAluno(retiraFila(fila));
    imprimeAluno(retiraFila(fila));
    imprimeAluno(retiraFila(fila));

    printf("Fila depois de retirar\n");
    imprimeFila(fila);

    printf("Inserindo de volta na fila\n");
    insereFila(fila, a1);
    insereFila(fila, a2);
    imprimeFila(fila);

    printf("Destruindo fila\n");
    destroiFila(fila);

    printf("Destruindo alunos\n");
    destroiAluno(a1);
    destroiAluno(a2);
    destroiAluno(a3);
    destroiAluno(a4);
    destroiAluno(a5);
}
