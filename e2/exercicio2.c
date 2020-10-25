#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char* nome;
    int matricula;
    float p1;
    float p2;
    float p3;
} Aluno;

void imprime_turma(int n, Aluno** turma);
void imprime_aprovados(int n, Aluno** turma);
float media_turma(int n, Aluno** turma);

int main(int argc, char *argv[])
{
    int n;

    printf("Quantidade de alunos: ");
    scanf("%d", &n);
    Aluno** turma = (Aluno**) malloc(sizeof(Aluno*) * n);

    /*
    FILE *entrada;
    entrada = fopen("./turma4.txt", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        return 1;
    }
    fscanf(entrada, "%d\n", &n);
    Aluno** turma = (Aluno**) malloc(sizeof(Aluno*) * n);

    for (int i = 0; i < n; i++) {
        turma[i] = (Aluno*) malloc(sizeof(Aluno));

        turma[i]->nome = (char*) malloc(sizeof(char) * 51);
        fscanf(entrada, " %50[^\n]", turma[i]->nome);
        fscanf(entrada, "%d", &turma[i]->matricula);
        fscanf(entrada, "%f", &turma[i]->p1);
        fscanf(entrada, "%f", &turma[i]->p2);
        fscanf(entrada, "%f", &turma[i]->p3);
    }
    */

    for (int i = 0; i < n; i++) {
        turma[i] = (Aluno*) malloc(sizeof(Aluno));

        printf("Nome: ");
        turma[i]->nome = (char*) malloc(sizeof(char) * 51);
        scanf(" %50[^\n]", turma[i]->nome);

        printf("Matricula: ");
        scanf("%d", &turma[i]->matricula);

        printf("P1: ");
        scanf("%f", &turma[i]->p1);

        printf("P2: ");
        scanf("%f", &turma[i]->p2);

        printf("P3: ");
        scanf("%f", &turma[i]->p3);
    }

    imprime_turma(n, turma);
    printf("\n\n");

    imprime_aprovados(n, turma);
    printf("\n\n");

    printf("%f", media_turma(n, turma));
    printf("\n\n");

    for (int i = 0; i < n; i++) {
        free(turma[i]->nome);
        free(turma[i]);
    }

    free(turma);
    return 0;
}

void imprime_turma(int n, Aluno** turma) {
    for (int i = 0; i < n; i++) {
        printf("%d %s %f %f %f\n", turma[i]->matricula, turma[i]->nome, turma[i]->p1, turma[i]->p2, turma[i]->p3);
    }
}

float media_aluno(Aluno* aluno) {
    return (aluno->p1 + aluno->p2 + aluno->p3) / 3;
}

void imprime_aprovados(int n, Aluno** turma) {
    printf("Alunos aprovados\n");
    for (int i = 0; i < n; i++) {
        if (media_aluno(turma[i]) >= 5) {
            printf("%s media: %f \n", turma[i]->nome, media_aluno(turma[i]));
        }
    }
}

float media_turma(int n, Aluno** turma) {
    float soma = 0;

    for (int i = 0; i < n; i++) {
        soma += media_aluno(turma[i]);
    }

    return soma / n;
}
