#ifndef INTERFACE_MAIN_H
#define INTERFACE_MAIN_H

typedef struct data {
    unsigned long long int timestamp;
    int ano;
    int mes;
    int dia;
};

typedef struct aluno {
    int matricula;
    char nome[256];
    char sexo;
    struct data nascimento;
    int cpf;
};

typedef struct professor {
    int matricula;
    char nome[256];
    char sexo;
    struct data nascimento;
    int cpf;
};

typedef struct disciplina {
    char nome[128];
    int id;
    int semestre;
    char professor[128];
};

#define MAX_num_alunos 5
#define MAX_num_professores 5
#define MAX_num_disciplinas 5

extern struct aluno alunos[MAX_num_alunos];
extern struct professor professores[MAX_num_professores];
extern struct disciplina disciplinas[MAX_num_disciplinas];

extern int qtd_aluno = 0;
extern int qtd_professor = 0;
extern int qtd_disciplina = 0;

#endif