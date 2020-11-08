#ifndef professor_h
#define professor_h

typedef struct professor Professor;

Professor* inicProfessor(int siape, char* nome, float salario);

void imprimeProfessor(Professor* prof);

int getSiape(Professor* prof);

char* getNomeProfessor(Professor* prof);

float getSalario(Professor* prof);

void destroiProfessor(Professor* prof);

#endif
