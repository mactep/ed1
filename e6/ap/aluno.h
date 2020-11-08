#ifndef aluno_h
#define aluno_h

typedef struct aluno Aluno;

Aluno* inicAluno(int mat, char* nome, float CR);

void imprimeAluno(Aluno* al);

int getMatricula(Aluno* al);

char* getNomeAluno(Aluno* al);

float getCR(Aluno* al);

void destroiAluno(Aluno* al);

#endif
